// ��·�鲢����˳����������-�鲢����

#include<stdio.h>
#include<stdlib.h>

void Merge(int b[],int low,int mid,int high){// ��2���������а�������ϲ���

 //���������У���low����mid����mid+1����high����������������������c��low��high ��low,mid,high����Ԫ��������������λ�õ���š�
    int i,j,k;
    int *c = (int*)malloc(sizeof(int)*(high+1));// ����1������Ϊ��high+1��������

    i=k=low-1;j=mid;
    while(i<mid&&j<high){// ѭ��������2�����ж���û�бȽ���ȫ��Ԫ��
        if(b[i]<b[j]){// b[i]ֵ��С
            c[k]=b[i];
            k++;i++;//��ǰ1�����еġ�ָ�롱����1λ
        }
        else{// b[i]>=b[j]����ʱb[j]��ֵ�Ƚ�С��
            c[k]=b[j];
            k++;j++;//����1�����е�ָ�����1λ
        }
    }

    while(i<mid){//1����Ԫ��û�бȽ���ϣ�2�����Ѿ��Ƚ������

        c[k]=b[i];
        k++;i++;
    }
    while(j<high){//1���бȽ�����ˣ�2����û�бȽ���ϡ�
        c[k]=b[j];
        k++;j++;
    }
    for(i=low-1;i<high;i++)
        b[i]=c[i];//��������õĽ�����¸�ֵ��ԭ���顣

}

void MSort(int b[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        MSort(b,low,mid);//�ݹ����
        MSort(b,mid+1,high);
        Merge(b,low,mid,high);//�ϲ�2�����������С�
    }
}
