// 打印规则“*”图案。

#include<stdio.h>
#include<stdlib.h>

void Pristar(int n){//n为奇数
    int i,j,k,s,*a;
    k = (n+1)/2;
    a=(int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++)
        a[i]=k-1-i;// 第i行第1个*的位置
    for(i=0;i<k;i++){
        s=0;//f=0;l=0;//统计当前行打印的*的个数
        for(j=0;j<n;j++){
            if(j!=a[i])// 当前还不是打印第1个*的位置
                printf(" ");
            else{//当前遇到第1个打印*的位置
                 printf("*");
                 s++;//统计当前行已打印*的个数。
                 if(s==(i+1))//当前行*的个数已经打印完毕
                    break;//跳出当前行的打印
                 a[i]=j+2;//本行，下一个*的打印位置（若还存在下一个*打印）
            }
        }
        printf("\n");//当前行打印完毕，回车，进入下一行，为下一次打印做准备
    }

    for(i=0;i<k;i++)// 恢复一下数组a的初始数值
        a[i]=k-1-i;// 第i行第1个*的位置

    for(i=k-2;i>=0;i--){
        s=0;//每一行打印前将该值置0
        for(j=0;j<n;j++){
            if(j!=a[i])//
                printf(" ");
            else{
                 printf("*");
                 s++;//统计当前行已打印*的个数。
                 if(s==(i+1))//当前行*的个数已经打印完毕,注意本行的条件，与上面相应部分的条件不一样。
                     break;//跳出当前行的打印
                 a[i]=j+2;
            }
        }
        printf("\n");
    }

}


/*
int main(){
    int n=7;
   // printf("请输入层数：");
    //scanf("%d",&n);
    printf("\n\n");
    printf("图案如下：\n");
    Pristar(n);
    Pristar(9);
return 0;
}*/

/*
 if(j==a[i]){
                if(0==f)
                    l=1;
                else
                    l=0;
                f=1;//表示当前j位置可以打印*

            }
            if(1==f){//打印*
                if(1==l){
                    printf("*");
                    f=0;
                }
                else
                    printf(" ");
                s++;
                if(s<i+1)
                    a[i]=j+1;
                else// s==(i+1)
                    break;//直接跳出内层循环，打印下一层。
                //f=0;
            }
            else// f==0
                printf(" ");

        }
*/
