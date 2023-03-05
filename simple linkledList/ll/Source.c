#include<stdio.h>
#include<stdlib.h>

struct node {
	int x;
	struct node* next;
};

struct node* add(struct node* r, int x)
{
	
	if (r == NULL) {
		r = (struct node*)malloc(sizeof(struct node));
		r->x = x;
		r->next = NULL;
	}

	while (r != NULL) {
		r = r->next;
	}
	r->next = (struct node*)malloc(sizeof(struct node*));
	struct node* iter = r->next;
	iter->x = x;
	iter->next = NULL;
}
struct node* insert(int x,struct node* r) {

	struct node* temp = malloc(sizeof(struct node*));
	temp->x = x;
	temp->next = NULL;
	if (r != NULL) {
		temp->next = r;
	}
	r = temp;
}
void print(struct node* r) 
{
	while (r != NULL) {
		printf("%d\t", r->x);
		r = r->next;
	}
}

int main()
{
	struct node* root = NULL;
	
	root=add(root, 10);
	root=add(root, 20);
	root=add(root, 30);
	root=add(root, 40);
	root=add(root, 50);
	print(root);
	
}