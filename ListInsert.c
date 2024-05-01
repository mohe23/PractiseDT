// 顺序表的插入、删除（升序表）

#include<stdio.h>
#include<stdlib.h>

void Prnt(int b[],int low,int high){//打印第low个至第high个数据
    int i;
    for(i=low-1;i<high;i++){
        if(i<high-1)//打印最后1个元素之前的所有元素
            printf("%d ",b[i]);
        else// 打印最后1个元素。
            printf("%d\n",b[i]);
    }

}
int ListInsert(int b[],int ble,int e,int l){// 在数组b第l个位置插入数值e，l-不是下标 ble-是当前数组中存放元素个数 假设数组容量足够
    int i,ret=-1;// ret-返回值
    if(l<1||l>(ble+1)){//插入位置非法
        ret=ble;
        printf("插入位置非法！\n");
    }
    else{// 插入位置合法
        for(i=ble;i>=l;i--)
            b[i]=b[i-1];//将第l个元素及其以后元素向右移动一个位置

        b[i]=e;//将e放入下标为“l-1”的存储位置。并且此时i==(l-1)
        ret = ble+1;
    }

return ret;//返回数组长度
}

int ListDelete(int b[],int ble,int l){// 删除数组b的第l个元素，ble-是数组b的现有元素个数
    int i,ret;//
    if(l>=1&&l<=ble){// 删除位置合法
        for(i=l-1;i<=(ble-2);i++)//将第（l+1）个至第ble个元素左移1位。
            b[i] = b[i+1];
        ret = ble-1;//数组有效数据个数减1
    }
    else{// 删除位置非法
        ret = ble;
        printf("删除位置非法！\n");
    }

return ret;//返回更新后的数组长度。
}
/*
int main(){
    int i,num,ale,a[10]={12,34,56,58,62,78,83,90};
    num=23;ale=8;
    printf("插入前：");
    Prnt(a,1,ale);
    ale = ListDelete(a,ale,2);
    //ale = ListInsert(a,ale,num,2);
    //printf("插入后：");
    Prnt(a,1,ale);

return 0;
}
*/
