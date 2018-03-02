#include<stdio.h>
#include<algorithm>
using namespace std;
int num[4];
int cmp(int a,int b){
	return(a>b)?true:false;
}
int main(){
	/*
	题目大意：任给出四位数k0,用它的四个数字由大到小重新排列成一个四位数m,再减去它的反序数rev(m),得出数k1=m-rev(m),然后，继续对k1重复上述变换，
	得数k2.如此进行下去，卡普耶卡发现，无论k0是多大的四位数， 只要四个数字不全相同，最多进行7次上述变换，就会出现四位数6174.
	解题思路：简单题。但是一开始有个测试点（6174本身）错误，找到了就很好改了
	*/
	int n,na,nb;
	scanf("%d",&n);
	
	do{
		num[0]=n/1000;
		num[1]=(n%1000)/100;
		num[2]=((n%1000)%100)/10;
		num[3]=((n%1000)%100)%10;
		if(*num==*(num+1)&&*(num+2)==*(num+3)&&*num==*(num+2)){
			printf("%04d - %04d = 0000",n,n);
			break;
		}
		sort(num,num+4,cmp);
		na=num[0]*1000+num[1]*100+num[2]*10+num[3];
		nb=num[3]*1000+num[2]*100+num[1]*10+num[0];
		n=na-nb;
		printf("%04d - %04d = %04d\n",na,nb,n);

	}while(n!=6174);
	return 0;
}