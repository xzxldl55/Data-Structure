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
//删除位序为i的元素
ElemType ListDelete(SqList &L,int i,ElemType e){//删除位序i的元素，并将其返回
        int j;
        if(i<0 || i>L.length) return false;//位序不合法
        if(L.length <= 0) return false;//此表为空表
        e = L.elem[i];//将待删除元素传给e
        for(j = i+1;j<=L.length;j++)//将被删除元素之后的所有元素前移一位（将要删除的元素亦被覆盖）
                L.elem[j-1] = L.elem[j];
        L.length--;
        return e;
}
