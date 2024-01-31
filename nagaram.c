#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[]= "nagaram";
char r[]= "angrama";

void main(void)
{
    int cnt=0, len= strlen(s);
    if(len != strlen(r))
    {
        printf("False\n");
        exit(0);
    }

    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(s[i]==r[j])
            {
                cnt++;
                r[j] ='\0';
                break;
            }
        }
    }
    if(cnt==strlen(s))
        printf("true");
    else
        printf("false");
}