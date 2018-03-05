
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<math.h>


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


struct ArrayStack* createstack(int size) {
	
	struct ArrayStack *s = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
	if(!s)
	return NULL;
	else
	
	s->size=size;
	s->top=-1;
	s->array=(int*)malloc(s->size*sizeof(int));  
	if(!s->array)
	return NULL;
	else
	return s;
	
}

//good to pass the full stack to take the top ptr

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
	s->array[++s->top]=data;  //goto the array of the stack and increment the top index and insert data at that address	
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
    return d;					
		
}
else
printf("stack doesnt exist");
return NULL;
}
void DeleteStack(struct ArrayStack *s)
{
	//to delete something it shud first
	if(s){
	if(s->array)	
	free(s->array);
	free(s);
}
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
	
int findconsec(ArrayStack *s,struct ArrayQueue *s1)	
	{
		int pairordered=1;
		while(!isEmptyStack(s))
		{
			
			int m = Pop(s);
			Enqueue(s1,m);
			if(!isEmptyStack(s))
			{
			int n =Pop(s);
			Enqueue(s1,n);
			if(abs(n-m)!=1)
			pairordered=0;
		}
		}
		
		//now let put it back to stack
		while(!emptyQueue(s1))
		Push(s,Dequeue(s1));
		//but the order is reversed . So lets revrse it back
		while(!isEmptyStack(s))
		Enqueue(s1,Pop(s));
	    while(!emptyQueue(s1))
		Push(s,Dequeue(s1));
	   	return pairordered;
	}
	
int main(){
int ch,data,m,d=1,j,size;
printf("enter the size");
scanf("%d",&size);
struct ArrayStack *s = createstack(size);
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
			Push(s,data);
			break;
		case 2: 	
		    j = Pop(s);
			break;
		case 3:
		    m= findconsec(s,s1);
			if(m)
			printf("they are pair wise ordered");
			else
			printf("they are not pair wise ordered");
			break;	
		case 4:
		    DeleteStack(s);
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















