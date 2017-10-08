typedef int ElemType;
#include <stdlib.h>
#include <iostream>
#include <SqStack.h>
using namespace std;

int main(){
        SqStack mystack;
        int i,x,a[]={6,8,16,2,34,56,7,10,22,45,62,88,90,3,9};
        InitStack_Sq(mystack,10,10);
        for(i = 0;i<12;i++)
                if(!Push_Sq(mystack,a[i])){
                        cout<<"进栈失败"<<endl;
                        return 0;
                }

        if(!GetTop_Sq(mystack,x)){
                cout<<"取栈顶元素失败"<<endl;
                return 0;
        }

        cout<<"当前栈顶元素是"<<x<<endl;
        cout<<"当前顺序栈的长度为："<<StackLength_Sq(mystack)<<endl;

        cout<<"依次出栈的数据元素序列为：";
        while(!StackEmpty_Sq(mystack)){
                if(!Pop_Sq(mystack,x)){
                        cout<<"出栈失败"<<endl;
                        return 0;
                }
                cout<<x<<" ";
        }
        cout<<endl;
        cout<<"当前顺序栈的长度为："<<StackLength_Sq(mystack)<<endl;
        cout<<endl;
        DestroyStack_Sq(mystack);

        return 0;
}
