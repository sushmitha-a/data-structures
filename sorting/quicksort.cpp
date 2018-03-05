
#include<stdio.h>
#include<malloc.h>


int partition(int a[],int low,int high)
{
	int pivot;
	pivot=a[high];
	int i = (low-1);
	
	for(int j=0;j<=high-1;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}		
	}
	int temp = a[high];
			a[high] = a[i+1];
			a[i+1] = temp;
	return i+1;
	
}

int quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int p =  partition(a,low,high);
		quicksort(a,low,p-1);
		quicksort(a,p+1,high);
	}
	
}

int main()
{
	int a[20],n,i;
	printf("Enter the no of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("jef");
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	printf("%d",a[i]);
    return 0;
}

