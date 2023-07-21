//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name from user and write string in that file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to write string in that file.
//          Input         :     1.File Name Which we have to open.
//          Output        :     Read the whole file.
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char * argv[])
{
    int fd = 0;
    int iRet = 0;
    char Buffer[BLOCKSIZE];
    int iLength = 0;


    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage :Used to write string in file.\n");
        printf("Command Line arguments : Executable_Name\tFile_Name\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to open the given file.\n");
        return -1;
    }
    else
    {
        printf("Enter the string :\n");

        scanf(" %[^'\n']s",Buffer);

        iLength = strlen(Buffer);

        iRet = write(fd,Buffer,iLength);

        printf("%d bytes of data is written successfully.\n",iRet);


    }
    close(fd);

    return 0;
}


























