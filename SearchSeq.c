// ˳����ң�˳���

#include<stdio.h>
#include<stdlib.h>

int Search_Seq(int num,int b[],int ble){// ˳�����
    int i,t=-1;
    for(i=0;i<ble;i++){
        if(num==b[i]){//���ҳɹ�
            t = i;//���ҳɹ�ʱ�����ص��ǲ���Ԫ��������λ�õ��±�ֵ
            break;//һ�����ҳɹ���������ѭ����
        }
    }
    if(-1==t)
        printf("����ʧ�ܣ�\n");

    return t;
}
/*
int main(){
    int i,ret,ale,m,*a;
    char c1,c2,c3;
    printf("������3���ַ���");
    scanf("%c%c%c",&c1,&c2,&c3);
    printf("c1:%c c2:%c c3:%c\n",c1,c2,c3);
    printf("���������鳤�ȣ�");
    scanf("%d",&ale);
    printf("����������Ԫ�أ�");
    for(i=0;i<ale;i++)
        scanf("%d",&a[i]);
    printf("�����������Ԫ�أ�");
    scanf("%d",&m);
    //int a[]={34,56,12,47,76,39,75};
    //ale = 7;m=3;
    ret=Search_Seq(m,a,ale);
    if(-1==ret)
        printf("����ʧ�ܣ���ǰ�����в�����%d\n",m);
    else
        printf("%d��������λ��Ϊ��%d\n",m,ret+1);

    return 0;
}
*/
