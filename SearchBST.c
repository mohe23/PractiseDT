// �����������ĵݹ����   �����������Ĳ��� �����������Ĵ��� �Ƚ�2���������Ƿ���ͬ

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int num;//��ֵ
    struct Node *left, *right;//���Һ���
}Tnode,*PTnode;// Tnode��*PTnode������ṹ��ı�����

void Midtravel(Tnode *t){// �������
    if(t->left!=NULL)//��������Ϊ��
        Midtravel(t->left);
    printf("%d ",t->num);
    if(t->right!=NULL)// ��������Ϊ��
        Midtravel(t->right);
}

PTnode Search_BST(PTnode p,int key){//�������������ң��ݹ麯��
    if((!p)||(p->num==key))
        return p;
    else if(key<p->num)// ����Ԫ�� < ��ǰ�ڵ�ֵ�����뵱ǰ�ڵ���������������ҡ�
        return Search_BST(p->left,key);
    else// key > p->num�������������������ҡ�
        return Search_BST(p->right,key);

}
// 12:3,37  53:NULL��100   37:24, NULL  100:61,NULL   61:NULL, 90   90:78,NULL
void InsertBST(PTnode *p,int elem){// �����������Ĳ��뺯��,��ʱp��1������ָ��
    if(!(*p)){//���p�ǿս�㣬2�������1-��ǰ�������ǿ�����2-p��1��Ҷ�ӽ�����/�Һ���
        Tnode *s = (Tnode*)malloc(sizeof(Tnode));//Ϊ��������ֵelem������1��Tnode��㣬��Ϊ�����洢�ռ䡣
        s->num = elem;//��������Ԫ��elem��ֵ���´����Ľ���������
        s->left=s->right=NULL;//���Һ���ָ�붼Ϊ��
        *p = s;//���´����Ľ����뵽��ȷλ�á�
    }
    else if(elem < (*p)->num)//����ǰ�ڵ㲻�գ���elem < ��ǰ�ڵ����ֵ
        InsertBST(&((*p)->left),elem);//�ڽ����������ϣ��������Ҳ���λ��
    else if(elem > (*p)->num)// ��ǰ�ڵ㲻�գ��� elem > ��ǰ�ڵ����ֵ
        InsertBST(&((*p)->right),elem);//�ڵ�ǰ�ڵ���������ϣ�����Ѱ��
    else// elem == p->num
        printf("������Ԫ��%d�Ѿ������ڸö�����������\n\n",elem);
}

void CreateBST(PTnode *p,int b[],int ble){// ����1������������p��p-1������ָ�� ����b-��Ŵ��������е���ֵ��ble-����b�ĳ���
    int i;// pһ��Ҫ�Ƕ���ָ�룬��Ȼ����ı䡣һ��Ҫ��ס��
    for(i=0;i<ble;i++)
        InsertBST(p,b[i]);//������������Ԫ�ز��뵽����������p�С�

}

int CompareTree(PTnode p1,PTnode p2){// �Ƚ�2���������Ƿ����
    int ret,left,right;
    if(p1==NULL&&p2==NULL)// 2�������ǿ���
        ret = 1;//��������ͬ
    else if((p1!=NULL&&p2==NULL)||(p1==NULL&&p2!=NULL))// 1����Ϊ��������1�������ǿ���
        ret = 0;//����������ͬ
    else if(p1->num != p2->num)// 2�������ڵ�������ͬ
        ret = 0;//����������ͬ
    else{// 2�������ڵ���������ͬ
        left=CompareTree(p1->left,p2->left);
        right=CompareTree(p1->right,p2->right);
        ret = left&&right;
    }

return ret;//�����жϽ����
}

/*
int main(){
    PTnode p=NULL; //(PTnode)malloc(sizeof(Tnode));//��Ϊ1�������
   // Tnode*q = (Tnode*)malloc(sizeof(Tnode));
    //q->left=q->right=NULL;q->num=34;
    //p = q;//����ָ��p��ֵ��
    int flag,ale,a[]={45,12,53,3,37,100,24,61,90,78};
    ale = 10;
   // printf("q->num= %d\n\n",q->num);
    Tnode *t=(Tnode*)malloc(sizeof(Tnode));PTnode y=(PTnode)malloc(sizeof(Tnode));PTnode y1=(PTnode)malloc(sizeof(Tnode));
    PTnode y2=(PTnode)malloc(sizeof(Tnode));PTnode y3=(PTnode)malloc(sizeof(Tnode));PTnode y4=(PTnode)malloc(sizeof(Tnode));
    PTnode y5=(PTnode)malloc(sizeof(Tnode));PTnode y6=(PTnode)malloc(sizeof(Tnode));PTnode y7=(PTnode)malloc(sizeof(Tnode));
    PTnode y8=(PTnode)malloc(sizeof(Tnode)); PTnode y9;int ke=100;int kt=55;
    t->num=45;t->left=y;t->right=y1;y->num=12;y->left=y2;y->right=y3;y1->num=53;y1->left=NULL;y1->right=y4;
    y2->num=3;y2->left=NULL;y2->right=NULL;y3->num=37;y3->left=y5;y3->right=NULL;y4->num=100;y4->left=y6;y4->right=NULL;
    y5->num=24;y5->left=NULL;y5->right=NULL;y6->num=61;y6->left=NULL;y6->right=y7;y7->num=90;y7->left=y8;y7->right=NULL;
    y8->num=78;y8->left=NULL;y8->right=NULL;

    CreateBST(&p,a,ale);//����1������������p
    flag = CompareTree(t,p);//�Ƚ�2��������
    if(1==flag)
        printf("������������ͬ��\n");
    else
        printf("������������ͬ��\n");

    //printf("������������\n");
    //Midtravel(p);
    InsertBST(&p,55);
     flag = CompareTree(t,p);//�Ƚ�2��������
    if(1==flag)
        printf("������������ͬ��\n");
    else
        printf("������������ͬ��\n");
    //printf("�����������������\n");
    //Midtravel(p);

return 0;
}*/
/*
int main(){
    Tnode *t=(Tnode*)malloc(sizeof(Tnode));PTnode y=(PTnode)malloc(sizeof(Tnode));PTnode y1=(PTnode)malloc(sizeof(Tnode));
    PTnode y2=(PTnode)malloc(sizeof(Tnode));PTnode y3=(PTnode)malloc(sizeof(Tnode));PTnode y4=(PTnode)malloc(sizeof(Tnode));
    PTnode y5=(PTnode)malloc(sizeof(Tnode));PTnode y6=(PTnode)malloc(sizeof(Tnode));PTnode y7=(PTnode)malloc(sizeof(Tnode));
    PTnode y8=(PTnode)malloc(sizeof(Tnode)); PTnode y9;int ke=100;int kt=55;
    t->num=45;t->left=y;t->right=y1;y->num=12;y->left=y2;y->right=y3;y1->num=53;y1->left=NULL;y1->right=y4;
    y2->num=3;y2->left=NULL;y2->right=NULL;y3->num=37;y3->left=y5;y3->right=NULL;y4->num=100;y4->left=y6;y4->right=NULL;
    y5->num=24;y5->left=NULL;y5->right=NULL;y6->num=61;y6->left=NULL;y6->right=y7;y7->num=90;y7->left=y8;y7->right=NULL;
    y8->num=78;y8->left=NULL;y8->right=NULL;
    printf("t->num: %d\n",t->num);printf("y->num: %d\n",y->num);
    InsertBST(t,kt);
    printf("������������");
    Midtravel(t);printf("\n\n");
    y9 = Search_BST(t,ke);
    if(y9!=NULL)
        printf("���ҳɹ�����ѯԪ��Ϊ��%d\n\n",ke);
    else
        printf("%d���Ҳ��ɹ���\n\n",ke);

    //InsertBST(t,55);//�����������t�в���55
    //printf("61�����ӣ��Һ��ӣ�%d,%d\n",y6->left->num,y6->right->num);
    if(y6->left==NULL)
        printf("123456\n");
InsertBST(&p,54);
    if(p==NULL)
        printf("����Ԫ��ʧ��\n");
    else
        printf("����Ԫ�سɹ�! p->num = %d\n",p->num);
return 0;
}
*/
