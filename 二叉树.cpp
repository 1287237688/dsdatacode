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

//创建二叉树 
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

//按竖向树状打印二叉树
void PrintTree(struct BinTreeNode *bt, int nLayer)  /* 按竖向树状打印的二叉树 */
//(1) 二叉树的横向显示应是二叉树竖向显示的90°旋转。
//分析上图可知，这种树形打印格式要求先打印右子树，再打印根，最后打印左子树，
//按由上而下顺序看，其输出的结点序列为：CFEADB，这恰为逆中序遍历。
//所以横向显示二叉树的算法为先右子树、再跟结点、再左子树的RDL结构。
//(2)在这种输出格式中，结点的左右位置与结点的深度有关，
//故算法中设置了一个表实当前跟结点层深的参数，
//以控制输出结点的左、右位置，每当递归进层时层深参数加1。
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

//二叉树的先序遍历
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

//二叉树的中序遍历 
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

//二叉树的后序遍历
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

//二叉树的层序遍历
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

//最大值判断
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

//最小值判断
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

//树高判断
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


//判断是否为平衡二叉树 
/*该函数判断二叉树p是否是一棵二叉搜索树，且其结点值都大于prev*/
bool isBSTInOrderHelper(struct BinTreeNode *p, int &prev)
{
 if (p==NULL) return true;
 if (isBSTInOrderHelper(p->Left, prev)) { // 如果左子树是二叉搜索树，且结点值都大于prev
  if (p->Element > prev) { //判断当前结点值是否大于prev，因为此时prev已经设置为已经中序遍历过的结点的最大值。
   prev = p->Element;
   return isBSTInOrderHelper(p->Right, prev); //若结点值大于prev，则设置prev为当前结点值，并判断右子树是否二叉搜索树且结点值都大于prev。
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
		printf("此树为二叉搜索树"); 
	}
	else printf("此树为二叉树");
}


//二叉搜索树的查找
struct BinTreeNode *Find(struct BinTreeNode *BinTree,int x){
	if(BinTree==NULL)  return NULL;
	if(x<BinTree->Element){
		Find(BinTree->Left,x);//左子树中递归查找 
	}
	else if(x>BinTree->Element){
		Find(BinTree->Right,x);
	}
	else  return BinTree;
}

void ifFind(struct BinTreeNode *BinTree,int x){
	if(Find(BinTree,x)){
		printf("此二叉平衡树中有元素%d",x);
	}
	if(!Find(BinTree,x))  printf("此二叉树中没有元素%d",x);
}


//二叉搜索树的插入操作
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

////输出插入元素之后的二叉搜索树
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

//二叉搜索树的删除操作(采用右子树最小元素代替所要删除节点)
struct BinTreeNode *Delete(struct BinTreeNode *BinTree,int x){
	struct BinTreeNode* BT;
	if(!BinTree){
		printf("要删除的元素没有找到");
	}
	else{
		if(x<BinTree->Element){
			BinTree->Left=Delete(BinTree->Left,x);
		}
		else if(x>BinTree->Element){
			BinTree->Right=Delete(BinTree->Right,x);
		}
		else{//BinTree就是要删除的那个节点 
			if(BinTree->Left&&BinTree->Right){//若被删除节点有左右两个子节点 
				BT=FindMin(BinTree->Right);//从右子树中找最小的元素填充该节点
				BinTree->Element=BT->Element;
				//从右子树中删除最小元素
				BinTree->Right=Delete(BinTree->Right,BinTree->Element); 
		}
		else{//被删除节点有一个或没有子节点 
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

////输出删除元素之后的二叉搜索树
//void PutDelete(struct BinTreeNode *BinTree,int x){
//	struct BinTreeNode *BT;
//	BT=Delete(BT,x);
//    LevelorderTraversal(BT);
//} 


int main(){
	struct BinTreeNode *BinTree,*BT,*B;
	int x;
	printf("************************二叉树操作集***********************\n");
	printf("请输入二叉树：\n");
	BinTree=CreateBinTree();
	//safe_flush(stdin);
	printf("\n");
	printf("打印二叉树如下：\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("*****判断此二叉树的类型：");
	ifBST(BinTree);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("二叉树的中序遍历：\n");
	InOrderTrversal(BinTree);
	printf("打印二叉树如下：\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("二叉树的先序遍历：\n");
	PreorderTraversal(BinTree);
	printf("打印二叉树如下：\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("二叉树的后序遍历：\n");
	PostorderTraversal(BinTree);
	printf("打印二叉树如下：\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("二叉树的层序遍历：\n");
	LevelorderTraversal(BinTree);
	printf("打印二叉树如下：\n");
	PrintTree(BinTree, 1);
	printf("\n");
	printf("\n");
	printf("查找二叉树的最大值：");
	max(BinTree);
	printf("\n");
	printf("\n");
	printf("查找二叉树的最小值：");
	min(BinTree);
	printf("\n");
	printf("\n");
	printf("二叉树的高度：");
	Height(BinTree);
	printf("\n");
	printf("\n");
	if(isBSTInOrder(BinTree)){
			printf("输入所要查找的值：");
	        scanf("%d",&x);
	        printf("判断二叉树中是否有此值："); 
	        ifFind(BinTree,x);
	        printf("\n");
	        printf("\n");
	        //safe_flush(stdin);
	        printf("输入所要插入的值:");
	        scanf("%d",&x);
	        printf("输出插入结点之后的二叉树(前序遍历)：\n");
	        BT=Insert(BinTree,x);
	        PreorderTraversal(BT);
	        printf("打印二叉树如下：\n");
        	PrintTree(BT, 1);
 	        printf("\n");
	        printf("\n");
	        //safe_flush(stdin);
	        printf("输入所要删除结点的值："); 
	        scanf("%d",&x);
			printf("输出删除节点之后的二叉树(前序遍历)：\n");
			B=Delete(BinTree,x);
	        PreorderTraversal(B);
	        printf("\n");
	        printf("打印二叉树如下：\n");
        	PrintTree(B, 1);
	   }
	return 0;
}

