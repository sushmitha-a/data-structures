
#include<stdio.h>
#include<malloc.h>
#include<conio.h>

#define MAXSIZE 10
struct ArrayQueue{
	struct tree *array[7];  
	int front,rear;
	int capacity;
};
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};


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
	s->top=-1;//so that wen u insert the first element u can increment and insert
	s->array=(int*)malloc(s->size*sizeof(int));  //here we allocate some memory to the arra ptr 
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
	if(s)
	{
		int t;
		t =s->array[s->top];
	if(isEmptyStack(s))
	printf("\nstack is empty");
	else
        s->array[--s->top];
		return t;	                    
    					
		
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


struct tree* newnode(int data)
{
struct tree *p = (struct tree*)malloc(sizeof(struct tree));
p->data = data;
p->left = NULL;
p->right=NULL;	
return p;
}

struct tree* insert(struct tree *root,int data)
{
	
	if(root==NULL)
	{
		root= newnode(data);
		return root;
	}
	else
	{
		if(data<root->data)
{
		root->left = insert(root->left,data);
	
	}
		else if(data>root->data)
		{ 
		
		root->right = insert(root->right,data);
         }
	return root;
	
    }
    
}







struct ArrayQueue *create(int size){
	struct ArrayQueue *s = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
	s->capacity = 7;
	s->front=-1;
	s->rear=-1;
	if(!s->array)
	return NULL;
	else 
	return s;
}

int emptyQueue(struct ArrayQueue *s)
{
	return(s->front==-1);
}
int fullQueue(struct ArrayQueue *s) //if the next elent is already present in a circular queue tthen u cant push i.e., next elem shud be pointed by front 
{	
if((s->rear+1)%s->capacity==s->front)
return 1;
else 
return 0;
}

void Enqueue(struct ArrayQueue *s,struct tree *data)
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

struct tree* Dequeue(struct ArrayQueue *s)
{
	if(!emptyQueue(s))
	{
		  struct tree *t;
	   t = s->array[s->front];
		if(s->front==s->rear)
		{
			s->front=s->rear=-1;
			return t;
		}
		else
		{
		s->front = (s->front+1)%s->capacity;
		return t;
}
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
	
void levelordertraversal(struct tree *root)
{
		struct ArrayQueue *s = create(100);
		struct ArrayStack *s1 = createstack();
	    Enqueue(s,root);
	    while(!emptyQueue(s))
	    {
	    	root=Dequeue(s);
	    	Push(s1,root->data);
	    	if(root->left)
	    	Enqueue(s,root->left);
	    	if(root->right)
	    	Enqueue(s,root->right);
	    	
		}
		while(!isEmptyStack(s1))
		printf("%d",Pop(s1));
	//Delete(s);
}
	
	
int main(){
    struct tree *p;
int data,n,i;
printf("enter the no of elements");
scanf("%d",&n);
printf("enter the data");
scanf("%d",&data);
p=newnode(data);
for(i=0;i<n-1;i++)
{
printf("enter the data");
scanf("%d",&data);
struct tree *t = insert(p,data);		
}
levelordertraversal(p);
return 0;
	
	
}


