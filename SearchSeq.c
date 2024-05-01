// 顺序查找（顺序表）

#include<stdio.h>
#include<stdlib.h>

int Search_Seq(int num,int b[],int ble){// 顺序查找
    int i,t=-1;
    for(i=0;i<ble;i++){
        if(num==b[i]){//查找成功
            t = i;//查找成功时，返回的是查找元素在数组位置的下标值
            break;//一旦查找成功，就跳出循环。
        }
    }
    if(-1==t)
        printf("查找失败！\n");

    return t;
}
/*
int main(){
    int i,ret,ale,m,*a;
    char c1,c2,c3;
    printf("请输入3个字符：");
    scanf("%c%c%c",&c1,&c2,&c3);
    printf("c1:%c c2:%c c3:%c\n",c1,c2,c3);
    printf("请输入数组长度：");
    scanf("%d",&ale);
    printf("请输入数组元素：");
    for(i=0;i<ale;i++)
        scanf("%d",&a[i]);
    printf("请输入待查找元素：");
    scanf("%d",&m);
    //int a[]={34,56,12,47,76,39,75};
    //ale = 7;m=3;
    ret=Search_Seq(m,a,ale);
    if(-1==ret)
        printf("查找失败，当前数组中不存在%d\n",m);
    else
        printf("%d在数组中位置为：%d\n",m,ret+1);

    return 0;
}
*/
