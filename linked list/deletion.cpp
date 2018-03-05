#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;	
}; struct node *head,*ptr,*nw,*ptr1;

void insertion(struct node **,int,int);
void deletion(struct node **,int);
void display(struct node **);

int main(){
	int dt,dt1,n,l=1;
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
	
		*head=ptr->next;
		free(ptr);
		
	}
	
	else	
	{
		printf("hgh");
		while(ptr->next!=NULL&&k<pos)
		{
			k++;
			ptr1=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL)
		printf("position doesnot exist");
		else{
			ptr1->next=ptr->next;
			free(ptr);
			
		}
		
	}
	
}
