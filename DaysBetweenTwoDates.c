//   �����2�����ڣ������գ�֮�������


#include<stdio.h>
#include<stdlib.h>

int LeapYear(int year){// �ж����year�Ƿ�������
    int flag=0;
    if((year%4==0&&year%100!=0)||(year%400==0))
        flag = 1;

    return flag;
}


int BetweenMonths(int m[],int year,int month1,int month2){// ����year���У�month1�µ�month2���ܹ��ж����죬����m-���ÿ���µ�����
    int i,fl,sum=0;                                       //����m���±�1��ʼ�洢��ЧԪ�ء�
    for(i=month1;i<=month2;i++){

        if(2==i){// ��2�·��ر��ע
            fl = LeapYear(year);//�ж��Ƿ�������
            if(1==fl)//�ж�������
                m[i]++;
        }
        sum+=m[i];
    }
    return sum;//ע�ⷵ��ֵ����Ҫ����
}

int Daytoend(int m[],int year,int month,int day){//����month��(day+1)��-month����ĩ�ж����졣
    int f,sum;
    if(2==month){
        f = LeapYear(year);
        if(1==f)// ���꣬����2��
            m[month]++;
    }
    sum = m[month]-day;

    return sum;//��������
}

int Monthday(int m[],int year,int month1,int day1,int month2,int day2){
    //����month1��day1��-month2��day2���ܼ�����
    int s,s1,s2;
    s1 = BetweenMonths(m,year,month1,month2);
    s2 = Daytoend(m,year,month2,day2);
    s = s1-s2;

    return s;//��������
}

int Yearday(int year1,int year2){// ����year1��1��1��-year2��12��31��һ�������ꡣ
    int i,f,sum=0;
    for(i=year1;i<=year2;i++){
        f = LeapYear(i);//�ж��Ƿ�������
        if(1==f)//����
            sum+=366;
        else//ƽ��
            sum+=365;
    }

    return sum;
}

int TwoDates(int m[],int year1,int month1,int day1,int year2,int month2,int day2){//����2���������������,Ĭ�Ϻ�1������>=ǰ1������
    int flag,s1,s2,s3,s4;
    s1 = Yearday(year1,year2);//����year1-year2��һ��������
    s2 = Monthday(m,year1,1,1,month1,day1);//����1.1-month1.day1�ж�����
    s3 = Monthday(m,year2,1,1,month2,day2);//����month2.(day2+1)-12.31�ж�����
    flag = LeapYear(year2);//�ж�year2�Ƿ�������
    if(1==flag)
        s3 = 366-s3;
    else
        s3 = 365-s3;
    s4 = s1-s2-s3;

    return s4;
}

/*
int main(){
   int y1,y2,m1,m2,d1,d2,s;
   int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
   y1=2000;m1=1;d1=1;y2=2000;m2=12;d2=31;
   s = TwoDates(a,y1,m1,d1,y2,m2,d2);//s=Daytoend(a,y,m2,d1);//s = BetweenMonths(a,y,m1,m2);//s = Monthday(a,y,m1,d1,m2,d2);////
   printf("������%d\n",s);

   return 0;
}*/
