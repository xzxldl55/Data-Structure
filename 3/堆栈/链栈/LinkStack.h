#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include <LinkStack.h>
typedef LinkList LinkStack;
//！！！！不带头结点
//初始化
void InitStack_L(LinkList &S){
        S = NULL;
}

//栈长
int StackLength_L(LinkStack S){
        int k = 0;
        LinkStack p =S;
        while(p){
                k++;
                p = p -> next;
        }
        return k;
}

//进栈
bool Push_L(LinkStack &S,ElemType e){
        LinkStack p;
        if((p = (LNode *)malloc(sizeof(LNode)))==NULL)return false;
        p ->data = e;
        p ->next = S;
        S = p;
        return true;
}

//出栈
bool Pop_L(LinkStack &S,ElemType &e){
        LinkStack p;
        if(S){
                p = S;
                S = S ->next;//栈顶下移
                e = p ->data;
                free(p)
                return true;
        }
        return false;
}
//取栈顶
bool GetTop_L(LinkStack S,ElemType &e){
        if(S){
                e = S ->data;
                return true;
        }
        return false;
}
//判空
bool StackEmpty_L(LinkStack S){
        if(!S)return true//空返回true
                return false;
}
//撤销
void DestroyStack_L(LinkStack &S){
        LinkStack p,p1;
        p = S;
        while(p){

                p1 = p;
                p = p->next;
                free(p1);
        }
        S = NULL;
}



#endif // LINKSTACK_H_INCLUDED
