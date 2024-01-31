#include <stdio.h>

int a[4][6] = {{1,1,1,0,0,0},
               {1,1,1,0,0,0},
               {0,0,0,1,0,0},
               {0,0,0,0,1,1}};

void changeislandtowater(int *arr, int r, int c)
{
    if(r<0 || r>=4 || c<0 ||c>=6 || a[r][c]==0)
        return;
    
    *((arr + r*6)+c)= 0;

    changeislandtowater(arr, r-1, c);
    changeislandtowater(arr, r+1, c);
    changeislandtowater(arr, r, c-1);
    changeislandtowater(arr, r, c+1);
}
void main(void)
{
    int cnt=0;

    for(int i=0;i<4;i++)
        for(int j=0;j<6;j++)
        {
            if(a[i][j]==1)
            {
                cnt++;
                changeislandtowater((int *)a,i,j);
            }
        }
    printf("%d", cnt);
}