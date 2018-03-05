//reverse a singly linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
}; struct node *head;

struct node* recursivereverse(struct node *);
int main()
{
	struct node *ptr,*nw,*ptr3,*ptr4,*ptr5;
	int i,g,j;
	head= (struct node*)malloc(sizeof(struct node));
	head->data=NULL;
	head->next=NULL;
	ptr=head;
	for(i=1;i<=9;i++)
	{
	   nw= (struct node*)malloc(sizeof(struct node));
	   nw->data = i;	  
	   if(i==9)
	   nw->next=NULL;
	   ptr->next=nw;
	   ptr=ptr->next;
	   		
	}
	ptr=head;
	for(i=1;i<=9;i++)
	{
		ptr=ptr->next;
		printf("%d",ptr->data);
	}
	
	printf("\nEnter 1 if u need to insert the node");
 scanf("%d",&g);
 if(g==1)
 ptr4=head->next;
 recursivereverse(ptr4);
	return 0;
	
}

struct node* recursivereverse(struct node *head)
{
	struct node *ptr9,*ptr;
	ptr=head;
	if(ptr->next==NULL)
	{
		printf("%d",ptr->data);
		return ptr;
	}
	else
	{
		ptr9=recursivereverse(ptr->next);
		ptr9->next=ptr;
		printf("%d",ptr->data);
		return ptr;
	}
	
}



