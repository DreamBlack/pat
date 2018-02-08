#include<stdio.h>
#include<iostream>
using namespace std;

void decToThir(int a){
	char temp[2]={'0'};
	if(a<10){
		temp[1]=a+'0';
	}else{
		int yu=0,shang=a,i=1;
		yu=shang%13;
		shang/=13;
		if(yu<10){
				temp[1]=yu+'0';
			}else{
				temp[1]=yu+'A'-10;
			}
		if(shang<10){
				temp[0]=shang+'0';
			}else{
				temp[0]=shang+'A'-10;
			}
		
	}
	printf("%c%c",temp[0],temp[1]);
}
void great(int r,int g,int b){
	char index[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	printf("#");
	printf("%c%c",index[r/13],index[r%13]);
	printf("%c%c",index[g/13],index[g%13]);
	printf("%c%c",index[b/13],index[b%13]);
}
int main(){
	/*
	题目大意：给三个十进制的数，把它们转换为十三进制的数输出。要求在前面加上一个”#”号
	题目分析：
	1、这个题很简单，一开始做好之后提交到牛客网是对的，但是提交到浙大PAT上就不对了。后来
	decToThir这个函数改为返回void而不是char数组就可以了。结论：以后不要写返回数组的函数
	2、其实这个题由于每个数都在0-168之间，输出的在0-c之间，可以用一种非常简单的写法
	3、ASCII表里0-9对应48-57，接下来有几个字符，而不是接着便是大写A-B（大写字母排在小写字母前面）
	*/

	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	printf("#");
	decToThir(r);
	decToThir(g);
	decToThir(b);
	
	//great(r,g,b);
	
	return 0;
}