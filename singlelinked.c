//implementation of single linked list in c we keep  number
#include<stdio.h>
#include<stdlib.h>

//create an node sturcture
struct Node
{
	int data;
	struct Node *link;
};


//create header node
struct Node *header=NULL;

//create a node
struct Node *createNode(int data)
{

//declare a newnode for address location
	struct Node *newnode;
	newnode=(struct Node *)malloc(sizeof(struct Node));

//we access a data into newnode
	newnode->data=data;
	newnode->link=NULL;
	return(newnode);
}
int main()
{
	struct Node *node;
	node=createNode(10);
printf("Node data:%d\n",node->data);
return(0);
}


	
