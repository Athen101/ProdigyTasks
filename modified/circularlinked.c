#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  

struct node {
    int info;
    struct node* next;
};

struct node* tail = NULL;
int size = 0;  

void insertatfront(int data) {
    if (size >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (tail == NULL) {
        temp->info = data;
        temp->next = temp;
        tail = temp;
    } else {
        temp->info = data;
        temp->next = tail->next;
        tail->next = temp;
    }
    size++;
}

void insertatend(int data) {
    if (size >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (tail == NULL) {
        temp->info = data;
        temp->next = temp;
        tail = temp;
    } else {
        temp->info = data;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    size++;
}

void insertinmiddle(int data) {
    if (size >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }
    if (tail == NULL) {
        printf("\nList is empty. Insert at front\n");
        insertatfront(data);
    } else {
        int position, i = 1;
        struct node* temp;
        printf("Enter the position to be inserted: ");
        scanf("%d", &position);
        if (position == 1) {
            insertatfront(data);
        } else {
            temp = tail->next;
            while (i < position - 1 && temp != tail) {
                temp = temp->next;
                i++;
            }
            if (temp == tail && position - 1 > i) {
                printf("\nPosition out of range, inserting at last\n");
                insertatend(data);
            } else {
                struct node* new_node = (struct node*)malloc(sizeof(struct node));
                new_node->info = data;
                new_node->next = temp->next;
                temp->next = new_node;
                size++;
            }
        }
    }
}

void deleteatfirst() {
    struct node* temp;
    if (tail == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = tail->next;
        if (tail == tail->next) {
            tail = NULL;
        } else {
            tail->next = temp->next;
        }
        free(temp);
        size--;
    }
}

void deleteinmiddle() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    int position, i = 1;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &position);

    if (position == 1) {
        deleteatfirst();
    } else {
        struct node* temp = tail->next;
        struct node* prev = NULL;
        printf("Start deleting at position: %d\n", position);

        do {
            prev = temp;
            temp = temp->next;
            i++;
        } while (i < position && temp != tail->next);

        if (i < position || temp == tail->next) {
            printf("\nPosition out of range\n");
        } else {
            printf("Deleting node at position: %d\n", position);
            prev->next = temp->next;
            if (temp == tail) {
                tail = prev;
            }
            free(temp);
            size--;
        }
    }
}

void deleteatend() {
    struct node* temp;
    if (tail == NULL) {
        printf("List is empty\n");
    } else {
        temp = tail->next;
        if (tail == tail->next) {
            free(tail);
            tail = NULL;
        } else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = tail->next;
            free(tail);
            tail = temp;
        }
        size--;
    }
}

void search(int data) {
    if (tail == NULL) {
        printf("It is empty\n");
    } else {
        struct node* temp = tail->next;
        int position = 1;
        do {
            if (temp->info == data) {
                printf("\nElement %d found at position %d\n", data, position);
                return;
            }
            temp = temp->next;
            position++;
        } while (temp != tail->next);
        printf("Element %d not found\n", data);
    }
}

void display() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = tail->next;
    printf("Circular linked list: ");
    do {
        printf("%d-->", temp->info);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(head)\n");
}

int main() {
    int ch, data;
    while (1) {
        printf("\n1. Insert at front");
        printf("\n2. Insert in middle");
        printf("\n3. Insert at end");
        printf("\n4. Delete at front");
        printf("\n5. Delete in middle");
        printf("\n6. Delete at end");
        printf("\n7. Search");
        printf("\n8. Display");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter element to be inserted: ");
            scanf("%d", &data);
            insertatfront(data);
            break;
        case 2:
            printf("Enter element to be inserted: ");
            scanf("%d", &data);
            insertinmiddle(data);
            break;
        case 3:
            printf("Enter element to be inserted: ");
            scanf("%d", &data);
            insertatend(data);
            break;
        case 4:
            deleteatfirst();
            break;
        case 5:
            deleteinmiddle();
            break;
        case 6:
            deleteatend();
            break;
        case 7:
            printf("Enter value to be searched: ");
            scanf("%d", &data);
            search(data);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
