#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>


int     main()
{
        int     pid = fork();
        if (pid == -1)
                return (-1);
        if (pid == 0)  //child process
        {
                while (1) //infinite loop
                {
                        printf("some output\n");
                        usleep(50000);
                }
        }
        else //parent process
        {
		kill(pid, SIGSTOP); //stops the parent process, that makes child aslo stops
		int	t;  //declare a variable to store the time
		do
		{
			
			printf("Time in seconds for execution: "); //ask user for a time
			scanf("%d", &t); //store it in 't'
			if (t > 0)
			{
				kill(pid, SIGCONT); //continue the process(also start the child process)
				sleep(t); //keep executing the process for 't' time
				kill(pid, SIGSTOP); //stop execution
			}
		} while (t > 0);		


                kill(pid, SIGKILL); //kill itself
                wait(NULL); //makes parent process wait for child process terminates first
        }

        return(0);
}

