// ������������������ǵݹ��㷨

#include<stdio.h>
#include<stdlib.h>
#include"sfile.h"// ���õ��������ڵ�BiTNode�Ľṹ�嶨��
// ���У�Ҫ����дջ�Ķ����Լ���ز���
// #define maxsize 20
typedef struct{
     BiTNode *dat;//BiTNode�������������
     int top;//ջ��ָ�룬ջ��ʱ��top==-1
     int size;//ջ���������
}Tstack;

void InitTstack(Tstack *t){// ��ʼ��ջ ��ʹ��ָ�������������ԡ���������ջ�Ĳ������
    t->dat = (BiTNode*)malloc(sizeof(BiTNode)*maxsize);//��ջt����洢�ռ�
    t->top=-1;//��ʾջ��
    t->size = maxsize;//ջ�����������
}

void TPush(Tstack *t,BiTNode b){// �����b��ջ��
     if(t->top!=(t->size-1)){// ��ʾջδ�������Խ������������ջ
         t->top++;//ջ����ʱ��ջ��ָ��ʼ��ָ��ջ��Ԫ��
         t->dat[t->top] = b;//���������ڵ���ջ��
         printf("TPushִ�н�����������ڵ���ջ�ɹ���\n");
     }
     else{// ջ��
         printf("TPushִ�н�����������ڵ���ջʧ�ܣ�ջ������\n");
     }
}

int EmptyTstack(Tstack *t){// �ж�ջs�Ƿ��ǿ�ջ�����ǿ�ջ����1�����򷵻�0
    int ret;
    if(t->top==-1)
        ret = 1;//ջ�ǿ�ջ
    else
        ret = 0;//ջ�Ƿǿ�ջ

return ret;//����ֵ
}

BiTNode TPop(Tstack *t){// ջ��Ԫ�س�ջ
   BiTNode bt;//����1���������ڵ㣬��Ϊ����ֵ
   int a;
   a = EmptyTstack(t);//�ж�ջt�Ƿ��ǿ�ջ
   if(a!=1){// ջ�Ƿǿ�ջ
       bt = t->dat[t->top];//��ջ��Ԫ�ظ�ֵ��bt
       t->top--;//ջ��ָ���1��ָ���µ�ջ��Ԫ��
       printf("TPopִ�н����ջ��Ԫ�س�ջ�ɹ���\n");
   }
   else{// ջ�ǿ�ջ
       printf("TPopִ�н����ջ�ǿ�ջ��\n");
   }

return bt;
}

void Imidtravel(BiTNode *b){// ������������� �ǵݹ��㷨

    Tstack s;//����1��ջ
    InitTstack(&s);//��ʼ����ջ��Ϊջ����洢�ռ�
    BiTNode *p,*q;//
    q = (BiTNode*)malloc(sizeof(BiTNode));//Ϊq����洢�ռ䣬һ��Ҫ���䣬��Ϊq��Ҫ����ֵ��
    p = b;//��p��ֵΪb
    while((p!=NULL)||(EmptyTstack(&s)!=1)){// ����������ǰ�ڵ�ǿջ�ջ�ǿ�
        if(p!=NULL){//��ǰ�������ڵ�ǿ�
            TPush(&s,*p);//����ǰ�ڵ���ջ
            p=p->lchild;//p����Ϊ����
        }
        else{//p�ڵ�Ϊ��
            (*q) = TPop(&s);//ջ��Ԫ�س�ջ
            printf("%d \n\n",q->data);// ����
            p = q->rchild;//ָ����������

        }
    }
}

/*
int main(){
    int a;
    Tstack k;//����1��ջ����
    BiTNode d,d1,d2;//����1���������ڵ�
    d.data=26;d.lchild=(&d1);d.rchild=(&d2);//���������ڵ㸳ֵ
    d1.data=66;d1.lchild=NULL;d1.rchild=NULL;d2.data=86;d2.lchild=NULL;d2.rchild=NULL;
    InitTstack(&k);
    /*printf("ջ��ָ�룺%d  ջ���������%d\n",k.top,k.size);
    a = EmptyTstack(&k);
    if(1==a)
        printf("ջ�ǿ�ջ��\n");
    else
        printf("ջ�Ƿǿ�ջ��\n");
    TPush(&k,d);//��ջ����
    printf("ջ��ָ�룺%d  ջ���������%d\n",k.top,k.size);
    a = EmptyTstack(&k);
    if(1==a)
        printf("ջ�ǿ�ջ��\n");
    else
        printf("ջ�Ƿǿ�ջ��\n");*/
   /* printf("\n�������������ǵݹ飩��");
    Imidtravel(&d);
   // d1 = TPop(&k);
    //printf("d1.data: %d\n",d1.data);
return 0;
}

*/


