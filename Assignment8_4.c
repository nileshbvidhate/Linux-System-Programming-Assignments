//////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          Write a program in which create two different processes as process2 and process3
//          and our parent process terminates till both the process terminates.
//
/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to create multiple child processes internally.
//          Output        :     Creates multiple child process.
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
    int iRet1 = 0;
    int iRet2 = 0;
    int iRet3 = 0;
    

    
    printf("--------------------------------------------------------\n");
    printf("Creating new process.\n");
    printf("--------------------------------------------------------\n");
    
    iRet1 = fork();
    if(iRet1 == 0)
    {
        printf("Child Process1 is created Successfully and creating child process2.\n");

        iRet2 = fork();
        if(iRet2 == 0)
        {
            printf("Child Process2 is created Successfully and runnig.\n");
            execl("./ChildProcess2","NULL",NULL);
        }
        else
        {
            printf("Parent Process of ChildProcess2 is running.\n"); 
        }

        printf("--------------------------------------------------------\n");
        
        iRet3 = fork();
        if(iRet3 == 0)
        {
            printf("Child Process3 is created Successfully and process is running.\n");
            execl("./ChildProcess3","NULL",NULL);
        }   
        else
        {
            printf("Parent Process of ChildProcess3 is running.\n"); 
    
        }

        printf("--------------------------------------------------------\n");

        execl("./ChildProcess1","NULL",NULL);

        printf("--------------------------------------------------------\n");

    }
    else
    {
        printf("Parent Process of ChildProcess1 is running.\n");       
    }    

    printf("--------------------------------------------------------\n");
    return 0;
}


