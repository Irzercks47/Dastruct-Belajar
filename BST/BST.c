#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

//dalam struct nya menggunakan nama diatas
typedef struct BstNodes{
	int data;
	struct BstNodes *left;
	struct BstNodes *right;
}bst;

//membuat node baru
bst* GetNewNode(int data){
	bst *newNode = (bst*)malloc(sizeof(bst));
	newNode->data = data;
	newNode->right = newNode->left = NULL;
	return newNode;
}

// Fungsi Insert untuk memasukkan data ke dalam BST
// Menggunakan rekursi karena:
// 1. Mempermudah navigasi ke posisi yang tepat dalam tree.
// 2. Tidak perlu menyimpan node saat traversal karena fungsi akan memanggil dirinya sendiri.
bst* Insert(bst *root, int data){
	//jika node kosong makan kita akan melakukan insertion
	if(root == NULL){
		root = GetNewNode(data);
	}
	//bila data kurang dari sama dengan data root maka kita akan ke kiri
	else if(data <= root->data){
		//akan melakukan recurse terus sampai mendapat node kosong
		root->left = Insert(root->left, data);
	}
	//jika data ini lebih besar dari root data maka dia akan ke kanan
	else{
		//akan melakukan recurse terus sampai mendapat node kosong
		root->right = Insert(root->right,data);
	}
	//kita akan return rootnya karena root ini bukan variable global
	return root;
}

// Fungsi Search mencari data di dalam BST
// Prinsipnya mirip dengan Insert:
// - Jika data lebih kecil dari sama dengan root->data maka lanjut ke kiri
// - Jika data lebih besar root->data maka lanjut ke kanan
// - Jika sama maka data sudah ditemukan
int Search(bst *root ,int data){
	//jika root null maka akan return false yang juga berarti data tidak ada
	if(root == NULL) return 0;
	//namun jika ditemukan data yang sama maka akan return true
	//bila return node kita akan return rootnya
	else if(root->data == data) return 1;
	//kita akan search ke kiri bila data ini lebih kecil atau sama dengan root data
	else if(data <= root->data) Search(root->left, data);
	//kita akan search ke kanan bila data ini lebih besar dari root data
	else Search(root->right, data);
}

bst* Find(bst *root ,int data){
	//jika root null maka akan return false yang juga berarti data tidak ada
	if(root == NULL) return 0;
	//namun jika ditemukan data yang sama maka akan return true
	//bila return node kita akan return rootnya
	else if(root->data == data) return root;
	//kita akan search ke kiri bila data ini lebih kecil atau sama dengan root data
	else if(data <= root->data) Search(root->left, data);
	//kita akan search ke kanan bila data ini lebih besar dari root data
	else Search(root->right, data);
}

//di fungsi ini kita akan mencari nilai min dari data
int FindMin(bst *root){
	//bila root null atau kosong maka kita akan return 0 dan ada message root is null atau bisa kita sebut tree kosong
	if(root == NULL){
		printf("Root is null");
		return 0;
	}
//	//menggunakan looping
//	while(root->left != NULL){
//		root = root->left;
//	}
//	return root->data;

	//menggunakan rekursi
	//untuk cara rekursi ini kita akan traverse bagian paling kiri terus karena bst sendiri memiliki ciri khas data yang kecil akan ditaruh dibagian kiri
	else if(root->left == NULL){
		//bila root left sudah habis maka kita akan return data dari root itu
		return root->data;
	}
	//bila node belum habis kita akan memanggil FindMin terus
	return FindMin(root->left);
}

bst* FindMinimal(bst *root){
	if(root == NULL) return NULL;
	else if(root->left == NULL){
		return root;
	}
	return FindMin(root->left);
}

//di funsgi ini kita akan mencari nilai max dari data
int FindMax(bst *root){
	if(root == NULL){
		printf("Root is null");
		return 0;
	}
	//menggunakan looping
	//bila menggunakan looping maka kita akan looping sama right nya ini habis
	while(root->right != NULL){
		//disini kita akan mengganti root dengan root right yang gunanya untuk traversal
		root = root->right;
	}
	//bila looping selesai maka kita akan return data dari root atau node terakhir
	return root->data;
	//menggunakan rekursif
//	else if(root->right == NULL){
//		return root->data;
//	}
//	return FindMax(root->right);
}

//disini kita akan memanfaatkan recursif untuk traversal semua node yang ada di bst maka dari itu time complexity dari funsgi ini adalah o(n)
// Fungsi untuk menghitung tinggi (height) dari BST
// Height dihitung berdasarkan jumlah **edge** dari root ke leaf terdalam
// - Base case: jika node kosong maka kita akan return -1
// - Setiap node akan return nilai max dari anak kiri dan kanan, ditambah 1
// - jika merupakan leaf node maka akan mengembalikan 0
int FindHeight(bst* root){
	//disini bila kita sudah mencapai leaf node atau node yang tidak mempunyai anak akan kita return dengan -1
	//tujuan mengapa menggunakan -1 adalah karena di fmax sudah di +1 maka nilai leaf node ini nanti akan 0 namun bila kita return 0 maka nilai leaf node akan 1 sehingga kita akan menghitung leaf node ini
	//pada height ini kita mencari edges bukan total nodes
	if(root == NULL) return -1;
	//untuk penghitungannya sendiri kenapa tidak menggunakan counter adalah karena disini menghitungnya dengan akumulasi fmax
	//yang dimaksud adalah ada parent yang memiliki 2 anak yang dimana 2 anak ini leafnode maka karena disini kita mulai dari kiri prioritasnya
	//dikiri karena leafnode maka akan return 0 karena -1 + 1 adalah 0 sehingga edges dikiri ini adalah 0 maka kita akan cek juga dibagian kanan nah ternyata return juga 0 karena fmax(kiri, kanan) + 1 maka jadi (0, 0) + 1 = 1 maka parent node ini memiliki bobot 1
	//bila kita ke grandparent nya maka nanti dikiri ini akan return 1 dan bila kanan ini sama seperti kiri maka akan return 1 juga jadi fmax dari grandparent adalah (1, 1) + 1 = 2 sampai naik ke rootnya akan diambil bobot terbesar dan ditambahkan 1
	return fmax(FindHeight(root->left), FindHeight(root->right)) + 1;
}

//traversal sesuai dengan level dari nodenya atau bisa disebut bredth first
//cara kerjanya adalah kita menggunakan queue yang dimana kita akan menyimpan semua alamat node di queue kemudian kita akan gunakan node yang ada di head untuk mengambil alamat yang ada di left dan right kemudian bila dua alamat ini sudah diambil maka kita akan dequeue headnya
//disini kita bisa menggunakan linked list dan array untuk inisiasi queue nya
// Fungsi LevelOrder (Breadth First Search):
// - Menggunakan queue berbasis array (q[])
// - Simpan pointer node dalam bentuk uintptr_t disini kita perlu casting isi dari q[] ke uintptr_t
// - Proses:
//   1. Tambahkan root ke queue
//   2. Selama queue tidak kosong:
//      - Ambil node dari head
//      - Cetak data
//      - Masukkan anak kiri dan kanan (jika ada) ke queue
void LevelOrder(bst *root){
	//bila root kosong berarti bst kosong jadi akan return null
	if(root == NULL){
		printf("Root is null");
		return;
	}
	//Tipe uintptr_t memungkinkan kita menyimpan pointer (bst*) sebagai angka.
	uintptr_t q[100];
	//karena disini menggunakan queue yang dimana insertion dari tail dan deletion dari head
	int tail = 0,head = 0;
	//kita akan masukkan root kedalam queue tail dengan root dan juga kita perlu increment tail karena sudah ada insertion
	q[tail++] = (uintptr_t)root;
	printf("BST: ");
	//menggunakan head < tail karena tail ini menggambarkan isi dari queue jadi bila head kurang dari tail maka artinya queue msih ada isinya
	while (head < tail){
		//kita masukkan pointer yang ada di head untuk melakukan traversal dan sebagai penanda posisi kita
		bst *curr = (bst*)q[head++];
		printf("%d ", curr->data);
		//bila left dari curr ada maka
		if(curr->left != NULL) {
			//kita akan melakukan insertion di queue dan jangan lupa untuk increment pada tail sebagai pertanda adanya insertion
 			q[tail++] = (uintptr_t)curr->left;
		}
		//bila right dari curr ada maka
		if(curr->right != NULL) {
			//kita akan melakukan insertion di queue dan jangan lupa untuk increment pada tail sebagai pertanda adanya insertion
			q[tail++] = (uintptr_t)curr->right;
		}
	}
	printf("\n");
}

//dalam depth traversal ini printf ini bisa kita misalkan sebagai root
//preorder -> root left right, karena mulai dari root sehingga kita bisa menaruh printf dlu baru rekursi kiri dan kekanan
//printf ini juga bisa berarti node sudah dikunjungi PreOrder(root->left) kalau hanya dengan ini belum berarti sudah dikunjungi namun sudah kita lewati
void PreOrder(bst *root){
	if(root == NULL) return;
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//inorder -> left root right, karena mulai dari left sehingga kita bisa menaruh rekursi kiri dlu baru printf kemudian rekursi ke kanan
void InOrder(bst *root){
	if(root == NULL) return;	
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//inorder -> left right root, karena mulai dari left sehingga kita bisa menaruh rekursi kiri dlu baru rekursi ke kanan kemudian printf 
void PostOrder(bst* root){
	if(root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

//mengecek apakah tree ini bst
//jadi cara kerjanya adalah kita akan mengecek apalah value dari root->data ini sesuai dengan rentan dari min dan max value
//untuk membangdingkan root kita menggunakan min dan max dari integer
int BstUtil(bst *root, int minValue, int maxValue){
	//bila tree dan subtree ini kosong maka kita akan return true
	if(root == NULL) return 1;
	//bila root->data ini lebih besar dari min dan lebih kecil dari max
	if(root->data >= minValue && root->data <= maxValue
		//dan disini kita akan lakukan rekursi dengan dengan memanggil BstUtil(root->left, minValue, root->data) dalam case ini karena kita ke node kiri maka kita akan memanggil fungsi BstUtil(alamat left, minValue, 10)
		//kemudian kita akan mengecek if(root->data >= minValue && root->data <= maxValue) karena kita sudah pindah node yang memiliki data 8 sehingga if ini akan menjadi if(8 >= minValue && 8 <= 10) yang dimana adalah true untuk selanjutnya cara kerjanya sama seperti ini tinggal kita mengganti nilai saja
	 	&& BstUtil(root->left, minValue, root->data)
	 	//bagian ini cara kerjanya sama dengan diatas
		&& BstUtil(root->right, root->data, maxValue))
			//bila sudah memenuhi semua persyaratan diatas maka akan return true
			return 1;
	//sebaliknya akan return false
	else return 0;
	//jadi dia akan akumulasi semua returnnya dari root ke subtree hingga ke leaf node bila semua return true maka tree adalah bst
	//bila misal ada yang tidak sesuai maka dia akan return false
}

//memudahkan dalam pemanggilan fungsi pengecekan bst
int IsBst(bst *root){
	return BstUtil(root, INT_MIN, INT_MAX);
}

//delete node di bst
// Fungsi Delete untuk menghapus node dari BST
// Terdapat 3 kemungkinan kasus:
// 1. Node tidak memiliki anak (leaf) maka langsung dihapus
// 2. Node memiliki satu anak maka ganti node dengan anaknya
// 3. Node memiliki dua anak:
//    - Ambil nilai **terkecil dari subtree kanan**
//    - Ganti nilai node dengan nilai tersebut
//    - Hapus node yang berisi nilai pengganti tadi (leaf)
bst* Delete(bst* root, int data){
	//bila root null akan return root atau null karena disini root = null
	if(root == NULL) return root;
	//bila data ini lebih kecil dari data yang ada di root maka akan ke kiri
	//guna dari menyimpan ke root->left ini adalah bila node yang ditemukan di kiri maka kita bisa simpan state setelah dirubah
	//nb: Setiap kali kita melakukan perubahan pada subtree melalui rekursi maka harus menyimpan kembali ke parent-nya.
	else if(data < root->data) root->left = Delete(root->left, data);
	//yang bagian ini sama seperti diatas
	else if(data > root->data) root->right = Delete(root->right, data);
	else{ //ketika sudah menemukan datanya
		//case 1: tidak punya child
		//bila tidak punya child kita bisa langsung hapus nodenya
		if(root->left == NULL && root->right == NULL) {
			//kita free rootnya
			free(root);
			//jadi root harus di null kan karena bila di null tetap akan ada alamatnya namun sudah tidak ada isinya supaya kita tidak ke root yang sudah di free-kan maka root harus di assign null
			root = NULL;
		}
		//case 2: satu anak
		//untuk satu anak ini kita bisa mengganti koneksi dari root yang akan dihapus ke anaknya 
		else if(root->left == NULL){
			//root akan di assign di temp
			bst *temp = root;
			//kemudian root yang akan dihapus ini akan kita ganti dengan yang ada di right
			root = root->right;
			//kemudian nilai root yang akan dihapus kita hapus
			free(temp);
		}
		//cara kerja yang ini sama dengan yang diatas cuma disini bila yang dihapus ada di kiri
		else if(root->right == NULL){
			bst *temp = root;
			root = root->left;
			free(temp);
		}
		//case 3: bila punya 2 anak
		else{
			//kita akan mencari nilai anaknya yang paling kecil
			//kenapa meskipun anaknya tidak ada yang dikiri disini bisa mendapatkan min karena else ini aka ke recurse juga hingga node habis sehingga nanti akan menemukan nilai min
			int temp = FindMin(root->right);
			//nilai yang ingin dihapus kita ganti dengan nilai yang paling kecil
			//nb: kenapa di case ini nodenya tidak di hapus karena dia memiliki 2 anak bila kita hapus nodenya maka struktur akan hancur dan banyak data akan hilang atau tidak bisa diakses
			root->data = temp;
			//kemudian karena disini kita menggunakan variasi yang dimana untuk mengganti nilai yang dihapus adalah dengan mengambil nilai min dari subtree kanan maka kita harus delete subtree di kanan
			//nb: satu variasi lagi adalah dengan mengambil nilai max dari subtree kiri kenapa kita mencari nilai min dan max ini karena nilai ini itu pasti merupakan leaf node sehingga bila dihapus tidak akan ada masalah
			//beda dengan yang memiliki 2 anak bila node mereka dihapus maka bst akan rusak 
			root->right = Delete(root->right, temp);
		}
	}
	return root;
}

bst* GetInorderSuccessor(bst *root, int data){
	//mencari posisi dari data
	bst *curr = Find(root, data);
	//bila tidak ditemukan maka tree kosong
	if(curr == NULL) return NULL;
	//case 1: jika node punya right
	if(curr->right != NULL){
		//bila menggunakan looping bisa seperti ini 
		//bst *temp = curr;
		//while(curr->left != NULL){
			//temp = temp->left;
			//return temp;
			//akan return rekursi terus sampai menemukan nilai minimal di kanan
			//Successor adalah nilai terkecil di subtree kanan
			return FindMinimal(curr->right);
		}
	}
	//case 2: bila tidak ada right
	//1.Mulai dari root (karena kita perlu akses ke seluruh ancestor).
	//2.Bandingkan curr->data dengan ancestor->data:
	//3.Kalau curr->data < ancestor->data, berarti kita sedang berada di subtree kiri, jadi ancestor ini bisa jadi successor! ? simpan ke successor, lalu lanjut ke kiri
	//4.Kalau curr->data >= ancestor->data, berarti kita masih harus ke kanan (tidak bisa jadi successor)
	//5.Ulangi sampai kita menemukan node curr (alias node target)	
	Return kandidat successor terakhir yang tersimpan.
	else{
		//kita bikin variabel untuk menyimpan sucessor
		bst* successor;
		//kemudian bikin variabel untuk menyimpan karena disini tidak punya right maka kita harus simpan semua ancestor disini kita muali dari root
		//maksud ancestor disini adalah node yang posisinya diatas dari curr
		bst* ancestor = root;
		//ketika ancestor atau root ini tidak sama dengan curr maka
		//nb: curr merupakan data yang ingin kita cari successornya
		//jadi disini kita tidak ingin ancestor nya ini sama dengan curr
		// Kita traversal dari root menuju node 'curr'
		while(ancestor != curr){
			//bila data curr ini lebih kecil dari ancestor
			// disini artinya kita berjalan ke subtree kiri, jadi kandidat ancestor bisa jadi successor
			if(curr->data < ancestor->data){
				//bila data dari curr kurang dari ancestor kita ingin simpan ancestor itu di successor
				successor = ancestor;
				//kemudian kita akan pindah lagi ke kiri untuk mencari mengecek ancestor lain
				ancestor = ancestor->left;	
			}
			//bila data dari ancestor ini lebih kecil maka kita akan pindah ke kanan untuk mencari data yang mempunyai nilai lebih besar dari ancestor
			// kita berada di subtree kanan, jadi tidak bisa jadi successor
			else{
				ancestor = ancestor->right;
			}
		}
		//bila loop sudah selesai maka kita akan return
		return successor;
	}
	
}
//nb: 
//Predecessor adalah Node terbesar yang lebih kecil dari node saat ini.Letaknya di subtree kiri paling kanan.
//Successor adalah Node terkecil yang lebih besar dari node saat ini. Letaknya di subtree kanan paling kiri.

//nb: fungsi yang memiliki time complexity O(h) adalah fungsi yang menelusuri dari root ke leaf
//bila yang memiliki waktu O(n) adalah yang traversal ke seluruh node bst
int main(){
	bst *root = NULL;
//	root = Insert(root, 10);
//	root = Insert(root, 8);
//	root = Insert(root, 12);
//	root = Insert(root, 11);
//	root = Insert(root, 14);
//	root = Insert(root, 6);
//	root = Insert(root, 7);
	root = Insert(root, 50);
	root = Insert(root, 30);
	root = Insert(root, 70);
	root = Insert(root, 20);
	root = Insert(root, 40);
	root = Insert(root, 60);
	root = Insert(root, 80);
	root = Insert(root, 10);
	root = Insert(root, 25);
	root = Insert(root, 35);
	root = Insert(root, 45);
	root = Insert(root, 55);
	root = Insert(root, 65);
	root = Insert(root, 75);
	root = Insert(root, 90);
//	int number;
//	printf("Search Number: ");
//	scanf("%d", &number);
//	printf("\n");
//	if(Search(root, number) == 1) printf("Number found \n");
//	else printf("There is no such number \n");
	printf("Min Node is: %d \n", FindMin(root));
	printf("Max Node is: %d \n", FindMax(root));
	LevelOrder(root);
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	if(IsBst(root) == 0){
		printf("tree is not bst \n");
	}
	else printf("tree is bst \n");
	root = Delete(root, 70);
	InOrder(root);
	return 0;
}


