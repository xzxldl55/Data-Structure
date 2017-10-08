//定义结点结构体
typedef struct Node{
        ElemType data;
        struct Node *next;
}LNode,*LinkList;

//基本操作
void InitList_L(LinkList &L){
        L = (LNode *)malloc(sizeof(LNode));
        if(!L) exit(1);
        L -> next = NULL;
}
//求表长
int ListLength_L(LinkList L){
        LinkList p;
        int k = 0;
        p = L -> next;
        while(p){
                k++;
                p = p -> next;
        }
        return k;
}
//查找元素
LNode *LocateElem_L(LinkList L,ElemType e){
        LinkList p;
        p = p -> next;
        while(p&&p->data!=e)p = p->next;
        return p;
}
//插入元素--前插
bool ListInsert_L(LinkList &L,int i,ElemType e){
        LinkList p,s;
        int j;
        p = L;
        j = 0;
        //寻找第i-1个结点
        while(p->next&&j<i-1){
                p = p->next;
                j++;
        }
        if(j!=i-1)return false;
        if((s = LNode *)malloc(sizeof(LNode)) == NULL) exit(1);
        s -> data = e;
        s -> next = p -> next;
        p ->next = s;
        return true;
}
//删除元素
bool ListDelete_L(LinkList &L,int i,ElemType &e){
        LinkList p,q;
        int j;
        p = L;j = 0;
        while(p -> next -> next&&j<i-1){p = p->next;j++;}//寻找第i-1个结点，让p指向此节点
        if(j!=i-1)return false;
        q = p -> next;//Q为其后继结点，即需要删除的结点
        p ->next = q ->next;//删除q
        e = q->data;free(q);
        return true;
}
//取元素操作
bool GetElem_L(LinkList L,int i,ElemType &e){
        LinkList p;
        int j;
        p = L;
        j = 0;
        while(p->next&&j<i){
                p = p ->next;
                j++;
        }//将p移动到第i个结点处
        if(j!=i)return false;
        e = p->data;
        return true;
}
//创建单链表
//尾插建表
void CreateList_L_Rear(LinkList &L,ElemType a[],int n){//n为a[]元素个数
        LinkList p,q;int i;
        L = (LinkList)malloc(sizeof(LNode));//创建头结点
        q = L;//q始终指向尾结点
        for(i = 0;i<n;i++){
                p = (LinkList)malloc(sizeof(LNode));//创建新的结点
                p ->data = a[i];
                q ->next = p;//插入在尾结点之后
                q = p;//q指向新的尾结点
        }
        q ->next = NULL;//尾结点next制空
}
//头插建表
void CreateList_L_Front(LinkList &L,ElemType a[],int n){
        LinkList p;int i;
        L = (LinkList)malloc(sizeof(LNode));
        L ->next = NULL;
        for(i = n-1;i>=0;i--){
                p =  (LinkList)malloc(sizeof(LNode));
                p->data = a[i];
                p ->next = L ->next;
                L->next = p;
                //从后向前插
        }
}
//单链表遍历
void ListTraverse_L(LinkList L){
        LinkList p = L ->next;
        while(p){
                cout<<setw(6)<<p->data;
                p = p->next;
        }
        cout<<endl;
}
//撤销操作
void DestroyList_L(LinkList &L){
        LinkList p,p1;
        p = L;
        while(p){
                p1 = p;
                p = p->next;
                free(p1);
        }
        L = NULL;
}

