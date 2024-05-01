// 二叉树的中序遍历，非递归算法

#include<stdio.h>
#include<stdlib.h>
#include"sfile.h"// 会用到二叉树节点BiTNode的结构体定义
// 不行，要重新写栈的定义以及相关操作
// #define maxsize 20
typedef struct{
     BiTNode *dat;//BiTNode型数组的数组名
     int top;//栈顶指针，栈空时，top==-1
     int size;//栈的最大容量
}Tstack;

void InitTstack(Tstack *t){// 初始化栈 。使用指针做变量，可以“保留”对栈的操作结果
    t->dat = (BiTNode*)malloc(sizeof(BiTNode)*maxsize);//给栈t分配存储空间
    t->top=-1;//表示栈空
    t->size = maxsize;//栈的最大容量。
}

void TPush(Tstack *t,BiTNode b){// 将结点b进栈。
     if(t->top!=(t->size-1)){// 表示栈未满，可以将二叉树结点入栈
         t->top++;//栈不空时，栈顶指针始终指向栈顶元素
         t->dat[t->top] = b;//将二叉树节点入栈。
         printf("TPush执行结果：二叉树节点入栈成功！\n");
     }
     else{// 栈满
         printf("TPush执行结果：二叉树节点入栈失败，栈已满！\n");
     }
}

int EmptyTstack(Tstack *t){// 判断栈s是否是空栈，若是空栈返回1，否则返回0
    int ret;
    if(t->top==-1)
        ret = 1;//栈是空栈
    else
        ret = 0;//栈是非空栈

return ret;//返回值
}

BiTNode TPop(Tstack *t){// 栈顶元素出栈
   BiTNode bt;//定义1个二叉树节点，作为返回值
   int a;
   a = EmptyTstack(t);//判断栈t是否是空栈
   if(a!=1){// 栈是非空栈
       bt = t->dat[t->top];//将栈顶元素赋值给bt
       t->top--;//栈顶指针减1，指向新的栈顶元素
       printf("TPop执行结果：栈顶元素出栈成功！\n");
   }
   else{// 栈是空栈
       printf("TPop执行结果：栈是空栈！\n");
   }

return bt;
}

void Imidtravel(BiTNode *b){// 二叉树中序遍历 非递归算法

    Tstack s;//定义1个栈
    InitTstack(&s);//初始化该栈，为栈分配存储空间
    BiTNode *p,*q;//
    q = (BiTNode*)malloc(sizeof(BiTNode));//为q分配存储空间，一定要分配，因为q还要被赋值。
    p = b;//给p赋值为b
    while((p!=NULL)||(EmptyTstack(&s)!=1)){// 当二叉树当前节点非空或栈非空
        if(p!=NULL){//当前二叉树节点非空
            TPush(&s,*p);//将当前节点入栈
            p=p->lchild;//p更新为左孩子
        }
        else{//p节点为空
            (*q) = TPop(&s);//栈顶元素出栈
            printf("%d \n\n",q->data);// 不行
            p = q->rchild;//指向右子树。

        }
    }
}

/*
int main(){
    int a;
    Tstack k;//定义1个栈变量
    BiTNode d,d1,d2;//定义1个二叉树节点
    d.data=26;d.lchild=(&d1);d.rchild=(&d2);//给二叉树节点赋值
    d1.data=66;d1.lchild=NULL;d1.rchild=NULL;d2.data=86;d2.lchild=NULL;d2.rchild=NULL;
    InitTstack(&k);
    /*printf("栈顶指针：%d  栈最大容量：%d\n",k.top,k.size);
    a = EmptyTstack(&k);
    if(1==a)
        printf("栈是空栈！\n");
    else
        printf("栈是非空栈！\n");
    TPush(&k,d);//入栈操作
    printf("栈顶指针：%d  栈最大容量：%d\n",k.top,k.size);
    a = EmptyTstack(&k);
    if(1==a)
        printf("栈是空栈！\n");
    else
        printf("栈是非空栈！\n");*/
   /* printf("\n中序遍历结果（非递归）：");
    Imidtravel(&d);
   // d1 = TPop(&k);
    //printf("d1.data: %d\n",d1.data);
return 0;
}

*/


