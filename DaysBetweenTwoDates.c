//   计算出2个日期（年月日）之间的天数


#include<stdio.h>
#include<stdlib.h>

int LeapYear(int year){// 判断年份year是否是闰年
    int flag=0;
    if((year%4==0&&year%100!=0)||(year%400==0))
        flag = 1;

    return flag;
}


int BetweenMonths(int m[],int year,int month1,int month2){// 计算year年中，month1月到month2月总共有多少天，数组m-存放每个月的天数
    int i,fl,sum=0;                                       //数组m从下标1开始存储有效元素。
    for(i=month1;i<=month2;i++){

        if(2==i){// 对2月份特别关注
            fl = LeapYear(year);//判断是否是闰年
            if(1==fl)//判断是闰年
                m[i]++;
        }
        sum+=m[i];
    }
    return sum;//注意返回值，不要忘了
}

int Daytoend(int m[],int year,int month,int day){//计算month月(day+1)日-month月月末有多少天。
    int f,sum;
    if(2==month){
        f = LeapYear(year);
        if(1==f)// 闰年，且是2月
            m[month]++;
    }
    sum = m[month]-day;

    return sum;//返回天数
}

int Monthday(int m[],int year,int month1,int day1,int month2,int day2){
    //计算month1月day1日-month2月day2日总计天数
    int s,s1,s2;
    s1 = BetweenMonths(m,year,month1,month2);
    s2 = Daytoend(m,year,month2,day2);
    s = s1-s2;

    return s;//返回天数
}

int Yearday(int year1,int year2){// 计算year1年1月1日-year2年12月31日一共多少年。
    int i,f,sum=0;
    for(i=year1;i<=year2;i++){
        f = LeapYear(i);//判断是否是闰年
        if(1==f)//闰年
            sum+=366;
        else//平年
            sum+=365;
    }

    return sum;
}

int TwoDates(int m[],int year1,int month1,int day1,int year2,int month2,int day2){//计算2个日期相隔多少天,默认后1个日期>=前1个日期
    int flag,s1,s2,s3,s4;
    s1 = Yearday(year1,year2);//计算year1-year2年一共多少天
    s2 = Monthday(m,year1,1,1,month1,day1);//计算1.1-month1.day1有多少天
    s3 = Monthday(m,year2,1,1,month2,day2);//计算month2.(day2+1)-12.31有多少天
    flag = LeapYear(year2);//判断year2是否是闰年
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
   printf("天数：%d\n",s);

   return 0;
}*/
