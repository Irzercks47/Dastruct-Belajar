#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;
struct Node* head;

void Insert(int data, int n) 
{
	Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	//pada bagian ini insert bila list masih kosong
	if(n == 1)
	{
		//yang dimana bila kosong next dari list yang baru adalah head yang karena masih kosong sehingga nilai next jadi null  
		temp1->next = head;
		//karena sudah ada isi maka head akan diisi oleh alamat list pertama
		head = temp1;
		return;
	}
	//bila list ada isi maka kita buat variabel temp2 untuk menyimpan list sementara
	//kenapa kita taruh head di variabel baru agar head yang asli tidak berubah
	Node* temp2 = head;
	int i;
	//disini kita akan looping list tersebut
	for(i = 0; i < n; i++) 
	{
		//bila loop berjalan maka kita akan pindah ke list selanjutnya
		temp2 = temp2->next;
	}
	//bila list ada isinya maka insertnya akan beda dari yang kosong
	//yang pertama harus kita lakukan adalah di next list baru ini akan kita masukkan next dari list sebelumnya
	temp1->next = temp2->next;
	//setelah kita memindah next dari list sebelumnya ke list baru
	//maka kita akan mengganti next di list lama ke alamat list yang baru	
	temp2->next = temp1;
}

void Print()
{
	Node* temp = head;
	printf("list is : ");
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() 
{
	head = NULL; //empty list
	Insert(2,1); //List: 2
	Insert(3,2); //List: 2, 3
//	Insert(4,1); //List: 4,2,3
//	Insert(5,2); //List: 4,5,2,3
	
	Print();	
	
	return 0;
}

