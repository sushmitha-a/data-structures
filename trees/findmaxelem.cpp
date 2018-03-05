//find max in tree
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
       
		root->left = insert(root->left,data);
	
	}
		else if(data>root->data)
		{ 
		
		root->right = insert(root->right,data);
         }
	return root;
	
    }
    
}

int findmax(struct tree *root,int max)
{   
	if(root)
	{
		
		if(root->data>max)
		{
		max= root->data;
	    max= findmax(root->right,max);
	    
        }
        return max;
}
return max;
}

int main(){
struct tree *p;
int data,n,i,j;
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

i = findmax(p,data);
printf("%d",i);
return 0;
}


