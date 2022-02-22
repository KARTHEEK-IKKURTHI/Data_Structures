#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct copy
{
	int field;
	struct copy *ptr;
};

struct node *insert_at_begin(struct node *, int);
void display(struct node *);
void display_copied(struct copy *);
struct node *insert_at_end(struct node *, int);
struct node *insert_in_bw(struct node *, int);
int delete_node(struct node *,int );
int count_nodes(struct node *);
struct copy *copy_list(struct node *);

void main()
{
	struct node *AVAIL = NULL;
	struct copy *new_list = NULL;
	int x, flag=0, ch, c=0;

	while(flag != 1)
	{

		printf("Enter your choice:\n");
		printf("1.Insert at beginning\n2.Insert at end\n3.Insert in between\n4.Display\n5.Delete node\n6.Count nodes\n7.Copy linked list to create new\n8.quit\n\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter the value to insert:\n");
				scanf("%d",&x);
				AVAIL = insert_at_begin(AVAIL, x);
				break;
			case 2:
				printf("Enter Value to insert at end:\n");
				scanf("%d",&x);
				AVAIL = insert_at_end(AVAIL,x);
				break;
			case 3:
				printf("Enter Value to insert in between:\n");
				scanf("%d",&x);
				AVAIL = insert_in_bw(AVAIL,x);
				break;
			case 4:
				printf("ALL elements of linked list are:\n");
				display(AVAIL);
				break;
			case 5:
				printf("Enter element you want to delete\n");
				scanf("%d",&x);
				delete_node(AVAIL,x);
				break;
			case 6:
				c = count_nodes(AVAIL);
				printf("Number of nodes is/are:%d\n",c);
				break;
			case 7:
				new_list=copy_list(AVAIL);
				printf("New created linked list is:\n");
				display_copied(new_list);
				break;
			case 8:
				flag = 1;
				printf("Task Completed\n");
				break;
			default:
				printf("Enter valid choice\n");
		}
	}

}

struct node *insert_at_begin(struct node *AVAIL_ref, int value)
{

	struct node *new_node;

	new_node = (struct node *)malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		if(AVAIL_ref == NULL)
		{
			new_node->info = value;
			new_node->link = NULL;
			return new_node;
		}
		else
		{
			new_node->info = value;
			new_node->link = AVAIL_ref;
			return new_node;
		}
	}
}

void display(struct node *first)
{
	struct node *save;
	save = first;

	while(save!=NULL)
	{
		printf("%d\n",save->info);
		save = save->link;
	}
}

void display_copied(struct copy *begin)
{
	struct copy *save;
	save = begin;

	while(save != NULL)
	{
		printf("%d\n",save->field);
		save = save->ptr;
	}
}

struct node *insert_at_end(struct node *AVAIL_ref, int value)
{
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	struct node *save;

	if(new_node == NULL)
	{
		printf("Overflow\n");
		}
	else
	{
		if(AVAIL_ref == NULL)
		{
			new_node->info = value;
			new_node->link = NULL;
			return new_node;
		}
		else
		{
			new_node->info = value;
			new_node->link = NULL;

			save = AVAIL_ref;
			while(save->link != NULL)
			{
				save = save->link;
			}
			save->link = new_node;
			return AVAIL_ref;
		}
	}
}

struct node *insert_in_bw(struct node *AVAIL_ref, int value)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *save;

	if(new_node == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		new_node->info = value;

		if(AVAIL_ref == NULL)
		{
			new_node->link = NULL;
			return new_node;
		}
		else
		{
			if(new_node->info <= AVAIL_ref->info)
			{
				new_node->link = AVAIL_ref;	
				return new_node;
			}
			else
			{
				save = AVAIL_ref;
				while(save->link != NULL && new_node->info >= save->link->info)
				{
					save = save->link;
				}
				
				new_node->link = save->link;
				save->link = new_node;
				return AVAIL_ref;
			}
		}
	}
}

int delete_node(struct node *first, int value)
{
	struct node *save = (struct node *)malloc(sizeof(struct node));
	struct node *pred = (struct node *)malloc(sizeof(struct node));

	if(first == NULL)
	{
		printf("Underflow\n");
		return -1;
	}
	else
	{
		save = first;

		while(save->info != value && save != NULL)
		{
			pred = save;
			save = save->link;
		}

		if(save->info != value)
		{
			printf("Node not found\n");
			return -1;
		}

		if(value == first->info)
		{
			first = first->link;
		}
		else
		{
			pred->link = save->link;
		}

		free(save);
		return 0;
	}

}

int count_nodes(struct node *first)
{
	struct node *save = (struct node *)malloc(sizeof(struct node));
	int count=0;

	if(first == NULL)
	{
		printf("Underflow\n");
		return count;
	}
	else
	{
		save = first;
		while(save->link != NULL)
		{
			save = save->link;
			count = count + 1;
		}
		count++;
		return count;
	}	
}

struct copy *copy_list(struct node *first)
{
	struct node *save = (struct node *)malloc(sizeof(struct node));
	struct copy *begin = NULL;
	struct copy *pred =  (struct copy *)malloc(sizeof(struct node));
	
	if(first == NULL)
	{
		printf("List Underflow\n");
		return NULL;
	}
	else
	{
		
	
		begin = (struct copy *)malloc(sizeof(struct node));

		begin->field = first->info;
		begin->ptr = NULL;
		pred = begin;
		

		save = first;
		while(save->link != NULL)
		{
			save = save->link;
			struct copy *new_node = (struct copy *)malloc(sizeof(struct node));


			new_node->field = save->info;
			new_node->ptr = NULL;
			pred->ptr = new_node;
			pred = new_node;
		}
		return begin;
	}
