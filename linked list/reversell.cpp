//reverse a singly linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
}; struct node *head;

struct node* reverselist(struct node **);
void display(struct node *);
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
 ptr4=head;
 ptr5=reverselist(&ptr4);
  display(ptr5);
	return 0;
	
}

//to solve it we need to know what are the changes to be done at node level
//assume in the loop we arrived at a node so 
//node next shud be prev nde  and the current nodes next shud be the prev node of current node
//any ways while traversing ull know the next nodes value . What u need to know is the prev nodes value
//so basically here once are at a iteration we will lose the node we travesed in prev itrtn . So we need save the node in seperate variable so that it wont get lost by the current node ptr
//also head shud become the last node

//1.Im travesing. So in each iteration im going to the next node . Just like i move to a[i++] in each iteration. Here since we cant find the go to next node that way
//we will access the memory location of the next element by node->next.So its like storing the copy of the node in each iteration in a temp variable 

//if the operation involves movement of head with each iteration then instead of copying it to ptr use the head only :P

struct node *reverselist(struct node **head)
{
	struct node *ptr1=NULL,*ptr2,*temp=NULL,*ptr4;
	while(*head!=NULL)
	{
	    ptr1=(*head)->next;
	    (*head)->next=temp;
	    temp=*head;
	    *head=ptr1;
	    
	}   
	 
    	return temp;	
}

void display(struct node *head)
{
	while(head->next!=NULL)
	{
		printf("%d",head->data);
		head=head->next;		
	}
	
	
}
