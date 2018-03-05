
#include<stdio.h>
#include<malloc.h>
#include<math.h>

//first create a struct heap
struct heap {
	int *array;
	int count;
	int capacity;
	int heap_type;	
};

struct heap *CreateHeap(int capacity,int heap_type)
{
	struct heap *h = (struct heap *)malloc(sizeof(struct heap));
	if(h==NULL)
	{
		printf("error");
		return NULL;
	}
	h->heap_type=heap_type;
	h->count=0;
	h->capacity=capacity;
	h->array=(int *)malloc(sizeof(int)*h->capacity);
	if(h->array==NULL)
	{
		printf("error");
		return NULL;
	}
	return h;
}


int findParent(struct heap *h,int i)
{
	if(i<0||i>h->count)
	return -1;
	else
	return i-1/2;
	
}

int leftChild(struct heap *h,int i)//u get the index of parent and return index of left child
{
int left=(2*i)+1;
if(left>=h->count)
return -1;
else
return left;
}

int rightChild(struct heap *h,int i)//u get the index of parent and return index of left child
{
int right=(2*i)+2;
if(right>=h->count)
return -1;
else
return right;
}

int getMax(struct heap *h)
{
if(h->count==0)	
	return -1;
	else
	return h->array[0];
}

void percolateDown(struct heap *h,int i)
{
	int l,r,max,temp;
	l=leftChild(h,i);
	r=rightChild(h,i);
	max=i;
    if(l!=-1&&h->array[l]>h->array[max])
	max=l;
	if(r!=-1&&h->array[r]>h->array[max])
	max=r;	
	if(max!=i)
	{
		temp= h->array[i];
		h->array[i]=h->array[max];
		h->array[max]=temp;
        	percolateDown(h,max);	
	}	
	
}

int deleteMax(struct heap *h)
{
	int data;
	if(h->count==0)
	data=-1;
	else
	{
	data=h->array[0];
	 h->array[0] = h->array[h->count-1];
	h->count--;
	percolateDown(h,0);
}
return data;
}
void percolateUp(struct heap *h,int i)
{	
int temp;
if(i<=0||i>h->count)
return;

else
{
		if(h->array[i]>h->array[(i-1)/2])
        {
        	temp=h->array[(i-1)/2];
        	h->array[(i-1)/2]=h->array[i];
        	h->array[i]=temp;
        	percolateUp(h,(i-1)/2);	
		}
	
}

}

void ResizeHeap(struct heap *h)
{
	int *array_old=h->array;
	h->array=(int*)malloc(sizeof(int)*(h->capacity*2));
	if(h->array==NULL)
	{ 
	printf("memory error");
	return;
}
for(int i=0;i<h->capacity;i++)
{
	h->array[i]=array_old[i];
	h->capacity*=2;
	free(array_old);
}
	
}
void insert(struct heap *h,int data)
{
	int temp,i;
	if(h->count==h->capacity)
	ResizeHeap(h);
	h->count++;
	i=h->count-1;
	h->array[i]=data;
    percolateUp(h,i);  
		
}
void traverse(struct heap* h)
{
for(int i=0;i<h->count;i++)
{
	printf("\n%d",h->array[i]);
}
}
void buildHeap(struct heap *h,int n)
{
	int t,i;
	if(h==NULL)
	return;
	else
	while(n>h->capacity)
	ResizeHeap(h);
	printf("enter the elements");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&t);
		h->array[i]=t;
	}
	h->count=n;
	for(i=(n-1)/2;i>=0;i--)
	//for(i=0;i<=(n-1)/2;i++)
	{
		percolateDown(h,i);
	}
}
int main()
{
	int capacity,heap_type,n;
	printf("enter the capacity");
	scanf("%d",&capacity);
	printf("enter the heap_type");
	scanf("%d",&heap_type);	
   struct heap *h = CreateHeap(capacity,heap_type);
    printf("enter the size");
    scanf("%d",&n);
    buildHeap(h,n);
    traverse(h);
	  insert(h,2);
      insert(h,5);
      insert(h,6);
      insert(h,10);
      insert(h,14);
      insert(h,11);
      insert(h,20);
      insert(h,9);
      traverse(h);
      printf("you deleted %d",deleteMax(h));
      traverse(h);
      printf("you deleted %d",deleteMax(h));
     traverse(h);
	 printf("you deleted %d",deleteMax(h));
     traverse(h);
	 printf("you deleted %d",deleteMax(h));
     traverse(h);    
     printf("you deleted %d",deleteMax(h));
     traverse(h);
     printf("you deleted %d",deleteMax(h));
     traverse(h);
     printf("you deleted %d",deleteMax(h));
     traverse(h);
     printf("you deleted %d",deleteMax(h));
     traverse(h);
	// printf("you deleted %d",deleteMax(h));
     //printf("you deleted %d",deleteMax(h));
     

printf("%d",findParent(h,5));
}










