#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4

int x[MAX_SIZE];
int head = -1;
int tail = -1;

//bila tail dan head berada di index -1 berarti array sedang kosong
int isEmpty(){
	if(head == -1 && tail == -1){
		//true
		return 0;
	}
	//false
	return 1;
}
//dalam enqueu kita bisa menggunakan modulus agar array ini membetuk lingkaran dalam logical view
//fungsi berbentuk lingkaran ini adalah agar memory di array ini tidak bisa habis bila kita enqueue dan dequeque secara terus menerus
void Enqueue(int n){
	//jika tail sama denagan head berarti array seadang full
	if((tail + 1) % MAX_SIZE == head){
		printf("Queue is full \n");
		return;
	}
	//bila array empty maka dalam enqueue kita akan increment head dan tail agar array ada isinya
	if(isEmpty() == 0){
		head++; tail++;
	}
	//bila array sudah mempunyai isi maka kita akan increment tail yang kemudian di modulus dengan max_size agar array berbentuk lingkaran dalam logical view
	else{	
		tail++ % MAX_SIZE;
	}
	//kemudian n akan di insert diindex belakang atau tail
	x[tail] = n;
}

int Dequeue(){
	//kita akan simpan head secara sementara di variable temp
	int temp = head;
	//bila array kosong akan langsung di return
	if(isEmpty() == 0){
		printf("Queue is Empty \n");
		return;
	}
	//bila head sama dengan tail yang berarti array sedang berada di index pertama maka
	if(head == tail){
		//kita akan dicrement head dan tail disini karena casenya head dan tail berada pada index yang sama berarti head dan tail sama
		head = head - 1;
		tail = head;
	} else{
		//dalam array dequeque kita makan increment head supaya kita tidak bisa mengambil nilai dari index tersebut
		head++ % MAX_SIZE;
	}
	//kita akan return element yang di dequeque
	return x[temp];
}

//fungsi print array
void Print(){
	int i;
	printf("Queue: ");
	for(i = head; i <= tail; i++){		
		printf("%d", x[i]);
	}
	printf("\n");
}

int Front(){
	printf("%d", x[head]);
}

int main(){
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	Enqueue(6);
	Print();
	printf("head: %d\n", head);
	printf("tail: %d\n", tail);
	printf("dequeue: %d\n", Dequeue());
	Print();
	printf("isEmpty: %d\n",isEmpty());
	Front();
	return 0;
}

//NB: bila tidak ada looping maka queue ini memiliki time complexity o(1) yang berarti setiap fungsinya memiliki waktu konstan



