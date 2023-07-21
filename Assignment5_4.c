////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name from user and combine all contents
//          of files from that directory into one file named as all combine.txt
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to combine all data of the files from directory into one file.
//          Input         :     Directory Name.
//          Output        :     combine all files data into one file.
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
    int fd = 0;
    int cfd = 0;
    char Buffer[1024];

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage :  Used to combine all data of the files from directory into one file.\n");
        printf("Command Line arguments : Executable_Name\t Directory_Name\n");
        return -1;
    }

    cfd = creat("Combined.txt",0777);
    if(cfd == -1)
    {
        printf("Unable to create Combined.txt\n");
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


                    fd = open(fpath,O_RDONLY);
                    if(fd == -1)
                    {
                        printf("Unable to open the file.\n");
                        return -1;
                    }


                    while((iRet = read(fd,Buffer,1024)) != 0)
                    {
                        write(cfd,Buffer,iRet);
                    }

                    close(fd);

                }

            }

        }
        printf("Data is combined Successfully\n");

    }


    close(cfd);

    return 0;
}






















