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

void Dequeue(struct ArrayQueue *s)
{
	if(!emptyQueue(s))
	{
		printf("u popped %d",s->array[s->front]);
		if(s->front==s->rear)
		{
			s->front=s->rear=-1;
		}
		else
		s->front = (s->front+1)%s->capacity;
		
}
else
printf("queue is empty");
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
	int size,ch,data;
	printf("enter the size");
	scanf("%d",&size);
	struct ArrayQueue *s = create(size);

    while(ch!=3)
    {
    printf("enter your choice 1.enqueue 2.dequeue 3.delete");
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
		            Delete(s);
	}
}
return 0;
	
	
}

