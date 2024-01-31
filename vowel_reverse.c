/*
LEARNING 
You cannoth directly assign char to a character pointer. i.e you cannot do following
char *word;
char c = 'a';
word[i] =c; XXXXXXX

You need to make it a arr and the you can assigne the array to pointer.
char str[]="leetcode";
char *word =str;
char c = 'a';
word[i] = c [Correct]
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char str[]="leetcode";
char vlu[]={'a', 'e', 'i', 'o', 'u'};

bool check(char a)
{
    for(int i=0; i<5; i++)
    {
        if(a == vlu[i])
        {
            return true;
        }
    }
    return false;
}

void main(void)
{
    int i,j=0;
    char *word =str;
    int len = strlen(word);

    j=len;
    for(i=0; i<len; i++)
    {
        if(check(word[i]))
        {
            while(j>i)
            {
                j--;
                if(check(word[j]))
                {
                    char temp= word[i];
                    word[i]= word[j];
                    word[j]=temp;
                    break;
                }
            }
        }
    }
    printf("%s", word);
}