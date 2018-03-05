#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
}; struct node *head;

struct node* nfromlast(struct node*,int);

int main()
{
	struct node *ptr,*nw,*ptr3;
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
	
	printf("\nEnter 1 if u need to find nth node from last");
 scanf("%d",&g);
 if(g==1)
  printf("enter the value of n");
 scanf("%d",&j);
  ptr3=nfromlast(head,j);
	printf("\n%d",ptr3->data);
	
	return 0;
	
}

//to insert nth node from the last.For this we shud traverse tot-n nodes from first . for that we shud first remove n nodes from first, then how many ever node u 
//traverse are tot-n nodes . So one ptr which removes n nodes from first,so it only has tot-n nodes to trverse. so u get the tot-n count using it .So start a ptr 
//from head and traverse ti tot-n

struct node* nfromlast(struct node *head, int n)
{
	struct node *ptr1,*ptr2;
	int count;
	ptr1=head;
	ptr2=NULL;
	for(count=1;count<n;count++)
	{
		if(ptr1)
		ptr1=ptr1->next;
			}
	while(ptr1->next!=NULL)
{	

	if(ptr2==NULL)
	{
	ptr2=head;
}
		ptr1=ptr1->next;
		ptr2=ptr2->next;

}
if(ptr2)
	return ptr2;
else
return NULL;	
	
}



