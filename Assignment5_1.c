////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which writes structure in file. Structure should contain
//          information of studen.
//
////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Used to write the structure in file.
//          Input         :     File Name
//          Output        :     Writes the structure in file.
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

    sobj.rollno = 11;
    sobj.marks = 91.0f;
    sobj.age = 22;
    strcpy(sobj.sname,"Nilesh");

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = creat(Fname,0777);

    iRet =  write(fd,&sobj,sizeof(sobj));

    if(iRet == 0);
    {
        printf("structure is written successfully.\n");
    }

    return 0;
}
