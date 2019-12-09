#include<stdio.h>
#include<stdlib.h>
struct line{
    int a;
    struct line *next;
}; 
struct line *create(int *arr,int n){
    struct line *head,*p1,*p2;
    p1=(struct line*)malloc(sizeof(struct line));
    p1->next=NULL;
    //p2->next=NULL;
    for(int i=0;i<n;i++){
        if(i==0){
            p1->a=arr[i];
            head=p1;
            p2=p1;
        }
        else{
            p1=(struct line*)malloc(sizeof(struct line));
            p1->a=arr[i];
            p2->next=p1;
            p2=p1;
        }
    }
    p2->next=NULL;
    return head;
}
int main(){
    struct line *p1;
    int arr[100],n,k,s=0;
    scanf("%d",&k);
    while(k!=-1){
        if(k%2!=0){
            arr[s]=k;
            s++;
        }
        scanf("%d",&k);
    }
    n=s;
    p1=create(arr,n);
    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("%d",p1->a);
        }
        else{
            printf("%d ",p1->a);
        }
        p1=p1->next;
    }
    return 0;
}
