#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

int front = -1;
int rear = -1;
int array[MAX_SIZE];

int isEmpty()
{
	if (front == -1 && rear == -1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if (rear == MAX_SIZE - 1)
		return 1;
	else
		return 0;
}void enQueue(int x)
{
	if (isFull()) //
	{
		printf("dizi dolu\n");
	}
	else if (isEmpty())
		front = rear = 0;
	else
		//rear = rear + 1;
	array[++rear] = x;
}
void deQueue() //pop
{
	if (isEmpty())
		printf("dizi bos\n");
	else if (front == rear)
		front = rear = -1;
	else
		front = front + 1;//ilk giren ilk çýktýðý için frontu bir geriye kaydýrýyo
}
void print()
{
	int i;
	printf("queue:\t");
	for (i = front; i <= rear; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}


int main()
{
	enQueue(61);
	//enQueue(55);
	//enQueue(52);
	//enQueue(8);
	print();
	deQueue();
	deQueue();
	deQueue();
	//print();
	return 0;

}
