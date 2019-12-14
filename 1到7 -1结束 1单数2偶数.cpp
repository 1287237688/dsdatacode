#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}LinkListNode;
int main()
{
	int n,i;
	scanf("%d",&n);
	LinkListNode *head,*p,*node;
	if(n == 0)
	{
		return 0;
	}
	node = (LinkListNode*)malloc(sizeof(LinkListNode));
	scanf("%d",&(node->data));
	node->next = NULL;
	p = head = node;
	for(i = 0;i<n-1;i++)
	{
		node = (LinkListNode*)malloc(sizeof(LinkListNode));
		scanf("%d",&(node->data));
		p->next = node;
		p = node;	
	}
	p = head;
	for(i = 0;i<n-1;i++)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("%d",p->data);
	return 0;
}
