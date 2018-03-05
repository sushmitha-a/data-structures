

#include<stdio.h>
#include<malloc.h>
#include<conio.h>

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
       printf("1");
		root->left = insert(root->left,data);
	
	}
		else if(data>root->data)
		{ 
		printf("2");
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
		int count=0;
	    Enqueue(s,root);
	    while(!emptyQueue(s))
	    {
	    	root=Dequeue(s);
	    	if(root->left!=NULL&&root->right!=NULL)
	    	count++;
	    	if(root->left)
	    	Enqueue(s,root->left);
	     if(root->right)
	    	Enqueue(s,root->right);
		}
		printf("the no of fulll nodes are %d",count);
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



