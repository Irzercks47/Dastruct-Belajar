#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct Node{
	char c;
	struct Node *next;
}Node;

Node *top;
char d[MAX_SIZE];

//inisiasi node baru
Node *GetNewNode(char x){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->c = x;
	newNode->next = NULL;
	return newNode;
}

//kita akan push char dari array ke linked list
//karena ini menggunakan stack maka push dari top
void Linked_Push(char x){
	Node *newNode = GetNewNode(x);
	newNode->next = top;
	top = newNode;
}

//untuk reverse maka kita bisa menggunakan stack
//disini saya akan melakukan looping untuk mengambil char dari array yang kemudian akan di push ke linked list
void Reverse(int i, int length){
	for(i = 0; i < length; i++){
		Linked_Push(d[i]);
	}
}

//pada bagian ini kita akan memanfaatkan dynamic memory allocation yang bersifat stack untuk melakukan reverse terhadap array char
void Reverse_recurse(char x[], int i, int length){
	if(i >= length) return;
	Reverse_recurse(x, i + 1, length);
	printf("%c", x[i]);
}

void Print(){
	Node *temp = top;
	while(temp != NULL){
		printf("%c", temp->c);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	int i = 0;
	//untuk menentukan length dari array kita bisa mengambil besar byte dari array dan kemudian dibagi dengan besar byte dari element pertama
	int length = sizeof(d) / sizeof(d[0]);
	d[0] = 'h';
	d[1] = 'e';
	d[2] = 'l';
	d[3] = 'l';
	d[4] = 'o';
	printf("array of char : ");
	for(i = 0; i < length; i++){
		printf("%c", d[i]);
	}
	printf("\n");
//	Reverse(i, length);
	printf("Reverse char : ");
	Reverse_recurse(d, 0, length);
//	Print();
	printf("\n");
	return 0;
}
