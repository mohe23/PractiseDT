// 冒泡排序(顺序表，结果升序）-交换排序

#include<stdio.h>
#include<stdlib.h>

void Pri();// 打印函数声明

void BubbleSort(int b[],int ble){
    int i,j,t,flag=1;
    for(i=ble-1;i>=1;i--){
        flag=0;// 每次外层循环一开始，就是使flag=0。这个必须放在内层循环外，要是放在内层循环里，会出现只要出现1次没有交换，那么就
              // 使得flag=0，就会误以为数组已经有序，然后跳出循环，其实很有可能，当前数组没有序。
        for(j=0;j<i;j++){
            if(b[j]>b[j+1]){// 前1个元素 > 后1个元素，出现“逆序”，就要交换2个元素的位置。
                flag = 1;//表示一趟排序中，出现了交换元素
                t = b[j];
                b[j]=b[j+1];
                b[j+1]=t;
            }
        }
      if(1==flag)// 本趟排序中，出现了交换元素的情况。
         Pri(b,ble);//每一次排序后，打印数组元素
      else
        break;//数组已经有序，直接跳出循环
    }

}
