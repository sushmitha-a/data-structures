//display the elements of linked list in reverse order
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
}; struct node *head;

void displayreverseorder(struct node *);
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
 displayreverseorder(ptr4);
	return 0;
	
}


void displayreverseorder(struct node *head)
{
	
	if(head->next==NULL)
	{
		printf("%d",head->data);
	}
	else
	{
	displayreverseorder(head->next);
	printf("%d",head->data);
}
}
