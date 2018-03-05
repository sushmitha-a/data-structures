#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
}; struct node *head,*nw,*ptr,*ptr1;

void insertion(struct node **,int,int);
void display(struct node **);

int main(){
	
	int dt,dt1,l=1;
	head = (struct node *)malloc(sizeof(struct node));
	head->data=NULL;
	head->next=NULL;
	
	while(l==1)
	{
	printf("enter the starting element value");
	scanf("%d",&dt);
	printf("enter the position value");
	scanf("%d",&dt1);
	insertion(&head,dt,dt1);
	display(&head);	
    printf("\n press 1 to continue (1/0)");
    scanf("%d",&l);
}		
}

void insertion(struct node **head,int data,int pos)
{
	int k=1;
	nw= (struct node *)malloc(sizeof(struct node));
	 nw->data=data;
	if(pos==1)
	{
		nw->next=*head;  //head should be used as *head bcoz we are passinng a double pointer 
	    *head=nw;	
	 } 
	else
	{
		ptr=*head;
		while(ptr->next!=NULL&&k<pos)
		{
		   ptr1=ptr;
		   ptr=ptr->next;
		   k++;
		}
		ptr1->next=nw;
		nw->next= ptr;
	 } 
	
	
	
}

void display(struct node **head)
{
	
	ptr=*head;
	while(ptr->next!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
	
	
}


