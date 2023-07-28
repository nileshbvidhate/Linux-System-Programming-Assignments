////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept directory name from user 
//          and create hole in file if size is less than 1Kb and
//          if is greater than 1Kb then truncate the remainig data.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to create hole or truncate the data.
//          Input         :     Directory name
//          Output        :     Creates hole or truncates data from the file.
//          Date          :     28/07/2023
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
    char Buffer[7] = "Nilesh";
    int fd = 0;
    int i = 0;


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
                if(Obj.st_size < 1024)
                {
                    fd = open(fName,O_RDWR);
                    if(fd == -1)
                    {
                        printf("Unable to open file :%s \n",fName);
                    }

                    iRet = lseek(fd,1024,SEEK_END);
                    write(fd,Buffer,6);
                    
                    if(iRet == (Obj.st_size + 1024))
                    {
                        printf("Hole is created successfully in  : %s.\n",fName);
                    }
                    i++;
                }
                else if(Obj.st_size > 1024)
                {
                    truncate(fName,1024);
                    printf("Data is truncated from : %s\n",fName);
                    i++;
                }
                
            }   
        }
        if(i == 0)
        {
            printf("There is no file for create hole and truncate the data.\n");
        }
    }
    
    closedir(dptr);

    return 0;
}

    
    
    
    
    



