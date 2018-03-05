
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


int checkIsomorphic(struct tree *p,struct tree *p1)
{
	//we should check if root exists in both and then do the do left and write 
	if(!p&&!p1)
	return 1;
	else
	if(p&&!p1||!p&&p1)
	return 0;
	else if(p&&p1)
	
	return(checkIsomorphic(p->left,p1->left)&&checkIsomorphic(p->right,p1->right));
	
}

int main()
{
struct tree *p,*p1;
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
printf("enter the no of elements");
scanf("%d",&n);
printf("enter the data");
scanf("%d",&data);
p1=newnode(data);
for(i=0;i<n-1;i++)
{
printf("enter the data");
scanf("%d",&data);
struct tree *t1 = insert(p1,data);				
}
printf("\ninorder ");
if(checkIsomorphic(p,p1))
printf("isomorphic");
else
printf("not isomorphic");
return 0;
}


