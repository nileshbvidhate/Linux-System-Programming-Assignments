////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which a Program which accept directory name from user and create a new directory of that name.
//
////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to create the new directory.
//          Input         :     Directory name
//          Output        :     Directory is created with the given name.
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    int iRet = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments.\n");
        printf("Usage   : Used to create the new directory.\n");
        printf("Working : Executable_Name \t Directory_Name\n ");
        return -1;
    }

    iRet = mkdir(argv[1],0777);
    if(iRet == -1)
    {
        printf("Unable to create the Directory.\n");
    }
    else
    {
        printf("New Directory created with the name : %s\n",argv[1]);
    }


    return 0;
}


















