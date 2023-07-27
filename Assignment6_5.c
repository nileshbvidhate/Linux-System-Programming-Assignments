////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name and offset from user
//           and removes all the data from thar offset.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to delete data from file from the specific offset.
//          Input         :     File name
//          Output        :     Delete data from specific offset.
//          Date          :     27/07/2023
//
//
//
////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>



int main(int argc, char *argv[])
{
    int fd = 0;   
    int iRet = 0;
    
    if(argc != 3)
    {
        printf("Insufficient arguments.\n");
        printf("Usage : Executable_name\t File_Name \t offset\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open the file.\n");
        return -1;
    }
    else
    {
        iRet = ftruncate(fd,atoi(argv[2]));
        if(iRet == 0)
        {
            printf("Data is deleted successfully.\n");
        }
    }

    return 0;
}

    
    
    
    
    



