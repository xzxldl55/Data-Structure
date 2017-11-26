#ifndef SQQUEUE_LENGTH_H_INCLUDED
#define SQQUEUE_LENGTH_H_INCLUDED
        typedef struct{
                ElemType *queue;
                int front;//队首-->指向队首。。出队是先出在移动队首
                int rear;//队尾-->指向队尾的下一个。。所以进队是先进在移动队尾
                int length;
                int queuesize;
                int incrementsize;
        }SqQueue;


#endif // SQQUEUE_LENGTH_H_INCLUDED
