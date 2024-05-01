// 循环队列（顺序队列）

#include<stdio.h>
#include<stdlib.h>
#define maxsize 20

typedef struct{
    int *elem;//数组名
    int front;//队首指针
    int rear;//队尾指针  当队列不空时，rear指向队列中实际最后1个元素的“下一个”位置。并不是指向队列中实际最后1个元素
}SqQueue;//循环队列定义

void InitQueue(SqQueue *sq){// 初始化循环队列
    sq->elem = (int*)malloc(sizeof(int)*maxsize);//给循环队列分配存储空间 maxsize是暗含的。
    sq->front=sq->rear=0;//初始化队头指针，队尾指针，
}

int LengthQueue(SqQueue sq){// 求循环队列中有效数据个数
    int le=-1;
    le = (sq.rear-sq.front+maxsize)%maxsize;//计算队列中存储元素的长度。
return le;
}

void EnQueue(SqQueue *sq,int e){// 元素e从队尾入队
    if((sq->rear+1)%maxsize==sq->front){// 队列已满，无法将e入队。
        printf("执行EnQueue：队列已满，%d入队失败！\n",e);
    }
    else{// 队列未满。e可以入队
        sq->elem[sq->rear]=e;//将e入队。
        sq->rear = (sq->rear+1)%maxsize;//队尾指针加1
        printf("执行EnQueue：元素%d入队成功！\n",e);
    }
}

int DeQueue(SqQueue *sq){// 队首元素出队
    int e;
    if(sq->front!=sq->rear){// 队列sq不空，有队首元素可以出队
        e = sq->elem[sq->front];//队首元素出队，
        sq->elem[sq->front]=0;//这句可有也可不有，最好不要写，浪费时间
        sq->front = (sq->front+1)%maxsize;//对手指针加1，指向新的队首元素。
        printf("执行DeQueue: 队首元素%d出队成功！\n",e);
    }
    else{// sq是空队
        printf("执行DeQueue: 此队列是空队,出队失败！\n");
    }
return e;
}

int GetHead(SqQueue *sq){// 取队首元素
    int rt;
    if(sq->front!=sq->rear){// 队不是空队
        rt = sq->elem[sq->front];
       // printf("执行GetHead: 执行成功，队首元素：%d！\n",rt);
       printf("执行GetHead: 执行成功，队首元素：%d\n",rt);
    }
    else//队是空队。
        printf("执行GetHead：执行失败，该队列是空队！\n");
return rt;
}
/*
int main(){
    int a;
    SqQueue q;
    InitQueue(&q);//初始化循环队列。
    printf("队首指针：%d  队尾指针：%d\n",q.front,q.rear);
    printf("队列长度：%d\n",LengthQueue(q));
    EnQueue(&q,34);EnQueue(&q,46);EnQueue(&q,6);// 入队操作
    printf("队首指针：%d  队尾指针：%d  队首元素： %d\n",q.front,q.rear,q.elem[q.front]);
    a = DeQueue(&q);//队首元素出队
    printf("队首指针：%d  队尾指针：%d  队首元素： %d\n",q.front,q.rear,q.elem[q.front]);
    a = GetHead(&q);
    //a = GetHead(&q);
    //a = GetHead(&q);
    //a = GetHead(&q);
return 0;//标配
}
*/
