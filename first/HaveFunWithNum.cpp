#include<stdio.h>
int main(){
	/*
	题目大意：给出一个长度不超过20的整数，问这个整数两倍后的数位是否为原数位的一个排列。
	不管是yes还是no最后都要输出整数乘以2的结果
	解题思路：
	这题乍一看挺简单的。不过后来发现这个数字（十进制）可能有20位，int,long,long long,double什么的根本
	没办法表示。ok，不用数字了，用string保存好了，可是怎么实现double(乘二，即加上自身)的计算呢，看了这个加法
	得靠自己程序完成了
	遇到的问题：
	1、一开始为了方便运输将输入的数右对齐（个位数对应在19的位置上），同时将原来位置上的元素置0
	但是这里没有想到，如果输入的刚好是20位的，上一步最后将原来位置置0的操作会使得整个数组都为0
	2、当输入和结果位数相同但仍不满足题目条件时候，忘了输出no
	3、不知道为啥最后，输入的是20位整数时，运行后会报错，但是却通过了Oj
	stack around the variable ipt was corrupted
	*/

	int ipt[20]={0};//输入的数
	int opt[20]={0};
	int counti[10]={0};
	int counto[10]={0};//记录输入和double后0-9出现的次数
	char c;
	int pos=0,blength,alength;
	do{
		c=getchar();
		ipt[pos++]=c-'0';
	}while(c!='\n');
	blength=alength=pos-1;
	//对齐
	int nowpos=19;

	for(int i=blength-1;i>=0&&nowpos>=0;i--){
		ipt[nowpos--]=ipt[i];
		counti[ipt[i]]++;
	}

	//最后nowpos指向最高位的前一个下标

	//计算n+n
	int add=0,cnt=0;//add位当前位相加的和cnt为前一位产生的进位
	for(int i=19;i>nowpos&&i>=0;i--){
		add=ipt[i]*2+cnt;
		if(add>9){//
			cnt=1;
			opt[i]=add%10;
		}else{
			cnt=0;
			opt[i]=add;
		}
		counto[opt[i]]++;
	}
	if(cnt==1){//以上加法成功
		opt[nowpos]=1;
		alength++;
		nowpos--;
		printf("No\n");
	}else{
		//判断是不是0-9出现的次数都相同
		bool isfun=true;
		for(int i=0;i<10;i++){
			if(counti[i]!=counto[i]){
				isfun=false;
			}
		}
		if(isfun){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	for(int i=nowpos+1;i<20;i++){
		printf("%d",opt[i]);
	}
	return 0;

}