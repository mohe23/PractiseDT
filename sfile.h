// ��Žṹ�嶨�壬ջ���壬���ж��壬�Լ���ز���
#ifndef SFILE_H_INCLUDED
#define SFILE_H_INCLUDED

#define maxsize 20// ��ʱmaxsize�͵ȼ���20�������ı�˳��ջ��������ֱ���޸ġ�20�������ˣ������޸ĵ�30��40��
typedef int se;// ��int������1�����������������ջ��Ҫ����ַ���ֱ�Ӱѡ�int����Ϊ"char"�����ˡ�

typedef struct{// ˳��ջ�Ľṹ�嶨��
    se *ele;//���Ԫ�ص�����
    int top;//ջ��ָ�룬��top==-1����ʾջ�գ���top==(stacksize-1)����ջ��������û�а��ս�
    int stacksize;//ջ���������
}SqStack;

typedef struct BiTNode{
    int data;//������
    struct BiTNode *lchild, *rchild;//��ǰ�ڵ�����ӡ��Һ���
}BiTNode;// �������ڵ�Ķ�������洢��ʾ

#endif // SFILE_H_INCLUDED
