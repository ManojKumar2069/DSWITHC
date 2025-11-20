#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10
int top = -1;
int stack[MAX];


bool is_empty() {
    return top == -1;
}


bool is_full() {
    return top == MAX - 1;
}


void push(int ele) {
    if (is_full()) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = ele;
        printf("Pushed %d\n", ele);
    }
}


void pop() {
    if (is_empty()) {
        printf("Stack underflow\n");
    } else {
        printf("Popped %d\n", stack[top]);
        top--;
    }
}


void display() {
    if (is_empty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
    }
}
int main(){
    FILE *fp;
    fp=fopen("input.txt","r")
    if(fp==NULL){
        printf("File Cannot be opened\n")
        return 1;
    }
    char command[20];
    int value;
    while(fscanf(fp,"%s",command)!=EOF){
        if(strcmp(command,"push")==0){
            fscanf(fp,"%s",&value);
            push(value)
        }
        else if(strcmp(command,"pop")==0){
            pop();
        }
        else if(strcmp(command,"display")==0){
            display();
        }
        else{
            printf("Invalid command \n",command);
        }
    }
    fclose(fp);
    return 0
}
