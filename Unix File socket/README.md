# Outpot

![WhatsApp Image 2025-03-02 at 20 55 47_47bd86d9](https://github.com/user-attachments/assets/04c79445-040d-4688-9d28-3cf3bc07d88b)

![WhatsApp Image 2025-03-02 at 20 54 28_ed01c85e](https://github.com/user-attachments/assets/84c0a9b9-5c3b-4a64-a852-61b0f1e8acbb)


![WhatsApp Image 2025-03-02 at 20 54 38_32f5c4b6](https://github.com/user-attachments/assets/bc909dbe-a8a7-4439-8e7c-fcee59c5a1e7)


![WhatsApp Image 2025-03-02 at 20 57 29_cbfb9ef6](https://github.com/user-attachments/assets/41aa2cb7-c0c4-4bf9-8986-e5a87cc3551a)



# At first we have to run the server section , then the client section . 

# Lab Manual (pdf)
[EXPERIMENT NO 2.pdf](https://github.com/user-attachments/files/18915079/EXPERIMENT.NO.2.pdf)

# Unix Domain Socket Client-Server Application

This project demonstrates a simple client-server application using Unix Domain Sockets for inter-process communication (IPC). The client sends a list of integers to the server, which sorts them and sends the sorted integers back to the client.

## Requirements

- GCC compiler for C programming.
- A Unix-based system (Linux, macOS, etc.) to support Unix domain sockets.

## Files

- `server.c`: The server code that listens for client connections, sorts the integers, and sends them back.
- `client.c`: The client code that connects to the server, sends integers, and prints the sorted result.
- `README.md`: This documentation.

## Compilation

To compile the `server.c` and `client.c` programs, use the following commands:

```bash
gcc -o server server.c
gcc -o client client.c
Execution
Step 1: Start the Server
In one terminal, run the server program:

bash
Copy
./server
The server will start listening for incoming client connections.

Step 2: Run the Client
In another terminal, run the client program:

bash
Copy
./client
The client will prompt you for the number of integers and then ask for the integers themselves. After the client sends the integers to the server, the server will sort the integers and send them back to the client. The client will then display the sorted integers.

Example
Server Output:
bash
Copy
Server is listening for connections...
Server has sent the sorted integers to the client.
Client Output:
bash
Copy
Enter the number of integers: 5
Enter the integers:
9 5 3 7 1
Sorted integers:
1 3 5 7 9
Clean Up
After running the application, the server will automatically remove the Unix domain socket file (/tmp/sort_socket). You can manually remove it if needed.

bash
Copy
rm /tmp/sort_socket
Notes
The server currently handles one client at a time. If you want to handle multiple clients concurrently, you can modify the server to use fork() or multithreading.
This application uses basic system calls such as socket(), bind(), listen(), accept(), read(), and write() for communication.
License
This project is licensed under the MIT License - see the LICENSE file for details.

python
Copy

### How to use this `README.md`:
1. Save the content above in a file named `README.md` in the same directory as your project.
2. You can view the `README.md` in any markdown viewer, or you can open it in a Git repository or use it for any documentation purposes. 

Let me know if you need any further adjustments!


