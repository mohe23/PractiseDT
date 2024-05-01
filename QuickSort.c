// 快速排序（顺序表，升序）-交换排序

#include<stdio.h>
#include<stdlib.h>

int Getmid(int b[],int low,int high){// 一趟排序后，获得一开始b[low]在最终排序结果中的位置下标。每一趟排序，可以获得1个元素的最终位置
    int t;
    t = b[low];//一开始的b[low]是枢纽元素。
    while(low<high){
        while(low<high&&b[high]>=t)// 表示位于数组右侧的元素值 >= 一开始定的枢纽元素
            high--;
        b[low] = b[high];//从右侧扫描到的元素 < 枢纽元素,此时枢纽元素下标：low

        while(low<high&&b[low]<=t)// 从数组左侧扫描元素，元素值 <= 枢纽值
            low++; // 将左侧“指针”加1
        b[high]=b[low];// 此时，high：是枢纽元素的下标，将>枢纽元素的值赋值到下标high处
    }
    b[low] = t;// 循环结束
return low;
}

void QSort(int b[],int low,int high){// 快速排序，是1个递归程序
     int mid;
     if(low < high){
        mid = Getmid(b,low,high);
        QSort(b,low,mid-1);// 递归左子表
        QSort(b,mid+1,high);// 递归右子表
     }
}
