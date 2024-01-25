#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isqueuefull(struct queue *q)
{
    if((q->r >= q->size) && q->f<0)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int val)
{
    if(isqueuefull(q))
    {
        printf("Full\n");
    }
    else{
        if(q->r < q->size)
            q->r++;
        else if(q->f >0)
            q->r = 0;
        q->arr[q->r] = val;
        printf("q->r= %d\n",q->r);
    }    
}
int isqueueempty(struct queue *q)
{
    if(q->r==q->f)
        return 1;
    else
        return 0;
}

int dequeue(struct queue *q)
{
    int a=-1;
    if(isqueueempty(q))
    {
        printf("Empty\n");
    }
    else
    {
        if(q->f < q->size)
            q->f++;
        else
            q->f = 0;
       a = q->arr[q->f];
        printf("q->r= %d\n",q->f);
    }   
    return a; 
}
void main(void)
{
    int inpt, val;
     struct queue q;
    q.size=5;
    q.arr = (int*)malloc(q.size*sizeof(int));
    q.f=-1;
    q.r=-1;

    for(int i=0; i<5; i++)
        enqueue(&q,i);

    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n");
        scanf("%d",&inpt);

        if(inpt == 1)
        {
            printf("Enter Value= ");
            scanf("%d",&val);
            enqueue(&q,val);
        }
        else if(inpt ==2)
        {
            val =dequeue(&q);
            printf("Value= %d",val);
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
}