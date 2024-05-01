#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void InsertSort();// 直接插入排序
void BInsert();// 折半插入排序 函数声明
void Shell(); // 希尔排序主要函数
void ShellSort(); // 希尔排序函数
void BubbleSort();// 冒泡函数声明
int Getmid();// 函数声明
void QSort();// 快速排序函数声明
void SelectSort();// 简单选择排序声明
void HeapAdjust();// 调整堆函数声明
void CreateHeap();// 建成堆函数声明
void HeapSort();// 堆排序函数声明
void Merge();// 合并2有序表函数（升序）声明
void MSort();// 二路归并排序函数声明

void Pri(int *a,int le){// 打印数组元素
    int i;
    for(i=0;i<le;i++)
        printf("%d ",a[i]);
    printf("\n\n");//打印数组全部元素之后，换行
}

void Reverse(int a[],int ale){// 将数组所有元素倒置
    int i,t,mid;
    mid = ale/2;//作为1个特定的“界限”
    for(i=0;i<mid;i++){
        t = a[i];
        a[i]=a[ale-1-i];
        a[ale-1-i]=t;//交换对应元素。
    }
}

/*
int main()
{
    int i,n,j,a[10];
    double t=3.465;
    int *b,*c;
    b=(int*)malloc(sizeof(int));
    c=(int*)malloc(sizeof(int));
    (*b)=34;(*c)=45;
    printf("free(b)前：*b=%d,*c=%d\n",(*b),(*c));
    free(b);
    printf("free(b)后：*b=%d,*c=%d\n",(*b),(*c));
    if(c==NULL)
        printf("空！\n");
    else
         printf("不空！\n");

     if(b==NULL)
        printf("b空！\n");
    else
         printf("b不空！\n");

   /* printf("请输入1个数：");
    scanf("%d",&n);
    while(n>0){
        //printf("%d",n%10);
        a[j++]=n%10;
        n = n/10;
    }
    for(i=j-1;i>=0;i--)
        printf("%d",a[i]);*/
    //printf("double型%lf的取整输出：%.0lf\n",t,t);
    //printf("%d\n",10/4);
 /*  //int a[10]={49,38,65,97,76,13,27,49,55,4};//{49,38,65,97,76,13,27,49}; //int a[]={8,7,6,5,4,3,2,1};
   int a[] = {49,38,65,97,32,13,27,76};  //int a[]={49,38,65,97,76,13,27};
   //int a[] = {98,86,70,65,53,42,32}; // 0,38,76,65,49,49,13,27,97   0,49,38,65,97,76,13,27,49  2,34,78,12,45,60,75
   //int *a = (int*)malloc(sizeof(int)*7);a[0]=98;a[1]=86;a[2]=70;a[3]=65;a[4]=53;a[5]=43;a[6]=32;

   int b[]={5,3,1};
   int ale,ble,pt;
   ale=8;ble=3;
   pt = ++ble;
   printf("pt=%d,ble=%d\n",pt,ble);
   printf("排序前：");
   Pri(a,ale);
   Reverse(a,ale);
   //MSort(a,1,ale);// 二路归并排序
   //Merge(a,1,3,ale);
   //HeapSort(a,ale);//堆排序算法
   //CreateHeap(a,ale);//将1个无序序列调整成大根堆
   //HeapAdjust(a,1,7);//调整堆
   //SelectSort(a,ale);
    //pt = Getmid(a,0,ale-1);
   //printf("pt: %d\n",pt);
   //QSort(a,0,ale-1);
   //printf("\n");
   //BubbleSort(a,ale);
   //InsertSort(a,ale);//执行“直接插入排序”程序
   //BInsert(a,ale);
   //ShellSort(a,ale,b,ble);
   printf("排序后：");
   Pri(a,ale);
    //printf("Hello world!\n");*/
  /* return 0;
}

*/
