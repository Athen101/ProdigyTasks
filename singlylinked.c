#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* head = NULL;
int count = 0;
int max_size = 4;

struct node* create_node(int data);
void insert_at_begin(int data);
void insert_at_end(int data);
void delete_at_begin();
void delete_at_end();
void delete_in_middle(int position);
void display();
void search(int data);
void insert_in_middle(int data, int position);

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_begin(int data) {
    if (count >= max_size) {
        printf("List is full.\n");
        return;
    }
    struct node* new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    count++;
}

void insert_at_end(int data) {
    if (count >= max_size) {
        printf("List is full.\n");
        return;
    }
    struct node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    count++;
}

void delete_at_begin() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    count--;
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
    count--;
}

void delete_in_middle(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    if (position == 1) {
        head = temp->next;
        free(temp);
        count--;
        return;
    }
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position does not exist.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    count--;
}

void search(int data) {
    struct node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found at position %d\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", data);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Elements in the list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_in_middle(int data, int position) {
    if (count >= max_size) {
        printf("List is full.\n");
        return;
    }
    struct node* new_node = create_node(data);
    if (position == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position does not exist.\n");
            free(new_node);
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    count++;
}

int main() {
    int a;
    while (1) {
        int ch;
        printf("\n1. Insert at begin\n");
        printf("2. Insert in middle\n");
        printf("3. Insert at end\n");
        printf("4. Delete at begin\n");
        printf("5. Delete at end\n");
        printf("6. Delete in middle\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                insert_at_begin(a);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                int pos;
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insert_in_middle(a, pos);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                insert_at_end(a);
                break;
            case 4:
                delete_at_begin();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter the position of the element to be deleted: ");
                scanf("%d", &a);
                delete_in_middle(a);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter the element to search: ");
                scanf("%d", &a);
                search(a);
                break;
            case 9:
                exit(0);
            default:
                printf("Enter a valid choice.\n");
                break;
        }
    }
    return 0;
}
