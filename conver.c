//  数制转换（十进制->二进制)
// 方法：除2取余法，将十进制数n除以2，得到余数s和商t，将余数s压入栈，更新n，n=t，以此循环，直到n==0
#include<stdio.h>
#include<stdlib.h>
#include"sfile.h"

void Initstack();//初始化顺序栈函数声明
void Push();//入栈函数声明
se Pop();//出栈函数声明

void conversion(int num,SqStack s){//十进制转二进制  num-十进制数  s-存放二进制代码
    int e;
    Initstack(&s);//给栈（顺序栈）初始化
    while(num){// 计算num的二进制表示
        Push(&s,num%2);// 将计算得到的二进制数入栈
        num = num/2;//更新num值
    }
    while(s.top!=-1){// 输出二进制表示
        e = Pop(&s);//栈顶元素出栈
        printf("%d",e);// 打印二进制数
    }
}
/*
int main(){
    int n;
    SqStack r;//定义1个栈
    //Initstack(&r);//初始化顺序栈r
    n=31;
    printf("%d的二进制表示：",n);
    conversion(n,r);

    //printf("栈相关数据： %d %d\n",r.top,r.stacksize);
return 0;
}*/
