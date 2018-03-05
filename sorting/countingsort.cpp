

#include<stdio.h>
#include<malloc.h>


int* countingsort(int a[],int n,int b[],int k)
{
	int c[k],i,j;
	for(i=0;i<k;i++)
	c[i]=0;
	
	for(j=0;j<n;j++)
	c[a[j]]=c[a[j]]+1;
	
	for(i=1;i<k;i++)
	c[i]=c[i]+c[i-1];
	
	for(j=n-1;j>=0;j--)
	{
		b[c[a[j]]-1]=a[j];
		c[a[j]]=c[a[j]]-1;
	}
	return b;
}
int main()
{
	int a[20],n,i,k,b[20];
	printf("Enter the no of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
		printf("Enter the no of consecutive elements");
	scanf("%d",&k);
	int *p = countingsort(a,n,b,k);
	for(i=0;i<n;i++)
	{
		printf("%d",*(p+i));
	}
}

