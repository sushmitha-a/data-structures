
#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 10
struct ArrayQueue{
	struct tree *array[7];  // its a ptr bcz we r just declaring the array we will define it with different sizes for each instance of the queue 
	int front,rear;
	int capacity;
};
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};


struct ArrayStack{
 	struct tree *array[6];
	int top;	
	int size;	
};

struct ArrayStack* createstack() {
	//we first create memory for struct ptr
	struct ArrayStack *s = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
	if(!s)
	return NULL;
	else
	// now we initialise each value of it
	s->size=MAXSIZE;
	s->top=-1;//so that wen u insert the first element u can increment and insert
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

void Push(struct ArrayStack *s,struct tree* data)
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
struct tree* Pop(struct ArrayStack *s)
{
	if(s)
	{
		struct tree* t;
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








	
void zigzagtraversal(struct tree *root)
{
		struct ArrayStack *temp = createstack();
		struct ArrayStack *s1 = createstack();
        struct ArrayStack *s2 = createstack();
	    Push(s1,root);
	    int flag=0;
		while(!isEmptyStack(s1))
          {
	    	root=Pop(s1);
	    	if(root)
	    	{
            printf("%d",root->data);
            if(flag==0)
            {
	    	if(root->left)
	    	Push(s2,root->left);
	    	if(root->right)
	    	Push(s2,root->right);
	    	}
	    	else if(flag==1)
	    	{
	    	if(root->right)
	    	Push(s2,root->right);
			if(root->left)
	    	Push(s2,root->left);	
			}
		}
		if(isEmptyStack(s1))
		{
		flag=1-flag;
		temp=s1;
		s1=s2;
		s2=temp;
	}
	
}	
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
zigzagtraversal(p);
return 0;
	
	
}



