//////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          Write a program in which create three differnt processes internally
//          as process2 process3 and process4.
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
    int iRet4 = 0;

    pid_t EXIT_STATUS;

    int Child_PID1 = 0;
    int Child_PID2 = 0;
    int Child_PID3 = 0;
    int Child_PID4 = 0;

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
            Child_PID2 = wait(&EXIT_STATUS);
            printf("Child process is terminated having PID : %d\n",Child_PID2);
            printf("Exit status of child process is : %d \n",EXIT_STATUS);
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
            Child_PID3 = wait(&EXIT_STATUS);
            printf("Child process is terminated having PID : %d\n",Child_PID3);
            printf("Exit status of child process is : %d \n",EXIT_STATUS);
        }

        printf("--------------------------------------------------------\n");

        iRet4 = fork();
        if(iRet4 == 0)
        {
            printf("Child Process4 is created Successfully and process is running.\n");
            execl("./ChildProcess4","NULL",NULL);
        }   
        else
        {
            printf("Parent Process of ChildProcess4 is running.\n"); 
            Child_PID4 = wait(&EXIT_STATUS);
            printf("Child process is terminated having PID : %d\n",Child_PID4);
            printf("Exit status of child process is : %d \n",EXIT_STATUS);
        }

        printf("--------------------------------------------------------\n");

        execl("./ChildProcess1","NULL",NULL);
    }
    else
    {
        printf("Parent Process of ChildProcess1 is running.\n"); 
        Child_PID1 = wait(&EXIT_STATUS);
        printf("Child process is terminated having PID : %d\n",Child_PID1);
        printf("Exit status of child process is : %d \n",EXIT_STATUS);
      
    }    

    printf("--------------------------------------------------------\n");
    return 0;
}


