// �۰��������˳���������� - ��������

#include<stdio.h>
#include<stdlib.h>

void BInsert(int *b,int le){// �۰��������
    int i,j,t,low,high,mid;
    for(i=1;i<le;i++){
        t=b[i];low=0;high=i-1;
// mid = (low+high)/2;���ܷ������Ҫ���������ѭ���##������ʲô��
        while(low<=high){
            mid = (low+high)/2;
            if(t>b[mid])// ������Ԫ�� > b[mid]
                low = mid+1;
            else// ������Ԫ�� <= b[mid]
                high = mid-1;
        }// high:������Ԫ����˳�������ȷλ�õ�ǰ1��λ�õ��±ꡣ
        for(j=i-1;j>=(high+1);j--)// ���Ǵ�����Ԫ��������������������򲻻�ִ�����forѭ������Ϊj=high<(high+1)��������ѭ������
            b[j+1]=b[j];
        b[high+1] = t; // Ҫ�Ǵ�����Ԫ���������������������������ظ���ֵ�����Ա����ظ���ֵ������û��Ҫ��
    }
}
