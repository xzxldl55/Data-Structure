#include "iostream.h"
int max(int a,int b){
	return(a>b?a:b);
}
float max(float a,float b,float c){
	float t = a;
	if(t<b) t = b;
	if(t<c) t = c;
	return t;
}
int main(){
        cout<<"max(2,3)="<<max(2,3)<<endl;
        cout<<"max(2.3,5.6,3.1)="<<max(2.3,5.6,3.1)<<endl;
        return 0;
}

