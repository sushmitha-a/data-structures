#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int blockSize;
struct ListNode{
int value;
struct ListNode *next;
};

struct LinkedBlock{
   struct LinkedBlock *next;
   struct ListNode *head;
   int nodeCount;
};

struct LinkedBlock *blockHead; //head pointer which is global

// create an empty block 
struct LinkedBlock* newLinkedBlock(){
struct LinkedBlock* block = (struct LinkedBlock*)malloc(sizeof(struct LinkedBlock));
block->next=NULL;
block->nodeCount=0;
block->head=NULL;
return block;
}

//create an empty node
struct ListNode* newListNode(int value){
struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
node->value=value;
node->next=NULL;	
return node;
}

//search element
void searchElement(int k,struct LinkedBlock **fLinkedBlock,struct ListNode **fListNode){
   //find the block and store the pointer to the block in **fLinkedblock so that it gets updated in the calling function without returning any pointer
   
   int j = (k+blockSize-1)/blockSize;  //to know in which clock it is present
   
   //now we have to traverse till that block
   //copy head into a var and traverse till that block and store the pointer to block address in fLinkedBlock
      
      struct LinkedBlock *p=blockHead; 
    while(--j)
    {
    	p=p->next;
	}
   *fLinkedBlock=p;
   
   //now find the node inside the block and return its pointer value to *fListNode
   //for that first take the head value of p and traverse
   
   struct ListNode* q=p->head;
   k=k%blockSize;
   if(k==0)
   {
   	k=blockSize;
	   }	
   k= p->nodeCount+1-k; //as head points to tail u shud find in reverse direction
   while(k--)
   {
   	q=q->next;
   }
   *fListNode=q;
}




//shift a block
void shift(struct LinkedBlock *A)
{
	struct LinkedBlock* B;
	struct ListNode* temp;
	// u shud shift only if the no of nodes in the block is greater than node size
	//now u shud check if there a next block present to shift  if not create a new block
 	while(A->nodeCount>blockSize)
	{
		if(A->next==NULL)
		{
			A->next=newLinkedBlock(); //u call this function to create a new block
			B=A->next;
			//now u shud move the tail of A to head of B
			temp=A->head->next;
		    A->head->next=A->head->next->next;//u removed the link to tail and stored in temp.Now u shud add it in B
		    B->head=temp;
		    temp->next=temp;//since its a circular ll its next will be itself
		    A->nodeCount--;
		    B->nodeCount++;
	}
	
	else  //if there is an exixting block after A then go to that block and add the element as head
	{
		//here no need to create a new block just go to A's next block and access the elements
		B=A->next;
		temp= A->head->next;
		A->head->next=A->head->next->next;
		temp->next=B->head->next;
	    B->head->next=temp;
	    B->head=temp;
	    A->nodeCount--;
	    B->nodeCount++;
		
	}
	A=B;
}
}

//to add an element we shud serach it and store its address in a ptr and then add it
void addElement(int k,int x)//this takes the k th element to be added with value x
{
	struct ListNode *p,*q;
	struct LinkedBlock *r;
	// 2 cases 1.when there is nothing present u need to create a block and create a node make it as head store the x value inside the node
	
	// first call the function 
	if(!blockHead) //if head pointer of the list of blocks is null
	{
		blockHead=newLinkedBlock();
		blockHead->head=newListNode(x);
		blockHead->head->next=blockHead->head;
		blockHead->nodeCount++;
	}
	else{
		if(k==0)//first postion
		{
		   p=blockHead->head;
		   q=p->next;
		   p->next=newListNode(x);
		   p->next->next=q;
		   blockHead->head=p->next;
		   blockHead->nodeCount++;
		   shift(blockHead);   // ull call the shift function to shift the tail node to the head of next block if nodecount>blocksize
		}
		else{
			searchElement(k,&r,&p);// here u got the position and block of the element
			q=p;
			while(q->next!=p)//traverse till u reach the before node of position p
				q=q->next;
				q->next=newListNode(x);
				q->next->next=p;
				r->nodeCount++;
			    shift(r);//now that u added the element in the right place u shud shift it 
			
		}
	}
	
	
}

int searchElement(int k)
{
	struct ListNode *p;
	struct LinkedBlock *q;
	searchElement(k,&q,&p); // if u send the address of a pointer it will be referred to as a double pointer so the actual value in the calling function gets 
	                          //modified and u need not return any thing
	                          
	return p->value;                          
}

int test(){
	
	int tt=clock();
	int m,i,k,x;
	char cmd[10];
	scanf("%d",&m);
	blockSize=(int)(sqrt(m-0.001))+1;
	for(i=0;i<m;i++)
	{
		scanf("%s",cmd);
		if(strcmp(cmd,"add")==0)
		{
			scanf("%d %d",&k,&x);
			addElement(k,x);
			
		}else if(strcmp(cmd,"search")==0)
		{
			scanf("%d",&k);
			printf("%d\n",searchElement(k));
			
		}else{
			fprintf(stderr,"wronginput\n");
		}
	}
	return 0;	
	
}


int main(){
	  test();
return 0;
}































