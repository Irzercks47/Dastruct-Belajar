#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void Push(int x) {
	//jika topnya punya nilai yang sama dengan MAX_SIZE maka array akan overflow
	if(top == MAX_SIZE) {
		printf("STACK OVERFLOW");
		return;
	}
	//kita akan assign x di index top
	//cara kerjanya disini top akan increment sebelum kita assign value x
	stack[++top] = x;
}

void Pop() {
	//jika topnya memiliki nilai -1 berarti stack ini kosong
	if(top == -1){
		printf("THERE IS NO ELEMENT");
	}
	//untuk pop cukup kita decrement saja topnya karena
	//bila kita lakukan push maka nilai yang ada di index tersebut akan di overwrite
	//contoh bila top sudah di angka 2 dengan nilai 5 bila kita lakukan pop maka top akan di index 1 yang misalkan memiliki nilai 3
	//maka nilai yang di index 2 masih tetap akan ada di array namun kita tidak bisa akses karena stack menggunakan top jadi index 2 ini tidak akan berguna
	//lalu misalkan kita push x dengan nilai 4 maka dia akan push di index 2 karena top sebelumnya adalah 1 sehingga nilai di inex 2 yang awalnya 5 akan diganti dengan 4
	top--;
}

int Top() {
	//untuk mengambil top tinggal kita panggil stack dengan index top
	return stack[top];
}

void Print() {
	int i;
	printf("STACK: ");
	for(i = 0; i <= top; i++){
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int main() {
	Push(2);Print();
	Push(3);Print();
	Push(4);Print();
	Pop();Print();
	Push(5);Print();
	return 0;
}
