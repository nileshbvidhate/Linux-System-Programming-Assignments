
///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to open the any file.
//          Input         :     File Name Which we have to open.
//          Output        :     Open the Given file.
//          Date          :     21st july 2023
//
//
//
/////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name from user and open that file.
//
////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to open the file according to user wish.\n");
        printf("Command Line arguments : Executable_Name\t File_Name\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open the file.\n");
        return -1;
    }
    else
    {
        printf("File is opend successfully in read and write mode with file descriptor : %d .\n",fd);
    }

    close(fd);
    return 0;
}
