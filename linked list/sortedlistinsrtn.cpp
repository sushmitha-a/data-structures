//sorted linked list insertion
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

//the difference u take position as input. U shud find where too insert the given data by traversing the list till u reach a higher valued data
struct node{
	int data;
	struct node *next;
}; struct node *head;

void insertsorted(struct node*,int);

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
	
	printf("\nEnter 1 if u need to insert the node");
 scanf("%d",&g);
 if(g==1)
  printf("enter the value of n");
 scanf("%d",&j);
  insertsorted(head,j);
	
	return 0;
	
}

void insertsorted(struct node *head,int value)
{
	int count=0,h;
	struct node *nw= (struct node*)malloc(sizeof(struct node));
	nw->data=value;
	struct node *ptr1,*ptr2;
	if(head->next!=NULL)
	ptr1=head;
	
	else
	{
	nw->next=head->next;
	head->next=nw;
}
    
	while(ptr1->next!=NULL)
	{
			count++;
	h=ptr1->data;
	if(value<=h)
       break;
       else
       {
		ptr2=ptr1;
	ptr1=ptr1->next;

   }
       printf("%d",ptr1->data);
    	
}
if(count==1)
{

nw->next=ptr1->next;
ptr1->next=nw;
}

else
{
	nw->next=ptr1;
	ptr2->next=nw;
}
	printf("u can insert the value at %d position",count);
	
 } 
