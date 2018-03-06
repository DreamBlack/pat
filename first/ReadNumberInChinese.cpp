#include <cstdio>
using namespace std;
char c[6][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
char t[11][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int a, flag = 0;
void read(int num) {
    int flag1 = 0, flag2 = 0, flag3 = 0;
    if(num / 1000) {
        printf("%s %s", t[num / 1000], c[2]);
        flag1 = 1;//千位有数字
    }
    if(flag == 1 && flag1 == 0) printf("ling ");//新的段里面最高位没有千位，但是上一段有结果，需要加0
    if(num / 100 % 10) {
        if(flag1 == 1) printf(" ");
        printf("%s %s", t[num / 100 % 10], c[1]);
        flag2 = 1;//百位有数字
    }
    if(flag1 == 1 && flag2 == 0 && num % 100 != 0)//千位有数字百位没数字但十位或者个位有数字
        printf(" ling");
    if(num / 10 % 10) {
        if(flag1 == 1 || flag2 == 1) printf(" ");//千位或者百位有数字，需要空格
        printf("%s %s", t[num / 10 % 10], c[0]);
        flag3 = 1;//十位有数字
    }
    if(flag2 == 1 && flag3 == 0 && num % 10 != 0)//百位有数字并且十位没数字但是个位有数字
        printf(" ling");
    if(num % 10) {
        if(flag1 == 1 || flag2 == 1 || flag3 == 1) printf(" ");
        printf("%s", t[num % 10]);
    }
    
}
int main() {
	/*
	题目大意：给一个十亿以内的数，输出它的中文读法
	解题思路：超级烦。做了半天也还是有一个测试点错误。心累
	1. 四位四位的分离读取，每次read(num)中的num为万或者亿之前的四位数
	2. 子函数和主函数里面都设立多个flag1flag2flag3..保证输出的“ling”（确定在万位、千位中间是否产生了0）
	3. 设立全局flag表示跨越（从亿到万或者从亿到千，或者从万到千这些过程中有无0）有的话会产生“ling”，使flag=1;
	4. 空格采取不确定的用flag单独判断的形式，没有统一的形式。
	*/
    int flag1 = 0, flag2 = 0;
    scanf("%d", &a);
    if(a < 0) {
        printf("Fu ");
        a = 0 - a;
    }
    if(a == 0) printf("ling");//注意但输入为0时
    if(a > 99999999) {//亿位上有数字
        int temp = a / 100000000;
        read(temp);
        printf(" %s", c[4]);//输出亿
        a = a % 100000000;
        flag1 = 1;
    }
    if(a > 9999) {
        int temp = a / 10000;
        if(flag1 == 1) {
            printf(" ");
            flag = 1;
        }
        read(temp);
        printf(" %s", c[3]);
        a = a % 10000;
        flag2 = 1;
    }
    flag = 0;
    if((flag1 == 1 || flag2 == 1) && a != 0) {
        flag = 1;
        printf(" ");
    }
    read(a);
    return 0;
}