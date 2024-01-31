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

bool isqueuefull(void)
{
    int cnt=0;
    bool ret = false;
    struct node *fnode = findex;
    while(fnode!=NULL)
    {
        fnode=fnode->next;
        cnt++;
    }
    if(cnt>=QUEUE_SIZE)
    {
        ret= true;
    }
    return ret;
}

bool isqueueempty(void)
{
    struct node *fnode = findex;
    bool ret = false;
    if(fnode==NULL)
    {
        ret= true;
    }
    return ret;
}

void displayqueue(void)
{
    struct node *fnode = findex;
    printf("Queue Value= ");
    while(fnode !=NULL)
    {
        printf("%d ", fnode->val);
        fnode=fnode->next;
    }
}

void enqueue(int val)
{
    struct node **rnode = &rrindex;
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

void dequeue(int *val)
{
    struct node **fnode = &findex;
    struct node *tempnode;
    *val = (*fnode)->val;
    tempnode = *fnode;
    *fnode = (*fnode)->next;
    free(tempnode);
}
void vlist(int *v)
{
    printf("\nvlist= ");
    for(int i=0;i<7; i++)
    {
        printf("%d", v[i]);
    }
    printf("\n");
}

void main(void)
{
    int nod;
    int i= 1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    printf("%d ", i);
    visited[i]= 1;
    enqueue(i);

    while(!isqueueempty())
    {
        int nod= 0;
        dequeue(&nod);

        for(int j=0;j<7; j++)
        {
            if(a[nod][j] == 1 && visited[j]==0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
