#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void InsertSort();// ֱ�Ӳ�������
void BInsert();// �۰�������� ��������
void Shell(); // ϣ��������Ҫ����
void ShellSort(); // ϣ��������
void BubbleSort();// ð�ݺ�������
int Getmid();// ��������
void QSort();// ��������������
void SelectSort();// ��ѡ����������
void HeapAdjust();// �����Ѻ�������
void CreateHeap();// ���ɶѺ�������
void HeapSort();// ������������
void Merge();// �ϲ�2�����������������
void MSort();// ��·�鲢����������

void Pri(int *a,int le){// ��ӡ����Ԫ��
    int i;
    for(i=0;i<le;i++)
        printf("%d ",a[i]);
    printf("\n\n");//��ӡ����ȫ��Ԫ��֮�󣬻���
}

void Reverse(int a[],int ale){// ����������Ԫ�ص���
    int i,t,mid;
    mid = ale/2;//��Ϊ1���ض��ġ����ޡ�
    for(i=0;i<mid;i++){
        t = a[i];
        a[i]=a[ale-1-i];
        a[ale-1-i]=t;//������ӦԪ�ء�
    }
}

/*
int main()
{
    int i,n,j,a[10];
    double t=3.465;
    int *b,*c;
    b=(int*)malloc(sizeof(int));
    c=(int*)malloc(sizeof(int));
    (*b)=34;(*c)=45;
    printf("free(b)ǰ��*b=%d,*c=%d\n",(*b),(*c));
    free(b);
    printf("free(b)��*b=%d,*c=%d\n",(*b),(*c));
    if(c==NULL)
        printf("�գ�\n");
    else
         printf("���գ�\n");

     if(b==NULL)
        printf("b�գ�\n");
    else
         printf("b���գ�\n");

   /* printf("������1������");
    scanf("%d",&n);
    while(n>0){
        //printf("%d",n%10);
        a[j++]=n%10;
        n = n/10;
    }
    for(i=j-1;i>=0;i--)
        printf("%d",a[i]);*/
    //printf("double��%lf��ȡ�������%.0lf\n",t,t);
    //printf("%d\n",10/4);
 /*  //int a[10]={49,38,65,97,76,13,27,49,55,4};//{49,38,65,97,76,13,27,49}; //int a[]={8,7,6,5,4,3,2,1};
   int a[] = {49,38,65,97,32,13,27,76};  //int a[]={49,38,65,97,76,13,27};
   //int a[] = {98,86,70,65,53,42,32}; // 0,38,76,65,49,49,13,27,97   0,49,38,65,97,76,13,27,49  2,34,78,12,45,60,75
   //int *a = (int*)malloc(sizeof(int)*7);a[0]=98;a[1]=86;a[2]=70;a[3]=65;a[4]=53;a[5]=43;a[6]=32;

   int b[]={5,3,1};
   int ale,ble,pt;
   ale=8;ble=3;
   pt = ++ble;
   printf("pt=%d,ble=%d\n",pt,ble);
   printf("����ǰ��");
   Pri(a,ale);
   Reverse(a,ale);
   //MSort(a,1,ale);// ��·�鲢����
   //Merge(a,1,3,ale);
   //HeapSort(a,ale);//�������㷨
   //CreateHeap(a,ale);//��1���������е����ɴ����
   //HeapAdjust(a,1,7);//������
   //SelectSort(a,ale);
    //pt = Getmid(a,0,ale-1);
   //printf("pt: %d\n",pt);
   //QSort(a,0,ale-1);
   //printf("\n");
   //BubbleSort(a,ale);
   //InsertSort(a,ale);//ִ�С�ֱ�Ӳ������򡱳���
   //BInsert(a,ale);
   //ShellSort(a,ale,b,ble);
   printf("�����");
   Pri(a,ale);
    //printf("Hello world!\n");*/
  /* return 0;
}

*/
