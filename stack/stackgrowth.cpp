// To check if the stack grows up or down

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void stackGrowthcheck(int *temp)
{
	int temp2;
	printf("%d",temp);
	printf("\n%d",&temp2);
	if(temp>&temp2)
	printf("\nstack is upwards");
	else
	printf("\nstack is downwards");
}
int main(){
	
	int temp1;
	stackGrowthcheck(&temp1);
	
	return 0;
}
