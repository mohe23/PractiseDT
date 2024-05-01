#include<stdio.h>
#include<stdlib.h>

int Calv(int a,int b){//����a^b��
    int i,s=1;
    for(i=0;i<b;i++)
        s = s*a;

return s;
}

int** CreateDet(int order){//����1��orderxorder��С�����飬�洢order������ʽ
    int i;
    int **a=(int**)malloc(sizeof(int*)*order);
    for(i=0;i<order;i++)
        a[i]=(int*)malloc(sizeof(int)*order);//����1��order x order��С�����顣

return a;//���ض���ָ�롣
}

void FreeDet(int**a,int order){//�����ά����Ĵ洢�ռ䡣
    int i;
    for(i=0;i<order;i++)
        free(a[i]);//������еĴ洢������
}

int** GetDet(int**a,int order,int l){//��ȥ����ʽa�ĵ�1�����l�У���ʣ�µ�Ԫ�ذ���ԭ����˳�򣬳�Ϊ(order-1)������ʽ
    int i,j;
    int**b = CreateDet(order-1);//����1����order-1��X(order-1)�����飬����µ�����ʽ
    order--;//��������1
    l--;//��Ϊ��Ӧ���±�
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

void PriDet(int**a,int order){//��ӡ����ʽa
    int i,j;
    for(i=0;i<order;i++){
        for(j=0;j<order;j++){
            printf("%d ",a[i][j]);//��ӡ��Ԫ��
        }
        printf("\n");
    }
}

int CalDet(int**a,int order){//��������ʽ��ֵ��
    int s=0;
    if(order==2){//����ʽΪ��������ʽ��ֱ�Ӽ��㼴��
        //int s=0;
        s = a[0][0]*a[1][1]-a[0][1]*a[1][0];
        //return s;
    }
    else{//����ʽ����>2
        for(int i=0;i<order;i++){
            int**b=CreateDet(order-1);//Ϊʣ��Ԫ����ɵ�����ʽ����洢�ռ�
            b = GetDet(a,order,i+1);//���ʣ��Ԫ����ɵ�����ʽ��
            s = s+a[0][i]*Calv(-1,2+i)*CalDet(b,order-1);
        }
    }

return s;
}

int main(){
   int i,j,order,c,**a,**b;
   c=3;
   printf("�����������");
   scanf("%d",&order);
   a=CreateDet(order);//Ϊ�������������ʽ����洢�ռ�
   b=CreateDet(order-1);
   for(i=0;i<order;i++){
       for(j=0;j<order;j++)
           scanf("%d",&a[i][j]);
   }
   c = CalDet(a,order);
   printf("����ʽ��������%d\n",c);

   //a[3][3]={1,2,3,4,5,6,7,8,9};
   /*
   b = GetDet(a,order,c);
   printf("�������ʽa:\n");
   PriDet(a,order);
   printf("�������ʽb:\n");
   PriDet(b,order-1);*/

return 0;
}

/*
int s,a,b;
    a=-1;b=4;
    s = Calv(a,b);
    printf("%d^%d = %d\n",a,b,s);

*/
