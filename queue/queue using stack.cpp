
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#define MAXSIZE 10
struct ArrayStack{
 	int *array;
	int top;	
	int size;	
};

struct ArrayStack* createstack() {
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
   return(s->top==-1);   	
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
        return(d);	                    
    					
}
else
printf("stack doesnt exist");
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

void Enqueue(struct ArrayStack *s,int data)
{
	Push(s,data);
}

void Dequeue(struct ArrayStack *s,struct ArrayStack *s1)
{
	while(!isEmptyStack(s))
	{
		Push(s1,Pop(s));
	}
	if(!isEmptyStack(s1))
	Pop(s1);
	else
	printf("stack empty");
	while(!isEmptyStack(s1))
	{
		Push(s,Pop(s1));
	}
}

void getStatus(struct ArrayStack *s,struct ArrayStack *s1)
{
	while(!isEmptyStack(s))
	{
		Push(s1,Pop(s));
	}
	if(!isEmptyStack(s1))
	printf("the front of the queue is at %d",s1->array[s1->top]);
	else
	printf("the queue is empty");
    return;
	while(!isEmptyStack(s1))
	{
		Push(s,Pop(s1));
	}
	
		printf("the rear of the queue is at %d",s->array[s->top]);
}

int main(){
int ch,data,d=1;
struct ArrayStack *s = createstack();	
struct ArrayStack *s1 = createstack();	

while(d==1)
{
	printf("\nenter the operation 1.Push 2.Pop 3.GetStatus 4.delete");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nenter the data");
			scanf("%d",&data);
			Enqueue(s,data);
			break;
		case 2: 	
		Dequeue(s,s1);
			break;
		case 3:
		getStatus(s,s1);
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
