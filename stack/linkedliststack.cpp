 

#define MAXSIZE 10

#include<stdio.h>
#include<malloc.h>
#include<conio.h>


struct node{
	int data;
	struct node *next;
};
int size;
struct node *create()
{
	struct node*head;
	head= (struct node*)malloc(sizeof(struct node));
	head->data=NULL;
	head->next=NULL;
	return head;
}

int isempty(struct node *head)
{
	if(head->next==NULL)
	return 1;
	else
	return 0;
}
int isfull()
{
	return(size==MAXSIZE);
}
struct node* push(struct node *head,int data)
{
	if(isfull())
	{
		printf("stack full");
	}
	else
    {
	struct node *nw;
	nw = (struct node*)malloc(sizeof(struct node));
	nw->data=data;
	nw->next=head->next;   //insert at the beginning implementation
	head->next=nw;
	size++;
}
return head;
}
struct node* pop(struct node *head)
{
	struct node *t;
	int dt;
	if(isempty(head))
	{
		printf("stack empty");
	}
	else
	{
		t = head->next;
		dt = t->data;
		head->next=t->next;
		free(t);
		printf("the element %d is deleted from %d position",dt,size);
		size--;
	}
	return head;
}

struct node* deletestack(struct node *head){
struct node *temp;
while(head->next!=NULL)
{
	temp=head->next;
	head->next=temp->next;
	free(temp);	
	}
return head;			
}
																																																																																		


int main(){
	struct node *head = create();
	int d=1,ch,data;
	while(d==1)
{
	printf("\nenter the operation 1.Push 2.Pop 3.Delete");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nenter the data");
			scanf("%d",&data);
			head=push(head,data);
			break;
		case 2: 	
			head=pop(head);
			break;
		case 3:
		    head=deletestack(head);
			break;				
	}
	if(ch==3)
	{
	printf("\ndeleted");
	break;
}
	else{
	printf("\nenter 1 to continue");
    scanf("%d",&d);
}
}

return 0;
	
	
}






