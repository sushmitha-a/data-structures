
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


int findLCA(struct tree *p,int a,int b)
{
	int u;
	if(p)
	{
		
	    if(p->data<a&&p->data>b||p->data>a&&p->data<b)
        return p->data;
        else
        {
        if(p->data>a&&p->data>b)
		u= findLCA(p->left,a,b);
		else
		u= findLCA(p->right,a,b);
		return u;
	}
}
return 0;
}

int main()
{
struct tree *p;
int data,n,i,a,b;
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
printf("enter the limits");
scanf("%d %d",&a,&b);
findLCA(p,a,b);
printf("\npostorder ");
printf("%d",findLCA(p,a,b));
return 0;
}


