


#include<stdio.h>
#include<malloc.h>
#include<conio.h>




#define MAXSIZE 10
struct ArrayStack{
 	int *array;
	int top;	
	int size;	
};

struct ArrayQueue{
	int *array;  
	int front,rear;
	int capacity;
};

struct ArrayStack* createstack() {
	//we first create memory for struct ptr
	struct ArrayStack *s = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
	if(!s)
	return NULL;
	else
	s->size=MAXSIZE;
	s->top=-1;
	s->array=(int*)malloc(s->size*sizeof(int));  
	if(!s->array)
	return NULL;
	else
	return s;
	
}


int isEmptyStack(struct ArrayStack *s)
{
   return(s->top==-1);   	 // returns true if top is -1 else false
}

int isFullStack(struct ArrayStack *s)
{
	return(s->top==s->size-1);
}

void Push(struct ArrayStack *s,int data)
{
	if(s)
	{
	if(isFullStack(s))
	printf("\nstack is full");
	else
	s->array[++s->top]=data;  	
}
else 
printf("\nstack doesnt exist");
}
int Pop(struct ArrayStack *s)
{
	int d;
	if(s)
	{
	if(isEmptyStack(s))
	printf("\nstack is empty");
	else
	d=s->array[s->top];
	s->array[--s->top];
        return(d);	                    
    					
		
}
else
printf("\nstack doesnt exist");
}


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
int fullQueue(struct ArrayQueue *s) {	
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
printf("\nqueue is full");
}

int Dequeue(struct ArrayQueue *s)
{
	int d;
	if(!emptyQueue(s))
	{
		if(s->front==s->rear)
		{
			d=s->array[s->front];
			s->front=s->rear=-1;
			return d;
		}
		else
		d=s->array[s->front];
		s->front = (s->front+1)%s->capacity;
		return d;		
}
else
printf("\nqueue is empty");
}		
		
		
void Delete(struct ArrayQueue *s)		
	{
	   if(s){
	   	if(s->array)
	   	free(s->array);
	   	free(s);
	   }
	   
	}
	
void ReverseQueue(struct ArrayQueue *s)
{
	struct ArrayStack *st = createstack();
	while(!emptyQueue(s))
	{
		Push(st,Dequeue(s));
	}
    while(!isEmptyStack(st))
	{
		Enqueue(s,Pop(st));	
		}	
	while(!emptyQueue(s))
	{
		printf("\n %d",Dequeue(s));
	}
	
	}	
	
int main(){
	int size,ch,data;
	printf("\nenter the size");
	scanf("%d",&size);
	struct ArrayQueue *s = create(size);
    do
    {
    
		           printf("\nenter the data");
		           scanf("%d",&data); 
		           Enqueue(s,data);
		           printf("\n press 1 to continue press 2 to reverse");
	               scanf("%d",&ch);
	               if(ch==2)
	                ReverseQueue(s);  
				   
}while(ch==1);
return 0;
	
	
}

