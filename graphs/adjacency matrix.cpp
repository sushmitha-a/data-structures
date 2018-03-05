
#include<stdio.h>
#include<malloc.h>
#include<conio.h>

struct graph{
	int v;
	int e;
	int **a;
};

struct graph* arrrep(int v1,int e1)
{
	int v2,v3,i,j;
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
	printf("hdg");
	if(!g)
	return NULL;
	g->v=v1;
	g->e=e1;
	g->a = (int **)malloc((g->v)* sizeof(int *));
    for (i=0;i<g->v; i++)
         g->a[i] = (int *)malloc((g->v) * sizeof(int));
		printf("wehf");
	if(g->a)
	printf("yes");
	
	for(i=0;i<g->v;i++)
	{
		for(j=0;j<g->v;j++)
		{
			g->a[i][j]=0;
		}
	}
	printf("sjdfh");
	for(i=0;i<g->e;i++)
	{
	printf("enter the edge ");
	
	scanf("%d %d",&v2,&v3);
	if(v2>=g->v||v3>=g->v)
	{
       printf("enter valid nos");
       scanf("%d %d",&v2,&v3);
		}
	g->a[v2][v3]=1;
}
	return g;
}


int main(){
	
	int v,e,i,j;
	printf("enter the noof vertices");
	scanf("%d",&v);
	printf("enter the no of edges");
	scanf("%d",&e);
	struct graph *g = arrrep(v,e);
    for(i=0;i<g->v;i++)	
    {
    	printf("\n");
    	{
    	for(j=0;j<g->v;j++)
          printf(" %d",g->a[i][j]);
	}
}


}



























