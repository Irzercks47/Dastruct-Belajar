#include <stdio.h>
#include <stdlib.h>

//cara kerja sama seperti linked list biasa namun stack ini menganut LIFO(Last In First Out)
//yang dimana element terakhir yang masuk akan keluar duluan
//jadi kita hanya menggunakan top atau head saja
typedef struct Node {
	int data;
	struct Node *next;
}Node;

Node *top;

Node *GetNewNode(int x){
	Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void Push(int x){
	Node *newNode = GetNewNode(x);
	newNode->next = top;
	top = newNode;
}

void Pop(){
	Node *temp = top;
	top = temp->next;
	free(temp);
}

void Print(){
	Node *temp = top;
	printf("Stack : ");
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	Push(2);Print();
	Push(3);Print();
	Push(4);Print();
	Pop();Print();
	Push(5);Print();
	Pop();Print();
	return 0;
}
