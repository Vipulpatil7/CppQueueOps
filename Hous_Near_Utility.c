#include <stdio.h>
#include<stdlib.h>

char inp[5][3] = {
    {0,1,0},
    {1,0,0},
    {1,1,0},
    {0,0,0},
    {0,0,1},
};
int **arr;
int row= sizeof(inp)/sizeof(inp[0]);
int col= sizeof(inp[0])/sizeof(inp[0][0]);

void main(void)
{
    /*printf("s= %d\n", sizeof(inp));
    printf("row= %d\n", row);
    printf("col= %d\n", col);*/

    arr = (int **)malloc(row * sizeof(int *));
    for(int r=0; r<5; r++)
    {
        arr[r] = (int*)calloc(0, col * sizeof(int));
    }    

    /*printf("\ninp= \n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d ", inp[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    int dist=0;
    int b=0;
    int tr=0;
    int result =0;
    for(int b=0; b<row; b++)
    {         
        tr=b-1;
        if(tr<0)
        {
            tr=row;
        }
        for(int j=0; j<col; j++)
        {
            dist=0;
            int i=b;
            do
            {
                if(inp[i][j]==1)
                {
                    arr[b][j] =dist+1;
                    break;
                }
                dist++;
                i++;
                if(i==row) 
                    i=0;
            }while(i!=tr+1);
        }
    }
    /*printf("Output-\n");
    for(int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/

    int act_res= arr[0][0] +arr[0][1]+arr[0][2];
    int block =0;
    for(int i =0; i<row; i++)
    {
        result = arr[i][0] +arr[i][1]+arr[i][2];
        if(result <act_res)
        {
            act_res=result;
            block =i;
        }
    }
    printf("Block= %d\n", block);

}