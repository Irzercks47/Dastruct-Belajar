#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *head;
Node *tail;

Node *GetNewNode(int x){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
}

int isEmpty(){
	if(head == NULL && tail == NULL){
		return 0;
	}
	return 1;
}

//enqueue insert lewat tail
void Enqueue(int x){
	Node *newNode = GetNewNode(x);
	//bila empty maka insert lewat tail karena empty maka head ini akan sama isinya dengan head 
	if(isEmpty() == 0){
		tail = newNode;
		head = tail;
	}
	//dalam insertionnya lewat tail
	else{
		//alamat tail->next sebelumnya akan kita ganti dari null ke newNode
		tail->next = newNode;
		//setelah itu tail akan kita ganti ke alamat newNode
		tail = newNode;
	}
}

//dequeue ini deletion lewat head
void Dequeue(){
	Node *temp = head;
	if(isEmpty() == 0){
		printf("List is empty \n");
		return;
	}
	//jika head sama dengan tail yang berarti hanya memiliki 1 list maka
	if(head == tail){
		//karena head dan tail memiliki memory list yang sama maka bisa kita ganti dengan null karena isi dari list cuma 1
		head = tail = NULL;
	}
	//jika list berisi banyak 
	else{
		//maka head akan kita pindah ke element selanjutnya
		head = head->next;
	}
	//kita free tempnya
	free(temp);	
}

//mengambil element dari head
void Front(){
	if(isEmpty() == 0){
		printf("head is empty \n");
		return;
	}
	printf("Front: %d \n", head->data);	
}

void Print(){
	Node *temp = head;
	printf("Queue: ");	
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	if(isEmpty() == 0){
		printf("List is empty \n");
	}
	Enqueue(2); Enqueue(4); Enqueue(5);
	Print();
	Dequeue();
	Enqueue(6); Enqueue(9);
	Print();
	Dequeue(); Dequeue();
	Print();
	Front();
	return 0;
}
