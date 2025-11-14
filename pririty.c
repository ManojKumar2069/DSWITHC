#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Function to swap two values
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Insert value in min heap
void insert(int value) {
    if (size >= MAX) {
        printf("Priority Queue is full!\n");
        return;
    }

    heap[size] = value;
    int i = size;
    size++;

    // Heapify up
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("Inserted %d\n", value);
}

// Remove minimum element (highest priority)
int removeMin() {
    if (size <= 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    // Heapify down
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else
            break;
    }

    return root;
}

// Display heap elements
void display() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue (min-heap): ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n2. Remove Min\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                value = removeMin();
                if (value != -1)
                    printf("Removed: %d\n", value);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

