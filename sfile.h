// 存放结构体定义，栈定义，队列定义，以及相关操作
#ifndef SFILE_H_INCLUDED
#define SFILE_H_INCLUDED

#define maxsize 20// 此时maxsize就等价于20，如果想改变顺序栈的容量，直接修改“20”就行了，比如修改到30，40。
typedef int se;// 给int型起了1个别名。这样，如果栈想要存放字符，直接把“int”换为"char"就行了。

typedef struct{// 顺序栈的结构体定义
    se *ele;//存放元素的数组
    int top;//栈顶指针，若top==-1，表示栈空；若top==(stacksize-1)，则栈满。这里没有按照教
    int stacksize;//栈的最大容量
}SqStack;

typedef struct BiTNode{
    int data;//数据域
    struct BiTNode *lchild, *rchild;//当前节点的左孩子、右孩子
}BiTNode;// 二叉树节点的二叉链表存储表示

#endif // SFILE_H_INCLUDED
