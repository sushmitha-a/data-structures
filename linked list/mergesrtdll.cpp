//merge two sorted linked lists
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};
struct node *head1,*head2,*nw,*nw1;

struct node* mergesorted(struct node*,struct node*);

int main(){
	struct node *ptr1,*ptr2,*ptr3;
	int i,j,l1,l2;
	head1= (struct node*)malloc(sizeof(struct node));
	head1->data=NULL;
	head1->next=NULL;
	ptr1=head1;
	head2=(struct node*)malloc(sizeof(struct node));
	head2->data=NULL;
	head2->next=NULL;
	ptr2=head2;
	printf("enter the sizes of 2 linked lists");
	scanf("%d",&l1);
	scanf("%d",&l2);
	printf("insert the elements in the first linked list");
	for(i=1;i<=l1;i++)
	{
		nw=(struct node*)malloc(sizeof(struct node));
		if(i==l1)
		nw->next=NULL;
		ptr1->next=nw;
		scanf("%d",&nw->data);
		ptr1=nw;
	}
	printf("insert the elements in the second linked list");
	for(j=1;j<=l2;j++)
	{
		nw1=(struct node*)malloc(sizeof(struct node));
		if(i==l2)
		nw1->next=NULL;
		ptr2->next=nw1;
		scanf("%d",&nw1->data);
		ptr2=nw1;
}
     ptr1=head1;
  		for(i=1;i<=l1;i++)
	{
		ptr1=ptr1->next;
		printf("%d",ptr1->data);
	}
	ptr2=head2;
    for(j=1;j<=l2;j++)
	{
		ptr2=ptr2->next;
		printf("%d",ptr2->data);
	}	
	
    struct node *tr= mergesorted(head1->next,head2->next);
	for(i=0;i<l1+l2;i++)
	{
		printf("%d",tr->data);
		tr=tr->next;
	}
}


//here u only need to traverse till u find the bigger element.If u find a bigger element then stop traversing and place the element in that position
//do this for each element in the one of the ll
struct node* mergesorted(struct node *ptr1,struct node *ptr2)
{
	struct node *result=NULL;
	if(ptr1==NULL)
    return ptr1;
    return ptr2;
	if(ptr1->data<ptr2->data)
	{
	result=ptr1;
	result->next=mergesorted(ptr1->next,ptr2);
	
}
else
{
	result=ptr2;
	result->next=mergesorted(ptr2->next,ptr1);
}
	return result;
}

