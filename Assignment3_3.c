////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory names from user and move all files from source directory to destination directory.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to move the all files of directory to the another directory.
//          Input         :     1.Source Directory Name.
//                        :     2.Destination Directory Name.
//          Output        :     Gets the all files in another directory.
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
#include<string.h>

int main(int argc, char * argv[])
{
    DIR *dptr = NULL;
    struct dirent *entry = NULL;
    char SourcePath[100];
    char DestPath[100];
    struct stat Obj;
    int iRet = 0;


    if(argc != 3)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to move the all files of directory to the another directory.\n");
        printf("Command Line arguments : Executable_Name \t Source_Directory_Name \t Destination_Directory_Name\n");
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
            sprintf(SourcePath,"%s/%s",argv[1],entry->d_name);
            sprintf(DestPath,"%s/%s",argv[2],entry->d_name);
            iRet = stat(SourcePath,&Obj);

            if(iRet == -1)
            {
                printf("stat() system call is not executed.\n");
                return -1;
            }
            else
            {
                if(S_ISREG(Obj.st_mode))
                {
                      rename(SourcePath,DestPath);
                }

            }

        }
        printf("Files are moved to the Directory : %s\n ",argv[2]);

    }

    return 0;

}





















