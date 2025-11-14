#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

// Check if deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Insert only at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted %d at rear\n", value);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deleted %d from front\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deleted %d from rear\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Input Restricted Deque ---\n");
        printf("1. Insert at Rear\n2. Delete from Front\n3. Delete from Rear\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;

            case 2:
                deleteFront();
                break;

            case 3:
                deleteRear();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
