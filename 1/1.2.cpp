//定义一个学生类！
class stud{
        private: //声明以下部分为私有
                int num;
                char name[10];
                char sex;
        public://公共的属性&&方法
                stud(){
                        num = 10010;
                        strcpy(name,"De Loong");
                        sex = "F";
                }
                ~stud(){}
                void display(){
                        cout<<"num:"<<num<<endl;
                        cout<<"name:"<<name<<endl;
                        cout<<"sex:"<<sex<<endl;
                }
};
stud stud1;
