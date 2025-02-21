<h2>This is the output </h2>

![Screenshot (204)](https://github.com/user-attachments/assets/423d7327-924f-4702-8779-90b47dfbdaeb)

# Lab Manual (pdf)

[expt1 msg queue manual.pdf](https://github.com/user-attachments/files/18915111/expt1.msg.queue.manual.pdf)

# sloved code (pdf)

[EXPERIMENT NO1 – MESSAGE QUEUE_240115_094231.pdf](https://github.com/user-attachments/files/18915129/EXPERIMENT.NO1.MESSAGE.QUEUE_240115_094231.pdf)

# IPC (Message Queue) - Decimal Number Conversion

This project demonstrates inter-process communication (IPC) using message queues. The goal of the project is to take a decimal number from the user, convert it to binary, octal, and hexadecimal bases, and send those values to a message queue. Three separate programs will read and display the binary, octal, and hexadecimal values from the message queue.

## Objective

- Accept a decimal number from the user.
- Convert the decimal number to binary, octal, and hexadecimal.
- Send the converted values (binary, octal, and hexadecimal) to a message queue.
- Implement three separate receiver programs to display the binary, octal, and hexadecimal values from the message queue.

## Files

- `sender.c`: Sends the decimal number and its conversions (binary, octal, hex) to the message queue.
- `receiver_binary.c`: Receives and displays the binary value from the message queue.
- `receiver_octal.c`: Receives and displays the octal value from the message queue.
- `receiver_hex.c`: Receives and displays the hexadecimal value from the message queue.
- `README.md`: Documentation for the project.

## Requirements

- C Compiler (GCC)
- Unix-based system (Linux, macOS, etc.) with support for IPC (message queues)

## Compilation

To compile the programs, run the following commands in the terminal:

```bash
gcc -o sender sender.c
gcc -o receiver_binary receiver_binary.c
gcc -o receiver_octal receiver_octal.c
gcc -o receiver_hex receiver_hex.c

Execution
Step 1: Start the Sender Program
In one terminal window, run the sender program:

bash
Copy
./sender
The sender program will prompt you to enter a decimal number. It will then convert the number to binary, octal, and hexadecimal formats and send those values to the message queue.

Step 2: Start the Receiver Programs
In three separate terminal windows, run the receiver programs:

bash
Copy
./receiver_binary
./receiver_octal
./receiver_hex
Each receiver program will listen for the message from the sender and display the corresponding value (binary, octal, or hexadecimal).

Example
Sender Output:
pgsql
Copy
Enter a decimal number (or type 'end' to quit): 255
Receiver Binary Output:
sql
Copy
Binary Value: 11111111
Receiver Octal Output:
yaml
Copy
Octal Value: 377
Receiver Hexadecimal Output:
yaml
Copy
Hex Value: FF
Ending the Communication
You can stop the communication by typing end in the sender program. This will close the message queue and terminate the programs.

Notes
The programs communicate using message queues (msgget, msgrcv, msgsnd, msgctl).
The sender program continuously asks for a decimal number and sends the converted values to the message queue until "end" is entered.
The receiver programs display their respective converted values (binary, octal, and hex) until the sender program sends "end".
The message queue is deleted after the communication ends.




