// ˳��ջ

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sfile.h"


void Initstack(SqStack *st){// ��ʼ��˳��ջ
    st->ele = (se*)malloc(sizeof(se)*maxsize);//��˳��ջ����1����С��maxsize�����顣
    st->top=-1;//��ʼ����ջ��ָ�롱ֵ��
    st->stacksize=maxsize;//ջ
}

void Push(SqStack *st,se elm){// ��ջ����������elm��ջ
     if(st->top<(st->stacksize-1)){// ջδ�������Խ�Ԫ��elm��ջ��
         st->top++;//��ջ��ָ���1��ֻҪջ���գ�ջ��ָ��ʼ��ָ��ջ��Ԫ�ء�
         st->ele[st->top]=elm;//��Ԫ��elm��ջ��
     }
     else// ջ������
         printf("˳��ջ��������ջʧ�ܣ�\n");
}

se Pop(SqStack *st){// ��ջ��Ԫ�س�ջ
   se e;
   if(st->top!=-1){// ջ���գ���ջ��Ԫ�س�ջ��
       e = st->ele[st->top];//ջ��Ԫ��
       st->top--;//��ջ��ָ��ָ���µ�ջ��Ԫ�ء�
       //printf("��ջ�ɹ���\n");
   }
   else
       printf("��ǰջΪ��ջ����ջʧ��\n");

return e;
}

/*
int main(){
    SqStack s;// ��ȻInitstackʹ�õĲ�����"SqStack*"��Ҳ���Զ���1��SqStack�ͱ���������ú���ʱ�������á�&s������ס�ˡ�
    char a[10];
    int length,e;
    e=12;
    Initstack(&s);//��ʼ��˳��ջs
    length = sizeof(a)/sizeof(a[0]);
    printf("length��%d  size��%d  top: %d\n",length,s.stacksize,s.top);
    //s.top=s.stacksize-1;// ��˳��ջ�������ӵ����ʹ�á�ջ����
    Push(&s,e);// ע��s��SqStack�ͱ�����������ָ�������
    printf("��ջ��top��%d  ջ��Ԫ�أ�%d\n",s.top,s.ele[s.top]);//ע��s��SqStack�ͱ�����������ָ�����
    e = Pop(&s);//��ջ��
    printf("��ջ��top��%d��e: %d\n",s.top,e);
return 0;
}
*/
