/*
L E A R N I N G
Suppose you are passing pointer to an array to a function and you want to increment the value of pointer
in the function then following will not work

void increment(int *ptr)
{
    *ptr++;     // W R O N G- Such code will not increment the value.
    
    //C O R R E C T part - *ptr = *ptr+1;
}
void main(void)
{
    int arr[] ={0};
    int k=0;
    increment(*arr[k]);
}
*/





#include <stdio.h>

int a[4][6] = {{1,1,1,0,0,0},
               {1,1,1,0,0,0},
               {0,0,0,1,0,0},
               {0,0,0,0,1,1}};

void changeislandtowater(int *arr, int r, int c, int *ar)
{
    if(r<0 || r>=4 || c<0 ||c>=6 || a[r][c]==0)
    {
        return;
    }
    *ar = *ar+1;
    *((arr + r*6)+c)= 0;

    changeislandtowater(arr, r-1, c,ar);
    changeislandtowater(arr, r+1, c,ar);
    changeislandtowater(arr, r, c-1,ar);
    changeislandtowater(arr, r, c+1,ar);
}
void main(void)
{
    int cnt=0;
    int area[10]={0};
    int k=0;

    for(int i=0;i<4;i++)
        for(int j=0;j<6;j++)
        {
            if(a[i][j]==1)
            {
                cnt++;
                changeislandtowater((int *)a,i,j,&area[k]);
                k++;
            }
        }
    printf("%d", cnt);
    printf("\n%d %d %d", area[0], area[1], area[2]);
}