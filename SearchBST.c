// 二叉排序树的递归查找   二叉排序树的插入 二叉排序树的创建 比较2个二叉树是否相同

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int num;//数值
    struct Node *left, *right;//左右孩子
}Tnode,*PTnode;// Tnode和*PTnode是这个结构体的别名。

void Midtravel(Tnode *t){// 中序遍历
    if(t->left!=NULL)//左子树不为空
        Midtravel(t->left);
    printf("%d ",t->num);
    if(t->right!=NULL)// 右子树不为空
        Midtravel(t->right);
}

PTnode Search_BST(PTnode p,int key){//二叉排序树查找，递归函数
    if((!p)||(p->num==key))
        return p;
    else if(key<p->num)// 查找元素 < 当前节点值，进入当前节点的左子树继续查找。
        return Search_BST(p->left,key);
    else// key > p->num，进入右子树继续查找。
        return Search_BST(p->right,key);

}
// 12:3,37  53:NULL，100   37:24, NULL  100:61,NULL   61:NULL, 90   90:78,NULL
void InsertBST(PTnode *p,int elem){// 二叉排序树的插入函数,此时p是1个二级指针
    if(!(*p)){//结点p是空结点，2种情况：1-当前二叉树是空树；2-p是1个叶子结点的左/右孩子
        Tnode *s = (Tnode*)malloc(sizeof(Tnode));//为待插入数值elem，创建1个Tnode结点，并为其分配存储空间。
        s->num = elem;//将待插入元素elem赋值到新创建的结点的数据域
        s->left=s->right=NULL;//左右孩子指针都为空
        *p = s;//将新创建的结点插入到正确位置。
    }
    else if(elem < (*p)->num)//即当前节点不空，且elem < 当前节点的数值
        InsertBST(&((*p)->left),elem);//在结点的左子树上，继续查找插入位置
    else if(elem > (*p)->num)// 当前节点不空，且 elem > 当前节点的数值
        InsertBST(&((*p)->right),elem);//在当前节点的右子树上，继续寻找
    else// elem == p->num
        printf("待插入元素%d已经存在于该二叉排序树！\n\n",elem);
}

void CreateBST(PTnode *p,int b[],int ble){// 创建1个二叉排序树p，p-1个二级指针 数组b-存放待插入书中的数值。ble-数组b的长度
    int i;// p一定要是二级指针，不然不会改变。一定要记住。
    for(i=0;i<ble;i++)
        InsertBST(p,b[i]);//将数组中所有元素插入到二叉排序树p中。

}

int CompareTree(PTnode p1,PTnode p2){// 比较2个二叉树是否相等
    int ret,left,right;
    if(p1==NULL&&p2==NULL)// 2棵树都是空树
        ret = 1;//两棵树相同
    else if((p1!=NULL&&p2==NULL)||(p1==NULL&&p2!=NULL))// 1棵树为空树，另1棵树不是空树
        ret = 0;//两棵树不相同
    else if(p1->num != p2->num)// 2棵树根节点数据域不同
        ret = 0;//两棵树不相同
    else{// 2棵树根节点数据域相同
        left=CompareTree(p1->left,p2->left);
        right=CompareTree(p1->right,p2->right);
        ret = left&&right;
    }

return ret;//返回判断结果。
}

/*
int main(){
    PTnode p=NULL; //(PTnode)malloc(sizeof(Tnode));//作为1个根结点
   // Tnode*q = (Tnode*)malloc(sizeof(Tnode));
    //q->left=q->right=NULL;q->num=34;
    //p = q;//给空指针p赋值。
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

    CreateBST(&p,a,ale);//创建1个二叉排序树p
    flag = CompareTree(t,p);//比较2个二叉树
    if(1==flag)
        printf("两个二叉树相同！\n");
    else
        printf("两个二叉树不同！\n");

    //printf("中序遍历结果：\n");
    //Midtravel(p);
    InsertBST(&p,55);
     flag = CompareTree(t,p);//比较2个二叉树
    if(1==flag)
        printf("两个二叉树相同！\n");
    else
        printf("两个二叉树不同！\n");
    //printf("插入后中序遍历结果：\n");
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
    printf("中序遍历结果：");
    Midtravel(t);printf("\n\n");
    y9 = Search_BST(t,ke);
    if(y9!=NULL)
        printf("查找成功！查询元素为：%d\n\n",ke);
    else
        printf("%d查找不成功！\n\n",ke);

    //InsertBST(t,55);//想二叉排序树t中插入55
    //printf("61的左孩子，右孩子：%d,%d\n",y6->left->num,y6->right->num);
    if(y6->left==NULL)
        printf("123456\n");
InsertBST(&p,54);
    if(p==NULL)
        printf("插入元素失败\n");
    else
        printf("插入元素成功! p->num = %d\n",p->num);
return 0;
}
*/
