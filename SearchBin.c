// �۰���ң�˳���

#include<stdio.h>
#include<stdlib.h>

int Search_Bin(int b[],int ble,int key){// �۰���ҡ�����b���������� ble-����b�ĳ��� key-ָ������Ԫ��
    int low,mid,high,ret=-1;
    low=0;high=ble-1;
    while(low<=high){// ʹ��1��whileѭ��
        mid = (low+high)/2;
        if(key==b[mid]){//���ҳɹ���һ��Ҫ����ѭ������
            ret = mid;
            break;//
        }
        else if(key<b[mid])// key<��ǰɨ��ֵ
            high = mid-1;
        else// key > ��ǰɨ��ֵ
            low = mid+1;
    }

    return ret;
}
/*
int main(){
   int i,r,ale,key;
   /*printf("���������鳤�ȣ�");
   scanf("%d",&ale);
   a =(int*)malloc(sizeof(int)*ale);//Ϊ�������洢�ռ�
   printf("������������Ԫ�أ�");
   for(i=0;i<ale;i++)
       scanf("%d",&a[i]);
    printf("�������Ԫ�أ�");
    scanf("%d",&key);
   //for(i=0;i<3;i++)
     //  printf("%d ",a[i]);
    int a[]={90,95,98};  // 12,45,78,90,95,98
    ale=3;key=90;
   r = Search_Bin(a,ale,key);
   printf("���ҽ��:r=%d\n",r);

return 0;
}*/
