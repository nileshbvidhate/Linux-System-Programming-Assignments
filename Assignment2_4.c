////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name from user and print all file names and its types from that directory.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to print file names inside the directory and file types.
//          Input         :     Directory Name.
//          Output        :     Prints the file names and file types.
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
    DIR *dptr = NULL;
    struct dirent *entry = NULL;
    char fpath[100];
    struct stat Obj;
    int iRet = 0;

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to print file names inside the directory and file types.\n");
        printf("Command Line arguments : Executable_Name\t Directory_Name\n");
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
        printf("---------------------------------------------------\n");
        printf("File Names from the directory are :\n");
        printf("---------------------------------------------------\n");

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
                    printf("%s\t Regular File\n",entry->d_name);
                }
                else if(S_ISDIR(Obj.st_mode))
                {
                    printf("%s\t Directory File.\n",entry->d_name);
                }
                else if(S_ISLNK(Obj.st_mode))
                {
                    printf("%s\t Symbolic Link file",entry->d_name);
                }
            }

        }
        printf("\n");
        printf("---------------------------------------------------\n");
    }

    return 0;
}





















