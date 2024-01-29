/*
* Code- 
* - Binary tree using Linked list.
* - Preorder Tarversal
* - Postorder Tarversal
* - Inorder Tarversal
* - Searching in Binary tree
* - Inserting in Binary tree
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int dat;
    struct node *left;
    struct node *right;    
};

struct node * create_node(int dat)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->dat=dat;
    n->left =NULL;
    n->right= NULL;
    return n;
}

void preorder_traversal(struct node *n)
{
    if(n!=NULL)
    {
        printf("%d ",n->dat);
        preorder_traversal(n->left);
        preorder_traversal(n->right);
    }
}

void postorder_traversal(struct node *n)
{
    if(n!=NULL)
    {
        postorder_traversal(n->left);
        postorder_traversal(n->right);
        printf("%d ",n->dat);
    }
}

void inorder_traversal(struct node *n)
{
    if(n != NULL)
    {
        inorder_traversal(n->left);
        printf("%d ",n->dat);
        inorder_traversal(n->right);
    }
}

int isBST(struct node *n)
{
    static struct node* prev;
    if(n!=NULL)
    {
        if(!isBST(n->left))
        {
            return 0;
        }
        if(prev!=NULL && n->dat <= prev->dat)
        {
            return 0;
        }
        prev = n;
        return isBST(n->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *n, int key)
{
    struct node *temp = NULL;
    if(n != NULL)
    {
        if(key == n->dat)
        {
            return n;
        }
        else if(key < n->dat)
        {
            return(search(n->left, key));
            
        }
        else
        {
            return(search(n->right, key));
        }
    }
}

void insert(struct node *n, int key)
{
    struct node *prev = NULL;
    while(n != NULL)
    {
        prev = n;
        if(key == n->dat)
        {
            return;
        }
        else if(key < n->dat)
        {
            n=n->left;            
        }
        else
        {
           n=n->right;
        }
    }

    struct node *new = create_node(key);
    
    if(key < prev->dat)
    {
        prev->left= new;
    }
    else
    {
        prev->right =new;
    }

}

void main(void)
{
    int val, j=0;
    struct node *p[10];

    for(int i=0;i<7;i++)
    {
        p[i] = create_node(i);
    }

    //        3
    //     /    \
    //    1      5
    //   / \   / \
    //  0   2  4    6
    p[3]->right=p[5];
    p[3]->left=p[1];

    p[1]->left=p[0];
    p[1]->right=p[2];

    p[5]->left=p[4];  
    p[5]->right=p[6]; 

    printf("\nPreorder Traversal- ");
    preorder_traversal(p[3]);
    printf("\nPostorder Traversal- ");
    postorder_traversal(p[3]);
    printf("\nInorder Traversal- ");
    inorder_traversal(p[3]);

    printf("\nisBST- ");
    printf("%d",isBST(p[3]));
    printf("\n\n");

    struct node *temp = search(p[3], 5);
    printf("\nFound- %d", temp->dat);

    insert(p[3], 16);
    printf("\nInorder Traversal- ");
    inorder_traversal(p[3]);

}