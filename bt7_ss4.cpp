#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node;

// Tao 1 Node  
Node* createNode(int value){
	// cap phat bo nho 
	Node* newNode = (Node*)malloc(sizeof(Node));
	// gan data cho node
	newNode->data = value;
	// gan phan link
	newNode->next = NULL;
	return newNode;
};

// Hàm d?o ngu?c danh sách
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev; 
        prev = current;       // Di chuyen prev len
        current = next;       // Di chuyen current len
    }
    *head = prev; 
}

// them 1 phan tu vao cuoi danh sach
void insertEnd(Node** head, int value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp-> next = newNode;
	
}

// duyet danh sach 
void printList(Node* head){
	Node* temp  = head;
	while (temp != NULL){
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
	printf("NULL \n");
}
int main() {
	Node*head = NULL;
	int n;
	
	printf("Nhap so luong phan tu : ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int value;
		printf("Nhap gia tri cho phan tu %d : ", i+1);
		scanf("%d",&value);
		insertEnd(&head, value);
	}
	printf("Danh sach hien tai : \n");
	printList(head);
	
	//Dao nguoc
	reverseList(&head);
	printf("Danh sach sau khi dao nguoc : \n");
	printList(head);
	return 0;

}

