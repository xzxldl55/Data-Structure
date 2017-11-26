#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED
// 记得要定义TElemType和Nild在main函数中
    typedef BiTree ElemType;//将队列、堆栈的类型定义为二叉树链表类型
    //结构定义
    typedef struct BiTNode{
        TElemType data;
        struct BiTNode *lchild;//左孩子
        struct BiTNode *rchild;//右孩子
    }BiTNode,*BiTree;

    //基本操作
    //先序遍历
    void PreOrderBiTree(BiTree BT,void Visit(TElemType)){
        if(BT){
            Visit(BT->data);
            PreOrderBiTree(BT->lchild,Visit);//递归遍历左子树
            PreOrderBiTree(BT->rchild,Visit);
        }
    }
    //中序遍历
    void InOrderBiTree(BiTree BT,void Visit(TElemType)){
        if(BT){
            PreOrderBiTree(BT->lchild,Visit);//递归遍历左子树
            Visit(BT->data);
            PreOrderBiTree(BT->rchild,Visit);
        }
    }
    //后序遍历
    void PostOrderBiTree(BiTree BT,void Visit(TElemType)){
        if(BT){
            PreOrderBiTree(BT->lchild,Visit);//递归遍历左子树
            PreOrderBiTree(BT->rchild,Visit);
            Visit(BT->data);
        }
    }
    //层序遍历
    void LevelOrderBiTree(BiTree BT,void Visit(TElemType)){
        SqQueue Q;//利用队列遍历
        BiTree p;
        if(BT){//BT非空
            InitQueue_Sq(Q,MAXSIZE,10);//初始化队列
            EnQueue_Sq(Q,BT);//根指针进队
            while(!QueueEmpty_Sq(Q)){//队列非空
                DeQueue_Sq(Q,p);//元素出队，赋给p
                Visit(p->data);//出队即访问一遍
                if(p->lchild != NULL)//p有左孩子
                    EnQueue_Sq(Q,p->lchild);//左孩子入队，下一次while遍历之
                if(p->rchild !=NULL)
                    EnQueue_Sq(Q,p->rchild);
            }
            //while循环遍历，直到所有孩子遍历完毕
        }
    }
    //初始化操作
    void InitBiTree(BiTree &BT){
        BT = NULL;
    }
    //创建二叉树
    //先序遍历输入二叉树，#代替虚节点
    void CreateBiTree(BiTree &BT){
        //Nil表示#-->虚节点
        TElemType a;
        cin>>a;
        if(a==Nil)
            BT = NULL;//输入了一个空结点
        else{
            BT = (BiTree)malloc(sizeof(BiTNode));//生成根节点
            if(!BT) exit(1);//请求空间失败
            BT->data = a;
            CreateBiTree(BT->lchild);//递归创建左子树
            CreateBiTree(BT->rchild);//递归创建右子树
        }
    }
    //判空树
    bool BiTreeEmpty(BiTree BT){
        if(BT){
            return false;
        }else{
            return true;//为空树
        }
    }
    //求二叉树深度
    int BiTreeDepth(BiTree BT){
        int Lh,Rh;//分别为左/右子树的深度
        if(!BT) return 0;
        Lh = BiTreeDepth(BT->lchild);//递归求其深度，直接到左子树的最深处，在向上，第一次为return 0（最深处的叶子）在向上return执行，每次都会+1，由此得出深度
        Rh = BiTreeDepth(BT->rchild);
        return Lh>Rh?Lh+1:Rh+1;
    }
    //查找元素
    BiTree SearchBiTree(BiTree BT,TElemType e){
        BiTree p;//中介指针
        if(!BT) return NULL;
        if(BT->data == e) return BT;//查找成功返回指针
        if(BT->lchild){//递归查找
            p = SearchBiTree(BT->lchild,e);
            //若查找成功则返回除NULL外的指针，再返回出去
            if(p) return p;
        }
        if(BT->rchild){
            p = SearchBiTree(BT->rchild,e);
            if(p) return p;
        }
        return NULL;//查找失败
    }
    //查找双亲结点-->层序遍历类似
    BiTree Parent(BiTree BT,TElemType e){
        //查找e的双亲结点，为根节点则返回NULL
        SqQueue Q;//利用队列
        BiTree p;
        if(BT){//BT非空
            InitQueue_Sq(Q,MAXSIZE,10);//初始化队列
            EnQueue_Sq(Q,BT);//根指针进队
            while(!QueueEmpty_Sq(Q)){//队列非空
                DeQueue_Sq(Q,p);//元素出队，赋给p
                if(p->lchild&&p->lchild->data == e || p->rchild&&p->rchild->data ==e)//若p的左右孩子是要查找的结点
                    return p;//返回p
                else{
                    if(p->lchild)
                        EnQueue_Sq(Q,p->lchild)//没找到，再向下找
                    if(p->rchild)
                        EnQueue_Sq(Q,p->rchild);
                }
            }
            //while循环遍历，直到所有孩子遍历完毕
        }
        return NULL;//没找到
    }
    //查找左孩子结点
    BiTree LeftChild(BiTree BT,TElemType e){
        //查找e的左孩子，没有则返回NULL
        BiTree p;
        if(BT){
            p = SearchBiTree(BT,e);//找到e结点
            if(p)//成功找到
                return p->lchild;
        }
        return NULL;
    }
    //查找右孩子
    BiTree RightChild(BiTree BT,TElemType e){
        //查找e的右孩子，没有则返回NULL
        BiTree p;
        if(BT){
            p = SearchBiTree(BT,e);//找到e结点
            if(p)//成功找到
                return p->rchild;
        }
        return NULL;
    }
    //查找左兄弟
    BiTree LeftSibling(BiTree BT,TElemType e){
        //查找e的左兄弟，没有则返回NULL
        BiTree p;
        if(BT){
            p = Parent(BT,e);//找到其双亲
            if(p->lchild&&p->rchild&&p->rchild->data ==e)//如果e为其双亲的右孩子，且p有左孩子
                return p->lchild;
        }
        return NULL;
    }
    //查找右兄弟
    BiTree RightSibling(BiTree BT,TElemType e){
        //查找e的右兄弟，没有则返回NULL
        BiTree p;
        if(BT){
            p = Parent(BT,e);//找到其双亲
            if(p->lchild&&p->rchild&&p->lchild->data ==e)//如果e为其双亲的右孩子，且p有左孩子
                return p->rchild;
        }
        return NULL;
    }
    // 插入子树
    bool InsertBiTree(BiTree p,int LR,BiTree c){
        // p指向的是二叉树BT中的某个节点，根据LR的值将子树c做为p的孩子插入
        if(p){
            if(LR ==0){
                //左子树
                c->rchild = p->lchild;//将p的左子树做为c的右子树
                p->lchild = c;
            }else(LR ==1){
                c->rchild = p->rchild;
                p->rchild = c;
            }
            return true;
        }
        return false;
    }
    // ！！二叉树输出
    void PrintBiTree(BiTree BT,int n = 1){
        //采用凹入形式表达，n为缩进的层数，初值为1
        int i;
        if(!BT) return;//空树
        PrintBiTree(BT->rchild,n+1);//递归在n+1层打印右子树-->从最右开始向上打印
        for(i=2;i<n;i++)
            cout>>"    ";//打印空格
        if(n>1) cout>>"---";//非根打印连线
        cout>>BT->data<<endl;//打印当前节点值
        PrintBiTree(BT->lchild,n+1);
    }
    //二叉树撤销
    void DestroyBiTree(BiTree &BT){
        if(BT){
            DestroyBiTree(BT->lchild);
            DestroyBiTree(BT->rchild);
            free(BT);
            BT = NULL;
        }
    }
    //删除子树
    bool DeleteChild(BiTree p,int LR){
        if(p){
            if(LR ==0){
                DestroyBiTree(p->lchild);
            }else{
                DestroyBiTree(p->rchild)
            }
            return true;
        }
        return false;
    }
#endif // BITREE_H_INCLUDED
