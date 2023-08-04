////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          Write a program in which parent process waits till
//          its child process terminates.
//
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to create process inside a process.
//          Input         :     No
//          Output        :     Creates new process inside the process.
//          Date          :     04/08/2023
//
//
//
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{   
    int iRet = 0;
    pid_t EXIT_STATUS;
    int Child_PID = 0;


    printf("Creating new process.\n");

    iRet = fork();

    if(iRet == 0)
    {
        printf("Child Process is created Successfullyand process is running.\n");
        
        execl("./ChildProcess","NULL",NULL);
    }
    else
    {
        printf("Parent Process is running.\n");   
    }

    Child_PID = wait(&EXIT_STATUS);

    printf("Child process is terminated having PID : %d\n",Child_PID);

    printf("Exit status of child process is : %d \n",EXIT_STATUS);
    
    return 0;
}


