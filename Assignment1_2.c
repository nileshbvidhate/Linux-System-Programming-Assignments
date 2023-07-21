//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name and mode from user and open that file in specified mode.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to open the any file in specified mode according to user.
//          Input         :     1.File Name Which we have to open.
//                              2.File mode in which we have open file.
//          Output        :     Open the Given file in given mode
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to open the file in specific mode according to user wish.\n");
        printf("Command Line arguments : Executable_Name\t File_Name \t mode_of_file\n");
        return -1;
    }


    if(strcmp(argv[2],"Read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        Mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"ReadWrite") == 0)
    {
        Mode = O_RDWR;
    }
    else
    {
        printf("Give the proper mode.\n");
        return -1;
    }


    fd = open(argv[1],Mode);

    if(fd == -1)
    {
        printf("Unable to open the file.\n");
        return -1;
    }
    else
    {
        printf("File is opend successfully with file descriptor : %d .\n",fd);
    }
    close(fd);

    return 0;
}
