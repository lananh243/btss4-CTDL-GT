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

//them 1 phan tu vao dau head
void insertHead(Node** head, int value){
	// buoc 1 tao 1 node moi 
	Node* newNode = createNode(value);
	// tro node moi den head
	newNode->next = *head;
	// cap nhat head tro den node moi
	*head = newNode;
};

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
	
	int newValue;
	printf("Nhap gia tri can chen : ");
	scanf("%d",&newValue);
	insertHead(&head, newValue);

	printf("Danh sach sau khi chen : \n");
	printList(head);
	return 0;

}

