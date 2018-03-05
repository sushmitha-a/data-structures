
#include<stdio.h>
#include<malloc.h>
int* selectionsort(int a[],int n)
{
	int min;
for(int i=0;i<n-1;i++)
{
     min = i;
     for(int j=i+1;j<n;j++)
     {
     	if(a[min]>a[j])
     	min=j;
	 }
   int temp = a[min];
   a[min]= a[i];
   a[i]=temp;
   
   	}
	return a;	
	
}
int main()
{
	int a[20],n,i;
	printf("Enter the no of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	int *p = selectionsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",*(p+i));
	}
}

