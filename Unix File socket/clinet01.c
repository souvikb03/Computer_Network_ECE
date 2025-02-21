#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/sort_socket"
#define MAX_NUMBERS 100

int main() {
    int client_fd;
    struct sockaddr_un addr;
    int numbers[MAX_NUMBERS];
    ssize_t num_bytes;

    // Create a UNIX domain stream socket
    client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the address of the server
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("connect");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    // Input the number of integers
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid number of integers.\n");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    // Input the integers
    printf("Enter the integers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Send the number of integers to the server
    num_bytes = send(client_fd, &n, sizeof(int), 0);
    if (num_bytes == -1) {
        perror("send");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    // Send the integers to the server
    num_bytes = send(client_fd, numbers, sizeof(int) * n, 0);
    if (num_bytes == -1) {
        perror("send");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    // Receive the sorted integers from the server
    num_bytes = recv(client_fd, numbers, sizeof(int) * n, 0);
    if (num_bytes <= 0) {
        perror("recv");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    // Display the sorted integers
    printf("Sorted numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Close the socket
    close(client_fd);

    return 0;
}
