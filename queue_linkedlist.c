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
    bool ret = false;
    while(fnode!=NULL)
    {
        fnode=fnode->next;
        cnt++;
    }
    if(cnt>=QUEUE_SIZE)
    {
        printf("Queue is Full\n");
        ret= true;
    }
    return ret;
}

bool isqueueempty(struct node *fnode)
{
    bool ret = false;
    if(fnode==NULL)
    {
        printf("Queue is Empty\n");
        ret= true;
    }
    return ret;
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

void enqueue(struct node **rnode, int val)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->val= val;
    newnode->next =NULL;
    if(findex==NULL)
    {
        findex=newnode;
        *rnode=newnode;
    }
    else 
    {
        (*rnode)->next=newnode;
        *rnode = newnode;
    }
}

void dequeue(struct node **fnode, int *val)
{
    struct node *tempnode;
    *val = (*fnode)->val;
    tempnode = *fnode;
    *fnode = (*fnode)->next;
    free(tempnode);
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
                if(!isqueuefull(findex))
                {
                    printf("Enter Value= ");
                    scanf("%d", &val);
                    enqueue(&rrindex, val);
                }
            break;

            case 2:
                if(!isqueueempty(findex))
                {
                    dequeue(&findex,&val);
                    printf("\nValue= %d\n",val);
                }
            break;

            case 3:
                if(!isqueueempty(findex))
                    displayqueue(findex);
            break;

            default:
                printf("Invalid Input\n");
        }
    }
}
