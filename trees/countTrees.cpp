
#include<stdio.h>
#include<malloc.h>
#include<math.h>
int sum;
int countTrees(int n)
{
	if(n<=1)
	return 1;
	else
	{
		int left,right,root;
		for(root=1;root<=n;root++)
		{
			left = countTrees(root-1);
			right = countTrees(n-root);
			sum+=left*right;
		}
		return(sum);
	}
}


int main()
{
	printf("enter the num");
	int j;
	scanf("%d",&j);
	printf("%d",countTrees(j));
}
