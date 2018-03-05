//floyds cycle finding

#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};struct node *head;

int main()
{
	struct node *nw,*ptr1,*ptr2,*temp;
	
	int i,l,b;
	head=(struct node*)malloc(sizeof(struct node));
	head->data=NULL;
	head->next=NULL;
	int count=1;
	ptr1=head;
	printf("enter how many nodes u need in the list");
	scanf("%d",&l);
	printf("enter which position u wanna insert the node");
	scanf("%d",&b);
	//lets create a linked list and insert a loop in it
	for(count=1;count<=l;count++)
	{
		nw=(struct node*)malloc(sizeof(struct node));
		ptr1->next=nw;
	    nw->data=count;
	    if(count==b)
	    ptr2=nw;
	    if(count==l)
	    nw->next=ptr2;
	    //nw->next=NULL;
	    ptr1=ptr1->next;
	}
	temp=head->next;
	for(i=1;i<=l;i++)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	
	//now lets test if the linked list has a loop
	
	struct node *slwptr=head->next,*fstptr=head->next;
	int flag=0;
	while(fstptr->next->next!=NULL)
	{
		
	   slwptr=slwptr->next;
       fstptr=fstptr->next->next;
		if(slwptr->next==fstptr->next)	
		{
		flag=1;
	     break;
	 }
	}
	if(flag==1)
	printf("\n loop exists");
	else
	printf("no loop");
	
	//now lets find where does the loop start 
	if(flag==1)
	{
		int ct=1,k;
	slwptr=head->next;
	while(slwptr!=fstptr)
	{
	slwptr=slwptr->next;
	fstptr=fstptr->next;
	ct++;
    }
    printf("\n the loop starts at position %d from the start of the list",ct);
}

  //now lets find the length of the loop
  int cnt=1;
  fstptr=fstptr->next;
  while(slwptr!=fstptr)
  {
  	fstptr=fstptr->next;
  	cnt++;
  }
  printf("\nthe length of the loop is %d",cnt);
	return 0;
	
}

