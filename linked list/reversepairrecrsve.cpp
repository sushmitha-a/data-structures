#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
}; struct node *head1,*head2,*nw;

struct node* reversepairitrtve(struct node *head);
void display(struct node*);
int main()
{
	struct node *ptr1,*ptr2,*ptr3;
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
		nw->next=NULL;
	}
	if(i==6)
	ptr3=nw;
    ptr1->next=nw;
	ptr1=ptr1->next;
		
}

display(head1->next);
struct node *u = reversepairitrtve(head1->next);
printf("\n");
display(u);
}
void display(struct node *head)
{
	while(head!=NULL)
	{
	printf("%d",head->data);
	head=head->next;
}

}

struct node* reversepairitrtve(struct node *head){
	
	struct node *ptr,*temp;
    if(head==NULL||head->next==NULL)
    {
    	return head;
    }
    	else
    	{
    	ptr=head->next;
    	temp=ptr->next;
    	ptr->next=head;
    	head->next=reversepairitrtve(temp);
    	return ptr;
		}	
	
	
}












