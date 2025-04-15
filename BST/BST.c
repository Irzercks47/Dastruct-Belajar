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

//dalam insert lebih enak menggunakan recursion karena lebih efisien digunakan karena kita langsung bisa memilih posisi bila bst
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

//dalam search ini cara kerjanya sama dengan insertion yaitu kita akan recurse sampai data yang dicari ini sama dengan atau tidak sama dengan data yang ada di bst
int Search(bst *root ,int data){
	//jika root null maka akan return false yang juga berarti data tidak ada
	if(root == NULL) return 0;
	//namun jika ditemukan data yang sama maka akan return true
	else if(root->data == data) return 1;
	//kita akan search ke kiri bila data ini lebih kecil atau sama dengan root data
	else if(data <= root->data) Search(root->left, data);
	//kita akan search ke kanan bila data ini lebih besar dari root data
	else Search(root->right, data);
}

//di funsgi ini kita akan mencari nilai min dari data
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

//traversal sesuai dengan level dari nodenya
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

int main(){
	bst *root = NULL;
	root = Insert(root, 10);
	root = Insert(root, 8);
	root = Insert(root, 12);
	root = Insert(root, 11);
	root = Insert(root, 14);
	root = Insert(root, 6);
	root = Insert(root, 7);
//	int number;
//	printf("Search Number: ");
//	scanf("%d", &number);
//	printf("\n");
//	if(Search(root, number) == 1) printf("Number found \n");
//	else printf("There is no such number \n");
	printf("Min Node is: %d \n", FindMin(root));
	printf("Max Node is: %d \n", FindMax(root));
	LevelOrder(root);
	return 0;
}


