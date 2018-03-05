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

int find(struct tree *p,int data)
{   int i;
	if(p)
	{
		if(data==p->data)
		return 1;
		else if(data>p->data)
		{
        i = find(p->right,data);
		return i;
	}
		else if(data<p->data)
		{
		  i= find(p->left,data);
		  return i;
	}
}
return 0;
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
printf("\n enter the element to search");
scanf("%d",&j);
if(find(p,j)==1)
printf("found");
else
printf("not found");
return 0;
}


