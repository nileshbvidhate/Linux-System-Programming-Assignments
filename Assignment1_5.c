//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name and number of byets from user and read that number of bytes from file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to read specific number of byet from file.
//          Input         :     1.File Name Which we have to open.
//                        :     2.Number of bytes that we have to read.
//          Output        :     Reads the given number of bytes from the file.
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char * argv[])
{
    int fd = 0;
    int iRet = 0;
    char *Buffer = NULL;


    if(argc != 3)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage :Used to read specific number of byet from file.\n");
        printf("Command Line arguments : Executable_Name\t File_Name \t Number_of_bytes\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the given file.\n");
        return -1;
    }
    else
    {
        Buffer = (char *)malloc(sizeof(atoi(argv[2])));
        if(Buffer == NULL)
        {
            printf("Static memory is allocated for Buffer.\n");
            char Data[1024] = {'\0'};
            Buffer = Data;

        }
        else
        {
            printf("Dynamic memory is allocated for Buffer.\n");
            iRet = read(fd,Buffer,atoi(argv[2]));
            iRet = write(1,Buffer,iRet);
            printf("\n");
            if(iRet == -1)
            {
                printf("Unable to Write the data.\n");
            }
            else
            {
                printf("%d bytes of data is read successfully.\n",iRet);
            }

        }
    }

    close(fd);


    return 0;
}


























