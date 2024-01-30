#include <stdio.h>
#include <stdlib.h>

int **arr;
int r = 3, c = 4;

void display_arr(void)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void main(void)
{
    arr = (int **)calloc(0, r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)calloc(0, c * sizeof(int));
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || j == 0)
                    arr[i][j] = 1;
            else
                arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }
    display_arr();
}