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
#if 0
struct c_node * find_pr_node(int id, struct c_node *c)
{
    while(c != NULL)
    {
        if(c->id == id)
        {
            return c;
        }
        else
        {
            c= c->next;
        }
    }
    c = NULL;
    return c;
}

struct c_node * find_last_node(struct c_node *c)
{
    while(c != NULL)
    {
        c= c->next;
    }
    return c;
}

int pr_val_input(void)
{
    int val;
    printf("Enter value= ");
    scanf("%d",&val);
    return val;
}

void cache_traversal(struct c_node *ptr)
{
    printf("\nId\tVal\n");
    int i=0;
    while(ptr!=NULL)
    {
        //printf(" %d",i++);
        printf("%d\t%d\n",ptr->id, ptr->val);
        ptr=ptr->next;
    }
}
void rearrange_node(struct c_node *cc)
{
    struct c_node *temp, *ptr;
    temp = find_pr_node(cc->id, head);
    if(temp == NULL)
    {
        temp = find_last_node(head);
        temp->next = cc;
        cc->prev =temp;
        ptr=head->next;
        head = ptr;
    }
    else 
    {
        ptr = find_last_node(head);
        temp->prev=temp->next;      

    }
}
#endif
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
    printf("single_list_forward_init\n");
    for(int i=0; i<5; i++)
    {
        struct s_node *cache;
        cache = (struct s_node*)malloc(sizeof(struct s_node));
        cache->id =i;
        cache->val =i;
        cache->next = NULL;
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

void main(void)
{
    int pr_id,val;
    struct c_node *temp;

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

    single_list_rev_init();
    printf("Single Reverse\n");
    while(shead != NULL)
    {
        printf("%d\t%d\n",shead->id, shead->val);
        shead = shead->next;
    }

    single_list_forward_init();
    printf("Single Forward\n");
    while(sheadstart != NULL)
    {
        printf("%d\t%d\n",sheadstart->id, sheadstart->val);
        sheadstart = sheadstart->next;
    }
/*  
    for(int i=0;i<5;i++)
    {
        cache[i]->id =i+2;
        cache[i]->val =i+2;

        if(i==0)
        {
            printf("node at 0\n\n");
            cache[i]->prev = NULL;
        }
        else if(i==4)
        {
            printf("node at 4\n\n");
            cache[i]->next = NULL;
        }
        else 
        {
            cache[i]->prev = cache[i];
            cache[i]->next = cache[i];
        }

        printf("%d \t%d \t%d \t%d \t%d\n", i, cache[i]->id,cache[i]->val,cache[i]->prev,cache[i]->next);
    }
*/
    //cache_traversal(head);
#if 0
    printf("Enter the Process Id\n");
    scanf("%d", &pr_id);
    temp = find_pr_node(pr_id, head);
    if(temp == NULL)
    {
        temp = (struct c_node *)malloc(sizeof(struct c_node));
        val = pr_val_input();
        temp->id= pr_id;
        temp->val = val;
    }
    else
    {
        temp->id= pr_id;
        temp->val = val;
    }
    rearrange_node(temp);
#endif  

}