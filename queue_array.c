#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
    int cnt;
};

int isqueuefull(struct queue *q)
{
    if(q->cnt==0)
        return 1;
    else 
        return 0;
}

int isqueueempty(struct queue *q)
{
    if(q->cnt==5)
    {
        q->r = -1;
        q->f = -1;
        return 1;
    }
    else
        return 0;
}

void enqueue(struct queue *q, int val)
{
    if(q->r < q->size-1)
        q->r++;
    else if(q->f >=0)
        q->r = 0;

    q->arr[q->r] = val;
    q->cnt--;  
}

int dequeue(struct queue *q)
{
    int a=-1;

    if(q->f <= q->size-1)
        q->f++;
    else
        q->f = 0;

    a = q->arr[q->f];
    q->arr[q->f] =-1;
    q->cnt++;
    isqueueempty(q); 
    return a; 
}

void displayqueue(struct queue q)
{
    printf("Queue- ");
    for(int i=0; i<q.size; i++)
        printf("%d ", q.arr[i]);  

    printf("\nRare Index-  %d\n",q.r);
    printf("Front Index- %d\n",q.f);     
}

void main(void)
{
    int inpt, val;
     struct queue q;
    q.size=5;
    q.arr = (int*)malloc(q.size*sizeof(int));
    q.f=-1;
    q.r=-1;
    q.cnt=5;

    for(int i=0; i<5; i++)
        enqueue(&q,i+1);

    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\nChoice-");
        scanf("%d",&inpt);

        if(inpt == 1)
        {
            if(isqueuefull(&q))
            {
                printf("Full\n\n");
            }
            else
            {
                printf("Enter Value= ");
                scanf("%d",&val);
                enqueue(&q,val);
            }
        }
        else if(inpt ==2)
        {
            if(isqueueempty(&q))
            {
                printf("Empty\n\n");
            }
            else 
            {
                val =dequeue(&q);
                printf("Value= %d\n\n",val);
            }
        }
        else if(inpt ==3)
        {
            displayqueue(q);
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
}