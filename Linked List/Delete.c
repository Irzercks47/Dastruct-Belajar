#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * next;
}Node;

Node* head;

//insert in the end
void Insert(int data)
{
	Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	temp1->next = NULL;
	Node* temp2 = head;
	if(temp2 == NULL)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	//kita ingin looping sampai menemukan yang nextnya null
	while(temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	//setelah menemukan yang nextnya null maka akan kita ganti nextnya dengan list yang baru
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
}

//delete 
void Delete(int n)
{
	//kita assign head di temp1
	Node* temp1 = head;
	//bila n==1
	if(n == 1)
	{
		//kita ganti head dengan next dari list 1
		head = temp1->next;
		//kemudian kita free list 1
		free(temp1);
		return;
	}
	int i;
	//untuk posisi nth kita perlu looping sampai menemukan n-1 
	for(i=0; i<n-2; i++)
	{
		//menuju ke list baru
		temp1 = temp1->next;
	}
	//kita akan assign variabel baru untuk ke node yang akan dihapus
//	Node* temp2 = temp1->next;
	//kemudian kita akan ganti next yang ada di n-1 dengan next yang ada di node yang akan di hapus  
//	temp1->next = temp2->next;
	//kita akan assign variabel baru untuk ke node yang akan dihapus
	Node* temp2 = temp1->next;
	//bedanya ini dengan diatas kita bisa langsung menggunakan temp1 untuk mengambil next dari node yang akan dihapus
	temp1->next = temp1->next->next;
	//node yang akan dihapus akan di free
	free(temp2);
}

int main()
{
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5); //list: 2,4,6,5
	Print();
	int n;
	printf("Enter a position \n");
	scanf("%d", &n);
	Delete(n);
	Print();
	
	return 0;
}
