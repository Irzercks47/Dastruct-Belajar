#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int x[MAX_SIZE];
int head = -1;
int tail = -1;

int isEmpty(){
	if(head == -1 && tail == -1){
		return 0;
	}
	return 1;
}

void enqueue(int n){
	if(tail == MAX_SIZE - 1){
		printf("STACK OVERFLOW");
		return;
	}
	if(isEmpty() == 0){
		head++;
		tail++;
	}
	else{	
		tail++;
	}
	x[tail] = n;
}

int dequeue(){
	if(isEmpty() == 0){
		printf("Queue is Empty");
		return;
	}
	if(head == tail){
		int temp = head;
		head = -1;
		tail = head;
		return x[temp];
	} else{
		int temp = head;
		head++;
		return x[temp];
	}
}

int main(){
	int i = 0;
	enqueue(2);
	enqueue(3);
	enqueue(4);
	for(i = head; i <= tail; i++){		
		printf("%d", x[i]);
	}
	printf("\n");
	printf("head: %d\n", head);
	printf("tail: %d\n", tail);
	printf("dequeue: %d\n", dequeue());
	for(i = head; i <= tail; i++){		
		printf("%d", x[i]);
	}
	printf("\n");
	printf("isEmpty: %d\n",isEmpty());
	return 0;
}



