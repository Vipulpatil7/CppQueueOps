/*Init Single and Double Link List from external value*/

#include <stdio.h>
#include <stdlib.h>

struct slist {
    int dat;
    struct slist *next;
};

struct dlist {
    int dat;
    struct dlist *prev;
    struct dlist *next;
};
struct slist *shead = NULL;
struct slist *sstar_head = NULL;

struct dlist *dhead = NULL;
struct dlist *current = NULL;

struct slist * insert_slist(struct slist *node, int val)
{
    struct slist *ptr= (struct slist *) malloc(sizeof(struct slist));

    ptr->dat=val;
    ptr->next=NULL;
    if(shead == NULL)
    {
        node= ptr;
        sstar_head=ptr;
    }
    else
    {
        node->next=ptr;
        node =ptr;
    }    
    return node;
}

struct dlist *  insert_dlist(struct dlist *node, int val)
{
    struct dlist *ptr =(struct dlist *)malloc(sizeof(struct dlist));
    ptr->dat= val;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(current==NULL)
    {
        dhead = ptr;
        current = ptr;
    }
    else
    {
        ptr->prev=current;
        current->next=ptr;
        current =ptr;
    }
    return current;
}

void main(void)
{
    for(int i=0; i<5; i++)
    {
        shead = insert_slist(shead,i);
    }
    printf("\nSingle Forward- ");
    shead= sstar_head;
    while(shead != NULL)
    {
        printf("%d ",shead->dat);
        shead= shead->next;
    }

    for(int i=0; i<5; i++)
    {
        current = insert_dlist(current,i);
    }
    printf("\nDouble Forward- ");
    while(dhead != NULL)
    {
        printf("%d ",dhead->dat);
        dhead= dhead->next;
    }

    printf("\nDouble Reverse- ");
    while(current != NULL)
    {
        printf("%d ",current->dat);
        current= current->prev;
    }

}