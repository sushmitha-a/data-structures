

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


int inorder(struct tree *p,int path[],int len)
{
	if(p)
	{
		path[len]=p->data;
		len++;
		int m = inorder(p->left,path,len);
		int n = inorder(p->right,path,len);
		if(m==0&&n==0){
			printf("\n");
		for(int i=0;i<len;i++)
		printf("%d",path[i]);
	}
		len--;
	    return len;
	}
	else return 0;
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
int path[200];
inorder(p,path,0);
return 0;
}


