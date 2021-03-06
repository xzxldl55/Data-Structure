
typedef int ElemType;//举例将ElemyType类型定义为int
typedef struct {//创建顺序表结构体
        ElemType *elem;//用指针模拟数组，以实现动态分配内存
        int length;//表长
        int listsize;//实际空间大小
        int incrementsize;//每次可增加长度
}SqList;
//顺序表的基本操作接口
//初始化函数(创建顺序表，表最大容量为maxsize，每次可扩容incrementsize，返回顺序表首地址)
void InitList(SqList &L,int maxsize,int incrementsize);
int ListLength(SqList L);
int LocateElem(SqList L,ElemType e);
bool ListInsert(SqList &L,int i,ElemType e);
ElemType ListDeleteSit(SqList &L,int i,ElemType e);
bool ListDeleteVal(SqList &L,ElemType e);
ElemType GetElem(SqList &L,int i);
//创建顺序表
void ListCreate(SqList &L,ElemType *E,int i);
