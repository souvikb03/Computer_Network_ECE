#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/sort_socket"
#define MAX_NUMBERS 100

void sort_numbers(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_un addr;
    int numbers[MAX_NUMBERS];
    ssize_t num_bytes;
    socklen_t len;

    // Create a UNIX domain stream socket
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the address for the socket
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections (max 1 client at a time)
    if (listen(server_fd, 1) == -1) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening for incoming connections...\n");

    // Accept a connection from a client
    client_fd = accept(server_fd, NULL, NULL);
    if (client_fd == -1) {
        perror("accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected, receiving numbers...\n");

    // Receive the number of elements
    int n;
    num_bytes = recv(client_fd, &n, sizeof(int), 0);
    if (num_bytes <= 0) {
        perror("recv");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Receive the numbers
    num_bytes = recv(client_fd, numbers, sizeof(int) * n, 0);
    if (num_bytes <= 0) {
        perror("recv");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Sort the numbers
    sort_numbers(numbers, n);

    // Send the sorted numbers back to the client
    num_bytes = send(client_fd, numbers, sizeof(int) * n, 0);
    if (num_bytes == -1) {
        perror("send");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Sorted numbers sent to client.\n");

    // Close the sockets
    close(client_fd);
    close(server_fd);

    // Remove the socket file
    unlink(SOCKET_PATH);

    return 0;
}
