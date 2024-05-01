// 顺序栈

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sfile.h"


void Initstack(SqStack *st){// 初始化顺序栈
    st->ele = (se*)malloc(sizeof(se)*maxsize);//给顺序栈创建1个大小是maxsize的数组。
    st->top=-1;//初始化“栈顶指针”值。
    st->stacksize=maxsize;//栈
}

void Push(SqStack *st,se elm){// 进栈操作，若把elm进栈
     if(st->top<(st->stacksize-1)){// 栈未满，可以将元素elm进栈。
         st->top++;//将栈顶指针加1，只要栈不空，栈顶指针始终指向栈顶元素。
         st->ele[st->top]=elm;//将元素elm进栈。
     }
     else// 栈已满，
         printf("顺序栈已满，进栈失败！\n");
}

se Pop(SqStack *st){// 将栈顶元素出栈
   se e;
   if(st->top!=-1){// 栈不空，将栈顶元素出栈。
       e = st->ele[st->top];//栈顶元素
       st->top--;//将栈顶指针指向新的栈顶元素。
       //printf("出栈成功！\n");
   }
   else
       printf("当前栈为空栈，出栈失败\n");

return e;
}

/*
int main(){
    SqStack s;// 虽然Initstack使用的参数是"SqStack*"，也可以定义1个SqStack型变量，带入该函数时，可以用“&s”。记住了。
    char a[10];
    int length,e;
    e=12;
    Initstack(&s);//初始化顺序栈s
    length = sizeof(a)/sizeof(a[0]);
    printf("length：%d  size：%d  top: %d\n",length,s.stacksize,s.top);
    //s.top=s.stacksize-1;// 将顺序栈容量增加到最大，使得“栈满”
    Push(&s,e);// 注意s是SqStack型变量，不是其指针变量。
    printf("进栈后，top：%d  栈顶元素：%d\n",s.top,s.ele[s.top]);//注意s是SqStack型变量，不是其指针变量
    e = Pop(&s);//出栈；
    printf("出栈，top：%d，e: %d\n",s.top,e);
return 0;
}
*/
