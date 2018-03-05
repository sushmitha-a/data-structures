#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;	
}; struct node *head,*nw,*ptr,*ptr1;

void insertion(struct node **,int,int);
void deletion(struct node **,int);
void display(struct node **);

int main(){
	int dt,dt1,n,l=1;
	head = (struct node *)malloc(sizeof(struct node));
	head->data=NULL;
	head->prev=NULL;
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
    int b=1;
        while(b==1)
        {
    	printf("enter the position to delete");
    	scanf("%d",&n);
    	deletion(&head,n);
    	display(&head);
    	printf("\n press 1 to continue (1/0)");
        scanf("%d",&b);
    }
	

	
}

void insertion(struct node **head,int data,int pos)
{
	int k=1;
	nw= (struct node *)malloc(sizeof(struct node));
	 nw->data=data;
	if(pos==1)
	{
		nw->next=*head;
		nw->prev=NULL;
		if(*head)
		(*head)->prev=nw;//since we are using *head->next instead of head->prev it shud be type casted as (*head)->prev
		               //head should be used as *head bcoz we are passinng a double pointer
	    *head=nw;	
	 } 
	else
	{
		ptr=*head;
		while(ptr->next!=NULL&&k<pos-1)
		{
		   ptr=ptr->next;
		   k++;
		}
		if(k!=pos){
		printf("not found");
	}
		nw->prev=ptr;
		nw->next=ptr->next;
		if(ptr->next)
		ptr->next->prev=nw;
		ptr->next=nw;
		
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

void deletion(struct node **head,int pos)
{
	int k=1;
	if(*head==NULL)
	{
		printf("list empty");
	}
		ptr=*head;
	if(pos==1)
	{
		ptr=*head;
	    *head=(*head)->next;
	    if(*head!=NULL)
		(*head)->prev=NULL;
		free(ptr);
	}
	
	else	
	{
		while(ptr->next!=NULL&&k<pos)
		{
			k++;
            ptr=ptr->next;
		}
		if(k==pos)
		{
			ptr->prev->next=ptr->next;
			if(ptr->next)
			ptr->next->prev=ptr->prev;
			free(ptr);
	}
	else 
	printf("not exist");	
		
	}
	
}


