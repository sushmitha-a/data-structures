//to split a circular linked list into two equal parts 

//here we need to find the mid node.. i.e., find the length of the list. whenever u need to traverse thoru a list think if u can u use cncpt of fast ptr and slw ptr

//first find the middle of the list and the split it

#include<stdio.h>
#include<conio.h>
#include<malloc.h>


struct node{
	int data;
	struct node *next;
}; struct node *head1,*head2,*nw;

void splitlinklist(struct node*,struct node**,struct node**);
display(struct node*);
int main()
{
	struct node *ptr1,*ptr2,*ptr3,*ptr4;
    int i,j;
//1.create two intersecting linked lists

head1 = (struct node *)malloc(sizeof(struct node));

head1->data=NULL;

ptr1=head1;


for(i=1;i<=9;i++)
{
    nw=(struct node *)malloc(sizeof(struct node));
	nw->data=i;
	if(i==9)
	{
		nw->next=ptr2;
	}
	if(i==1)
	ptr2=nw;
    ptr1->next=nw;
	ptr1=ptr1->next;
		
}


display(head1->next);
splitlindlist(head1,ptr3,ptr4);
}
void display(struct node *head)
{
	while(head!=NULL)
	{
	printf("%d",head->data);
	head=head->next;
}

}
void splitlinklist(struct node *ptr1,struct node **ptr2,struct node **ptr3)
{
	struct node *h1=ptr1,*p1=ptr1,p2=ptr1;
    while(ptr1->next!=&&ptr->next->next!=NULL)
    {
    	p1=p1->next;
    	p2=p2->next->next;
	}
	
	
	
}
