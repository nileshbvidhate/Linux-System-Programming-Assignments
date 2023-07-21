//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name from user and read whole file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to read whole file.
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
    int iSize = 0;


    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage :Used to read whole file.\n");
        printf("Command Line arguments : Executable_Name\tFile_Name\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the given file.\n");
        return -1;
    }
    else
    {
        while((iRet = read(fd,Buffer,BLOCKSIZE)) != 0)
        {
                iRet = write(1,Buffer,iRet);
                iSize = iRet + iSize;
        }
        printf("\n");
        printf("%d bytes of data is read successfully.\n",iSize);

    }
    close(fd);

    return 0;
}


























