#include<stdio.h>
#include<stdlib.h>
#include<process.h>

typedef struct list{
	int x;
	struct list *next;
}node;
//node *head=NULL;
node* create(int e)
{
	node *n;
	n=(node*)malloc(sizeof(node));
	if(n==NULL)
		{
			printf("Node not created");
			exit(0);
		}
	n->x=e;
	n->next=NULL;
	return n;
}

node* insert(node *head)
{
	int e;
	fflush(stdin);
	printf("Enter the element:");
	scanf("%d",&e);
	node *newnode=create(e);
	if(head==NULL)
		head=newnode;
	else
		{
			node *t=head;
			//t=head;
			while(t->next!=NULL)
				t=t->next;
			t->next=newnode;
		}
	return head;
}


void printlist(node *head)
{
	node *t=head;
	while(t!=NULL)
		{
			printf("%d",t->x);
			if(t->next!=NULL)
				printf("->");
			t=t->next;
		}
}

node* recreverse(node *head)
{
	node *t=head;
	if(t->next->next==NULL)
		{
			//node *temp;
			//temp=t->next;
			t->next->next=t;
			t=t->next;
			t->next->next=NULL;
			return t;
		}
		node *temp,*z;
		temp=recreverse(t->next);
		z=t->next;
		t->next=t->next->next;
		z->next=t;
		t=temp;
		/*while(temp->next!=NULL)
			temp=temp->next;
		temp->next=t;*/
		return t;
}
	
int main()
{
	node *head=NULL;
	int c;
	printf("press\n1.enter element\n2.display\n3.reverse\n4.exit");
	while(1)
	{
		printf("\nChoice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:head=insert(head);
				break;
			case 2:printlist(head);
				break;
			case 3:head=recreverse(head);
					printf("\nlist is reversed\nprinting it\n");
					printlist(head);
				
				break;
			case 4:return 0;
			default:printf("\n\nERROR");
		}
	}
}
