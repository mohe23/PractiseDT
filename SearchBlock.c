// �ֿ����

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int maxnum;//���������ֵ
    int order;//���е�1��Ԫ���������е��±ꡣ
}Block;//�ṹ��Block����

int Search_Blo(int key,int b[],int ble,Block k[],int kle){// b-�洢����Ԫ�� k-�飬�洢��ÿһ���������ֵ���Լ���1����������b�е��±ꡣ
    int i,j=-1,ret=-1;// key-������Ԫ��
    for(i=0;i<kle;i++){// ȷ����
        if(key<=k[i].maxnum){
            j = i;// ȷ����
            break;//����ѭ��
        }
    }
    if(j!=-1){// key < ���������Ԫ��
        for(i=k[j].order;i<k[j+1].order;i++){
            if(key==b[i]){
                ret = i;//���ҳɹ���
                break;//����ѭ��
            }
        }
    }

return ret;
}
/*
int main(){
   int ble,ale,num,t;
   int a[18]={22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
   Block b[3];// ����1���ṹ������
   ale=18;ble=3;num=38;
   b[0].maxnum=22;b[0].order=0;b[1].maxnum=48;b[1].order=6;b[2].maxnum=86;b[2].order=12;

   t = Search_Blo(num,a,ale,b,ble);
   printf("���ҽ����t=%d\n",t);

return 0;
}
/*
printf("���������ݣ�ÿ������2����,ÿ����1������������ո������ÿ����2�������س�������\n");
   for(i=0;i<le;i++)
       scanf("%d%d",&b[i].key,&b[i].order);

   printf("�����\n");
   for(i=0;i<le;i++)
       printf("%d %d\n",b[i].key,b[i].order);
*/
