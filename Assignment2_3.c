////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name from user and print all file names from that directory.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to print file names inside the directory.
//          Input         :     Directory Name.
//          Output        :     Print the files inside the Directory
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char * argv[])
{
    DIR *dptr = NULL;
    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Insufficient Arguments...\n");
        printf("Usage : Used to print name of files inside the directory.\n");
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
        printf("---------------------------------------------------\n");
        printf("File Names from the directory are :\n");
        printf("---------------------------------------------------\n");

        while((entry = readdir(dptr)) != NULL)
        {
            printf("%s\n",entry->d_name);
        }
        printf("\n");
        printf("---------------------------------------------------\n");
    }

    return 0;
}





















