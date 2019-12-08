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
BinTree BuildTree(); /* ÓÉ²ÃÅÐÊµÏÖ£¬Ï¸½Ú²»±í */
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
    if(!T){ /*µÝ¹é³ö¿Ú*/
        return true;
    }
    else{ /*·Ç¿ÕÊ÷*/
        if(!T->Left){
            if(!T->Right)   /*×ó¿Õ&&ÓÒ¿Õ£ºµÝ¹é³ö¿Ú*/
                return true;
            else{           /*×ó¿Õ&&ÓÒ·Ç¿Õ£ºÐèÒªÅÐ¶ÏÓÒ×ÓÊ÷*/
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
        else{   /*×ó·Ç¿Õ£ºÐèÅÐ¶Ï×ó×ÓÊ÷*/
            p = T->Left;
            while(p->Right){
                p = p->Right;
            }
            if(T->Data <= p->Data)
                return false;
            else{
                if(!T->Right)   /*×ó·Ç¿Õ&&ÓÒ¿Õ£ºÎÞÐèÅÐ¶ÏÓÒ×ÓÊ÷*/
                    return IsBST(T->Left);
                else{           /*×ó·Ç¿Õ&&ÓÒ·Ç¿Õ£ºÐèÅÐ¶ÏÓÒ×ÓÊ÷*/
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
