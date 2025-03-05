# TCP Socket Programming with Bit Stuffing
This project demonstrates TCP socket programming in C, combined with bit stuffing, a technique used in data communication to ensure that specific bit patterns (like a flag sequence) do not appear in the data stream. The project consists of a server and a client that communicate over a TCP connection.

# Table of Contents
Overview

Bit Stuffing

Project Structure

How to Run

Example Output

Dependencies

Contributing

License

# Overview
# What is Bit Stuffing?
Bit stuffing is a technique used in data communication to ensure that specific bit patterns (like a flag sequence) do not appear in the data stream. If the flag sequence appears in the data, a "stuffed" bit (usually 0) is added to distinguish it from the actual flag.

# What Does This Project Do?
The client performs bit stuffing on the data and sends it to the server.

The server receives the data, performs bit unstuffing, and displays the original data.

Bit Stuffing
How Bit Stuffing Works
The client scans the input data for sequences of five consecutive 1s.

Whenever five 1s are found, a 0 is "stuffed" (inserted) after them to avoid confusion with the flag sequence (01111110).

How Bit Unstuffing Works
The server scans the received data for sequences of five consecutive 1s followed by a 0.

The 0 is removed to restore the original data.

Project Structure
The project consists of two C programs:

server.c: The server listens for incoming connections, receives stuffed data, performs bit unstuffing, and displays the original data.

client.c: The client performs bit stuffing on the data and sends it to the server.

How to Run
Prerequisites
A C compiler (e.g., gcc).

A Linux-based system (or any system with support for POSIX sockets).

Steps to Run
Clone the repository:

bash
Copy
git clone https://github.com/your-username/tcp-bit-stuffing.git
cd tcp-bit-stuffing
Compile the server and client programs:

bash
Copy
gcc server.c -o server
gcc client.c -o client
Run the server:

bash
Copy
./server
In a separate terminal, run the client:

bash
Copy
./client
# Example Output
# Client Output:
Original data: 011111101111101111110
Stuffed data: 01111110011111001111100
Stuffed data sent to server.
# Server Output:
Server listening on port 8080...
Received stuffed data: 01111110011111001111100
Unstuffed data: 011111101111101111110



#
Dependencies
GCC: To compile the C programs.

POSIX-compliant system: For socket programming.

Contributing
Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.