int correct(char*exp) {
        int i=0; ElemType x;
        SqStack st;
        InitStack_Sq(st,80,10);
        do{
                x=exp[i];
                switch(x)
                {
                        case'{':case'[':case'(':
                                Push_Sq(st,x);
                                break;
                        case')':
                                GetTop_Sq(st,x);
                                if(x!='(')return 0;
                                Push_Sq(st,x);
                                break;
                        case']':
                                GetTop_Sq(st,x);
                                if(x!='[') return 0;
                                Pop_Sq(st,x);
                                break;
                        case'}':
                                GetTop_Sq(st,x);
                                if(x!='{')return 0;
                                Pop_Sq(st,x);
                                break;
                        default:
                                break;
                }
                i++;
        }while(x!='＼0');
        return 1;
}
