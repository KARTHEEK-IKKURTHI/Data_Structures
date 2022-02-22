#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *lptr;
	struct node *rptr;
};

void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

void main()
{
	struct node *t, *a, *b, *c, *d, *e, *f, *g;

	a = (struct node *)malloc(sizeof(struct node));
	b = (struct node *)malloc(sizeof(struct node));
	c = (struct node *)malloc(sizeof(struct node));
	d = (struct node *)malloc(sizeof(struct node));
	e = (struct node *)malloc(sizeof(struct node));
	f = (struct node *)malloc(sizeof(struct node));
	g = (struct node *)malloc(sizeof(struct node));

	t = a;

	a->data = 'A';
	a->lptr = b;
	a->rptr = d;

	b->data = 'B';
	b->lptr = c;
	b->rptr = NULL;

	c->data = 'C';
	c->lptr = NULL;
	c->rptr = NULL;

	d->data = 'D';
	d->lptr = e;
	d->rptr = g;

	e->data = 'E';
	e->lptr = NULL;
	e->rptr = f;

	f->data = 'F';
	f->lptr = NULL;
	f->rptr = NULL;

	g->data = 'G';
	g->lptr = NULL;
	g->rptr = NULL;

	printf("pre order\n");
	preorder(t);
	printf("\nIn order\n");
	inorder(t);
	printf("\nPost Order\n");
	postorder(t);
	printf("\n");
}

void preorder(struct node *head)
{
	if(head == NULL)
	{
		printf("Empty Tree!!\n");
	}
	else
	{
		printf("%c ",head->data);
	}

	if(head->lptr != NULL)
	{
		preorder(head->lptr);
	}

	if(head->rptr != NULL)
	{
		preorder(head->rptr);
	}

	}

void inorder(struct node *head)
{
	
	if(head == NULL)
	{
		printf("Empty Tree!!\n");
	}

	if(head->lptr != NULL)
	{
		printf("\nhead->lptr: %c \n",head->lptr->data);
		inorder(head->lptr);
	}

	printf("Value of head : %c \n",head->data);

	if(head->rptr != NULL)
	{
		printf("\nhead->rptr: %c \n",head->rptr->data);
		inorder(head->rptr);
	}	

	
}

void postorder(struct node *head)
{
	if(head == NULL)
	{
		printf("Empty Tree!!\n");
	}

	if(head->lptr != NULL)
	{
		postorder(head->lptr);
	}

	if(head->rptr != NULL)
	{
		postorder(head->rptr);
	}

	printf("%c ",head->data);
}
