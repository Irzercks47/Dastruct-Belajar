#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;	
}Node;

Node *head;
Node *GetNewNode(int x) {
	Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertAtHead(int x)
{
	Node *newNode = GetNewNode(x);
	//jika list kosong maka head akan diisi oleh newNode
	if(head == NULL) {
		head = newNode;
		return;
	}
	//bila tidak kosong maka prev list pertama yang awalnya Null kita ganti dengan alamt dari newNode
	head->prev = newNode;
	//kemudian next dari newNode kita ganti dengan list pertama
	newNode->next = head;
	//kemudian headnya kita ganti ke newNode
	head = newNode;
}

void Print()
{
	Node* temp = head;
	printf("forward: ");
	while(temp != NULL)
	{
		printf("%d ", temp->data);	
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint() {
	Node *temp = head;
	if(temp == NULL) return; //bila empty akan return
	//pertama kita akan pergi ke list terakhir
	while(temp->next != NULL) {
		temp = temp->next;
	}
	printf("reverse: ");
	//kita akan pergi ke list pertama karena disini dubly maka kita bisa langasung menggunakan prev
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void InsertAtNth(int x, int pos) {
	//kita buat newNode
	Node *newNode = GetNewNode(x);
	//kemudian assign head ke temp
	Node *temp = head;
	//bila head null maka head akan diisi dengan alamat newNode
	if(head == NULL) {
		head = newNode;
		return;		
	}
	//jika minta di posisi 1 maka prev dri list pertama akan kita arahkan ke newNode 
	//kemudian nex dari newNode ini akan kita isi dengan alamat ke list pertama
	//kemudian kita mengganti head dengan alamat newNode  
	if(pos == 1){
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		return;
	}
	int i;
	//untuk insert yang membutuhkan posisi kita menggunakan for
	//tujuan nya disini adalah mencapai list yang posisi tang sebelumnya penjelasan lengkap di insertnth kenapa menggunakan -2
	//kemudian kita juga menambah temp->next != NULL untuk mengecek apabila sudah mencapai list terakhir bila iya maka loop akan berakhir
	for(i = 0; i < pos - 2 && temp->next != NULL; i++){
		//pindah list
		temp = temp->next;
	}
	//bila temp sudah sampai posisi maka kita ingin mengisi prev dari newNode dengan alamat list sebelumnya
	newNode->prev = temp;
	//kemudian kita akan mengisi next dari newNode dengan temp->next mengapa mengambil dari temp->next karena kita mengganti posisi temp dengan newNode maka next dari newNode menggunakan next dari temp
	newNode->next = temp->next;
	//kemudian setelah kita mensetting newNode maka kita bisa fokus ke temp
	//karena list selanjutnya dari temp berganti maka kita perlu mengganti alamat yang ada di next nya temp dengan newNode 
	temp->next = newNode;
	//disini kita melakukan pengecekan terhadap next dari newNode yang telah di insert apabila next tidak sama dengan null maka if ini akan berjalan
	if(newNode->next != NULL) {		
		//bila next tidak sama dengan null maka kita ingin mengganti prev dari list selanjutnya dengan newNode
		//NB: newNode->next->prev berarti kita ingin mengakses prev dari list setelah newNode 
		newNode->next->prev = newNode;
	}
}

void InsertAtTail(int x) {
	Node *newNode = GetNewNode(x);
	Node *temp = head;
	//kita akan looping sampai mencapai list terakhir
	while(temp->next != NULL) {
		temp = temp->next;
	}
	//bila sudah sampai maka kita ingin mengisi prev dari newNode dengan temp yang merupakan list terakhir
	newNode->prev = temp;
	//dan kita ingin mengganti next dari list terakhir dengan newNode
	temp->next = newNode;
}

int main()
{
	InsertAtHead(2);Print();ReversePrint();
	InsertAtHead(4);Print();ReversePrint();
	InsertAtHead(6);Print();ReversePrint();
	InsertAtTail(7);Print();
	InsertAtNth(8, 2); Print();
	InsertAtNth(1, 8); Print();
	return 0;
}
