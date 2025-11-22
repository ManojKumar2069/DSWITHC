#include <stdio.h>
#include <stdbool.h>
typedef struct Node{
    int data;
    struct Node *link;
}*SSL;
SSL head=NULL;
SSL last=NULL;
SSL Create_node(int num){
    struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
    if(nn=NULL){
        printf("Memory not allocated");
        return;
    }
    nn->data=num;
    nn->link=NULL;
    return nn;
}
void insert_rear(int num){
    SSL temp=NULL;
    SSL newnode=Create_node(num);
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
        temp=NULL;
        newnode=NULL;
    }
    return head;
}
void insert_front(int num){
    SSL newnode=Create_node(num);
    if(head==NULL){
        head=newnode;
        last=newnode;
    }
    else{
        newnode->link=head;
        head=newnode;
    }
    newnode=NULL;
    return head;
}

SSL delete_front(){
    SSL temp=NULL;
    SSL newnode=Create_node(num);
    if(head==NULL){
        printf("The linked list is empty\n");
        return
    }
    else{
        temp=head;
        value=temp->data;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    return head
}

SSL delete_rear(){
    SSL temp=NULL;
    SSL newnode=Create_node(num);
    if(head==NULL){
        printf("LINKED LIST IS EMPTY");
        return head;
    }
    else{
        temp=head;
        while(temp->link->link!=NULL){
            temp=temp->link;
        }
        value=temp->link->data
        printf("%d",&value);
        free(temp->link)
        temp->link=NULL
    }
    return head;
}

SSL delete_at_position(int pos){
    SSL temp=NULL;
    SSL newnode=Create_node(num);
    if(pos<1){
        printf("Invalid position");
        return head;
    }
    else if(pos==1){
        temp=head
        value=temp->data;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    else{
        temp=head;
        for(int i=1;i<pos-1&&temp=NULL;i++){
            temp=temp->link;
        }
        if(temp==NULL){
            printf("Position out of bound");
        }
        else{
            value=temp->link->data;
            printf("%s",value);
            deln=temp->link;
            temp->link=temp->link->link;
            free(deln);
            deln=NULL;
            temp=NULL;
        }
    }
    return head;
}

SSL reverse_list(struct Node *head){
    SSL prevn=NULL;
    SSL nextn=NULL;
    SSL currn=NULL;
    if(head==NULL){
        printf("The linked list is empty");
        return head;
    }
    else{
        currn=head;
        while(currn!=NULL){
            nextn=currn->link;
            currn->link=prevn;
            prevn=currn;
            currn=nextn;
        }
    }
    return prevn;
}

SSL Mid_element(){
    SSL prevn=NULL;
    SSL currn=NULL;
    if(head==NULL){
        printf("NO LL");
        return head;
    }
    else{
        currn=head,prevn=head;
        while(currn!=NULL&&currn->link!=NULL){
            prevn=prevn->link;
            curn=curn->link->link;
        }
    }
    return prevn;
}

int main(){

}
