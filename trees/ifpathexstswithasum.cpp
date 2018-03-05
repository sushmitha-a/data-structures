
#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};struct tree* newnode(int data)
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

//lets do inorder traversal
//the order is left root right
// u will keep printing the elements in the order of this
//so at a single node level : ull land on root 
//*** note a point ------ a node has a privilige to be a left child only if its not a root of some other node... if it is a root then it can become the child only
//after the children are traversed
//so first go to root->left check if it its childre are null if not make it as a root and repeat the same
//now if its children are null print it 
//then return to the previous node that called it 
//then print the root (i.e.,current node)
// repeat the same for right child
int findifpath(struct tree *p,int sum,int sersum)
{
	if(p)
	{
		sum=sum+p->data;
		int m = findifpath(p->left,sum,sersum);
		int n = findifpath(p->right,sum,sersum);
		if(m==0&&n==0){
			if(sum==sersum){
			return 2;
}
else return 1;
}
else if(m==2||n==2)
return 2;
else return 1;		
	}
	else return 0;
}
int main()
{
struct tree *p;
int data,n,i,sersum=0,sum=0;
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
printf("enter the required sum");
scanf("%d",&sersum);
if(findifpath(p,sum,sersum)==2)
printf("path exists");
else 
printf("path doesnt exist");
return 0;
}


