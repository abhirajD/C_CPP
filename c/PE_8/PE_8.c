/*Display greatest product of consequtive digits from a file*/
//Author - Abhiraj


#include<stdio.h>
#define MAX 1000
#define STEP 5

int prod(int in_array[],int step);  //This will find the greatest product of consequtive 'n' integers. 'n' = STEP

int main()
{
    FILE *fp;                       //Pointer to File
    int a[MAX],final;               //'a' stores integers from file // 'final' stores value returned from function 'prod'
    int i;

    /*Initialization*/
    for(i=0; i<MAX ; i++)
    a[i] = 0;

    /*File Import*/
    fp = fopen("PE_8_input.txt", "r");    //Gets In_8.txt file

    for( i=0 ; i<MAX ; i++)
    a[i] = getc(fp) - 48;           //'getc(fp) - 48' Imports ASCII value of integer from fp and converts it to real integer value

    /*Function Calling*/
    final = prod (a, STEP);

    /*Printing Output*/
    printf("Greatest product=%d\n",final);
}


int prod( int a[], int step)
{
    /*Initialization*/
    int temp,great;
    int i,j;
    i=0;       j=0;
    temp=1;    great=0;

    for( i=0; i<(MAX-5) ; i++)
    {
        j = i;
        while(j < i+step)           //Multiplies every 'n' consequtive array elements. 'n'=STEP
        {
            temp = temp*a[j];
            j++;
        }

        if(temp > great)
            great=temp;

        temp=1;                     //Reset.
    }

    return great;
}


