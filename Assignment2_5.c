////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name from user and print name of such file having largest size.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to Search largest size file.
//          Input         :     Directory Name.
//          Output        :     Prints the largest file name and file size,
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
        printf("Usage : Used to Search largest size file.\n");
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
                    if(iMaxSize < Obj.st_size)
                    {
                        iMaxSize = Obj.st_size;
                        strcpy(fName,entry->d_name);

                    }
                }

            }

        }
        printf("Largest File name is : %s \t Size : %d\n ",fName,iMaxSize);
    }

    return 0;
}





















