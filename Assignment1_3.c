//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name and mode from user and that program check
//          whether our process can access that file in accpeted  mode or not.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to check that file is accessible in given mode or not
//          Input         :     1.File Name Which we have to open.
//                              2.File mode in which we have open file.
//          Output        :     Gives that file is accessible or not.
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
        printf("Usage : Used to check that file is accessible in given mode or not.\n");
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


    fd = access(argv[1],Mode);

    if(fd == -1)
    {
        printf("Unable to access the file.\n");
        return -1;
    }
    else
    {
        printf("File is accessible in this mode.\n");
    }

    close(fd);

    return 0;
}
