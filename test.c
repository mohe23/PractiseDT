// 1�������ļ�

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int num;//��ֵ
    struct Node *left, *right;//���Һ���
}Tnode,*PTnode;// Tnode��*PTnode������ṹ��ı�����

PTnode func(PTnode p){
    if(!p){
        PTnode s = (PTnode)malloc(sizeof(Tnode));//
        s->num=10;s->left=s->right=NULL;
        p = s;
    }

return p;
}

void funct(PTnode p){
    if(!p){
        PTnode s = (PTnode)malloc(sizeof(Tnode));//
        s->num=10;s->left=s->right=NULL;
        p = s;
    }
}

void funcw(PTnode* p){// d��1������ָ�롣
     if(!(*p)){
        PTnode s = (PTnode)malloc(sizeof(Tnode));//
        s->num=10;s->left=s->right=NULL;
        (*p) = s;
    }
}

/*
int main(){
    int *t,*t1;
    t = (int*)malloc(sizeof(int));//����洢�ռ�
    t1 = (int*)malloc(sizeof(int));
    *t = 37; *t1 = 21;
    printf("ǰ��t��%d  t1: %d\n",*t,*t1);
    free(t);free(t1);//t1=NULL;//�ֶ���ֵΪNULL
    if(t==NULL)
        printf("t�Ѿ����ͷ���! t==NULL\n");
    else
        printf("��t��%d  t1: %d\n",*t,*t1);


return 0;
}
/*
int main(){
    printf("12345\n");
    PTnode t=NULL;PTnode f=NULL;PTnode v=NULL;
    t = func(t);funct(f);funcw(&v);
    if(!t)
        printf("func: �ṹ��tû�иı�\n");
    else
        printf("func: �ṹ��t�ı���\n");

    if(!f)
        printf("funcf: �ṹ��fû�иı�\n");
    else
        printf("funcf: �ṹ��f�ı���\n");

    if(!v)
        printf("funcw: �ṹ��vû�иı�\n");
    else
        printf("funcw: �ṹ��v�ı���\n");

return 0;
}
 char h[]="qwertydhek";
    //char*y=(char*)malloc(sizeof(char)*10);
    t = strlen(h);//�����ַ�����h�ĳ��ȡ�
    t1 = strlen(y);
    printf("�ַ�����h��y���ȣ�%d��%d\n",t,t1);
*/
