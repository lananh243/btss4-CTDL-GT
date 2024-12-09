#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tao 1 Node moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Them vao cuoi danh sach
void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Tim kiem gia tri trong danh sach
int searchList(Node* head, int value) {
    int index = 0;
    while (head != NULL) {
        if (head->data == value) {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1; // Không tìm th?y
}

// In danh sách
void printList(Node* head) {
    while (head != NULL) {
        printf("%d --> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri cho phan tu %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Danh sach hien tai:\n");
    printList(head);

    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    int index = searchList(head, value);
    if (index != -1) {
        printf("Gia tri %d tim thay tai vi tri %d\n", value, index);
    } else {
        printf("Gia tri %d khong tim thay trong danh sach.\n", value);
    }

    return 0;
}

