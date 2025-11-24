#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef Node* SSL;

SSL head = NULL;

SSL createNode(int value) {
    SSL n = (SSL)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    n->data = value;
    n->next = NULL;
    return n;
}


SSL insertFront(int value) {
    SSL n = createNode(value);
    n->next = head;
    head = n;
    return head;
}

// Insert at rear
SSL insertRear(int value) {
    SSL n = createNode(value);

    if (head == NULL) {
        head = n;
        return head;
    }

    SSL t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
    return head;
}


SSL insertAfter(int value, int after) {
    SSL t = head;
    while (t != NULL && t->data != after)
        t = t->next;

    if (t == NULL) {
        printf("Value %d not found!\n", after);
        return head;
    }

    SSL n = createNode(value);
    n->next = t->next;
    t->next = n;
    return head;
}


SSL insertBefore(int value, int before) {
    if (head == NULL) return head;

    if (head->data == before)
        return insertFront(value);

    SSL t = head;
    while (t->next != NULL && t->next->data != before)
        t = t->next;

    if (t->next == NULL) {
        printf("Value %d not found!\n", before);
        return head;
    }

    SSL n = createNode(value);
    n->next = t->next;
    t->next = n;

    return head;
}


SSL deleteFront() {
    if (head == NULL) {
        printf("List empty!\n");
        return head;
    }
    SSL t = head;
    head = head->next;
    printf("Deleted value from front : %d\n", t->data);
    free(t);
    return head;
}


SSL deleteRear() {
    if (head == NULL) {
        printf("List empty!\n");
        return head;
    }

    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return head;
    }

    SSL t = head;
    while (t->next->next != NULL)
        t = t->next;

    printf("Deleted value from rear: %d\n", t->next->data);
    free(t->next);
    t->next = NULL;

    return head;
}


SSL deletePosition(int pos) {
    if (pos < 1 || head == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    if (pos == 1)
        return deleteFront();

    SSL t = head;
    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL || t->next == NULL) {
        printf("Position out of range!\n");
        return head;
    }

    SSL d = t->next;
    printf("Deleted value at position %d : value %d\n", pos,d->data);
    t->next = d->next;
    free(d);

    return head;
}


SSL display() {
    SSL t = head;
    if (t == NULL) {
        printf("List empty!\n");
        return head;
    }
    printf("List: ");
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
    return head;
}

SSL swap(SSL a, SSL b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    return head;
}

SSL bubbleSort() {
    if (head == NULL || head->next == NULL)
        return head;

    SSL i, j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                swap(j, j->next);
            }
        }
    }
    return head;
}

SSL insertionSort() {
    if (head == NULL || head->next == NULL)
        return head;

    SSL sorted = NULL;
    SSL current = head;

    while (current != NULL) {
        SSL next = current->next;

        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            SSL temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
                temp = temp->next;

            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    head = sorted;
    return head;
}

struct Node* merge(struct Node* left, struct Node* right)
{
    if (!left) return right;
    if (!right) return left;

    struct Node* result = NULL;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

void splitList(struct Node* head, struct Node** left, struct Node** right)
{
    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

struct Node* mergeSort(struct Node* head)
{
    if (!head || !head->next)
        return head;

    struct Node *left, *right;

    splitList(head, &left, &right);

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file!\n");
        return 0;
    }

    char cmd[10];
    int a, b;

    while (fscanf(fp, "%s", cmd) != EOF) {

        if (strcmp(cmd, "IF") == 0) {
            fscanf(fp, "%d", &a);
            head = insertFront(a);
            printf("Value inserted at front %d\n",a);
        }
        else if (strcmp(cmd, "IR") == 0) {
            fscanf(fp, "%d", &a);
            head = insertRear(a);
            printf("Value inserted at rear %d\n",a);
        }
        else if (strcmp(cmd, "IA") == 0) {
            fscanf(fp, "%d %d", &a, &b);
            head = insertAfter(a, b);
            printf("Value inserted after %d\n",a);
        }
        else if(strcmp(cmd,"BS")==0)
        {
            printf("Using Bubble sort ");
            head=bubbleSort();
            printf("",display());
        }
        else if(strcmp(cmd,"IS")==0)
        {
            printf("Using Insertion sort ");
            head=insertionSort();
            printf("",display());
        }
        else if (strcmp(cmd, "IB") == 0) {
            fscanf(fp, "%d %d", &a, &b);
            head = insertBefore(a, b);
            printf("Value inserted before %d\n",a);
        }
        else if (strcmp(cmd, "DF") == 0) {
            head = deleteFront();
        }
        else if (strcmp(cmd, "DR") == 0) {
            head = deleteRear();
        }
        else if (strcmp(cmd, "DP") == 0) {
            fscanf(fp, "%d", &a);
            head = deletePosition(a);
        }
        else if (strcmp(cmd, "DISP") == 0) {
            head = display();
        }
        else if (strcmp(cmd, "END") == 0) {
            break;
        }
        else if(strcmp(cmd,"MS")==0){
            printf("Using merge sort");
            mergeSort(head);
            printf("",display());
        }
        else {
            printf("Unknown command: %s\n", cmd);
        }
    }

    fclose(fp);
    return 0;
}
