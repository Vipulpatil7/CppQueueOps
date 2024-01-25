/*Init Single and Double Link List from external value*/

#include <stdio.h>
#include <stdlib.h>

struct dlist {
    int dat;
    int id;
    struct dlist *prev;
    struct dlist *next;
};

struct dlist *dhead = NULL;
struct dlist *current = NULL;
struct dlist *start = NULL;
struct dlist *end = NULL;


struct dlist *  insert_dlist(struct dlist *node, int val, int key)
{
    struct dlist *ptr =(struct dlist *)malloc(sizeof(struct dlist));
    ptr->dat= val;
    ptr->id= key;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(current==NULL)
    {
        dhead = ptr;
        start = dhead;
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

void init_cache(void)
{
    for(int i=0; i<5; i++)
    {
        current = insert_dlist(current,i,i);
    }
    end= current;
}

void tarverse_cache(struct dlist *node, int dir)
{
    printf("\nid \tval\n");
    while(node != NULL)
    {
        printf("%d \t%d\n",node->id, node->dat);
        if(dir==1)
            node= node->next;
        else
            node= node->prev;
    }
}

struct dlist * find_id(struct dlist *node, int key)
{
    while(node != NULL)
    {
        if(node->id == key)
            break;
        else         
            node= node->next;
    }
    return node;
}

void interchange_node(struct dlist *node, struct dlist *last)
{
    struct dlist *ptr=NULL;
    if(node->prev == NULL)
    {
        ptr = node->next;
        ptr->prev = node->prev;
        start = ptr;
    }
    else if(node->next == NULL)
    {
        return;
    }
    else 
    {
        ptr = node->prev;
        ptr->next = node->next;
        ptr = node->next;
        ptr->prev=node->prev;
    }
    node->prev = last;
    last->next = node;
    node->next = NULL;
    end = node;
}

void main(void)
{
    int id,value;
    struct dlist *id_nod_loc=NULL;
    init_cache();
    tarverse_cache(dhead,1);
    while(1)
    {
        printf("\nEnter Process Id= ");
        scanf("%d",&id);

        id_nod_loc = find_id(dhead,id);
        if(id_nod_loc == NULL)
        {
            printf("\nEnter Value= ");
            scanf("%d",&value);
            start->id= id;
            start->dat=value;
            id_nod_loc = start;
        }

        interchange_node(id_nod_loc,end);
        dhead =start;
        tarverse_cache(dhead,1);
    }
}