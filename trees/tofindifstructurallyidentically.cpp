// to find if two tree are structurally identical
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


int structsame(struct tree *p,struct tree *p1)
{
	int i,j;
	if(p&&p1)
	{
	 	i= structsame(p->left,p1->left);
		j= structsame(p->right,p1->right);
		if(i==0||j==0)
		return 0;
		else return 1;
	}
	if(p==NULL&&p1==NULL)
	return 1;
	else 
	return 0;
}

int main()
{
struct tree *p,*p1;
int data,n,i;
printf("enter the no of elements of first tree");
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
printf("enter the no of elements of second tree");
scanf("%d",&n);
printf("enter the data");
scanf("%d",&data);
p1=newnode(data);
for(i=0;i<n-1;i++)
{
printf("enter the data");
scanf("%d",&data);
struct tree *t = insert(p1,data);		
}

if(structsame(p,p1))
printf("identical");
else
printf("not identical");
return 0;
}


