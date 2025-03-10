#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;

void Insert(int x) 
{
	//akan membuat block node atau alokasi memory untuk node dengan menggunakan malloc
	//malloc(sizeof(Struct Node)) ini akan return pointer namun karena malloc return void maka untuk menggunakan typecast dengan (struct Node*) supaya return pointernya
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	//kita bisa menggunakan (*temp).data untuk dereference nodenya namun bisa dipermudah dengan menggunakan temp->data
	temp->data = x;
	/***	
	//pada case ini insert didepan bagian ini bisa kita pangkas karena bila list kosong pasti head akan null dan head akan diisi alamat list baru namun bila list sudah ada isinya maka list yang baru akan mengambil alamat list pertama dan kemudian kita mengganti nilai head dengan value alamat list yang baru 
		//pada mulanya kita ingin next ini kosong karena memang belum mengetahui alamat dari list selanjutnya
		temp->next = NULL;
		//saat case insert di depan bila linked list ini memiliki isi saat kita insert maka next di list yang akan kita masukkan akan diganti dengan alamat list pertama sebelum kita insert
		if(head != NULL) temp->next = head;
	****/
	temp->next = head;
	//kemudian kita mengganti alamat di head dengan list yang akan kita masukkan 
	head = temp;
}

void Print() 
{
	//kita akan membuat block temp baru untuk traverse list kenapa membuat temp baru karena kita tidak ingin modify head bila termodify maka list akan hilang
	//jadi langkahnya adalah membuat variabel temp baru untuk store nilai head nanti yang akan di modify adalah temp ini
	struct Node* temp = head;
	printf("list is : ");
	//disini kita akan looping temp tersebut yang bila dimana temp ini tidak null maka akan print data
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		//kemudian setelah print data kita akan pindah ke list selanjutnya
		temp = temp->next;
	}
	printf("\n");
}

int main() 
{
	int i, n, x;
	head = NULL;
	printf("how many you want to store? \n");
	scanf("%d",&n);
	printf("\n");
	for(i = 0; i<n; i++ )
	{
		printf("Enter Number: \n");
		scanf("%d", &x);
		printf("\n");
		Insert(x);
		Print();
	}
	
	return 0;
	//NB:bila head merupakan variabel local dari main maka kita bisa memanggil seperti print(head)
	//kemudian kita bisa mengganti fungsi head dengan void print(struct Node* head)
	//kemudian kita bisa menghapus bagian ini struct Node* temp = head; dan mengganti temp dengan head karena bila kita passing kita tidak mengubah isi dari head
}

/**

//bedanya denga versi sebelumnya ada di struct Node* head; yang ada di local main
//kita harus menggunakan typedef karena bila tidak untuk setiap node kita harus mengetik struct dan membuat penulisan lebih rapi
typedef struct Node {
	int data;
	struct Node* next;
} Node;

//kemudian kita harus mengganti void menjadi Node *Insert karena kita memerlukan value return dari head di main karena head yang sudah local dan tidak global
Node *Insert(Node *head, int x) 
{
	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;
	return head;
}

//Print ini mengambil param Node *head
void Print(Node *head) 
{
	//karena kita mengambil param dan tidak mengubah head maka kita bisa langsung menggunakan head 
	printf("list is : ");
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() 
{
	int i, n, x;
	//disini kita harus declare head
	Node *head;
	printf("how many you want to store? \n");
	scanf("%d",&n);
	printf("\n");
	for(i = 0; i<n; i++ )
	{
		printf("Enter Number: \n");
		scanf("%d", &x);
		printf("\n");
		//kita harus assign insert lagi ke head supaya value head bisa diganti
		head = Insert(head, x);
		Print(head);
	}
	
	return 0;
}
**/
