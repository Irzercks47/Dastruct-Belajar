#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;	
}Node;
void Print();
void Reverse_Print();
void Reverse_List();

Node *head;

/*** iteration
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
***/

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

int main()
{
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	//iteration
	/**
	Print();
	Reverse();
	Print();
	**/
	//recursion
	Print(head);
	Reverse_Print(head);
	Reverse_List(head);
	Print(head);
	
	return 0;
}

/***recursion***/
//untuk rekursif maka kita bisa passing parameternya meskipun variabel global karena fungsinya dari passing ini adalah biar kita tahu posisi berada dimana
//cara kerjanya adalah kita akan passing head kemudian kita akan memanggil nextdari list tersebut hingga list ini Null
void Print(Node *p) //p adalah head 
{
	Node *temp = p;//membuat temp untuk manmpung head
	if(temp == NULL)//bila temp null maka akan return
	{
		printf("\n");
		return;
	}
	printf("%d", temp->data);//print data dari temp
	Print(temp->next);//kita akan print list selanjutnya
}

//untuk reverse print ini bisa lebih belajar tentang dynamic memory allocation
//yang dimana saat kita memanggil fungsi kita akan membuat bubble di stack yang dimana kita akan memanggil fungsi terus menerus hingga recursif habis
//ketika rekursif habis stack ini akan menghilangkan bubble yang dari terbelakang dulu
//setelah rekursif habis baru kita akan print datanya maka bisa reverse 
void Reverse_Print(Node *p)
{
	if(p == NULL) return;
	Reverse_Print(p->next);
	printf("%d", p->data);
}

//cara kerjanya hampir sama dengan yang reverse print
//bedanya disini kita ingin rekursif sampai list ini akan habis makanya dia exit condition menggunakan p->next
void Reverse_List(Node *p)
{
	//bila p->next == NULL maka kita akan menjalankan if
	if(p->next == NULL)
	{
		//kita akan ganti head menjadi p yang berarti list terakhir atau p akan menjadi head
		head = p;
		//pada saat ini p akan berada di list akhir dan return
		return;
		//karena list terakhir return maka kita nanti akan berada di list yang sebelum habis
		//jadi tidak akan menjalankan rekursif lagi  
	}
	//disini kita akan melakukan rekursif sampai list ini akan habis
	Reverse_List(p->next);
	//saat rekursif habis maka kita akan membuat variabel q yang berisi list terakhir
	Node *q = p->next;
	//kemudian kita mengganti next dari list tersebut ke list sebelumnya sehingga bisa akan reverse
	q->next = p;
	//setelah itu kita juga mengganti next dari list sebelumnya dengan null
	//disini menggunakan null karena bila rekursif maka null ini akan terbawa sampai akhir sehingga list terakhir akan mempunyai next berupa null
	p->next = NULL;
	//maka saat operasi ini selesai maka q akan menjadi list sebelumnya dan p menjadi list sesudahnya
}
