////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name which contains data of all file
//          we have to create all file again.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to create a new file from a file which
//                              has a data of new creation file.  
//          Output        :     Creates a new file with the data from anothe file.
//          Date          :     26/07/2023
//
//
//
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments.\n");
        printf("Usage : Executable_name\t File_Name\n");
        return -1;
    }

    int fdOpen = 0;
    int fdCreation = 0;

    char NFName[50] = {'\0'}; // new file name. which we have to create.
    int iRet = 0;
    int FNLength = 0;

    char Buf1[50] = {'\0'};
    char Buffer[BLOCKSIZE] = {'\0'};

    fdOpen = open(argv[1], O_RDONLY);
    if(fdOpen == -1)
    {
        printf("Unable to open file.\n");
        return -1;
    } 

    read(fdOpen,Buf1,50);

    iRet = sscanf(Buf1,"%s",NFName);


    FNLength = strlen(NFName);

    lseek(fdOpen,FNLength,SEEK_SET);

    printf("Creating the file : %s\n",NFName);

    fdCreation = creat(NFName,0777);
    if(fdCreation == -1)
    {
        printf("Unacle to create the file %s",NFName);
        return -1;
    }

    while((iRet = read(fdOpen,Buffer,BLOCKSIZE)) != 0)
    {
        write(fdCreation,Buffer,iRet);
    }
    
    printf("File is created succcessfully and data is written in that file.\n");

    return 0;
}

    
    
    
    
    



