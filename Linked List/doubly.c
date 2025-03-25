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

void DeleteAtHead() {
	//bila head null maka akan return
	if(head == NULL) {
		return;
	}
	//kita assign head di temp
	Node *temp = head;
	//kita akan ganti alamat di head dengan next yang ada di temp
	head = temp->next;
	//kita hapus temp
	free(temp);
	//karena temp->next tadi sudah menjadi head maka kita perlu mengganti prev menjadi NULL supaya tidak mengarah ke alamat yang sudah tidak dipakai 
	head->prev = NULL;
}

void DeleteAtTail() {
	//bila head null maka akan return
	if(head == NULL) {
		return;
	}
	//kita assign head di temp
	Node *temp = head;
	//kita akan looping sampai list terakhir
	while(temp->next != NULL){
		temp = temp->next;
	}
	//jika temp->prev == NULL atau tail merupakan satu"nya list di doubly maka
	if(temp->prev == NULL){
		//head kita null kan
		head = NULL;
		//kemudian temp kita free
		free(temp);
		return;
	}
	//namun bila tail ini bukan list satu"nya maka
	//next dari list sebelum temp akan kita ganti dengan null karena bila tail didelete maka next dari list sebelum temp akan null
	temp->prev->next = NULL;
	//kemudian temp kita free
	free(temp);
}

void DeleteAtNth(int pos){
	//kita assign head di temp
	Node *temp = head;
	//bila head null maka akan return
	if(head == NULL) {
		return;
	}
	//jika pos sama dengan 1
	if(pos == 1){
		//kita akan ganti alamat di head dengan next yang ada di temp
		head = temp->next;
		//kemudian temp kita free
		free(temp);
		//karena temp->next tadi sudah menjadi head maka kita perlu mengganti prev menjadi NULL supaya tidak mengarah ke alamat yang sudah tidak dipakai
		head->prev = NULL;
		return;
	}
	int i;
	//kita ingin mencapai list terakhir namun bila pos melebihi jumlah list maka looping akan berhenti di list terakhir
	for (i = 0; i < pos-2 && temp->next != NULL; i++){
		temp = temp->next;
	}
	//jika next dari temp null atau berada di list terakhir maka
	if(temp->next == NULL){
		//jika temp->prev == NULL atau tail merupakan satu"nya list di doubly maka
		if(temp->prev == NULL){
			//head kita ganti dengan null
			head = NULL;
			//kemudian temp kita free
			free(temp);
			return;
		}
		//namun bila tail ini bukan list satu"nya maka
		//next dari list sebelum temp akan kita ganti dengan null karena bila tail didelete maka next dari list sebelum temp akan null
		temp->prev->next = NULL;
		//kemudian temp kita free
		free(temp);
		return;
	}
	//jika list yang akan dihapus berada diantara 2 list maka
	//next dari list sebelum temp akan kita ganti dengan alamat yang ada di next dari temp karena kita akan menghapus temp
	temp->prev->next = temp->next;
	//kemudian prev dari list selanjutnya dari temp akan kita ganti dengan prev dari temp karena kita akan menghapus temp
	temp->next->prev = temp->prev;
	//kita mengganti alamat yang ada di next dari list sebelum temp dan prev dari list selanjutnya dari temp supaya kita bisa menggabungkan list sebelum dan sesudah temp 
	//kemudian temp kita free
	free(temp);
}

int main()
{
	InsertAtHead(2);Print();ReversePrint();
	InsertAtHead(4);Print();ReversePrint();
	InsertAtHead(6);Print();ReversePrint();
	InsertAtTail(7);Print();
	InsertAtNth(8, 2); Print();
	InsertAtNth(1, 8); Print();
	DeleteAtHead();Print();
	DeleteAtTail();Print();
	DeleteAtNth(10);Print();
	return 0;
}
