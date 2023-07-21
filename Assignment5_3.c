////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name from user and write information of all Regular
//          file and read the contents from that file.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to write the file information and contents of file.
//          Input         :     Directory Name.
//          Output        :     Writes file information and the data of the given file.
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
    char Buffer[1024];

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to write the file information and contents of file.\n");
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
                    printf("--------------------------------------------------\n");
                    printf("Information about file is :\n");
                    printf("--------------------------------------------------\n");

                    printf("File Name    : %s\n",entry->d_name);
                    printf("File Size    : %ld bytes\n",Obj.st_size);
                    printf("Inode Number : %ld\n",Obj.st_ino);
                    printf("Link Count   : %ld\n",Obj.st_nlink);
                    printf("Block Count  : %ld\n",Obj.st_blocks);
                    printf("Block size   : %ld bytes\n",Obj.st_blksize);
                    printf("Device ID    : %ld\n",Obj.st_dev);
                    printf("User ID      : %d\n",Obj.st_uid);
                    printf("Group ID     : %d\n",Obj.st_gid);

                    printf("--------------------------------------------------\n");
                    printf("Data from the file %s is :\n",entry->d_name);

                    fd = open(fpath,O_RDONLY);
                    if(fd == -1)
                    {
                        printf("Unable to open the file.\n");
                        return -1;
                    }

                    iRet = read(fd,Buffer,1024);
                    write(1,Buffer,iRet);
                    close(fd);
                    printf("\n");
                    printf("--------------------------------------------------\n");
                    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

                }

            }

        }


    }

    return 0;
}





















