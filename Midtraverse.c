// ����/����/�������������

#include<stdio.h>
#include<stdlib.h>

typedef struct TNode{
    int num;//�ؼ���ֵ
    struct TNode *left,*right;// ���Һ���ָ��
}TNode;

void Midtrave(TNode *t){// �������
    if(t->left!=NULL)//��������Ϊ��
        Midtrave(t->left);
    printf("%d ",t->num);
    if(t->right!=NULL)// ��������Ϊ��
        Midtrave(t->right);
}

void Firtrave(TNode*t){// �������������t
    if(t!=NULL){
        printf("%d ",t->num);
        if(t->left!=NULL)
            Firtrave(t->left);
        if(t->right!=NULL)
            Firtrave(t->right);
    }
}

void Endtrave(TNode *t){// �������������
    if(t!=NULL){
        if(t->left!=NULL)
            Endtrave(t->left);
        if(t->right!=NULL)
            Endtrave(t->right);
        printf("%d ",t->num);
    }
}

/*
int main(){
   TNode *t1,*t2,*t3;
   t1=(TNode*)malloc(sizeof(TNode)); t2=(TNode*)malloc(sizeof(TNode)); t3=(TNode*)malloc(sizeof(TNode));
   t1->num=12;t1->left=t2;t1->right=t3;t2->num=7;t2->left=NULL;t2->right=NULL;t3->num=34;t3->left=NULL;t3->right=NULL;
   printf("���������\n");          //t1-�� t2��t3:���Һ���
   Midtrave(t1);
   printf("\n\n");
   printf("���������\n");
   Firtrave(t1);
   printf("\n\n");
   printf("���������\n");
   Endtrave(t1);
   printf("\n\n");

return 0;
}
*/
