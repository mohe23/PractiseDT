// 简单选择排序（顺序表，结果升序）

#include<stdio.h>
#include<stdlib.h>

void Pri();// 打印函数声明

void SelectSort(int b[],int ble){// 简单选择排序函数
     int i,j,t;
     for(i=0;i<ble-1;i++){// 注意i的下标最大等于倒数第2个元素的下标。
       // k = i;
        for(j=i+1;j<ble;j++){//j的范围最大等于倒数第1个元素的下标。
            if(b[i]>b[j]){//当前扫描元素 < 目前最小元素b[i]，就交换b[i]与b[j]两个元素。
                t = b[j];
                b[j]=b[i];
                b[i]=t;
            }
        }
        Pri(b,ble);//打印每一趟排序结果。
     }
}
// 我这个实现方法，与书本上提供的实现方法不一样。
