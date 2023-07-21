////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name and position from user and read 20 bytes from that position.
//
////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to read specific bytes from specific point.
//          Input         :     File Name
//          Output        :     reads the specific content from specific point in the file.
//          Date          :     21st july 2023
//
//
//
/////////////////////////////////////////////////////////////


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    char Buffer[100];
    int iRet = 0;

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to read specific bytes from specific point.\n");
        printf("Command Line arguments : Executable_Name\t File_Name\n");
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
        printf("Data from the file is :\n");
        iRet = read(fd,Buffer,20);
        write(1,Buffer,iRet);
        printf("\n");

    }

    return 0;
}
