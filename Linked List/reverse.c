#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;	
}Node;

Node *head;

//reverse linked list
void Reverse()
{
	//pertama kita akan membuat bbrp variabel penting current,prev,next
	Node *current = head,*prev = NULL, *next;
	//kita ingin looping ketika current tidak null
	while(current != NULL)
	{
		//kita akan menyimpan next dari list di next karena nanti kita akan reverse linked list jadi next akan diganti dengan alamat baru jadi kita perlu menyimpan alamat lama untuk bisa berpindah list
		next = current->next;
		//kita akan ganti next di list dengan prev karena reverse list jadi kita perlu mengganti next di list yang sedang kita tempati menjadi prev
		current->next = prev;
		//karena kita akan pindah maka kita perlu mengganti variabel prev ini dengan current atau list yang sekarang kita tempati 
		prev = current;
		//kemudian kita akan berpindah ke list selanjutnya
		current = next;
	}
	//setelah selesai melakukan looping kita akan mengganti head dengan prev yang berisi list terakhir yang kita tempati 
	head = prev;
}

//insert in the end
void Insert(int data)
{
	Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	temp1->next = NULL;
	Node* temp2 = head;
	if(temp2 == NULL)
	{
		head = temp1;
		return;
	}
	while(temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp1;
}

void Print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);	
		temp = temp->next;
	}
	printf("\n");
}


int main()
{
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Print();
	Reverse();
	Print();
	
	return 0;
}
