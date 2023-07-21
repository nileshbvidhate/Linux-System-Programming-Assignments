////////////////////////////////////////////////////////////////////////////////////////
//Problem Statement :
//          write a Program which is used to demonstrate the concept of I/O redirection.
//
////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
//
//
//          Author        :     Nilesh Vidhate
//          Application   :     Input Output Redirection.
//          Input         :     Input File name.
//          Output        :     Output file name.
//          Date          :     21/07/2023
//
//
//
/////////////////////////////////////////////////////////////



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
    int Addition = 0;
    int Sub = 0;
    int Div = 0;
    int Mult = 0;

    int iNo1 = 0;
    int iNo2 = 0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    Addition = iNo1 + iNo2;
    Sub = iNo1 - iNo2;
    Div = iNo1/iNo2;
    Mult = iNo1 * iNo2;

    printf("Addition is : %d\n",Addition);
    printf("Subtraction is : %d\n",Sub);
    printf("Division is : %d\n",Div);
    printf("Multiplication is : %d\n",Mult);


    return 0;
}
// ./Myexe < Input.txt > Output.txt
