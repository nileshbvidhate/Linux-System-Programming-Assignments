////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which accept file name from user which contains information
//          of the student . we have to read all contents of that file.
//
////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to read the written structure from the file.
//          Input         :     File Name
//          Output        :     Reads the structure from file.
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////


#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)

struct Student
{
    int rollno;
    float marks;
    int age;
    char sname[20];
};

int main(int argc, char *argv[])
{
    int iRet = 0;
    int fd = 0;
    char Fname[20];
    struct Student sobj;


    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file.\n");
        return -1;
    }

    iRet = read(fd,&sobj,sizeof(sobj));
    if(iRet == -1)
    {
        printf("Unable to read the file.\n");
        return -1;
    }

    printf("Name : %s \n",sobj.sname);

    printf("age : %d \n",sobj.age);

    printf("Marks : %f \n",sobj.marks);

    printf("rollno : %d \n",sobj.rollno);


    return 0;
}
