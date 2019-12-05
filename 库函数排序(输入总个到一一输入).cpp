#include <iostream>
#include <algorithm>
#define MAXSIZE 50
using namespace std;
typedef int KeyType;

typedef struct                     
{  
	KeyType key;                                             
}ElemType;  

typedef  struct
{ 
	ElemType r[MAXSIZE+1]; 
	int length;
}SqList;                      

void Create(SqList &L)
{ 
	int i;
	cin>>L.length;
	for(i=1;i<=L.length;i++)
		cin>>L.r[i].key;   
}

void Output(SqList L)
{ 
	int i;
	for(i=1;i<=L.length;i++)
		cout<<L.r[i].key<<" ";
	cout<<endl;
}

int Partition(SqList &L,int low,int high)
{
    int a[55];
    for( int i=1; i<=high; i++ )
    	a[i] = L.r[i].key;
    sort(a+1,a+1+high);
    for( int i=1; i<=high; i++ )
        L.r[i].key = a[i];
}

void QuickSort(SqList &L, int low, int high)
{
    Partition(L,low,high);
}  

int main () 
{  
	SqList L;  
	int low,high;
	Create(L);
	low=1; 
	high=L.length;
	QuickSort(L,low,high);
	Output(L);
	return 0;
}
