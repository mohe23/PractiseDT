#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"sfile.h"

void Initstack();//��ʼ��˳��ջ��������
void Push();// ��ջ��������
se Pop();//��ջ��������

void Prit(int b[],int ble){//��ӡ����Ԫ�غ�������
     int i;
     for(i=0;i<ble;i++)
        printf("%d ",b[i]);

}

int Calva(char c,int a,int b){// c-��СдӢ���ַ������߼������  a��b-�����桢�١���0��1
    int value=-1;//����ֵ
    if('a'==c){//��
        value = a&&b;
    }
    else if('o'==c)//��
        value = a||b;
    else if('n'==c)//��
        value = !a;//ֻ�õ���a
    else if('i'==c){// �̺����� a->b
        if(1==a&&0==b)// ֻ��
            value=0;
        else
            value=1;
    }
    else if('e'){//��ֵ��==��
        value = (a==b);
    }
    else
        printf("�����д�\n");

return value;
}

int Ret(char ch){// �ж��ַ�ch�������ַ�������Ӣ���ַ�
    int rt=-1;
    if((ch-'0')>=0&&(ch-'0')<=9)
        rt = 0;//��ʾch�������ַ���
    else if(ch=='a'||ch=='o'||ch=='n'||ch=='i'||ch=='e')
        rt = 1;//��ʾch��5��Ӣ����ĸ֮һ��
    else//�����κβ���
    if(-1==rt)
        printf("ɨ�赽�Ƿ��ַ���������\n\n");
return rt;
}

int Process(char *s,int b[],int ble,SqStack*st){// ���ַ���sɨ�裬�����д���b-�Ų������ģ�ble-����������  *st-˳��ջ���ѳ�ʼ��
    int i,j,f,v,le;
    se a1,a2;//
    i=j=0;v=-1;
    le = strlen(s);//�����ַ���s����Ч�ַ�����
    for(i=0;i<le;i++){// ɨ���ַ���s
        f = Ret(s[i]);//�ж�s[i]������������ǲ�������
        if(0==f){// ��ǰɨ����ǲ�����
            Push(st,b[j]);
            j++;
        }
        else{// ��ǰɨ����ǲ�������
            if(s[i]=='n'){// �����ǡ�������ֻ��1����������
                a2=Pop(st);//��ջ��Ԫ�س�ջ
                v = Calva(s[i],a2,a2);//ִ�С��ǡ�����
                Push(st,v);//����������ջ��
            }
            else{//����"��"�������߼�����
                a2 = Pop(st);
                a1 = Pop(st);
                v = Calva(s[i],a1,a2);//��������߼�����
                Push(st,v);//����������ջ��
            }
        }
    //i++;//ע��whileѭ���У�����i��������±꣬ÿ��ѭ�����ˣ�i�ֶ���1��
    }
    v = Pop(st);//������������

return v;
}

void Pcal(int b[],int ble){// ����b�洢�����ִ���1������������Ȼ���1�����У�ble-1��-���λ��0-���λ
    int i,j,k;
    i=ble-1;j=1;
    for(;i>=0;i--){
        k = b[i];
        if(i==(ble-1)){// nλ�������������λ

            if(k+j==1){
                b[i]=1;j=0;//��λj=0
            }
            else{// k+j==2
                b[i]=0;j=1;//��λΪ1
            }
        }
        else{// (ble)λ�����Ƶ�����λ
            if(k+j<2){
                b[i]=k+j;j=0;//��λΪ0
            }
            else{//k+j==2
                b[i]=0;j=1;//��λΪ1
            }
        }
    }
}

void Prcl(int b[],int ble){// ���bleλ������������ȫ0��ȫ1,
    int i,le;
    le = pow(2,ble);//�����2^(ble)��ֵ
    for(i=0;i<le;i++){
        if(0==i)// ��1��ֱ���������ԭʼֵ
            Prit(b,ble);
        else{// ��2�μ��Ժ�
            Pcal(b,ble);//ִ�м�1����
            Prit(b,ble);//�����
        }
    }
}
/*
int main(){
    char s[10]="01a2i";
    int a[]={0,0,0};
    int i,ale,le,z;double w;
    SqStack t;
    ale=3;
    Initstack(&t);//��ʼ��ջt
   //z = Process(s,a,ale,&t);//����������
   //z = Ret('u');
   //z = Calva('e',1,0);
    //printf("�߼���������%d\n",z);
    //Prcl(a,ale);
    le = pow(2,ale);//�������ֵ���������
    for(i=0;i<le;i++){
        if(0==i){//��1�ˣ�ֱ�����ԭʼ����ֵ
            z = Process(s,a,ale,&t);//�����߼�ֵ
            Prit(a,ale);
            printf("%d\n",z);//
        }
        else{//��2�˼��Ժ�
            Pcal(a,ale);//��ִ�мӡ�1��������
            z = Process(s,a,ale,&t);
            Prit(a,ale);
            printf("%d\n",z);
        }
    }
return 0;
}
*/
/*
int c = 20;
    printf("output: %d\n",c);

     printf("����ǰ��");Pri(a,ale);Pcal(a,ale);//ִ�м�1������
    printf("�����");Pri(a,ale);//printf("2^3: %d\n",pow(2,3));
    z = pow(2,3);w =pow(2,3);printf("z: %d  w: %lf\n",z,w);
*/
