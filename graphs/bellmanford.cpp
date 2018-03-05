#include<stdio.h>
#include<malloc.h>
#include<conio.h>
 


struct ArrayQueue{
	int *array;  
	int capacity;
};

struct ArrayQueue *create(int size){
	struct ArrayQueue *s = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
	s->capacity = size;
	s->front=-1;
	s->rear=-1;
	s->array = (int*)malloc(sizeof(int));
	if(!s->array)
	return NULL;
	else 
	return s;
}

int emptyQueue(struct ArrayQueue *s)
{
	return(s->front==-1);
}
int fullQueue(struct ArrayQueue *s) 
{	
if((s->rear+1)%s->capacity==s->front)
return 1;
else 
return 0;
}

void Enqueue(struct ArrayQueue *s,int data)
{
	if(!fullQueue(s))
	{
	s->rear = ((s->rear+1)%s->capacity);	// ull first change the index value 
	s->array[s->rear]= data;
	if(s->front==-1)
	s->front=s->rear;
    }
else
printf("queue is full");
}

int searchQueue(struct ArrayQueue *s,int data)
{
	int p = s->front;
	if(!emptyQueue(s))
	{
	while(p!=(s->rear+1)%s->capacity)
	{
		if(s->array[p]==data)
		return 1;
		p++;
	}
}
	return 0;

}

int Dequeue(struct ArrayQueue *s)
{
	if(!emptyQueue(s))
	{
		int h=s->array[s->front];
		if(s->front==s->rear)
		{
			s->front=s->rear=-1;
		}
		else
		s->front = (s->front+1)%s->capacity;
		return h;
}
else
printf("queue is empty");
return NULL;
}		
		
		
void Delete(struct ArrayQueue *s)		
	{
	   if(s){
	   	if(s->array)
	   	free(s->array);
	   	free(s);
	   }
	   
	}
	
	
struct graph{
	int v;
	int e;
	int **a;
};

struct graph* arrrep(int v1,int e1)
{
	int v2,v3,i,j,d;
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
	if(!g)
	return NULL;
	g->v=v1;
	g->e=e1;
	g->a = (int **)malloc((g->v)* sizeof(int *));
    for (i=0;i<g->v; i++)
         g->a[i] = (int *)malloc((g->v) * sizeof(int));
	//g->a=(int**)malloc(sizeof(int)*((g->v)*(g->v)));
	if(g->a)
	printf("yes");
	
	for(i=0;i<g->v;i++)
	{
		for(j=0;j<g->v;j++)
		{
			g->a[i][j]=0;
		}
	}
	for(i=0;i<g->e;i++)
	{
	printf("enter the edge ");
	scanf("%d %d",&v2,&v3);
	printf("enter the distance ");
	scanf("%d",&d);
	if(v2>=g->v||v3>=g->v)
	{
       printf("enter valid nos");
       scanf("%d %d",&v2,&v3);
		}
	g->a[v2][v3]=d;
}
	return g;
}


int* bellmanford(graph *g,int l)
{
	int v= g->v;
	int distance[v],parent[v],size,nd;
	for(int i=0;i<v;i++)
	{
	distance[i]=0;
	parent[i]=0;
}
    printf("enter the size");
	scanf("%d",&size);
	struct ArrayQueue *s = create(size);
	Enqueue(s,l);	
	while(!emptyQueue(s))
	{
		printf("\n");
		int k = Dequeue(s);
		//printf("u dequeued %d",k);
	for(int i=0;i<v;i++)
	{
		
		if(i!=k)
		{
		if(g->a[k][i]!=0)
		{
			nd = g->a[k][i]+distance[k];
			if(distance[i]!=0&&nd<distance[i])
			{
				distance[i]=nd;
				parent[i]=k;
				//printf("%d",distance[i]);
			}
			else
			{
				if(distance[i]==0)
				{
				distance[i]=nd;
				parent[i]=k;
				//printf("%d",distance[i]);
			}
		}
			if(!searchQueue(s,i)&&g->a[i][i]!=-1)
			 {
			  Enqueue(s,i);
			  //printf("u enqueued %d",i);
		}
        }
}
}
//printf(" u passed %d %d",k,g->a[k][k]);
g->a[k][k]=-1;
}


int y;
for(int i=0;i<v;i++)
{
printf("%d",distance[i]);
}
return distance;
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

int *distance;
distance = bellmanford(g,0);
//printf("%d",*(distance+2));
}	


