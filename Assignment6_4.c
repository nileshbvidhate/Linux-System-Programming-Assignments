////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name from user 
//          and delete all such files whose size is greater than 100 bytes.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to delete the files whose size is greater than 100 bytes
//          Input         :     Directory name
//          Output        :     Delete the files.
//          Date          :     27/07/2023
//
//
//
////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    DIR *dptr = NULL;
    struct dirent *entry = NULL;
    struct stat Obj;
    int iRet = 0;
    char fName[30];


    if(argc != 2)
    {
        printf("Insufficient arguments.\n");
        printf("Usage : Executable_name\t Directory_Name\n");
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
        while((entry = readdir(dptr)) != NULL)
        {   
            sprintf(fName,"%s/%s",argv[1],entry->d_name);
            
            stat(fName,&Obj);

            if(S_ISREG(Obj.st_mode))
            {
                if(Obj.st_size > 100)
                {
                    iRet = remove(fName);
                    if(iRet == 0)
                    {
                        printf("%s is Deleted having size %ld.\n",entry->d_name,Obj.st_size);
                    }
                }
            }
        }
    }
    
    closedir(dptr);

    return 0;
}

    
    
    
    
    



