// 折半插入排序（顺序表，结果升序） - 插入排序

#include<stdio.h>
#include<stdlib.h>

void BInsert(int *b,int le){// 折半插入排序
    int i,j,t,low,high,mid;
    for(i=1;i<le;i++){
        t=b[i];low=0;high=i-1;
// mid = (low+high)/2;不能放在这里，要放在下面的循环里。##我在想什么！
        while(low<=high){
            mid = (low+high)/2;
            if(t>b[mid])// 待排序元素 > b[mid]
                low = mid+1;
            else// 待排序元素 <= b[mid]
                high = mid-1;
        }// high:待排序元素在顺序表中正确位置的前1个位置的下标。
        for(j=i-1;j>=(high+1);j--)// 若是待排序元素在已有序序列中最大，则不会执行这个for循环，因为j=high<(high+1)，不满足循环条件
            b[j+1]=b[j];
        b[high+1] = t; // 要是待排序元素在已有序序列中最大，这个就是重复赋值。可以避免重复赋值，但是没必要。
    }
}
