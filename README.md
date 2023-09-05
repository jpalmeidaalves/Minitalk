# Minitalk - 42 Common Core
## Communication Program with Client and Server
This is a simple communication program consisting of a client and a server that communicate with each other using UNIX signals. The server is started first and prints its PID, while the client sends a string to the server. If you complete the bonus part, the server will acknowledge every message received by sending a signal back to the client, and it will also support Unicode characters.
 ### Rules
 * Generate two executable files: server and client
 * Handle errors:  program should not quit unexpectedly or memory leaks
 * One global variable per program
 * Allowed functions: write, ft_printf and any equivalent YOU coded, signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit.
### Mandatory Part
#### Server
* Start the server first using the following command:
	./server
* After launching, the server will print its PID.
#### Client
* To send a string to the server, use the following command:
	./client <server_pid> "Your message here"
* The client will send the string to the server.
##### Once the server receives the string, it will print it.
##### The server displays the string quickly; it should not take too long to process.
##### The server can receive strings from several clients in a row without needing to restart.
##### Communication between the client and the server is done using UNIX signals, specifically SIGUSR1 and SIGUSR2.

### Bonus Part
#### Server Acknowledgment
* In the bonus part, the server acknowledges every message received by sending back a signal to the client.
#### Unicode Characters Support
* The program supports Unicode characters, allowing you to send and receive messages with Unicode characters.
