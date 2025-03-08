#include<stdio.h>
#include<stdlib.h>


struct Node {
	int data;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int value) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if(newNode == NULL) {
		printf("Memory allocation failed");
		exit(1);
	}
	newNode->data = value;
	newNode->next = NULL;

	return newNode;
};
int lengthOfll() {
	int n = 0;
	struct Node *temp = head;
	while(temp != NULL) {
		temp = temp->next;
		n++;
	}

	return n;


}

void deleteAtPos(int pos) {
	if(pos < 0 || pos > lengthOfll() - 1){
		printf("Invalid position");
		return;
	}

	struct Node *temp = head;
	for(int i = 0; i< pos - 1; i++) {
		temp = temp->next;
	}

	struct Node *deleteNode = temp->next;

	temp->next = deleteNode->next;

	free(deleteNode);

}
void insertAtPos(int value, int pos) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	
	if(newNode == NULL) {
		printf("Memory allocation failed");
		return;
	}
	int len = lengthOfll();


	if(pos < 0 || pos > len) {
		printf("Invalid position\n");
	}
	newNode->data = value;
	if(pos == 0){
		newNode->next = head;
		head = newNode;
		return;

	}
	struct Node *temp = head;
	for(int i = 0; i< pos-1; i++) {
		temp = temp->next;
	}

	newNode->next = temp->next;
	temp->next = newNode;

	return;
}

void insertAtHead(int value){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if(newNode == NULL) {
		printf("Memory allocation failed");
	}
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	if(tail == NULL) {
		tail = newNode;
	}
};


void insertAtTail(int value){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if(newNode == NULL) {
		printf("Memory allocation failed");
		exit(1);
	}
	newNode->data = value;	
	newNode->next = NULL;
	if(tail == NULL) {
		head = tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
};

void display() {
	struct Node *temp = head;
	while(temp != NULL) {
		printf("%d ->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
};

int searchNode(int value) {
	struct Node *temp = head;
	int idx = 0;

	for(int i = 0; i< lengthOfll(); i++) {
		if(temp->data == value) {
			printf("Found node: %d, index: %d\n", value, idx);
			return idx;
		}
		temp = temp->next;
		idx++;
	}
	printf("Node not found");
	return -1;
}

int main() {
	insertAtHead(8);
	insertAtHead(5);
	insertAtHead(2);
	insertAtHead(7);
	insertAtTail(6);
	display();
	insertAtPos(10, 2);
	display();
	deleteAtPos(2);
	searchNode(6);
	display();

	return 0;
}
