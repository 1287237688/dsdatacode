#include <stdio.h>
#include <stdlib.h>
typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
BinTree BuildTree(); /* �ɲ���ʵ�֣�ϸ�ڲ��� */
bool IsBST ( BinTree T );

int main()
{
    BinTree T;

    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}
bool IsBST ( BinTree T ){
    BinTree p=NULL;
    if(!T){ /*�ݹ����*/
        return true;
    }
    else{ /*�ǿ���*/
        if(!T->Left){
            if(!T->Right)   /*���&&�ҿգ��ݹ����*/
                return true;
            else{           /*���&&�ҷǿգ���Ҫ�ж�������*/
                p = T->Right;
                while(p->Left){
                    p = p->Left;
                }
                if(T->Data >= p->Data)
                    return false;
                else
                    return IsBST(T->Right);
            }
        }
        else{   /*��ǿգ����ж�������*/
            p = T->Left;
            while(p->Right){
                p = p->Right;
            }
            if(T->Data <= p->Data)
                return false;
            else{
                if(!T->Right)   /*��ǿ�&&�ҿգ������ж�������*/
                    return IsBST(T->Left);
                else{           /*��ǿ�&&�ҷǿգ����ж�������*/
                    p = T->Right;
                    while(p->Left){
                        p = p->Left;
                    }
                    if(T->Data >= p->Data)
                        return false;
                    else
                        return ( IsBST(T->Left) && IsBST(T->Right) );
                    }
            }
        }
    }
}
