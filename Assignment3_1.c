////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept two file names from user and copy the contents of the existing file into the newly created file..
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to create the copy of source file.
//          Input         :     1.Source File Name.
//                        :     2.Destination File Name.
//          Output        :     Cretes the new file with the source file contents.
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;

    int iRet = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        printf("Usage : Executable_name  Source_file_name  Dest_file_name \n");
        return -1;
    }

    fdSource = open(argv[1],O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open source file.\n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("unable to create destination file.\n");
        return -1;
    }

    while((iRet = read(fdSource,Buffer,BLOCKSIZE)) != 0)
    {
        write(fdDest,Buffer,iRet);
    }

    close(fdSource);
    close(fdDest);

    printf("File is copied successfully.\n");

    exit(0);

}
