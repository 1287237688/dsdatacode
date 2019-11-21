#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node,*pNode;
 
typedef struct
{
	pNode front;
	pNode rear;
}Queue,*pQueue;
 
void init(pQueue q)
{
	q->front=q->rear=(pNode)malloc(sizeof(Node));
}

int QueueLength(pQueue q)
{
	int count=0;
	pNode p=q->front->next;
	while(p!=NULL){
	count++;
	p=p->next;
	}
	printf("\n");
	return count;
}

void enqueue(pQueue q,int x)
{
	pNode pNew=(pNode)malloc(sizeof(Node));
	pNew->data=x;
	pNew->next=NULL;
	q->rear->next=pNew;
	q->rear=pNew;
}

void dequeue(pQueue q,int *e)
{
	pNode pTemp=(pNode)malloc(sizeof(Node));
	pTemp=q->front->next;
	*e=pTemp->data;
	q->front->next=pTemp->next;
	free(pTemp);
}
 
void show_queue(pQueue q)
{
	pNode p=q->front->next;
	printf(" ��ǰԪ�ش�ͷ��β:");
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
void GetHead(pQueue q,int *e){
	*e=q->front->next->data;
}
int main(){
	int count;
	int x;
	int e;
	Queue q;
	init(&q);
	printf("_____���10��Ԫ��_____");
	for(int i=0;i<10;i++){
		enqueue(&q,i);
		count=QueueLength(&q);
		printf("%d���,��ǰ����Ԫ�ظ���:%d ",i,count);
		show_queue(&q);
	}
	printf("\n_____����5��Ԫ��_____");
	for(int i=0;i<5;i++){
		dequeue(&q,&x);
		count=QueueLength(&q);
		printf("%d����,��ǰ����Ԫ�ظ���:%d ",x,count);
		show_queue(&q);
	}
	GetHead(&q,&e);
	printf("\n��ǰ��ͷΪ:%d\n",e);
	system("pause");
}

