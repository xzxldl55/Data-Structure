#ifndef SQQUEUE_H_INCLUDED
#define SQQUEUE_H_INCLUDED
        typedef struct{
                ElemType *queue;
                int front;//队首-->指向队首。。出队是先出在移动队首
                int rear;//队尾-->指向队尾的下一个。。所以进队是先进在移动队尾
                int queuesize;
                int incrementsize;
        }SqQueue;
        //初始化
        void InitQueue_Sq(SqQueue &Q,int maxsize,int incresize){
                Q.queue = (ElemType *)malloc(maxsize*sizeof(ElemType));//构造一个空的循环队列空间

                if(!Q.queue) exit(1);
                Q.front = 0;
                Q.rear = 0;
                Q.queuesize = maxsize;
                Q.incrementsize = incresize;
        }
        //求长
        int QueueLength_Sq(SqQueue Q){
                return (Q.rear - Q.front + Q.queuesize)%Q.queuesize;
        }
        //进队
        bool EnQueue_Sq(SqQueue &Q,ElemType e){
                if((Q.rear+1)%Q.queuesize == Q.front){//队满
                        Q.queue = (ElemType *)realloc(Q.queue,(Q.queueusize+Q.incrementsize)*sizeof(ElemType));//增补空间
                        if(!Q.queue)return false;
                        if(Q.front>Q.rear){//队首指针在队尾后面-->重新定位队首位置
                                int i;
                                for(i = Q.queuesize-1;i>=Q.front;i--){
                                        //将Q.front到Q.queuesize-1之间的元素后移Q.incrementsize个位置
                                        Q.queue[i+Q.incrementsize] = Q.queue[i];
                                }
                                Q.front += Q.incrementsize;//队首指针移动到原来元素的位置
                        }
                        Q.queuesize += Q.incrementsize;
                }
                Q.queue[Q.rear] = e;
                Q.rear = (Q.rear+1)%Q.queuesize;//队尾指针顺时针移动一个位置
                return true;
        }

        //出队
        bool DeQueue_Sq(SqQueue &Q,ElemType &e){
                if(Q.front == Q.rear)return false;//队空
                e = Q.queue[Q.front];//返回出队的元素值
                Q.front = (Q.front+1) % Q.queuesize;
                return true;0
        }
        //取队首
        bool GetHead_Sq(SqQueue Q,ElemType &e){
                if(Q.front == Q.rear) return false;
                e = Q.queue[Q.front];
                return true;
        }

        //判空
        bool QueueEmpty_Sq(SqQueue Q){
                return Q.rear == Q.front;//队空返回true
        }
        //撤销
        void DestroyQueue_Sq(SqQueue &Q){
                freelist(Q.queue);
                Q.queuesize = 0;
                Q.front = Q.rear = 0;
        }
#endif // SQQUEUE_H_INCLUDED
