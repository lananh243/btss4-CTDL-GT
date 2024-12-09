#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

//tao 1 node
Node* createNode(int value){
	// cap phat bo nho 
	Node* newNode = (Node*)malloc(sizeof(Node));
	// gan data cho node
	newNode->data = value;
	// gan phan link
	newNode->next = NULL;
	return newNode;
};

//Duyet danh sach
void traverList(Node* head){
	Node* temp  = head;
	while (temp != NULL){
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
	printf("NULL \n");
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

void deleteHead(Node** head){
	if(*head == NULL){
		return;
	}
	Node* temp = *head;
	*head = (*head)->next;
	free(temp);
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
	traverList(head);
	
	deleteHead(&head);
	printf("Danh sach sau khi xoa phan tu dau tien : \n");
	traverList(head);
}

