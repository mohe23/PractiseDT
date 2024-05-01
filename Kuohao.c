// 括号匹配 (括号：小括号，中括号，大括号)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void BracketMatch(char b[],int ble){//b-字符数组  ble-字符数组的长度
    bool bt=true;//初始值默认为“true”
    int i,small,mid,big;
    small=mid=big=0;//初始化3个整数值
    for(i=0;i<ble;i++){// 开始扫描字符串b
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
    if(small!=0||mid!=0||big!=0)// 要想括号匹配成功，small=mid=big=0
        bt = false;
    if(bt)// 括号匹配成功
        printf("yes\n");
    else// 括号匹配失败
        printf("no\n");
}
/*
int main(){
    int i,ale,sum;
    char a[20];
    ale=1;sum=1;i=ale&&sum;
    printf("i = %d\n",i);


    printf("请输入样例组数,按回车键后，再输入括号样例，每输入1个，就按回车键，再输入下一个样例\n");

    scanf("%d%*c",&sum);
    for(i=0;i<sum;i++){
        gets(a);//输入括号字符串
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
