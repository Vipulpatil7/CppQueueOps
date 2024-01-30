/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.
Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: [] 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/

#include <stdio.h>
#include <stdlib.h>

int a[] ={4,3,2,7,8,2,3,8};

void disp(int *arr)
{
    for(int i=0; i<8; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main(void)
{
    int opt[8] ={0};
    disp(a);
    for(int i=0; i<8; i++)
    {
        int index= (abs(a[i])-1);
        if(a[index]<0)
            opt[index] = abs(a[index]);
        a[index] =-a[index];
    }
    disp(a);
    disp(opt);
}