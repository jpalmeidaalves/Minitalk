/* 
In this program a signal is sent form a child process to a parent process.
pause() is used to make parent proccess to wait until a process is received.
The user is prompted to choose what signal to send

*/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<signal.h>



/*Handler function for SIGUSR1 and SIGUSR2 */
void sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		printf("PARENT : Received SIGUSR1 from child \n");
		sleep(1);
	}
	else
	{
		printf("PARENT : Received SIGUSR2 from child \n");
		sleep(1);
	}	
}

int main()
{
	pid_t	pid;
	pid = fork();
	
	/* Child Process */
  	if (pid == 0)
	{	
		int	msg;
		printf("CHILD: sending signal to PARENT\n");
		sleep(1);	//sleep 1 second to wait the parent process to print 
		printf("Type 1 to send SIGUSR1 or 2 to send SIGUSR2: ");
		scanf("%d", &msg);
		if (msg == 1)
			kill(getppid(), SIGUSR1);
		else
			kill(getppid(), SIGUSR2);

	}
	
	/* Parent Process */
	else
	{
		struct sigaction	act;
		act.sa_handler = &sig_handler;
		sleep(1);	//sleep 1 second to wait the child processe to print first
		printf("PARENT: waiting for signal\n");
		sigaction(SIGUSR1, &act, NULL); // Register(install) signal handler for SIGUSR1
		sigaction(SIGUSR2, &act, NULL); // Register(install) signal handler for SIGUSR2
		pause();
	}
	return 0;
}
