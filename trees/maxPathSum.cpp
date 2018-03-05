//find max path sum

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

int max=0;

int maxPathSum(struct tree *p,int sum){
	if(p)
	{
		sum=sum+p->data;
		int i = maxPathSum(p->left,sum);
		int j = maxPathSum(p->right,sum);
		if(i==0&&j==0)
		if(sum>max)
		max=sum;
		return 1;		
	}
	
	else
	return 0;
	
	
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
int sum=0;
maxPathSum(p,sum);
printf(" the max path sum is %d",max);
return 0;
}




