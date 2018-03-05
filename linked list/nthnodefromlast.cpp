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
struct node* nfromlast(struct node*,int);

int main(){
	int dt,dt1,n,l=1,g,j;
	struct node *ptr3;
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
    int b;
    printf("\n press 1 to continue (1/0)");
        scanf("%d",&b);
        while(b==1)
        {
    	printf("enter the position to delete");
    	scanf("%d",&n);
    	deletion(&head,n);
    	display(&head);
    	printf("\n press 1 to continue (1/0)");
        scanf("%d",&b);
    }
	
 printf("Enter 1 if u need to find nth node from last");
 scanf("%d",&g);
 if(g==1)
  printf("enter the value of n");
 scanf("%d",&j);
  ptr3=nfromlast(head,j);
	printf("%d",ptr3->data);
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
				
	while(ptr1->next->next!=NULL)
{		
	if(ptr2==NULL)
	{
	ptr2=head;
}
	else
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
}

}
if(ptr2)
	return ptr2;
else
return NULL;	
	
}




 









