/*
Prototype: int signal () (int signum, void (*func)(int))
	+ The signal() will call the func function if the process receives a signal signum.
	+ The signal() returns a pointer to function func if successful or it returns an error to errno and -1 otherwise.
	+ The func pointer can have three values:
		SIG_DFL: Default
		SIG_IGN: Ignore
		User defined handler function pointer: return type is void and one argument of 
						       type int >>  void(*)(int)
Sending Signals:
A process also can explicitly send signals to itself or to another process. 
raise() and kill() function can be used for sending signals.
Both functions are declared in signal.h header file.
int raise(int signum)
        sending signal signum to the calling process.
        (returns zero if successful and a nonzero value if it fails.)
int kill(pid_t pid, int signum)
        Used for send a signal signum to a process or process group specified by pid.

*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig_handler(int signum){

  //Return type of the handler function should be void
  printf("\nInside handler function\n");
  //uncoment the line below to handle the SIGINT signal as default(^c work again!) 
  //signal(SIGINT, SIG_DFL);
}

int main(){
  signal(SIGINT,sig_handler); // Register signal handler
  for(int i=1;;i++){    //Infinite loop
    printf("%d : Inside main function\n",i);
    sleep(1);  // Delay for 1 second
  }
  return 0;
}

