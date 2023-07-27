////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name and file name from user
//          and create file in that directory.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to create a file in given directory.  
//          Output        :     Creates the file in given directory.
//          Date          :     27/07/2023
//
//
//
////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>


int main(int argc, char *argv[])
{
    DIR *dptr = NULL;
    char Fname[50];

    int fd = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments.\n");
        printf("Usage : Executable_name\t Directory_Name \t File_Name\n");
        return -1;
    }

    dptr = opendir(argv[1]);

    if(dptr == NULL)
    {
        printf("Unable to open the directory file.\n");
        return -1;
    }
    else
    {
        sprintf(Fname,"%s/%s",argv[1],argv[2]);
        
        fd = creat(Fname,0777);
        if(fd == -1)
        {
            printf("Unable to create the file.\n");
        }
        else
        {
            printf("File is created successfully in the %s Directory.\n",argv[1]);
        }

        close(fd);
    }
    
    closedir(dptr);

    return 0;
}

    
    
    
    
    



