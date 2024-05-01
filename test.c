// 1个测试文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int num;//数值
    struct Node *left, *right;//左右孩子
}Tnode,*PTnode;// Tnode和*PTnode是这个结构体的别名。

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

void funcw(PTnode* p){// d：1个二级指针。
     if(!(*p)){
        PTnode s = (PTnode)malloc(sizeof(Tnode));//
        s->num=10;s->left=s->right=NULL;
        (*p) = s;
    }
}

/*
int main(){
    int *t,*t1;
    t = (int*)malloc(sizeof(int));//分配存储空间
    t1 = (int*)malloc(sizeof(int));
    *t = 37; *t1 = 21;
    printf("前：t：%d  t1: %d\n",*t,*t1);
    free(t);free(t1);//t1=NULL;//手动赋值为NULL
    if(t==NULL)
        printf("t已经被释放了! t==NULL\n");
    else
        printf("后：t：%d  t1: %d\n",*t,*t1);


return 0;
}
/*
int main(){
    printf("12345\n");
    PTnode t=NULL;PTnode f=NULL;PTnode v=NULL;
    t = func(t);funct(f);funcw(&v);
    if(!t)
        printf("func: 结构体t没有改变\n");
    else
        printf("func: 结构体t改变了\n");

    if(!f)
        printf("funcf: 结构体f没有改变\n");
    else
        printf("funcf: 结构体f改变了\n");

    if(!v)
        printf("funcw: 结构体v没有改变\n");
    else
        printf("funcw: 结构体v改变了\n");

return 0;
}
 char h[]="qwertydhek";
    //char*y=(char*)malloc(sizeof(char)*10);
    t = strlen(h);//计算字符数组h的长度。
    t1 = strlen(y);
    printf("字符数组h、y长度：%d、%d\n",t,t1);
*/
