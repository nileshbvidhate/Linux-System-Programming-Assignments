////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which creates a hole of size 
//          1kb at the end of file.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to create a hole of 1kb at the end of file.  
//          Output        :     Creates the hole in given file.
//          Date          :     27/07/2023
//
//
//
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>



int main(int argc, char *argv[])
{

    int fd = 0;
    int FileSize = 0;
    int Hole = 1024;
    char Buffer[10] = "NileshVidh";

    if(argc != 2)
    {
        printf("Insufficient arguments.\n");
        printf("Usage : Executable_name\t File_Name\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open the given file.\n");
        return -1;
    }

    FileSize = lseek(fd,0,SEEK_END);

    Hole = lseek(fd,Hole,SEEK_END);

    printf("1kb of whole is created Successfully at the end of file.\n");

    write(fd,Buffer,sizeof(Buffer)); // writting in the file after creating the 1kb of buffer.
    
    close(fd);

    return 0;
}

    
    
    
    
    



