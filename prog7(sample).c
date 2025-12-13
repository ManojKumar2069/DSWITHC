#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node* head=NULL;
struct Node* last=NULL;
struct Node* CreateNode(int data)
{
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
    if(nn==NULL)
    {

        printf("Memory is not allocated");
        exit(0);
    }
    else{
        nn->data=data;
        nn->next=NULL;
        nn->prev=NULL;
    }
    return nn;
};
struct Node* Insert_front(int data)
{
    struct Node *newNode=CreateNode(data);
    if(head==NULL)
    {
        head=newNode;
        last=newNode;
    }
    else{
        newNode->next=head;
        newNode->prev=newNode;
        head=newNode;
    }
    return newNode;
};
struct Node* Insert_rear(int data)
{
    struct Node *newNode=CreateNode(data);
    if(head==NULL)
    {
        head=newNode;
        last=head;
    }
    else
    {
        last->next=newNode;
        newNode->prev=last;
        last=newNode;
    }
    return newNode;
};
struct Node* delet_front()
{
    struct Node* temp=NULL;
    if(head==NULL)
    {
        printf("\nNo linkedlist\n");
    }
    else
    {
        temp=head;
        if(head==NULL)
        {
            last=NULL;
        }
        else{
            int data=temp->data;
            printf("%d\n",data);
            free(temp);
            temp=NULL;
        }
    }
    return head;
};
struct Node* delete_rear()
{
    struct Node* temp=NULL;
    if(head==NULL)
    {
        printf("\nNo LinkedList\n");
    }
    else{
        temp=last;
        if(last->prev==NULL)
        {
            last=last->prev;
            last->next=NULL;
        }
        else{
                head=NULL;
                last=NULL;
        }
        int data=temp->data;
        free(temp);
        printf("%d\n",data);
        temp=NULL;
    }
    return last;
};
void display()
{
    if(head==NULL)
    {
        printf("\nNo linked list\n");
        return;
    }
    else
    {
        struct Node* temp=head;
        while(temp!=NULL) {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
};
int main()
{
    //FILE *fp=fopen("input.txt","r");
    //if(fp==NULL)
    //{
        //printf("File cannot be opend");
    //}
    printf("\nInitial list:\n");
    Insert_front(10);
    Insert_front(20);
    Insert_front(30);
    Insert_front(40);
    display();
    //printf("\nlist after adding element at rear:\n");
    //Insert_rear(50);
    display();
    printf("\nlist after deleting front:\n");
    delet_front();
    display();
    printf("\nlist after deleting rear:\n");
    delete_rear();
    display();
};
