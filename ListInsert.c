// ˳���Ĳ��롢ɾ���������

#include<stdio.h>
#include<stdlib.h>

void Prnt(int b[],int low,int high){//��ӡ��low������high������
    int i;
    for(i=low-1;i<high;i++){
        if(i<high-1)//��ӡ���1��Ԫ��֮ǰ������Ԫ��
            printf("%d ",b[i]);
        else// ��ӡ���1��Ԫ�ء�
            printf("%d\n",b[i]);
    }

}
int ListInsert(int b[],int ble,int e,int l){// ������b��l��λ�ò�����ֵe��l-�����±� ble-�ǵ�ǰ�����д��Ԫ�ظ��� �������������㹻
    int i,ret=-1;// ret-����ֵ
    if(l<1||l>(ble+1)){//����λ�÷Ƿ�
        ret=ble;
        printf("����λ�÷Ƿ���\n");
    }
    else{// ����λ�úϷ�
        for(i=ble;i>=l;i--)
            b[i]=b[i-1];//����l��Ԫ�ؼ����Ժ�Ԫ�������ƶ�һ��λ��

        b[i]=e;//��e�����±�Ϊ��l-1���Ĵ洢λ�á����Ҵ�ʱi==(l-1)
        ret = ble+1;
    }

return ret;//�������鳤��
}

int ListDelete(int b[],int ble,int l){// ɾ������b�ĵ�l��Ԫ�أ�ble-������b������Ԫ�ظ���
    int i,ret;//
    if(l>=1&&l<=ble){// ɾ��λ�úϷ�
        for(i=l-1;i<=(ble-2);i++)//���ڣ�l+1��������ble��Ԫ������1λ��
            b[i] = b[i+1];
        ret = ble-1;//������Ч���ݸ�����1
    }
    else{// ɾ��λ�÷Ƿ�
        ret = ble;
        printf("ɾ��λ�÷Ƿ���\n");
    }

return ret;//���ظ��º�����鳤�ȡ�
}
/*
int main(){
    int i,num,ale,a[10]={12,34,56,58,62,78,83,90};
    num=23;ale=8;
    printf("����ǰ��");
    Prnt(a,1,ale);
    ale = ListDelete(a,ale,2);
    //ale = ListInsert(a,ale,num,2);
    //printf("�����");
    Prnt(a,1,ale);

return 0;
}
*/
