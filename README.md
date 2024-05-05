# Minitalk (Communication Program (Client-Server))

## Description
Create a communication program consisting of a client and a server.

# Server
- The server must be started first and print its PID after launch.
- It must be capable of receiving strings from multiple clients successively without needing to restart.
- Communication between the client and the server must be done solely using UNIX signals (SIGUSR1 and SIGUSR2).
- Only the signals SIGUSR1 and SIGUSR2 can be used.
# Client
- The client accepts two parameters:
  - The server's PID.
  - The string to send.
- It sends the provided string to the server.
- Once the server receives the string, it must print it.
# Communication Speed
The server must display the received string quickly. One second for displaying 100 characters is considered too long.

# Bonus Part
- The server acknowledges every received message by sending back a signal to the client.
- Support Unicode characters.

# Files
- client.c: Main program logic for the client.
- server.c: Main program logic for the server.

# Usage
1. Compile the source files using the provided Makefile.
2. Start the server first using ./server.
3. Obtain the server's PID.
4. Start the client using ./client <SERVER_PID> <MESSAGE> to send a message to the server.
