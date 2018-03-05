//To find the middle of linked list
//normally u shud traverse the full list once,find the middle value and then traverse once again till that middle mode
//wat if we do both at same time . One ptrto find length which goes till last another ptr which locate and store middle value
//instead use jumping concept .in a single strech use 2 ptrs one jumps 2 nodes another jumps one node so in one traversal u can find and also locate the middle node


#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
}; struct node *head;

void findmiddlenode(struct node *);
int main()
{
	struct node *ptr,*nw,*ptr3,*ptr4,*ptr5;
	int i,g,j,size;
	head= (struct node*)malloc(sizeof(struct node));
	head->data=NULL;
	head->next=NULL;
	ptr=head;
	printf("enter the size of the linked list");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
	   nw= (struct node*)malloc(sizeof(struct node));
	   nw->data = i;	  
	   if(i==size)
	   nw->next=NULL;
	   ptr->next=nw;
	   ptr=ptr->next;
	   		
	}
	ptr=head;
	for(i=1;i<=size;i++)
	{
		ptr=ptr->next;
		printf("%d",ptr->data);
}
 ptr4=head->next;
 findmiddlenode(ptr4);
	return 0;
	
}

void findmiddlenode(struct node *head)
{
	struct node *ptr1,*ptr2;
	ptr1=head;
	ptr2=head;
	while(ptr2->next!=NULL)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	}
	
	printf("the middle node is %d",ptr1->data);
}






