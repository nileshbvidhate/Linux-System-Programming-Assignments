////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name from user and Delete all empty files from that directory.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to Delete the empty files from directory.
//          Input         :     Directory Name.
//          Output        :     Deletes the empty files from directory.
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
    char fpath[100];
    struct stat Obj;
    int iRet = 0;
    int iMaxSize = 0;
    char fName[20];

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to Delete the empty files from directory.\n");
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
                    if(Obj.st_size == 0)
                    {
                        printf("%s\n",entry->d_name);
                        remove(fpath);
                    }
                }

            }

        }
        printf("These files are deleted from the directory.\n");
    }

    return 0;
}





















