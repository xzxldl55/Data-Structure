#ifndef SLINKSTRING_H_INCLUDED
#define SLINKSTRING_H_INCLUDED
        //单链结构串
        typedef struct LNode{
                char str;//每个结点存放一个字符
                struct LNode *next;
        }SNode,*SLinkString;

        //带头结点！！！！！

        //串赋值
        void StrAssign_L(SLinkString &S,char *chars){
                SLinkString p,q;
                S=(SLinkString)malloc(sizeof(LNode));
                if(!(*chars))S->next =null;//chars为空,串S置空
                else{
                        p = S;
                        while(*chars){
                                q = (SLinkString)malloc(sizeof(LNode));//创建新的结点
                                q->str = *chars;
                                p->next = q;
                                p = q;//p始终指向表尾
                                chars++;
                        }
                        q->next =NULL;
                }
        }
        //串复制
        void StrCopy_L(SLinkString &S,SLinkString T){
                SLinkString p,q,r;
                while(S->next){//释放S原本的空间
                        p = S;
                        S = S ->next;
                        free(p);
                }
                r = T->next;
                p = S;
                while(r){
                        q = (SLinkString)malloc(sizeof(LNode));
                        q->str = r->str;
                        p->next = q;
                        p = q;
                        r = r->next;
                }
                p ->next = NULL;
        }
        //串长度
        int StrLength_L(SLinkString S){
                int n = 0;
                SLinkString p = S->next;//
                while(p){
                        n++;
                        p = p->next;
                }
                return n;
        }

        //串比较
        int StrCompare_L(SLinkString S,SLinkString T){
                SLinkString p=S->next,q = T ->next;
                while(p&&q){
                        if(p->str>q->str) return 1;
                        else if(p->str<q->str) return -1;
                        p = p->next;
                        q = q->next;
                }
                if(p) return 1;
                else if(q) return -1;
                return 0;
        }

        //串连接



#endif // SLINKSTRING_H_INCLUDED
