
#include<stdio.h>
#include<conio.h>
#include<malloc.h>


int findParent(int i,int s[])
{
	int result;
	if(s[i]==i)
	return i;
	else
	result = findParent(s[i],s);
	s[i]=result;
	return result;
}

int Union(int i,int j,int s[],int r[])
{
	int o,t;
	o= findParent(i,s);
	t= findParent(j,s);
	if(r[o]>r[t])
	{
		s[t]=o;
	}
	
	else if(r[t]>r[o])
		s[o]=t;
	
		else if(r[t]==r[o])
	{
		s[t]=o;
		r[o]++;
	}

	
}

void makeSet(int s[],int len)
{
	for(int i=0;i<len;i++)
	s[i]=i;
	
}

int main()
{
	int s[5],r[5];
	r[0]=4;
	r[1]=3;
	r[2]=5;
	r[3]=1;
	r[4]=2;
	makeSet(s,5);
	Union(3,4,s,r);
	Union(0,1,s,r);
	Union(2,4,s,r);
	Union(1,2,s,r);
	printf("%d",findParent(3,s));
}
