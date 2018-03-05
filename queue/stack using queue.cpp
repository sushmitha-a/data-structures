

#include<stdio.h>
#include<malloc.h>
#include<conio.h>


struct ArrayQueue{
	int *array;  
	int front,rear;
	int capacity;
};

struct ArrayQueue *create(int size){
	struct ArrayQueue *s = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
	s->capacity = size;
	s->front=-1;
	s->rear=-1;
	s->array = (int*)malloc(sizeof(int));
	if(!s->array)
	return NULL;
	else 
	return s;
}

int emptyQueue(struct ArrayQueue *s)
{
	return(s->front==-1);
}
int fullQueue(struct ArrayQueue *s) 
{	
if((s->rear+1)%s->capacity==s->front)
return 1;
else 
return 0;
}

void Enqueue(struct ArrayQueue *s,int data)
{
	if(!fullQueue(s))
	{
	s->rear = ((s->rear+1)%s->capacity);	// ull first change the index value 
	s->array[s->rear]= data;
	if(s->front==-1)
	s->front=s->rear;
	printf("u pushed %d",data);
    }
else
printf("queue is full");
}

int Dequeue(struct ArrayQueue *s)
{
	if(!emptyQueue(s))
	{
		int d = s->array[s->front];
		printf("u popped %d",s->array[s->front]);
		if(s->front==s->rear)
		{
			s->front=s->rear=-1;
		}
		else
		s->front = (s->front+1)%s->capacity;
		return d;
}
else
printf("queue is empty");
}		
		
void Push(struct ArrayQueue *s,int data)	
{
	Enqueue(s,data);
}	

void Pop(struct ArrayQueue *s,struct ArrayQueue *s1)
{
	while(s->front!=s->rear)
	{
		Enqueue(s1,Dequeue(s));		
}
	Dequeue(s);
	while(s1->front!=s1->rear)
	{
		Enqueue(s,Dequeue(s1));		
}	
		
}						
void Delete(struct ArrayQueue *s)		
	{
	   if(s){
	   	if(s->array)
	   	free(s->array);
	   	free(s);
	   }
	   
	}
	
int main(){
	int size,ch=0,data;
	printf("enter the size");
	scanf("%d",&size);
	struct ArrayQueue *s = create(size);
	struct ArrayQueue *s1 = create(size);

    while(ch!=3)
    {
    printf("enter your choice 1.enqueue 2.dequeue 3.delete");
	scanf("%d",&ch);
	switch(ch)
	{
        case 1:    
		           printf("enter the data");
		           scanf("%d",&data); 
		           Push(s,data);
		           break;
		
		case 2:
	                Pop(s,s1);
		            break;
	    case 3:				
		            Delete(s);
	}
}
return 0;
	
	
}

