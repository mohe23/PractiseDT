// 折半查找（顺序表）

#include<stdio.h>
#include<stdlib.h>

int Search_Bin(int b[],int ble,int key){// 折半查找。数组b是升序数组 ble-数组b的长度 key-指定查找元素
    int low,mid,high,ret=-1;
    low=0;high=ble-1;
    while(low<=high){// 使用1个while循环
        mid = (low+high)/2;
        if(key==b[mid]){//查找成功后，一定要跳出循环！！
            ret = mid;
            break;//
        }
        else if(key<b[mid])// key<当前扫描值
            high = mid-1;
        else// key > 当前扫描值
            low = mid+1;
    }

    return ret;
}
/*
int main(){
   int i,r,ale,key;
   /*printf("请输入数组长度：");
   scanf("%d",&ale);
   a =(int*)malloc(sizeof(int)*ale);//为数组分配存储空间
   printf("输入有序数组元素：");
   for(i=0;i<ale;i++)
       scanf("%d",&a[i]);
    printf("输入查找元素：");
    scanf("%d",&key);
   //for(i=0;i<3;i++)
     //  printf("%d ",a[i]);
    int a[]={90,95,98};  // 12,45,78,90,95,98
    ale=3;key=90;
   r = Search_Bin(a,ale,key);
   printf("查找结果:r=%d\n",r);

return 0;
}*/
