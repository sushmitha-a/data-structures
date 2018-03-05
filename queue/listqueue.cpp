
#include<stdio.h>
#include<malloc.h>
#include<conio.h>


struct listQueue{
	struct list *front;
	struct list *rear;
};

struct list{
    int data;
    struct list *next;
};


struct listQueue* create()
{	
struct listQueue *s = (struct listQueue*)malloc(sizeof(struct listQueue));
s->front=NULL;
s->rear=NULL;
return s;
}

int emptyqueue(struct listQueue *s)
{
	if(s->front==NULL)
	return 1;
	else
	return 0;
}

void Enqueue(struct listQueue *s,int data)
{
  struct list *nw = (struct list*)malloc(sizeof(struct list));
  nw->data=data;
  nw->next=NULL;
  
  if(s->rear==NULL&&s->front==NULL)
  {

  s->front=nw;
  s->rear=nw;
  printf("%d",nw->data);
}
else
{
  s->rear->next=nw;
  s->rear=s->rear->next;	
}

}

void Dequeue(struct listQueue *s)
{
	if(!emptyqueue(s))
	{
		struct list *temp= s->front;
		if(s->front==s->rear)
		{
		s->front=s->front->next;
		s->rear=s->rear->next;
	    }
	else
	{
	s->front=s->front->next;
    }	
     free(temp);
}
else
printf("queue is empty");

}

void Delete(struct listQueue *s)
{
	struct list *ptr;
	if(!s)
	{
		printf("no queue existing");
	 } 
	else
	{
		ptr=s->front;
	while(s->front!=NULL)
	{
    ptr=s->front;
	s->front=s->front->next;
	free(ptr);
}
printf("successfully deleted");
}
}

void getstatus(struct listQueue *s)
{
	printf("the front ptr is pointing to data - %d",s->front->data);
    printf("the rear ptr is pointing to data - %d",s->rear->data);	
}

int main(){
	int ch,data;
	struct listQueue *s = create();
	 while(ch!=4)
    {
    printf("enter your choice 1.enqueue 2.dequeue 3.getstatus 4.delete");
	scanf("%d",&ch);
	switch(ch)
	{
        case 1:    
		           printf("enter the data");
		           scanf("%d",&data); 
		           Enqueue(s,data);
		           break;
		
		case 2:
	                Dequeue(s);
		            break;
		case 3:  
		            getstatus(s);
					break;            
	    case 4:				
		            Delete(s);
	}
}
return 0;
	
}

