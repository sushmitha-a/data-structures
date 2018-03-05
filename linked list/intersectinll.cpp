//Two lists with different lengths intersect at a point i.e., two different nodes of the list will point to same node.Find the length of the intersection 




//for this first remove the extranodes from longer list bcoz only if there are nodes in both lists it is possible so cut the extra. and now start pointing the nodes 
//parallelly.see if u can find same next nodes

#include<stdio.h>
#include<conio.h>
#include<malloc.h>


struct node{
	int data;
	struct node *next;
}; struct node *head1,*head2,*nw;

void lengthofintersection(struct node*,struct node*);
void display(struct node*);
int main()
{
	struct node *ptr1,*ptr2,*ptr3;
    int i,j;
//1.create two intersecting linked lists

head1 = (struct node *)malloc(sizeof(struct node));
head2 = (struct node *)malloc(sizeof(struct node));

head1->data=NULL;
head2->data=NULL;

ptr1=head1;
ptr2=head2;


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

for(i=1;i<=3;i++)
{
    nw=(struct node *)malloc(sizeof(struct node));
	nw->data=i;
	if(i==3)
	{
		nw->next=ptr3;
	}
    ptr2->next=nw;
	ptr2=ptr2->next; 
		
}
display(head1->next);
display(head2->next);
lengthofintersection(head1,head2);
}
void display(struct node *head)
{
	while(head!=NULL)
	{
	printf("%d",head->data);
	head=head->next;
}

}

void lengthofintersection(struct node *head1,struct node *head2)
{
	int count=0,i,j,l1=0,l2=0;
	struct node *ptr1=head1,*ptr2=head2;
	while(head1->next!=NULL)
	{
		head1=head1->next;
		l1++;
	}
	while(head2->next!=NULL)
	{
		head2=head2->next;
		l2++;
	}
	
	if(l1>l2)
	{
	i=l1-l2;	
	head1=ptr1;
	head2=ptr2;
}
	else
	{ 
	i=l2-l1;
	head1=ptr2;
	head2=ptr1;
}
	
	
	for(j=0;j<i;j++)
	{
	 head1=head1->next;  
	}
	printf("%d",head1->data);
	
	
while(head1->next!=NULL)
{
	
	if(head1->next==head2->next)
	{
		count++;
	}
	head1=head1->next;
	head2=head2->next;
	
	
	}	
	printf("the length of the intersection is %d",count);
}
