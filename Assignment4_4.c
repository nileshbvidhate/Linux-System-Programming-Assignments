////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept Directory name from user and copy first 10
//          bytes from all regular files into newly created file named as Demo.txt
////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to check contents of two files are same or not.
//          Input         :     Name of Directory.
//          Output        :     Get combined file .
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////




#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    int dfd = 0;
    DIR *dptr = NULL;
    struct dirent *entry = NULL;
    char fpath[100];
    char Buffer[1024];
    struct stat Obj;
    int iRet = 0;

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to check contents of two files are same or not.\n");
        printf("Command Line arguments : Executable_Name\t Directory_Name\n");
        return -1;
    }

    fd = creat("Demo.txt",0777);
    if(fd == -1)
    {
        printf("Demo.txt file is not created.\n");
        return -1;
    }


    dptr = opendir(argv[1]);

    if(dptr == NULL)
    {
        printf("Unable to open the directory.\n");
        return -1;
    }
    else
    {

        while((entry = readdir(dptr)) != NULL)
        {
            sprintf(fpath,"%s/%s",argv[1],entry->d_name);
            iRet = stat(fpath,&Obj);
            if(iRet == -1)
            {
                printf("stat() system call is not executed.\n");
                return -1;
            }
            else
            {
                if(S_ISREG(Obj.st_mode))
                {
                    dfd = open(fpath,O_RDONLY);
                    iRet = read(dfd,Buffer,10);
                    write(fd,Buffer,iRet);
                    close(dfd);
                }
            }

        }

    }
    close(fd);
    return 0;
}


















