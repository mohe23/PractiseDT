// 二路归并排序（顺序表，结果升序）-归并排序

#include<stdio.h>
#include<stdlib.h>

void Merge(int b[],int low,int mid,int high){// 将2个有序序列按照升序合并。

 //有序子序列：第low个至mid，第mid+1个至high个，按照升序排列在数组c中low至high 。low,mid,high：是元素在数组中所在位置的序号。
    int i,j,k;
    int *c = (int*)malloc(sizeof(int)*(high+1));// 创建1个长度为（high+1）的数组

    i=k=low-1;j=mid;
    while(i<mid&&j<high){// 循环条件：2个序列都还没有比较完全部元素
        if(b[i]<b[j]){// b[i]值较小
            c[k]=b[i];
            k++;i++;//将前1个序列的“指针”后移1位
        }
        else{// b[i]>=b[j]，此时b[j]的值比较小。
            c[k]=b[j];
            k++;j++;//将后1个序列的指针后移1位
        }
    }

    while(i<mid){//1序列元素没有比较完毕，2序列已经比较完毕了

        c[k]=b[i];
        k++;i++;
    }
    while(j<high){//1序列比较完毕了，2序列没有比较完毕。
        c[k]=b[j];
        k++;j++;
    }
    for(i=low-1;i<high;i++)
        b[i]=c[i];//将已排序好的结果重新赋值给原数组。

}

void MSort(int b[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        MSort(b,low,mid);//递归调用
        MSort(b,mid+1,high);
        Merge(b,low,mid,high);//合并2个有序子序列。
    }
}
