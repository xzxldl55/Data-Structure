
typedef int ElemType;//举例将ElemyType类型定义为int
typedef struct {//创建顺序表结构体
        ElemType *elem;//用指针模拟数组，以实现动态分配内存
        int length;//表长
        int listsize;//实际空间大小
        int incrementsize;//每次可增加长度
}SqList;
//顺序表的基本操作接口
void InitList(SqList &L,int maxsize,int incrementsize);
int ListLength(SqList L);
int LocateElem(SqList L,ElemType e);
bool ListInsert(SqList &L,int i,ElemType e);
ElemType ListDelete(SqList &L,int i,ElemType e);
