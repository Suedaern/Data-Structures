#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int top = -1;
int array[MAX_SIZE];
int front = -1, rear = -1;
int array1[MAX_SIZE];

void enQueue(int x)
{
	if (rear == MAX_SIZE - 1)
		printf("kuyruk dolu\n");
	else
	{
		rear = rear + 1;
		array1[rear] = x;
	}
}

void push(int element)
{
	if (top == MAX_SIZE - 1)
	{
		printf("ERROR! STACK OVERFLOW\n");
		return;
	}
	top = top + 1;  // array[++top]=element; tek satýrda ayný iþlemi yaptý
	array[top] = element;
	printf("%d added to stack\n", element);
}
void pop()
{
	if (top == -1)
	{
		printf("stack bos");
		return;
	}
	enQueue(array[top]);
	top = top - 1;
}
int Top()
{
	return array[top];
}

int isEmpty()
{
	if (top == -1)
		return 1; //true dönüyo
	else
		return 0; // false dönüyo
}
void print()
{
	int i;
	printf("Stack:");
	for (i = 0; i <= top; i++) //eþitlik koymayýnca en son elemaný yazmýyo.
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}


int main(int argc, char* argv[])
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	print();
	//printf("top element : %d\n", Top());
	//pop();
	print();
	printf("top element : %d\n", Top());


	return 0;
}










