// 中序/先序/后序遍历二叉树

#include<stdio.h>
#include<stdlib.h>

typedef struct TNode{
    int num;//关键字值
    struct TNode *left,*right;// 左右孩子指针
}TNode;

void Midtrave(TNode *t){// 中序遍历
    if(t->left!=NULL)//左子树不为空
        Midtrave(t->left);
    printf("%d ",t->num);
    if(t->right!=NULL)// 右子树不为空
        Midtrave(t->right);
}

void Firtrave(TNode*t){// 先序遍历二叉树t
    if(t!=NULL){
        printf("%d ",t->num);
        if(t->left!=NULL)
            Firtrave(t->left);
        if(t->right!=NULL)
            Firtrave(t->right);
    }
}

void Endtrave(TNode *t){// 后序遍历二叉树
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
   printf("中序遍历：\n");          //t1-根 t2、t3:左右孩子
   Midtrave(t1);
   printf("\n\n");
   printf("先序遍历：\n");
   Firtrave(t1);
   printf("\n\n");
   printf("后序遍历：\n");
   Endtrave(t1);
   printf("\n\n");

return 0;
}
*/
