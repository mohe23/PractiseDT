//  ����ת����ʮ����->������)
// ��������2ȡ�෨����ʮ������n����2���õ�����s����t��������sѹ��ջ������n��n=t���Դ�ѭ����ֱ��n==0
#include<stdio.h>
#include<stdlib.h>
#include"sfile.h"

void Initstack();//��ʼ��˳��ջ��������
void Push();//��ջ��������
se Pop();//��ջ��������

void conversion(int num,SqStack s){//ʮ����ת������  num-ʮ������  s-��Ŷ����ƴ���
    int e;
    Initstack(&s);//��ջ��˳��ջ����ʼ��
    while(num){// ����num�Ķ����Ʊ�ʾ
        Push(&s,num%2);// ������õ��Ķ���������ջ
        num = num/2;//����numֵ
    }
    while(s.top!=-1){// ��������Ʊ�ʾ
        e = Pop(&s);//ջ��Ԫ�س�ջ
        printf("%d",e);// ��ӡ��������
    }
}
/*
int main(){
    int n;
    SqStack r;//����1��ջ
    //Initstack(&r);//��ʼ��˳��ջr
    n=31;
    printf("%d�Ķ����Ʊ�ʾ��",n);
    conversion(n,r);

    //printf("ջ������ݣ� %d %d\n",r.top,r.stacksize);
return 0;
}*/
