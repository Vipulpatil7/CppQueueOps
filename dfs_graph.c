#include <stdio.h>
int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
int visited[7] ={0};

void dfs(int i)
{
    visited[i] = 1;
    printf("%d ", i);

    for(int j=0; j<7; j++)
    {
        if(a[i][j]==1 && visited[j]!=1)
        {
            dfs(j);
        }
    }
    
}
void main(void)
{
    dfs(5);
}