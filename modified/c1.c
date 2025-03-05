#include<stdio.h>
#include<stdlib.h>

int front = -1;
int rear = -1;
int n;

void enqueue(int a[], int x) {
    if ((rear + 1) % n == front) {
        printf("Queue overflow\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0; 
        a[rear] = x;
    } else {
        rear = (rear + 1) % n;
        a[rear] = x;
        printf("The element %d is inserted\n", x);
    }
}

void dequeue(int a[]) {
    if (front == -1 && rear == -1) {
        printf("Queue underflow\n");
    } else if (front == rear) {
        printf("The deleted element is %d\n", a[front]);
        front = -1;
        rear = -1;
    } else {
        printf("The element %d is deleted\n", a[front]);
        front = (front + 1) % n;
    }
}

void display(int a[]) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Elements are:\n");
        while (i != rear) {
            printf("%d\t", a[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", a[rear]);
    }
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    int a[n], e;

    while (1) {
        int ch;
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Insert element: ");
                scanf("%d", &e);
                enqueue(a, e);
                break;
            case 2:
                dequeue(a);
                break;
            case 3:
                display(a);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice\n");
                break;
        }
    }
    return 0;
}
