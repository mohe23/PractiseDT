// ��������˳�������-��������

#include<stdio.h>
#include<stdlib.h>

int Getmid(int b[],int low,int high){// һ������󣬻��һ��ʼb[low]�������������е�λ���±ꡣÿһ�����򣬿��Ի��1��Ԫ�ص�����λ��
    int t;
    t = b[low];//һ��ʼ��b[low]����ŦԪ�ء�
    while(low<high){
        while(low<high&&b[high]>=t)// ��ʾλ�������Ҳ��Ԫ��ֵ >= һ��ʼ������ŦԪ��
            high--;
        b[low] = b[high];//���Ҳ�ɨ�赽��Ԫ�� < ��ŦԪ��,��ʱ��ŦԪ���±꣺low

        while(low<high&&b[low]<=t)// ���������ɨ��Ԫ�أ�Ԫ��ֵ <= ��Ŧֵ
            low++; // ����ࡰָ�롱��1
        b[high]=b[low];// ��ʱ��high������ŦԪ�ص��±꣬��>��ŦԪ�ص�ֵ��ֵ���±�high��
    }
    b[low] = t;// ѭ������
return low;
}

void QSort(int b[],int low,int high){// ����������1���ݹ����
     int mid;
     if(low < high){
        mid = Getmid(b,low,high);
        QSort(b,low,mid-1);// �ݹ����ӱ�
        QSort(b,mid+1,high);// �ݹ����ӱ�
     }
}
