// 希尔排序（顺序表，结果升序）-交换排序

#include<stdio.h>
#include<stdlib.h>

void Pri();// 打印函数声明

void Shell(int b[],int blength,int d){// 希尔排序 d：分组间隔。
     int i,j,t;
     for(i=d;i<blength;i++){ // 从序号是(0+d)的元素开始
         t = b[i];// 待排序元素
         for(j=i-d;j>=0;j-=d){
            if(b[j]>t)// 待排序元素 > 当前待扫描元素
                b[j+d] = b[j];
            else
                break;// 要是<=，直接跳出循环
         }
         b[j+d]=t;
     }
}


void ShellSort(int b[],int ble,int c[],int cle){
    int i;
    for(i=0;i<cle;i++){
        Shell(b,ble,c[i]);
        Pri(b,ble);// 每次希尔函数处理之后，打印处理结果。
    }
}
