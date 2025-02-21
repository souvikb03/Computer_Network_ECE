//SOURAV_13000322066
//SERVER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/unix_socket_example"
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_un server_addr;
    int arr[BUFFER_SIZE];
    int n;

    // Create a socket
    client_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Input array from user
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Send the array to the server
    if (write(client_socket, &n, sizeof(int)) == -1) {
        perror("write");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    if (write(client_socket, arr, n * sizeof(int)) == -1) {
        perror("write");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Receive the sorted array from the server
    if (read(client_socket, arr, n * sizeof(int)) == -1) {
        perror("read");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Close the socket
    close(client_socket);

    return 0;
}