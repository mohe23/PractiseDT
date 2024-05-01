// ѭ�����У�˳����У�

#include<stdio.h>
#include<stdlib.h>
#define maxsize 20

typedef struct{
    int *elem;//������
    int front;//����ָ��
    int rear;//��βָ��  �����в���ʱ��rearָ�������ʵ�����1��Ԫ�صġ���һ����λ�á�������ָ�������ʵ�����1��Ԫ��
}SqQueue;//ѭ�����ж���

void InitQueue(SqQueue *sq){// ��ʼ��ѭ������
    sq->elem = (int*)malloc(sizeof(int)*maxsize);//��ѭ�����з���洢�ռ� maxsize�ǰ����ġ�
    sq->front=sq->rear=0;//��ʼ����ͷָ�룬��βָ�룬
}

int LengthQueue(SqQueue sq){// ��ѭ����������Ч���ݸ���
    int le=-1;
    le = (sq.rear-sq.front+maxsize)%maxsize;//��������д洢Ԫ�صĳ��ȡ�
return le;
}

void EnQueue(SqQueue *sq,int e){// Ԫ��e�Ӷ�β���
    if((sq->rear+1)%maxsize==sq->front){// �����������޷���e��ӡ�
        printf("ִ��EnQueue������������%d���ʧ�ܣ�\n",e);
    }
    else{// ����δ����e�������
        sq->elem[sq->rear]=e;//��e��ӡ�
        sq->rear = (sq->rear+1)%maxsize;//��βָ���1
        printf("ִ��EnQueue��Ԫ��%d��ӳɹ���\n",e);
    }
}

int DeQueue(SqQueue *sq){// ����Ԫ�س���
    int e;
    if(sq->front!=sq->rear){// ����sq���գ��ж���Ԫ�ؿ��Գ���
        e = sq->elem[sq->front];//����Ԫ�س��ӣ�
        sq->elem[sq->front]=0;//������Ҳ�ɲ��У���ò�Ҫд���˷�ʱ��
        sq->front = (sq->front+1)%maxsize;//����ָ���1��ָ���µĶ���Ԫ�ء�
        printf("ִ��DeQueue: ����Ԫ��%d���ӳɹ���\n",e);
    }
    else{// sq�ǿն�
        printf("ִ��DeQueue: �˶����ǿն�,����ʧ�ܣ�\n");
    }
return e;
}

int GetHead(SqQueue *sq){// ȡ����Ԫ��
    int rt;
    if(sq->front!=sq->rear){// �Ӳ��ǿն�
        rt = sq->elem[sq->front];
       // printf("ִ��GetHead: ִ�гɹ�������Ԫ�أ�%d��\n",rt);
       printf("ִ��GetHead: ִ�гɹ�������Ԫ�أ�%d\n",rt);
    }
    else//���ǿնӡ�
        printf("ִ��GetHead��ִ��ʧ�ܣ��ö����ǿնӣ�\n");
return rt;
}
/*
int main(){
    int a;
    SqQueue q;
    InitQueue(&q);//��ʼ��ѭ�����С�
    printf("����ָ�룺%d  ��βָ�룺%d\n",q.front,q.rear);
    printf("���г��ȣ�%d\n",LengthQueue(q));
    EnQueue(&q,34);EnQueue(&q,46);EnQueue(&q,6);// ��Ӳ���
    printf("����ָ�룺%d  ��βָ�룺%d  ����Ԫ�أ� %d\n",q.front,q.rear,q.elem[q.front]);
    a = DeQueue(&q);//����Ԫ�س���
    printf("����ָ�룺%d  ��βָ�룺%d  ����Ԫ�أ� %d\n",q.front,q.rear,q.elem[q.front]);
    a = GetHead(&q);
    //a = GetHead(&q);
    //a = GetHead(&q);
    //a = GetHead(&q);
return 0;//����
}
*/
