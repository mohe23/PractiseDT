// ϣ������˳����������-��������

#include<stdio.h>
#include<stdlib.h>

void Pri();// ��ӡ��������

void Shell(int b[],int blength,int d){// ϣ������ d����������
     int i,j,t;
     for(i=d;i<blength;i++){ // �������(0+d)��Ԫ�ؿ�ʼ
         t = b[i];// ������Ԫ��
         for(j=i-d;j>=0;j-=d){
            if(b[j]>t)// ������Ԫ�� > ��ǰ��ɨ��Ԫ��
                b[j+d] = b[j];
            else
                break;// Ҫ��<=��ֱ������ѭ��
         }
         b[j+d]=t;
     }
}


void ShellSort(int b[],int ble,int c[],int cle){
    int i;
    for(i=0;i<cle;i++){
        Shell(b,ble,c[i]);
        Pri(b,ble);// ÿ��ϣ����������֮�󣬴�ӡ��������
    }
}
