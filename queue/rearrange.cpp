
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<math.h>
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
    }
else
printf("queue is full");
}

int Dequeue(struct ArrayQueue *s)
{
	if(!emptyQueue(s))
	{
		int d=s->array[s->front];
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
		
		
void Delete(struct ArrayQueue *s)		
	{
	   if(s){
	   	if(s->array)
	   	free(s->array);
	   	free(s);
	   }
	   
	}
	
void rearrange(ArrayQueue *s,struct ArrayQueue *s1,int size)	
	{
		int i;
		if(size%2!=0)
		return;
		else
		{
		   for(i=0;i<size/2;i++)	
			{
				Enqueue(s1,Dequeue(s));
			}
			while(!emptyQueue(s1))
			{			
				Enqueue(s,Dequeue(s1));
				Enqueue(s,Dequeue(s));
			}
			for(i=0;i<size;i++)
			{
				printf("%d",s->array[i]);
			}
			
		}
		
	}

int main(){
int ch,data,m,d=1,j,size;
printf("enter the size");
scanf("%d",&size);
struct ArrayQueue *s = create(size);
struct ArrayQueue *s1 = create(size);	
while(d==1)
{
	printf("\nenter the operation 1.Push 2.Pop 3.find if pairwise ordered 4.Delete");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nenter the data");
			scanf("%d",&data);
			Enqueue(s,data);
			break;
		case 2: 	
		    j = Dequeue(s);
			break;
		case 3:
		  rearrange(s,s1,size);
			
		case 4:
		    Delete(s);
			break;	
			
	}
	if(ch==4)
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















