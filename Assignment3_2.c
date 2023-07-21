////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name and file name from user and check whether that file is present or not.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to check given file is present or not in directory.
//          Input         :     1.Directory Name.
//                        :     2.File Name
//          Output        :     States that file is present or not in given directory.
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<stdbool.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char * argv[])
{
    DIR *dptr = NULL;
    struct dirent *entry = NULL;
    char fpath[100];
    struct stat Obj;
    int iRet = 0;
    bool bFlag = false;

    if(argc != 3)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to check given file is present or not in directory.\n");
        printf("Command Line arguments : Executable_Name\t Directory_Name \t File_Name\n");
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
                    if(strcmp(argv[2],entry->d_name) == 0)
                    {
                        bFlag = true;
                        break;
                    }
                }

            }

        }


        if(bFlag == true)
        {
            printf("File is present.\n");
        }
        else
        {
            printf("File is not present.\n");
        }
    }

    return 0;

}





















