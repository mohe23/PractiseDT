#include<stdio.h>
#include<stdlib.h>

int Calv(int a,int b){//计算a^b。
    int i,s=1;
    for(i=0;i<b;i++)
        s = s*a;

return s;
}

int** CreateDet(int order){//创建1个orderxorder大小的数组，存储order阶行列式
    int i;
    int **a=(int**)malloc(sizeof(int*)*order);
    for(i=0;i<order;i++)
        a[i]=(int*)malloc(sizeof(int)*order);//创建1个order x order大小的数组。

return a;//返回二级指针。
}

void FreeDet(int**a,int order){//清除二维数组的存储空间。
    int i;
    for(i=0;i<order;i++)
        free(a[i]);//清除该行的存储容量。
}

int** GetDet(int**a,int order,int l){//除去行列式a的第1行与第l列，将剩下的元素按照原来的顺序，成为(order-1)阶行列式
    int i,j;
    int**b = CreateDet(order-1);//创建1个（order-1）X(order-1)的数组，存放新的行列式
    order--;//将阶数减1
    l--;//变为对应的下标
    for(i=0;i<order;i++){
        for(j=0;j<order;j++){
            if(j<l){
                b[i][j]=a[i+1][j];
            }
            else{//j>=l
                b[i][j]=a[i+1][j+1];
            }
        }
    }

return b;
}

void PriDet(int**a,int order){//打印行列式a
    int i,j;
    for(i=0;i<order;i++){
        for(j=0;j<order;j++){
            printf("%d ",a[i][j]);//打印该元素
        }
        printf("\n");
    }
}

int CalDet(int**a,int order){//计算行列式的值。
    int s=0;
    if(order==2){//行列式为二阶行列式，直接计算即可
        //int s=0;
        s = a[0][0]*a[1][1]-a[0][1]*a[1][0];
        //return s;
    }
    else{//行列式阶数>2
        for(int i=0;i<order;i++){
            int**b=CreateDet(order-1);//为剩余元素组成的余子式分配存储空间
            b = GetDet(a,order,i+1);//获得剩余元素组成的余子式。
            s = s+a[0][i]*Calv(-1,2+i)*CalDet(b,order-1);
        }
    }

return s;
}

int main(){
   int i,j,order,c,**a,**b;
   c=3;
   printf("请输入阶数：");
   scanf("%d",&order);
   a=CreateDet(order);//为即将输入的行列式分配存储空间
   b=CreateDet(order-1);
   for(i=0;i<order;i++){
       for(j=0;j<order;j++)
           scanf("%d",&a[i][j]);
   }
   c = CalDet(a,order);
   printf("行列式计算结果：%d\n",c);

   //a[3][3]={1,2,3,4,5,6,7,8,9};
   /*
   b = GetDet(a,order,c);
   printf("输出行列式a:\n");
   PriDet(a,order);
   printf("输出行列式b:\n");
   PriDet(b,order-1);*/

return 0;
}

/*
int s,a,b;
    a=-1;b=4;
    s = Calv(a,b);
    printf("%d^%d = %d\n",a,b,s);

*/
