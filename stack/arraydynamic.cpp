
#define MAXSIZE 1

#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct ArrayDyn{
	int *array;
	int top;
	int size;
};

struct ArrayDyn* createStack(){
	struct ArrayDyn *s = (struct ArrayDyn*)malloc(sizeof(struct ArrayDyn));
	if(!s)
	return NULL;
	s->top=-1;
	s->size=MAXSIZE;
	s->array= (int*)malloc(s->size*sizeof(int));  
	if(!s->array)
	return NULL;
	else
	return s;
}

int isEmptyStack(struct ArrayDyn *s)
{
   return(s->top==-1);   	 // returns true if top is -1 else false
}

int isFullStack(struct ArrayDyn *s)
{
	return(s->top==s->size-1);
}

void Push(struct ArrayDyn *s,int data)
{
	if(s)
	{
	if(isFullStack(s))
	{
	s->size*=2;
	printf("\nstack size got increased to %d",s->size);
    s->array = (int*)realloc(s->array,s->size*sizeof(int));
}
	else
	s->array[++s->top]=data;  //goto the array of the stack and increment the top index and insert data at that address	
}
else 
printf("\nstack doesnt exist");
	
}

int Pop(struct ArrayDyn *s)
{
	if(s)
	{
	if(isEmptyStack(s))
	printf("\nstack is empty");
	else
	printf("\nthe data %d is popped from %d index",s->array[s->top],s->top);
        return(s->array[--s->top]);	                    
    					//deletion logic is done by reducing the top index value u stored by one..ex: if top=5 and s->array[top]=6 and if u want to pop 6 then
                            // u will reduce the top value to 4 so that next time u insert u will get a chance to insert the value at 5 index and u can override the 
                            //existing 6 value . If u r not interested in insertion not a problem bcoz 5 th index is out of scope as we r only pointing till top 
                            //value i.e s->array[4]
		
}
else
printf("stack doesnt exist");
}
void DeleteStack(struct ArrayDyn *s)
{
	//to delete something it shud first
	if(s){
	if(s->array)	
	free(s->array);
	free(s);
}
}


int main(){
int ch,data,d=1;
struct ArrayDyn *s = createStack();	
while(d==1)
{
	printf("\nenter the operation 1.Push 2.Pop 3.Delete");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nenter the data");
			scanf("%d",&data);
			Push(s,data);
			break;
		case 2: 	
			printf("\nthe current top value is %d",Pop(s));
			break;
		case 3:
		    DeleteStack(s);
			break;				
	}
	if(ch==3)
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




















