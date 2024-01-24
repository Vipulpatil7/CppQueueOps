#include <stdio.h>
#include <stdlib.h>

struct c_node{
    struct c_node *prev;
    int id;
    int val;
    struct c_node *next;
};

struct s_node{
    int id;
    int val;
    struct s_node *next;
};
struct c_node *head = NULL;
struct c_node *current = NULL;

struct s_node *shead = NULL;
struct s_node *sheadstart = NULL;

void double_list_init(void)
{
    struct c_node *cache;
    for(int i=0;i<5;i++)
    {
        cache = (struct c_node *)malloc(sizeof(struct c_node));
        
        cache->id =i;
        cache->val =i;
        cache->next = NULL;
        cache->prev = NULL;
        if(current==NULL)
        {
            head = cache;
            current = cache;
        }
        else 
        {
            cache->prev = current;
            current->next = cache;
            current =cache;
        }
    }
}

void single_list_rev_init(void)
{
    for(int i=0; i<5; i++)
    {
        struct s_node *cache;
        cache = (struct s_node*)malloc(sizeof(struct s_node));
        cache->id =i;
        cache->val =i;
        cache->next= shead;
        shead =cache;
    }
}

void single_list_forward_init(void)
{
    for(int i=0; i<5; i++)
    {
        struct s_node *cache;
        cache = (struct s_node*)malloc(sizeof(struct s_node));
        cache->id =i;
        cache->val =i;
        cache->next=NULL;
        if(shead==NULL)
        {
            shead =cache;
            sheadstart =cache;
        }
        else 
        {
            shead->next= cache;
            shead=cache;
        }
    }
}

void main(void)
{
    single_list_forward_init();
    printf("Single Forward\n");
    while(sheadstart != NULL)
    {
        printf("%d\t%d\n",sheadstart->id, sheadstart->val);
        sheadstart = sheadstart->next;
    }

    single_list_rev_init();
    printf("Single Reverse\n");
    while(shead != NULL)
    {
        printf("%d\t%d\n",shead->id, shead->val);
        shead = shead->next;
    }
    
    double_list_init();

    printf("Double Forward\n");
    while(head != NULL)
    {
        printf("%d\t%d\n",head->id, head->val);
        head = head->next;
    }
    printf("Double Reverse\n");
    while(current != NULL)
    {
        printf("%d\t%d\n",current->id, current->val);
        current = current->prev;
    }
}