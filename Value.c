#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"sfile.h"

void Initstack();//初始化顺序栈函数声明
void Push();// 入栈函数声明
se Pop();//出栈函数声明

void Prit(int b[],int ble){//打印数组元素函数声明
     int i;
     for(i=0;i<ble;i++)
        printf("%d ",b[i]);

}

int Calva(char c,int a,int b){// c-用小写英文字符代表逻辑运算符  a、b-代表“真、假”的0、1
    int value=-1;//返回值
    if('a'==c){//与
        value = a&&b;
    }
    else if('o'==c)//或
        value = a||b;
    else if('n'==c)//非
        value = !a;//只用到了a
    else if('i'==c){// 蕴含操作 a->b
        if(1==a&&0==b)// 只有
            value=0;
        else
            value=1;
    }
    else if('e'){//等值“==”
        value = (a==b);
    }
    else
        printf("输入有错！\n");

return value;
}

int Ret(char ch){// 判断字符ch是数字字符，还是英文字符
    int rt=-1;
    if((ch-'0')>=0&&(ch-'0')<=9)
        rt = 0;//表示ch是数字字符。
    else if(ch=='a'||ch=='o'||ch=='n'||ch=='i'||ch=='e')
        rt = 1;//表示ch是5个英文字母之一。
    else//不做任何操作
    if(-1==rt)
        printf("扫描到非法字符！！！！\n\n");
return rt;
}

int Process(char *s,int b[],int ble,SqStack*st){// 对字符串s扫描，并进行处理。b-放操作数的，ble-操作数个数  *st-顺序栈，已初始化
    int i,j,f,v,le;
    se a1,a2;//
    i=j=0;v=-1;
    le = strlen(s);//计算字符串s中有效字符个数
    for(i=0;i<le;i++){// 扫描字符串s
        f = Ret(s[i]);//判断s[i]代表操作符还是操作数。
        if(0==f){// 当前扫描的是操作数
            Push(st,b[j]);
            j++;
        }
        else{// 当前扫描的是操作符。
            if(s[i]=='n'){// 代表“非”操作，只有1个操作数。
                a2=Pop(st);//将栈顶元素出栈
                v = Calva(s[i],a2,a2);//执行“非”操作
                Push(st,v);//将运算结果入栈。
            }
            else{//除了"非"的其他逻辑操作
                a2 = Pop(st);
                a1 = Pop(st);
                v = Calva(s[i],a1,a2);//进行相关逻辑运算
                Push(st,v);//将运算结果入栈。
            }
        }
    //i++;//注意while循环中，若是i是数组的下标，每次循环完了，i手动加1。
    }
    v = Pop(st);//最后的运算结果。

return v;
}

void Pcal(int b[],int ble){// 数组b存储的数字代表1个二进制数，然后加1，其中（ble-1）-最低位，0-最高位
    int i,j,k;
    i=ble-1;j=1;
    for(;i>=0;i--){
        k = b[i];
        if(i==(ble-1)){// n位二进制数的最低位

            if(k+j==1){
                b[i]=1;j=0;//进位j=0
            }
            else{// k+j==2
                b[i]=0;j=1;//进位为1
            }
        }
        else{// (ble)位二进制的其他位
            if(k+j<2){
                b[i]=k+j;j=0;//进位为0
            }
            else{//k+j==2
                b[i]=0;j=1;//进位为1
            }
        }
    }
}

void Prcl(int b[],int ble){// 输出ble位二进制数，从全0到全1,
    int i,le;
    le = pow(2,ble);//计算出2^(ble)的值
    for(i=0;i<le;i++){
        if(0==i)// 第1次直接输出数组原始值
            Prit(b,ble);
        else{// 第2次及以后
            Pcal(b,ble);//执行加1操作
            Prit(b,ble);//输出。
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
    Initstack(&t);//初始化栈t
   //z = Process(s,a,ale,&t);//计算运算结果
   //z = Ret('u');
   //z = Calva('e',1,0);
    //printf("逻辑运算结果：%d\n",z);
    //Prcl(a,ale);
    le = pow(2,ale);//计算出真值表的行数。
    for(i=0;i<le;i++){
        if(0==i){//第1趟，直接输出原始数组值
            z = Process(s,a,ale,&t);//计算逻辑值
            Prit(a,ale);
            printf("%d\n",z);//
        }
        else{//第2趟及以后
            Pcal(a,ale);//先执行加“1”操作。
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

     printf("计算前：");Pri(a,ale);Pcal(a,ale);//执行加1操作。
    printf("计算后：");Pri(a,ale);//printf("2^3: %d\n",pow(2,3));
    z = pow(2,3);w =pow(2,3);printf("z: %d  w: %lf\n",z,w);
*/
