//to check if the given list length is even or odd
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
}; struct node *head;

void findevenorodd(struct node *);
int main()
{
	struct node *ptr,*nw,*ptr3,*ptr4,*ptr5;
	int i,g,j,u;
	head= (struct node*)malloc(sizeof(struct node));
	head->data=NULL;
	head->next=NULL;
	ptr=head;
	printf("enter the size of the linked list");
	scanf("%d",&u);
	for(i=1;i<=u;i++)
	{
	   nw= (struct node*)malloc(sizeof(struct node));
	   nw->data = i;	  
	   if(i==u)
	   nw->next=NULL;
	   ptr->next=nw;
	   ptr=ptr->next;
	   		
	}
	ptr=head;
	for(i=1;i<=u;i++)
	{
		ptr=ptr->next;
		printf("%d",ptr->data);
	}
	
 ptr4=head;
 findevenorodd(ptr4);
	return 0;
	
}

void findevenorodd(struct node *head)
{
   struct node *ptr1=head;
   while(ptr1->next&&ptr1->next->next!=NULL)
   {
   	 ptr1=ptr1->next->next;
   }

	if(ptr1->next!=NULL)
	printf("\nlist is odd");
	else
	printf("\nlist is even");
}








