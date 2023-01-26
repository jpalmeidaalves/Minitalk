/* FIRST STEP TO ACOMPLISH THIS PROJECT IS UNDERSTAND HOW SIGNALS WORK!

/* SIGNALS >> Notifications sent to a process in order to notify it of various "important" events.
   By their nature, they interrupt whatever the process is doing at this minute, and force it to 
   handle them immediately. 
   * All signals hava a simbolic name(kill -l) and a number(1, 2, 3..)
   * Signal handler - function that gets called when the process receives that signal.
   * Is called in "asynchronous mode". When the signal is sent to the process, the operating system
     stops the execution of the process,     and "forces" it to call the signal handler function.
     When that signal handler function returns, the process continues execution from wherever it 
     happened to be before the signal was received, as if this interruption never occurred.*/

/*
>>>1. Sending Signals Using The Keyboard - certain key presses are interpreted by the system as 
   requests to send signals to the process with which we are interacting:
	ctrl + c : INT signal (SIGINT) : causes the process to immediately terminate.
	ctrl + z : TSTP signal (SIGTSTP) : causes the process to suspend execution.
	ctrl + \ : ABRT signal (SIGABRT) : causes the process to immediately terminate.
*/

//IN THIS PROGRAM THE ONLY WAY TO STOP ITS EXECUTION IS SENDING A SIGINT
/*
#include <stdio.h>
#include <unistd.h>
int	main()
{
	while(1)
	{
		printf("infinite loop!\n");
   		sleep(1); //function sleep is define in unistd.h
		printf("press ctrl + c to send a signal and terminate the program\n");
   		sleep(1);
	}
}
*/

/*
>>>2. Sending Signals From The Command Line
	kill : two parameters: a signal name (or number), and a process ID
		Syntax: kill -<signal> <PID>
*/
//IN THIS PROGRAM WE STOP ITS EXECUTION BY SENDING A SIGINT FROM ANOTHER TERMINAL
/*
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int     main()
{
	//pid_t is variable type defined in sys/types.h
	//function getpid() is defined in unistd.h
	pid_t my_pid = getpid(); //find my own process id
        while(1)
        {
                printf("infinite loop!\n");
                sleep(1);
		printf("my_pid is %d\n", my_pid);
		sleep(1);
                printf("Type: 'kill -INT my_pid in another terminal!\n");
                sleep(1);
        }
}
*/

/*
>>>3. Signal Handlers
	Most signals may be caught by the process. There are some functiona able to handle signals.
	The runtime environment sets up a set of default signal handlers for your program.
	Examples:
		The default signal handler for the TERM signal calls the exit() system call.
		The default handler for the ABRT signal calls the abort() system call.
*/
//IN THIS PROGRAM WE SEND THE ABRT SIGNAL WITH abot() function
/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int     main()
{
	int	x;
	printf("Type a number: \n");
        scanf("%d", &x);
	while (x != 10)
	{
		printf("to abort type 10\n");
	        scanf("%d", &x);
		if (x == 10)
        	{
			printf("You killed me! Bye\n");
			abort();
		}
	}
}
*/
/*
>>>4. Installing Signal handlers 
	4.1. signal():	set a signal handler for a single signal type.
			accepts a signal number and a pointer to a signal handler function	*/

//IN THIS PROGRAM WE HANDLE THE SIGINT WITH A FUNCTION THAT PRINTS A MESSAGE IF ctrl + c IS PRESSED
/*
#include <stdio.h>     // standard I/O functions                         
#include <unistd.h>    // standard unix functions, like getpid()         
#include <signal.h>    // signal name macros, and the signal() prototype 

void sig_handler_func(int signum) //RETURN TYPE OF A HANDLER FUNCTION HAS TO BE VOID
{
	(void)signum;
	printf("\nInside handler function\n");
	//uncoment the line below to handle the SIGINT signal as default(^c work again!) 
	//signal(SIGINT, SIG_DFL);	
}

int main()
{
	//set the SIGINT to be handled by 'sig_handle_func'
	signal(SIGINT, sig_handler_func);  
	while (1)
	{
		printf("Inside main function\n");
   		sleep(1);  // Delay for 1 second
	}		
}
*/		
/*
	4.2 sigaction() - allows the calling process to examine and/or specify the action to be
	associated with a specific signal.
	sigaction(sig, act, oact) means “set the disposition for sig to act, and store the old 
	disposition in oact”. Return value is 0 or -1, indicating whether the system call errored.
	struct sigaction
	{
		union __sigaction_u __sigaction_u; - Pointer to a signal-catching function or one of 							  the macros SIG_IGN or SIG_DFL. 
		sigset_t sa_mask; - Set of signals to be blocked during execution of the signal 
                         handling function.
		int     sa_flags; - Special flags.
		void(*) (int, siginfo_t*, void *)) sa_sigaction-Pointer to signal-catching function 
	};
	*mask for 'sig' is a set of signal numbers that expresses which signals the process can 
	receive while it is handling signal number 'sig'. 
	sa_handler specifies the action to be associated with signum and is  be
	one of the following:
	       * SIG_DFL for the default action.
	       * SIG_IGN to ignore this signal.
	       * A  pointer to a signal handling function.  This function receives the
        	 signal number as its only argument.

*/
/*
//IN THIS PROGRAM WE HANDLE SIGINT SIGNAL WITH THE STRUCT SIGACTION
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	my_handler(int signum)
{
	if(signum == SIGINT)
	{
		printf("\nInside handler function. ctrl + c is pressed\n");
		sleep(1); 
		printf("SIGINT is ignored! Use another signal!\n");
		sleep(1);
	}
}
int	main (void)
{
	struct	sigaction sa; //creates sa >> a variable of struct sigaction type
	sa.sa_handler = my_handler; //declares wich handler is used

	while(1)
	{
		printf("Infinite loop!. Process %d\n", getpid());
		sleep(1);
		sigaction(SIGINT, &sa, NULL);
	
	}
	return (0);
}
*/

//IN THIS PROGRAM WE HANDLE SIGUSR1 SIGNAL WITH THE STRUCT SIGACTION
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signalNum)
{
	if (signalNum == SIGUSR1)
	{
		printf("Caught SIGUSR1 signal.\n");
	}
}
 
 
int main(void) {
	signal(SIGUSR1, signalHandler);
	kill(getpid(), SIGUSR1); //send SIGUSR1 using kill()
//	raise(SIGUSR1);  //send SIGUSR1 using raise()
	return 0;
}




