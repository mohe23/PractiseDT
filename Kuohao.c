// ����ƥ�� (���ţ�С���ţ������ţ�������)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void BracketMatch(char b[],int ble){//b-�ַ�����  ble-�ַ�����ĳ���
    bool bt=true;//��ʼֵĬ��Ϊ��true��
    int i,small,mid,big;
    small=mid=big=0;//��ʼ��3������ֵ
    for(i=0;i<ble;i++){// ��ʼɨ���ַ���b
        switch(b[i]){
        case'{':
            big++;
            break;
        case'[':
            mid++;
            break;
        case'(':
            small++;
            break;
        case'}':
            big--;
            break;
        case']':
            mid--;
            break;
        case')':
            small--;
            break;
        }
    }
    if(small!=0||mid!=0||big!=0)// Ҫ������ƥ��ɹ���small=mid=big=0
        bt = false;
    if(bt)// ����ƥ��ɹ�
        printf("yes\n");
    else// ����ƥ��ʧ��
        printf("no\n");
}
/*
int main(){
    int i,ale,sum;
    char a[20];
    ale=1;sum=1;i=ale&&sum;
    printf("i = %d\n",i);


    printf("��������������,���س���������������������ÿ����1�����Ͱ��س�������������һ������\n");

    scanf("%d%*c",&sum);
    for(i=0;i<sum;i++){
        gets(a);//���������ַ���
        ale = strlen(a);
        BracketMatch(a,ale);
    }

return 0;
}*/

/*
char a[]="[(7)]";
    char b[]="{[])";
    int ale,ble;
    //bool b1,b2;
    ale=strlen(a);ble=strlen(b);
    BracketMatch(a,ale);BracketMatch(b,ble);
*/
