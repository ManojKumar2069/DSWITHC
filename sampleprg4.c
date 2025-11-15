#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
struct Node*createNode(int data){
struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
if (nn==NULL){
    printf("Memory not allocated");
    exit(1);
}
else{
    nn->data=data;
    nn->link=NULL;
}
return nn;
};
int main(){
struct Node* nn=createNode(10);
struct Node* nn1=createNode(20);
printf("data is %d, link address is %d",nn->data,nn->link);
printf("data is %d, link address is %d",nn1->data,nn->link);
}
struct Node*insertatfist(){
if(nn==NULL){
    printf("No LL avalable")
}
else{
    temp=head;
}
};
