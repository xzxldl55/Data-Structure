#ifndef TSMATRIX_H_INCLUDED
#define TSMATRIX_H_INCLUDED
#define MAX_SIZE 100
//三元组顺序表
        //单个结点
        typedef struct{
                int i;
                int j;
                ElemType e;
        }Triple;

        //总述
        typedef struct{
                int m,n,t;//矩阵行数、列数、非零元/常数/重复元素个数
                Triple data[MAX_SIZE];
        }TSMatrix;

        //创建稀疏矩阵
        bool CreateSMatrix(TSMatrix &M){
                int i;
                Triple T;
                bool k;
                cout<<"请输入矩阵的行数、列数、非零元个数:";
                cin>>M.m>>M.n>>M.t;
                if(M.t>MAX_SIZE)return false;
                M.data[0].i = 0;//初始化第一个矩阵元素
                M.data[0].j = 0;
                //输入数据
                for(i = 0;i<M.t;i++){
                        do{
                                cout<<"（下三角存储）请按照行序输入第"<<i+1<<"个下三角元素所在的行（0~"<<M.m-1;
                                cout<<"），列（0~"<<M.n-1<<"），元素值：";
                                cin>>T.i>>T.j>>T.e;//输入单个结点元素
                                k = 0;//值得范围正确与否判断标志
                                if(T.i<0||T.i>=M.m||T.j<0|T.j>=M.n)k = 1;//输入的T行列，超出范围
                                if(i>0){
                                        if(T.i<M.data[i-1].i||T.i == M.data[i-1].i&&T.j<=M.data[i-1].j)k = 1;//行列顺序有误
                                }
                        }while(k);
                        M.data[i] = T;//正确值赋予M
                }
                return true;
        }

        //矩阵的复制
        void CopySMatrix(TSMatrix M,TSMatrix &T){
                //将M复制到T
                T = M;
        }

        //矩阵的转置(i,j互换)-->难点：转置后行列互换，其三元组之间次序发生改变
        void TransposeSMatrix(TSMatrix M,TSMatrix &T){
                //稀疏矩阵M的转置T
                int p,col,q = 0;//q-->T的当前元素
                //T的行列、非零元赋值
                T.m = M.n;
                T.n = M.m;
                T.t = M.t;
                //Begin
                if(T.t){//非空矩阵

                }
        }


        /*矩阵的加法
        bool AddSMaTrix(TSMatrix A,TSMatrix B,TSMatrix &C){
                int i,j;
                if(A.t == B.t){
                      C.m = A.m;
                      C.n = A.n;
                      C.t = A.t;
                      for(i = 0;i<C.t;i++){
                        C.data[i].i = A.data[i].i;
                        C.data[i].j = A.data[i].j;
                        C.data[i].e = A.data[i].e + B.data[i].e;
                      }
                      return true;
                }
                cout<<"A、B两矩阵行列不一，无法相加减";
                return false;
        }
        //显示对称矩阵
        void ShowSMaTrix(TSMatrix M){
                if(!M.t||!M.m||!M.n)exit(1);//零矩阵
                int i,j;
                for(i = 0;i<M.m;i++){
                        for(j = 0;j<M.n;j++){
                                if(i>=j) {cout<<M.data[(i*(i+1))/2+j].e<<" ";}
                                else {cout<<M.data[(j*(j+1))/2+i].e<<" ";}
                        }
                        cout<<endl;
                }
        }*/


#endif // TSMATRIX_H_INCLUDED
