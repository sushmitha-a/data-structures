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

void inorder(struct tree *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d",p->data);
		inorder(p->right);
	}
}

void preorder(struct tree *p)
{
	if(p)
	{
		
		printf("%d",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(struct tree *p)
{
	if(p)
	{
		
		postorder(p->left);
		postorder(p->right);
		printf("%d",p->data);
	}
}

int main()
{
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
printf("\ninorder ");
inorder(p);
printf("\npreorder ");
preorder(p);
printf("\npostorder ");
postorder(p);
return 0;
}


