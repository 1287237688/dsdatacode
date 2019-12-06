#include<stdio.h>
#include<stdlib.h>

//18 10 20 7 15 0 22 0 9 0 0 0 0 ^z

struct BinTreeNode{
	int Element;
	struct BinTreeNode *Left;
	struct BinTreeNode *Right;
}; 

//void safe_flush(FILE *fp)
//{
//	char ch;
//	while( (ch = fgetc(fp)) != EOF && ch != '\n' );          
//}

//���������� 
struct BinTreeNode *CreateBinTree(){
	int data;
	struct BinTreeNode *BinTree,*Temp,*Queue[100];
	int head=0,tail=0;
	scanf("%d",&data);
	if(data==0){
		return NULL;
	}
	else{
		BinTree=(struct BinTreeNode*)malloc(sizeof(struct BinTreeNode));
		BinTree->Element=data;
		BinTree->Left=BinTree->Right=NULL;
		Queue[tail++]=BinTree; 
	}
	while(head<tail){
		scanf("%d",&data);
		if(data==0) Queue[head]->Left=NULL;
		else{
			Temp=(struct BinTreeNode*)malloc(sizeof(struct BinTreeNode));
			Temp->Element=data;
			Temp->Left=Temp->Right=NULL;
			Queue[head]->Left=Temp;
			Queue[tail++]=Temp;
		}
		scanf("%d",&data);
		if(data==0) Queue[head]->Right=NULL;
		else{
			Temp=(struct BinTreeNode*)malloc(sizeof(struct BinTreeNode));
			Temp->Element=data;
			Temp->Left=Temp->Right=NULL;
			Queue[head]->Right=Temp;
			Queue[tail++]=Temp;
		}
		head++;
	}
	return BinTree;
}

//��������״��ӡ������
void PrintTree(struct BinTreeNode *bt, int nLayer)  /* ��������״��ӡ�Ķ����� */
//(1) �������ĺ�����ʾӦ�Ƕ�����������ʾ��90����ת��
//������ͼ��֪���������δ�ӡ��ʽҪ���ȴ�ӡ���������ٴ�ӡ��������ӡ��������
//�����϶���˳�򿴣�������Ľ������Ϊ��CFEADB����ǡΪ�����������
//���Ժ�����ʾ���������㷨Ϊ�����������ٸ���㡢����������RDL�ṹ��
//(2)�����������ʽ�У���������λ�����������йأ�
//���㷨��������һ����ʵ��ǰ��������Ĳ�����
//�Կ��������������λ�ã�ÿ���ݹ����ʱ���������1��
{
  if(bt ==NULL) 
    return;
  PrintTree(bt->Right,  nLayer+1);
  for(int i=0;i<nLayer;i++)
  {
     printf("    ");  
  }
  printf("%d\n",bt->Element);
    
  PrintTree(bt->Left,nLayer+1);
} 

//���������������
void PreorderTraversal(struct BinTreeNode *BinTree){
	if(BinTree){
		printf("%d ",BinTree->Element);
		if(BinTree->Left){
			PreorderTraversal(BinTree->Left);
		}
		if(BinTree->Right){
			PreorderTraversal(BinTree->Right);
		}
	}
} 

//��������������� 
void InOrderTrversal(struct BinTreeNode *BinTree){
	if(BinTree){
		if(BinTree->Left){
			InOrderTrversal(BinTree->Left);
		}
		printf("%d ",BinTree->Element);
		if(BinTree->Right){
			InOrderTrversal(BinTree->Right);
		}
	}
}

//�������ĺ������
void PostorderTraversal(struct BinTreeNode *BinTree){
	if(BinTree){
		if(BinTree->Left){
			PostorderTraversal(BinTree->Left);
		}
		if(BinTree->Right){
			PostorderTraversal(BinTree->Right);
		}
		printf("%d ",BinTree->Element);
	}
} 

//�������Ĳ������
void LevelorderTraversal(struct BinTreeNode *BinTree){
	struct BinTreeNode *Q[10000];
	struct BinTreeNode *BT;
	int head=0,tail=0;
	if(BinTree==NULL) return;
	else{
		Q[tail++]=BinTree;
		while(head<tail){
			printf("%d ",Q[head]->Element);
			if(Q[head]->Left){
				Q[tail++]=Q[head]->Left;
			}
			if(Q[head]->Right){
				Q[tail++]=Q[head]->Right;
			}
			head++;
		}
	}
}

//���ֵ�ж�
void max(struct BinTreeNode *BinTree){
	struct BinTreeNode *Q[10000];
	struct BinTreeNode *BT,*B;
	B=BinTree;
	int head=0,tail=0,max;
	if(B==NULL) return;
	else{
		Q[tail++]=B;
		while(head<tail){
			if(Q[head]->Left){
				Q[tail++]=Q[head]->Left;
			}
			if(Q[head]->Right){
				Q[tail++]=Q[head]->Right;
			}
			head++;
		}
	}
	max=Q[0]->Element;
	for(int i=0;i<tail;i++){
		if(Q[i]->Element>max){
			max=Q[i]->Element;
		}
	}
	printf("%d",max);
}

//��Сֵ�ж�
void min(struct BinTreeNode *BinTree){
	struct BinTreeNode *Q[10000];
	struct BinTreeNode *BT,*B;
	B=BinTree;
	int head=0,tail=0,min;
	if(B==NULL) return;
	else{
		Q[tail++]=B;
		while(head<tail){
			if(Q[head]->Left){
				Q[tail++]=Q[head]->Left;
			}
			if(Q[head]->Right){
				Q[tail++]=Q[head]->Right;
			}
			head++;
		}
	}
	min=Q[0]->Element;
	for(int i=0;i<tail;i++){
		if(Q[i]->Element<min){
			min=Q[i]->Element;
		}
	}
	printf("%d",min);
}

//�����ж�
int GetHeight(struct BinTreeNode *BinTree){
	int Lh,Rh,Max;
	if(BinTree){
		Lh=GetHeight(BinTree->Left);
		Rh=GetHeight(BinTree->Right);
		Max=Lh>Rh?Lh:Rh;
		return (Max+1);
	}
	else return 0;
} 

void Height(struct BinTreeNode *BinTree){
	printf("%d",GetHeight(BinTree));
}


//�ж��Ƿ�Ϊƽ������� 
/*�ú����ж϶�����p�Ƿ���һ�ö�����������������ֵ������prev*/
bool isBSTInOrderHelper(struct BinTreeNode *p, int &prev)
{
 if (p==NULL) return true;
 if (isBSTInOrderHelper(p->Left, prev)) { // ����������Ƕ������������ҽ��ֵ������prev
  if (p->Element > prev) { //�жϵ�ǰ���ֵ�Ƿ����prev����Ϊ��ʱprev�Ѿ�����Ϊ�Ѿ�����������Ľ������ֵ��
   prev = p->Element;
   return isBSTInOrderHelper(p->Right, prev); //�����ֵ����prev��������prevΪ��ǰ���ֵ�����ж��������Ƿ�����������ҽ��ֵ������prev��
  } 
  else {
   return false;
  }
 }
 else {
  return false;
 }
}

bool isBSTInOrder(struct BinTreeNode *root)
{
 int prev = INT_MIN;
 return isBSTInOrderHelper(root, prev);
}

void ifBST(struct BinTreeNode *root){
	if(isBSTInOrder(root)){
		printf("����Ϊ����������"); 
	}
	else printf("����Ϊ������");
}


//�����������Ĳ���
struct BinTreeNode *Find(struct BinTreeNode *BinTree,int x){
	if(BinTree==NULL)  return NULL;
	if(x<BinTree->Element){
		Find(BinTree->Left,x);//�������еݹ���� 
	}
	else if(x>BinTree->Element){
		Find(BinTree->Right,x);
	}
	else  return BinTree;
}

void ifFind(struct BinTreeNode *BinTree,int x){
	if(Find(BinTree,x)){
		printf("�˶���ƽ��������Ԫ��%d",x);
	}
	if(!Find(BinTree,x))  printf("�˶�������û��Ԫ��%d",x);
}


//�����������Ĳ������
struct BinTreeNode *Insert(struct BinTreeNode* BinTree,int x){
	if(!BinTree){
		BinTree=(struct BinTreeNode*)malloc(sizeof(struct BinTreeNode));
		BinTree->Element=x;
		BinTree->Left=BinTree->Right=NULL; 
	}
	else{
		if(x<BinTree->Element){
			BinTree->Left=Insert(BinTree->Left,x);
		}
		else if(x>BinTree->Element){
			BinTree->Right=Insert(BinTree->Right,x);
		}
	}
	return BinTree;
}

////�������Ԫ��֮��Ķ���������
//void PutInsert(struct BinTreeNode* BinTree,int x){
//	struct BinTreeNode *BT;
//	BT=Insert(BT,x);
//    LevelorderTraversal(BT);
//} 


struct BinTreeNode *FindMin(struct BinTreeNode *BinTree){
	struct BinTreeNode *Q[10000];
	struct BinTreeNode *BT,*B=NULL,*min;
	int head=0,tail=0;
	if(BinTree==NULL) return B;
	else{
		Q[tail++]=BinTree;
		while(head<tail){
			if(Q[head]->Left){
				Q[tail++]=Q[head]->Left;
			}
			if(Q[head]->Right){
				Q[tail++]=Q[head]->Right;
			}
			head++;
		}
	}
	min=Q[0];
	for(int i=0;i<tail;i++){
		if(Q[i]->Element<min->Element){
			min=Q[i];
		}
	}
	return min;
}

//������������ɾ������(������������СԪ�ش�����Ҫɾ���ڵ�)
struct BinTreeNode *Delete(struct BinTreeNode *BinTree,int x){
	struct BinTreeNode* BT;
	if(!BinTree){
		printf("Ҫɾ����Ԫ��û���ҵ�");
	}
	else{
		if(x<BinTree->Element){
			BinTree->Left=Delete(BinTree->Left,x);
		}
		else if(x>BinTree->Element){
			BinTree->Right=Delete(BinTree->Right,x);
		}
		else{//BinTree����Ҫɾ�����Ǹ��ڵ� 
			if(BinTree->Left&&BinTree->Right){//����ɾ���ڵ������������ӽڵ� 
				BT=FindMin(BinTree->Right);//��������������С��Ԫ�����ýڵ�
				BinTree->Element=BT->Element;
				//����������ɾ����СԪ��
				BinTree->Right=Delete(BinTree->Right,BinTree->Element); 
		}
		else{//��ɾ���ڵ���һ����û���ӽڵ� 
			BT=BinTree;
			if(!BinTree->Left){
				BinTree=BinTree->Right;
			} 
			else{
				BinTree=BinTree->Left;
			}
			free(BT);
		}
		}
	}
	return BinTree; 
}

////���ɾ��Ԫ��֮��Ķ���������
//void PutDelete(struct BinTreeNode *BinTree,int x){
//	struct BinTreeNode *BT;
//	BT=Delete(BT,x);
//    LevelorderTraversal(BT);
//} 


int main(){
	struct BinTreeNode *BinTree,*BT,*B;
	int x;
	printf("************************������������***********************\n");
	printf("�������������\n");
	BinTree=CreateBinTree();
	//safe_flush(stdin);
	printf("\n");
	printf("��ӡ���������£�\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("*****�жϴ˶����������ͣ�");
	ifBST(BinTree);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("�����������������\n");
	InOrderTrversal(BinTree);
	printf("��ӡ���������£�\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("�����������������\n");
	PreorderTraversal(BinTree);
	printf("��ӡ���������£�\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("�������ĺ��������\n");
	PostorderTraversal(BinTree);
	printf("��ӡ���������£�\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("�������Ĳ��������\n");
	LevelorderTraversal(BinTree);
	printf("��ӡ���������£�\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("���Ҷ����������ֵ��");
	max(BinTree);
	printf("\n");
	printf("\n");
	printf("���Ҷ���������Сֵ��");
	min(BinTree);
	printf("\n");
	printf("\n");
	printf("�������ĸ߶ȣ�");
	Height(BinTree);
	printf("\n");
	printf("\n");
	if(isBSTInOrder(BinTree)){
			printf("������Ҫ���ҵ�ֵ��");
	        scanf("%d",&x);
	        printf("�ж϶��������Ƿ��д�ֵ��"); 
	        ifFind(BinTree,x);
	        printf("\n");
	        printf("\n");
	        //safe_flush(stdin);
	        printf("������Ҫ�����ֵ:");
	        scanf("%d",&x);
	        printf("���������֮��Ķ�����(ǰ�����)��\n");
	        BT=Insert(BinTree,x);
	        PreorderTraversal(BT);
	        printf("��ӡ���������£�\n");
        	PrintTree(BT, 1);
 	        printf("\n");
	        printf("\n");
	        //safe_flush(stdin);
	        printf("������Ҫɾ������ֵ��"); 
	        scanf("%d",&x);
			printf("���ɾ���ڵ�֮��Ķ�����(ǰ�����)��\n");
			B=Delete(BinTree,x);
	        PreorderTraversal(B);
	        printf("\n");
	        printf("��ӡ���������£�\n");
        	PrintTree(B, 1);
	   }
	return 0;
}

