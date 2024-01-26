#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 5

struct node {
    int val;
    struct node *next;
};

struct node *findex = NULL;
struct node *rrindex = NULL;

bool isqueuefull(struct node *fnode)
{
    int cnt=0;
    while(fnode!=NULL)
    {
        fnode=fnode->next;
        cnt++;
    }
    printf("Queue cnt %d\n", cnt);
    if(cnt>=QUEUE_SIZE)
        return true;
    else
        return false;
}

bool isqueueempty(struct node *fnode)
{
    if(fnode==NULL)
        return true;
    else
        return false;
}

void displayqueue(struct node *fnode)
{
    printf("Queue Value= ");
    while(fnode !=NULL)
    {
        printf("%d ", fnode->val);
        fnode=fnode->next;
    }
}

struct node * enqueue(struct node *rnode, int val)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->val= val;
    newnode->next =NULL;
    if(findex==NULL)
    {
        rnode =newnode;
        findex=newnode;
        rrindex=newnode;
    }
    else 
    {
        rnode->next=newnode;
        rnode = newnode;
    }
    return rnode;
}

struct node * dequeue(struct node *fnode, int *val)
{
    struct node *tempnode;
    *val = fnode->val;
    tempnode = fnode;
    fnode = fnode->next;
    free(tempnode);
    return fnode;
}


void main(void)
{
    int input, val;

    while(1)
    {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Display Queue\nChoice- ");
        scanf("%d",&input);

        switch (input)
        {
            case 1:
                if(isqueuefull(findex))
                {
                    printf("Full\n");
                }
                else
                {
                    printf("Enter Value= ");
                    scanf("%d", &val);
                    rrindex = enqueue(rrindex, val);
                }
            break;

            case 2:
                if(isqueueempty(findex))
                {
                    printf("Empty\n");
                }
                else{
                    findex= dequeue(findex,&val);
                    printf("\nValue= %d\n",val);
                }
            break;

            case 3:
                displayqueue(findex);
            break;

            default:
                printf("Invalid Input\n");
        }
    }
}
