
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define MAXSIZE 10
struct ArrayStack{
 	char *array;
	int top;	
	int size;	
};

//it creates memory for all the needed variables inside structure and returns a ptr that points to the starting addrs of the struct 
struct ArrayStack* createstack() {
	//we first create memory for struct ptr
	struct ArrayStack *s = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
	if(!s)
	return NULL;
	else
	// now we initialise each value of it
	s->size=MAXSIZE;
	s->top=-1;//so that wen u insert the first element u can increment and insert
	s->array=(char*)malloc(s->size*sizeof(char));  //here we allocate some memory to the arra ptr 
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

void Push(struct ArrayStack *s,char data)
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
	if(s)
	{
	if(isEmptyStack(s))
	printf("\nstack is empty");
	else
        return(s->array[--s->top]);	                    
    					
}
else
printf("stack doesnt exist");
}

void PrintStackinrev(struct ArrayStack *s)
{
	int a= s->top,i;
	for(int i=0;i<=a;i++)
	printf("the contents of the stack is  ");
	printf("%c",s->array[i]);
	
}


int main(){
int ch,i,d=1;
char data;
struct ArrayStack *s = createstack();	
printf("enter the size of the stack");
scanf("%d",&ch);
printf("enter the characters");
for(i=0;i<ch;i++)
{
	scanf(" %c",&data);
	if(s->array[s->top] != data)
	Push(s,data);
	else
	Pop(s);
}
	PrintStackinrev(s);

return 0;
} 

