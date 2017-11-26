#ifndef HUFFMANTREE_H_INCLUDED
#define HUFFMANTREE_H_INCLUDED
#define MAXVALUE 50
#define MAXBIT 10
        //结点结构
        typedef struct{
                int weight;//权重
                int parent,lchild,rchild;
        }HTNode;
        //哈夫曼树->动态分配
        typedef HTNode *HuffmanTree;

        //前置算法1，返回哈夫曼树HT的前i个节点中权值最小和权值次小的根节点序号。
        void select(HuffmanTree HT,int i,int &x1,int &x2){
                //x1为权值较小的，x2为次小的
                int m1,m2;
                m1=m2=MAXVALUE;//权值中介，并赋予最大值初始化
                x1=x2=0;
                int j;
                for(j=0;j<i;j++){
                        if(HT[j].weight<m1&&HT[j].parent == -1){//权值小于之前便利到的权值最小值，且parent=-1-->之前还没有select过的
                                m2=m1;
                                x2=x1;
                                m1=HT[j].weight;
                                x1=j;
                        }else if(HT[j].weight<m2&&HT[j].parent == -1){
                                m2=HT[j].weight;
                                x2=j;
                        }
                }
        }

        //构造哈夫曼树
        void HuffmanTreeing(HuffmanTree &HT,int *w,int n){
                //w数组存放n个权值，构造n个叶子节点的哈夫曼树HT--可构造出节点数为2n-1的最优树
                int i,s1,s2;
                HT = (HuffmanTree)malloc((2*n-1)*sizeof(HTNode));//分配存储空间
                //初始化数组
                for(i=0;i<2*n-1;i++){
                        if(i<n)HT[i].weight=w[i];//前n个叶子赋权值
                        else HT[i].weight = 0;
                        HT[i].parent = -1;
                        HT[i].lchild = -1;
                        HT[i].rchild = -1;
                }
                for(i=n;i<2*n-1;i++){//构造其n-1个非叶子节点
                        select(HT,i,s1,s2);//选出两个小的权值结点
                        HT[i].wight = HT[s1].weight + HT[s2].weight;
                        HT[i].parent=-1;
                        HT[i].lchild = s1;
                        HT[i].rchild = s2;
                        HT[s1].parent = HT[s2].parent = i;
                }
        }
        //哈夫曼编码的转换
        //哈弗曼编码字符结点
        typedef struct{
                int weight;//结点权值
                char bit[MAXBIT];//存放编码序列的数组
                int start;//编码的起始下标
        }HTCode,*HuffmanCode;

        //求哈夫曼编码的算法
        void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int n){
                //求n个字符（叶子节点）的哈夫曼编码HC
                int i,j;
                int child,parent;
                HTCode cd;
                HC = (HuffmanCode)malloc(n*sizeof(HTCode));//给HC分配保存n个字符的空间

                for(i=0;i<n;i++){//由于哈夫曼树存储特点就是，叶子节点在前，双亲在后面，所以可以如此遍历叶子节点
                        cd.start = MAXBIT - 1;//不等长编码的最后一位为MAXBIT - 1
                        cd.weight = HT[i].weight;//取得对应编码权值
                        child = i;
                        parent = HT[child].parent;//parent 指向双亲
                        while(parent != -1){//从下向上走，一直走到根节点root
                                if(HT[parent].lchild == child)
                                        cd.bit[cd.start] = '0';//左孩子
                                else
                                        cd.bit[cd.start] = '1';//右孩子
                                cd.start--;//从后向前存放
                                child = parent;//child指向双亲
                                parent = HT[child].parent;
                        }
                        for(j = cd.start+1;j<MAXBIT;j++)
                                HC[i].bit[j] = cd.bit[j];//保存每个叶子节点的编码
                        HC[i].start = cd.start + 1;
                        HC[i].weight = cd.weight;
                }
        }

#endif // HUFFMANTREE_H_INCLUDED
