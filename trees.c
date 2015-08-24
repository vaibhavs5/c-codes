#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node
{
    int key;
    int value;
    Node* left;
    Node* right;
}*root=NULL ;

Node* putNode(Node *x,int key,int value)
{
    if(x==NULL)
    {
        x=malloc(sizeof(Node));
        x->key=key;
        x->value=value;
        x->left=NULL;
        x->right=NULL;
        return x;
    }
    if(key<x->key) x->left=putNode(x->left,key,value);
    else if(key>x->key) x->right=putNode(x->right,key,value);
    else x->value=value;
    return x;
}

void put(int key,int value)
{
    root=putNode(root,key,value);
}

int get(int key)
{

    if(root==NULL) return 0;
    else if(root->key>key) //get(root->left->key);
    {
        root=root->left;
    }
    else if(root->key<key) //get(root->right->key);
    {
        root=root->right;
    }
    else
    {return root->value;}
    get(key);

   /* Node *ptr=root;
    while(ptr!=NULL)
    {
        if(ptr->key==key)
            return ptr->value;
        else if(ptr->key>key)
            ptr=ptr->left;
        else if(ptr->key<key)
            ptr=ptr->right;
    }
    return 0;   */
}

int main()
{
    int a;
    put(5,3);
    put(4,6);
    put(7,2);
    put(9,1);
    a=get(7);
printf("%d\n",a);
}


