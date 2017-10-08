#include <iostream.h>
using namespace std;
#include "SqList.h"
#include "stdlib.h"
#define MAXSIZE 100 //宏定义容量
#define LISTINCREMENT 10 //宏定义增长量
//初始化函数
void InitList(SqList &L,int maxsize = MAXSIZE,int incresize = LISTINCREMENT){
        L.elem = (ElemType *)malloc(maxsize*sizeof(ElemType));//分配一段最大容量为maxsize的数组空间
        if(!L.elem)exit(1);//分配失败，直接退出

        L.length = 0;
        L.listsize = maxsize;
        L.incrementsize = incresize;
}
//求表长
int ListLength(SqList L){
        return L.length;
}
//查找元素
int LocateElem(SqList L,ElemType e){//查找元素e在表L中的位置，成功返回其位序，失败返回 -1
        int i;
        for(i=0;i<L.length;i++)
                if(L.elem[i] == e)return i;
        return -1;
}
//插入元素操作——前插
bool ListInsert(SqList &L,int i,ElemType e){//将e插入在顺序表L的位序为i的元素之前
        int j;
        if(i<0 || i>L.length) return false;//不合法的位置
        if(L.length >= L.listsize){//当前存储空间已满，需增补空间
                L.elem = (ElemType *)realloc(L.elem,(L.listsize + L.incrementsize)*sizeof(ElemType));//重新划分空间
                if(!L.elem)return false;//分配失败
                L.listsize += L.incrementsize;//重新计算容量大小
        }

        for(j = L.length;j>i;i--)
                L.elem[j] = L.elem[j-1];//将被插入元素之后的所有元素预先后移
        L.elem[i] = e;
        L.length++;
        return true;
}
//匹配插入(原本就有序的前提下)
int ListInsertR(SqList &L,ElemType e){
        int j;
        int x;
        for(j=0;j<L.length;j++){
              if(L.elem[j]>=e)  x = j;
        }
        for(j = L.length;j>x;j--)
                L.elem[j] = L.elem[j-1];
        L.elem[x] = e;
        L.length++;
        return x;
}
//删除位序为i的元素
ElemType ListDeleteSit(SqList &L,int i,ElemType e){//删除位序i的元素，并将其返回
        int j;
        if(i<0 || i>L.length) return false;//位序不合法
        if(L.length <= 0) return false;//此表为空表
        e = L.elem[i];//将待删除元素传给e
        for(j = i+1;j<=L.length;j++)//将被删除元素之后的所有元素前移一位（将要删除的元素亦被覆盖）
                L.elem[j-1] = L.elem[j];
        L.length--;
        return e;
}
//删除值为e的元素-->表中元素值不相等
bool ListDeleteVal(SqList &L,ElemType e){
        int j;
        int i;//记录表中值为e的元素位序
        for(j=0;j<=L.length;j++)
                if(L.elem[j] == e){
                        i = j;
                        for(j = i;j<L.length;j++)
                                L.elem[j] = L.elem[j+1];
                        return true;
                }
        return false;
}
//取元素操作--已知位序返回元素值
ElemType GetElem(SqList &L,int i){
        if(i<0 || i>L.length)return false;
        if(L.length<=0)return false;
        return L.elem[i];
}
//遍历顺序表
void ListTraverse(SqList L){
        int i;
        for(i = 0;i<L.length;i++)
                cout <<L.elem[i];
        cout<<endl;
}
//创建顺序表
void ListCreate(SqList &L,ElemType *E,int length){
        int i;
        for(i=0;i<length;i++)
                L.elem[i] = E[i];
}

//就地逆置
void ListNiZhi(SqList &L){
        int i;
        int n = L.length;
        if(n/2 == 0){//偶数个
                for(i = 0;i<=(n-2)/2;i++){
                        L.elem[n-i] = L.elem[i];
                        L.elem[i] = L.elem[n-i-1];
                }
                //交换完之后变为逆序但在中间处有一个空位置
                for(i = n/2;i<=n;i++){
                        L.elem[i] = L.elem[i+1];
                }
                //此时已经将逆序表完成了
        }else{//当个数为单数时
                for(i = 0;i<(n-1)/2;i++){
                        L.elem[n-i] = L.elem[i];
                        L.elem[i] = L.elem[n-i-1];
                }
                for(i = ((n-1)/2)+1;i<=n;i++){
                        L.elem[i] = L.elem[i+1];
                }
        }

}

