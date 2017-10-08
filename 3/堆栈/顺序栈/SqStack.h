#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED
        //#include <stdlib.h>此处不引用，防止在C/C++文件中再次引用，造成重复
        //即，使用此头文件时需自己引用stdlib头文件
        #define STACK_INIT_SIZE 100 //初始分配最大空间
        #define STACKINCREMENT 10
        typedef struct{
                ElemType * stack;
                int top;
                int stacksize;
                int incrementsize;
        }SqStack;

        void InitStack_Sq(SqStack &S,int maxsize = STACK_INIT_SIZE,int incresize = STACKINCREMENT){
                S.stack = (ElemType *)malloc(maxsize * sizeof(ElemType));
                if(!S.stack) exit(1);
                S.top = -1;//置空
                S.stacksize = maxsize;
                S.incrementsize = incresize;
        };//初始化

        int StackLength_Sq(SqStack S){
                return S.top+1;
        };//求堆栈长

        bool Push_Sq(SqStack &S,ElemType e){
                if(S.top == S.stacksize -1){
                        S.stack = (ElemType *)realloc(S.stack,(S.stacksize+S.incrementsize)*sizeof(ElemType));
                        if(!S.stack) return false;
                        S.stacksize += S.incrementsize;
                }
                S.stack[++S.top] = e;
                return true;
        };//进栈-->栈顶top指向元素e

        bool Pop_Sq(SqStack &S,ElemType &e){
                if(S.top == -1)return false;//栈空
                e = S.stack[S.top--];
                return true;
        };//出栈，用e带出出栈的值

        bool GetTop_Sq(SqStack S,ElemType &e){
                if(S.top == -1) return false;
                e = S.stack[S.top];
                return true;
        };//取栈顶元素;

        bool StackEmpty_Sq(SqStack S){
                if(S.top == -1) return true;
                return false;
        };//判空

        void DestroyStack_Sq(SqStack &S){
                free(S.stack);
                S.stacksize = 0;
                S.top = -1;
        };//撤销顺序栈




#endif // SQSTACK_H_INCLUDED
