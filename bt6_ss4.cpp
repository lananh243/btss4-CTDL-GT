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

// xoa 1 phan tu vao vi tri bat ki 
void deleteElement(Node** head, int position){
	if(*head == NULL){
		printf("Vi tri ko hop le");
		return;
	}
	Node* temp = *head;
	//Xoa node dau tien
	if(position == 0){
		*head = temp->next;
		free(temp);
		return;
	}
	
	for(int i; i < position - 1 && temp != NULL;i++){
		temp = temp->next;
	}
	Node* nodeDelete = temp->next;
	temp->next = nodeDelete->next;
	free(nodeDelete);

}
int main() {

	Node*head = NULL;
	int n,value;
	
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
	
	printf("Moi ban nhap vao vi tri can xoa :");
	int position;
	scanf("%d", &position);
	deleteElement(&head,position);
	
	printf("Danh sach sau khi xoa : \n");
	printList(head);
}

