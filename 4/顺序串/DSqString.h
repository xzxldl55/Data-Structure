#ifndef DSQSTRING_H_INCLUDED
#define DSQSTRING_H_INCLUDED
        typedef struct{
                char *str;//存放串的首地址
                int length;//串长度
        }DSqString;

        //！！！！动态串的长度就等于其容量大小，当不够时，要多少分多少。

        //赋值
        bool StrAssign_Sq(DSqString &S,char *chars){
                //将chars赋给S
                int i,j;
                char *c;
                for(i = 0,c = chars;*c;i++,c++)//遍历chars从而获取其字符串长度
                if(!i){//当chars为空串时将S置空。
                        S.str = NULL;S.length = 0;
                }
                else{
                        if(!(S.str = (char *)malloc(i*sizeof(char))))return false;//分配内存

                        for(j=0;j<i;j++)
                                S.str[j] = chars[j];
                        S.length = i;
                }
                return true;
        }

        //串复制
        bool StrCopy_Sq(DSqString &S,DSqString T){
                int i;
                if(S.str)free(S.str);//释放S原有的的字符串空间
                if(!T.length){S.str = NULL;S.length = 0;}//如果T是空串，将S置空
                else{
                        if(!(S.str = (char *)malloc(T.length*sizeof(char))))return false;
                        for(i=0;i<T.length;i++)
                                S.str[i] = T.str[i];
                        S.length = T.length;
                }
                return true;
        }
        //串长
        int StrLength_Sq(DSqString S){return (S.length);}

        //串比较-->从前到后比较同则继续比较，亦则区分大小
        int StrCompare_Sq(DSqString S,DSqString T){
                int i=0;
                while(i<S.length&&i<T.length){
                        if(S.str[i]>T.str[i]) return 1;//S>T返回1
                        else if(S.str[i]<T.str[i]) return -1;//S<T返回-1
                        i++;
                }
                if(i<S.length) return 1;//当T比完了，S却还有。即S>T
                else if(i<T.length) return -1;

                return 0;//相等返回0
        }

        //串连接
        bool StrConcat_Sq(DSqString &S,DSqString T){
                //将顺序串T连接在S之后，返回连接后的S
                int i;
                if(T.length){//当T为空串时，啥也不用做
                        if(!(S.str = (char *)realloc(S.str,(S.length+T.length)*sizeof(char)))) return false;//分配空间
                        for(i=0;i<T.length;i++){
                                S.str[S.length+i]=T.str[i];
                        }
                        S.length += T.length;
                }

                return true;
        }

        //取子串！！
        bool SubString(DSqString S,DSqString &Sub,int pos,int len){
                int i;
                if(pos<0||pos>S.length-1||len<0||len>S.length-pos)return false;//位置或者长度不合理
                if(Sub.str) free(Sub.str);//先释放原有空间
                if(!len){Sub.str = NULL;Sub.length = 0;}
                else{
                        if(!(Sub.str = (char *)malloc(len*sizeof(char))))return false;
                        for(i=0;i<len;i++){
                                Sub.str[i] = S.str[pos+i];
                        }
                        Sub.length = len;
                }
                return true;
        }

        //子串定位
        bool Index_Sq(DSqString S,DSqString T,int &pos){
                //存在则用pos返回首地址
                int i,j;
                i = j = 0;
                while(i<S.length&&i<T.length){
                        if(S.str[i] == T.str[j]){i++;j++;}//对应字符相同则一直比较下去
                        else{//出现不同的字符，i回溯，重新开始下一次匹配
                                i = i-j+1;//
                                j = 0;
                        }
                }
                if(j == T.length){
                        pos = i-T.length;
                        return true;
                }
                else return false;
        }

        //插入子串
        bool StrInsert_Sq(DSqString &S,int pos,DSqString T){
                //在顺序串S的第pos个字符之前插入子串T并返回s-->pos是位序
                int i;
                if(pos<0||pos>S.length)return false;
                if(T.str){
                        if(!(S.str = (char *)realloc(S.str,(S.length+T.length)*sizeof(char))))return false;
                        for(i=S.length-1;i>=pos;i--){//为T挪出位置
                                S.str[i+T.length] = S.str[i];
                        }
                        for(i = 0;i<T.length;i++){//将T插入
                                S.str[pos+i] = T.str[i];
                        }
                        S.length += T.length;
                }
                return true;
        }

        //删除子串

        bool StrDelete_Sq(DSqString &S,int pos,int len){
                //从顺序串S的第pos个字符开始删除长度为len的子串，并返回S
                int i;
                if(pos<0||len<0||pos+len>S.length)return false;
                //元素前移-->删除子串
                for(i = pos+len;i<=S.length-1;i++){
                        S.str[i-len] = S.str[i];
                }
                //即使pos+len==S.length也没关系，会直接被realloc给删除
                S.str = (char*)realloc(S.str,(S.length-len)*sizeof(char));
                S.length = S.length-len;
                return true;
        }

        //置换子串
        void StrReplace_Sq(DSqString &S, DSqString T,DSqString V)
        {  // 用串V置换主串S中出现的所有与T相等的不重叠子串，并返回置换后的串S
                int  pos;
                while(Index_Sq(S,T,pos))                    // 判断T是否是S的子串
                {
                        StrDelete_Sq(S,pos,T.length);             // 删除子串T
                        StrInsert_Sq(S,pos,V);                    // 插入子串V
                }
        }

        //串的遍历
        void StrTraveres_Sq(DSqString S)
        {
                int i;
                for(i=0;i<StrLength_Sq(S);i++)
                        cout<<S.str[i];
                cout<<endl;
        }

        //串的撤销

        void DestroyString_Sq(DSqString &S)
        {
                free(S.str);
                S.str=NULL;        // S.str置空
                S.length=0;
        }





#endif // DSQSTRING_H_INCLUDED
