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
	��Ŀ���⣺������ʮ���Ƶ�����������ת��Ϊʮ�����Ƶ��������Ҫ����ǰ�����һ����#����
	��Ŀ������
	1�������ܼ򵥣�һ��ʼ����֮���ύ��ţ�����ǶԵģ������ύ�����PAT�ϾͲ����ˡ�����
	decToThir���������Ϊ����void������char����Ϳ����ˡ����ۣ��Ժ�Ҫд��������ĺ���
	2����ʵ���������ÿ��������0-168֮�䣬�������0-c֮�䣬������һ�ַǳ��򵥵�д��
	3��ASCII����0-9��Ӧ48-57���������м����ַ��������ǽ��ű��Ǵ�дA-B����д��ĸ����Сд��ĸǰ�棩
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