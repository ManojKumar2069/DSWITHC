#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    struct DNode* left;
    int data;
    struct DNode* right;
};

struct DNode* head_d=NULL;
struct DNode* last_d=NULL;

struct DNode* createNodeD(int data){
    struct DNode* nn=(struct DNode*)malloc(sizeof(struct DNode));
    if(nn==NULL){
        printf("Memory cannot be allocated \n");
    }
    else{
        nn->left=NULL;
        nn->data=data;
        nn->right=NULL;
    }
    return nn;
};

struct DNode* insert_front_d(int data){
    struct DNode* newnode=createNodeD(data);
    if(head_d==NULL){
        head_d=last_d=newnode;
    }
    else{
        newnode->left=NULL;
        newnode->data=data;
        newnode->right=head_d;
        head_d=newnode;
    }
    return newnode;
};

struct DNode* insert_rear_d(int data){
    struct DNode* newNode=createNodeD(data);
    if(head_d==NULL){
        head_d=last_d=newNode;
    }
    else{
        newNode->data=data;
        newNode->left=last_d->right;
        last_d->right=newNode;
        newNode->right=NULL;
        last_d=newNode;
    }
    return newNode;
};

struct DNode* delete_front_d(){
    if(head_d==NULL){
        printf("The linked list is empty\n");
    }
    else{
        struct DNode* temp=head_d->right;
        int deln;
        deln=head_d->data;
        printf("the deleted element from front is %d\n",deln);
        head_d=NULL;
        head_d=temp;
    }
};

struct DNode* delete_rear_d(){
    if(head_d==NULL){
        printf("NO LINKED LIST EXIST \n");
    }
    else{
        struct DNode* currn=head_d;
        struct DNode* prev=NULL;
        while(currn->right!=NULL){
            prev=currn;
            currn=currn->right;
        };
        int data=currn->data;
        printf("the deleted element from rear is %d\n",data);
        prev->right=NULL;
        last_d=prev;
        free(currn);
    }
};

void display_d(){
    struct DNode* temp=head_d;
    printf("The elemnets in the double linked list\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->right;
    }
}

struct DNode* insert_at_pos(int pos,int data){
    struct DNode* newNode=createNodeD(data);
    if(pos<=0){
        printf("please enter a proper position \n");
    }
    else if(pos==1){
        insert_front_d(data);
    }
    else{
        struct DNode* prev=NULL;
        struct DNode* currn=head_d;
        for(int i=0;pos<i&&currn!=NULL;i++){
            prev=currn;
            currn=currn->right;
        }
        newNode->right=currn;
        newNode->data=data;
        newNode->left=prev;
        prev->right=newNode;
        currn->left=newNode;
    }
    return newNode;
};

int main(){
    int data,choice,pos;
    while(1){
    printf("-----Double linked list-------\n");
    printf("----Menu----\n");
    printf("1.InsertFront\n2.InsertRear\n3.DeleteFront\n4.DeleteRear\n5.InsertAtPosition\n6.Display\n");
    printf("Enter the operations you want to perform \n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("Enter the element you want to insert at front\n");
        scanf("%d",&data);
        insert_front_d(data);
        break;
    case 2:
        printf("Enter the element you want to insert at rear\n");
        scanf("%d",&data);
        insert_rear_d(data);
        break;
    case 3:
        delete_front_d();
        break;
    case 4:
        delete_rear_d();
        break;
    case 5:
        printf("Enter the positions you want insert \n");
        scanf("%d",&pos);
        printf("Enter the element you want to insert \n");
        scanf("%d",&data);
        insert_at_pos(pos,data);
        break;
    case 6:
        display_d();
        break;
    default:
        printf("Plz select proper choise ");
        break;
    }
    }
    return 0;
}
