////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which a Program which accept two file names from user and check whether contents of that two files are same or not.
//
////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to check contents of two files are same or not.
//          Input         :     1.Name of File 1
//                        :     2.Name of File 2
//          Output        :     States that files are same or not.
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////




#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient arguments.\n");
        printf("Usage   : Used to check contents of two files are same or not.\n");
        printf("Working : Executable_Name \t File1 \t File2\n ");
        return -1;
    }
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;
    struct stat obj1;
    struct stat obj2;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];


    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are diffrent as sizes are diffrent\n");
        return -1;
    }

    while((ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,ret) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("Files are same.\n");
    }
    else
    {
        printf("Files are different\n");
    }

    close(fd1);
    close(fd2);

    return 0;
}


















