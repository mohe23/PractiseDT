// 分块查找

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int maxnum;//块中最大数值
    int order;//块中第1个元素在数组中的下标。
}Block;//结构体Block定义

int Search_Blo(int key,int b[],int ble,Block k[],int kle){// b-存储所有元素 k-块，存储了每一个块中最大值，以及第1个数在数组b中的下标。
    int i,j=-1,ret=-1;// key-待查找元素
    for(i=0;i<kle;i++){// 确定块
        if(key<=k[i].maxnum){
            j = i;// 确定块
            break;//跳出循环
        }
    }
    if(j!=-1){// key < 数组中最大元素
        for(i=k[j].order;i<k[j+1].order;i++){
            if(key==b[i]){
                ret = i;//查找成功，
                break;//跳出循环
            }
        }
    }

return ret;
}
/*
int main(){
   int ble,ale,num,t;
   int a[18]={22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
   Block b[3];// 定义1个结构体数组
   ale=18;ble=3;num=38;
   b[0].maxnum=22;b[0].order=0;b[1].maxnum=48;b[1].order=6;b[2].maxnum=86;b[2].order=12;

   t = Search_Blo(num,a,ale,b,ble);
   printf("查找结果：t=%d\n",t);

return 0;
}
/*
printf("请输入数据，每次输入2个数,每输入1个数，点击“空格键”，每输完2个按“回车键”：\n");
   for(i=0;i<le;i++)
       scanf("%d%d",&b[i].key,&b[i].order);

   printf("输出：\n");
   for(i=0;i<le;i++)
       printf("%d %d\n",b[i].key,b[i].order);
*/
