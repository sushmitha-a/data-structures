

#include<stdio.h>
#include<conio.h>
void mergesort(int a[],int temp[],int left,int right)
{
	 
	int mid,flag=0;
	if(right>left)
	{
		mid = (right+left)/2;
		mergesort(a,temp,left,mid);
		mergesort(a,temp,mid+1,right);
	    merge(a,temp,left,mid+1,right);
	 }
	 
}
void merge(int a[],int temp[],int left,int mid,int right)	 
	 {
	 	int i,left_end,size,temp_pos;
	 	left_end = mid-1;
	 	temp_pos = left;
	 	size = right-left-1;
	 	
	 	while(left<left_end&&mid<right)
	 	{
	 		if(left<mid)
	 		{
	 			temp[temp_pos]=a[left];
	 			temp_pos=temp_pos+1;
	 		    left=left+1;
			 }
	 		
	 		else{
	 			temp[temp_pos]=a[mid];
	 			left=left+1;
	 			temp_pos = temp_pos+1;
	 			
			 }
		 }
		 while(left<=left_end)
		 {
		 	temp[temp_pos]=a[left];
		 	temp_pos=temp_pos+1;
		 	left=left+1;
		 }
	 	while(mid<=right)
	 	{
	 		temp[temp_pos] = a[mid];
	 		temp_pos=temp_pos+1;
	 		
		 }
		 for(i=0;i<size;i++)
		 {
		 	a[right]=temp[right];
		 	right=right-1;
		 }
	 	
	 }
	 

int main()
{
	int a[20],temp[20],n,i;
	printf("Enter the no of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    mergesort(a,temp,0,n-1);
}
