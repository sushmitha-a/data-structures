
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

struct tree* findmax(struct tree *root,struct tree* max)
{   
	if(root)
	{
		
		if(root->data>max->data)
		{
		max= root;
	    max= findmax(root->right,max);
	    
        }
        return max;
}
return max;
}
struct tree *Delete(struct tree *p,int data)
{   
    struct tree *temp,*max;
	if(p)
	{
	   if(data>p->data)		
         p->right=Delete(p->right,data);
	
		else if(data<p->data)		
		 p->left=Delete(p->left,data);
	
	else
	{
		
		if(p->left&&p->right)
		{
			temp=findmax(p->left,max);
			p->data=temp->data;
			p->left=Delete(p->left,temp->data);
		}
		else
		temp=p;
		if(p->left==NULL)
		p=p->right;
		else
		p=p->left;
		free(temp);
	
}
return p;
}
else
printf("no element present");
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
printf("\n enter the element to delete");
scanf("%d",&j);
struct tree *g = Delete(p,j);
inorder(g);
return 0;
}


