//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name from user and print all information about that file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to get the information of file.
//          Input         :     1.File Name Which we have to open.
//          Output        :     Gives file information.
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
    struct stat Obj;

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage :Used to get the information of file..\n");
        printf("Command Line arguments : Executable_Name\t File_Name\n");
        return -1;
    }


    iRet = stat(argv[1],&Obj);

    if(iRet == -1)
    {
        printf("Unable to execute stat() system call.\n");
        return -1;
    }
    else
    {
        printf("--------------------------------------------------\n");
        printf("Information about file is :\n");
        printf("--------------------------------------------------\n");

        printf("File Name    : %s\n",argv[1]);
        printf("File Size    : %ld bytes\n",Obj.st_size);
        printf("Inode Number : %ld\n",Obj.st_ino);
        printf("Link Count   : %ld\n",Obj.st_nlink);
        printf("Block Count  : %ld\n",Obj.st_blocks);
        printf("Block size   : %ld bytes\n",Obj.st_blksize);
        printf("Device ID    : %ld\n",Obj.st_dev);
        printf("User ID      : %d\n",Obj.st_uid);
        printf("Group ID     : %d\n",Obj.st_gid);

        printf("--------------------------------------------------\n");

    }


    return 0;
}


























