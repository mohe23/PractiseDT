// 输出命题公式的真值表

#include<stdio.h>
#include<stdlib.h>

/*
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
*/

/*
typedef struct {
    char c[]
}
*/
int main(){
    int c = 20;
    printf("output: %d\n",c);

return 0;
}


