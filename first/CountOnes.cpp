#include<stdio.h>
int main(){
	/*
	题目大意：给出一个数字n，求1~n的所有数字里面出现1的个数
	解题思路：
	1、这道题不知道怎么做
	2、找规律题。
	这是一道数学问题。计算个位、十位、千位。。等位上1可能出现的个数，然后进行找规律累加。
	从第一位（个位）到最高位，设now为当前位的数字，left为now左边的所有数字构成的数字，right是now右边的所有数字构成的数字。
	只需要一次次累加对于当前位now来说可能出现1的个数，然后把它们累加即可。a表示当前的个位为1，十位为10，百位为100类推。
	对于now，有三种情况：
	1.now == 0 : 那么 ans += left * a; //因为now==0说明now位只有在left从0~left-1的时候会产生1，所以会产生left次，但是又因为右边会重复从0~999…出现a次
	2.now == 1 : ans += left * a + right + 1;//now = 1的时候就要比上一步多加一个当now为1的时候右边出现0~right个数导致的now为1的次数
	3.now >= 2 : ans += (left + 1) * a;//now大于等于2就左边0~left的时候会在now位置产生1，所以会产生left次，但是又因为右边会重复从0~999…出现a次
	*/
	int n;
	scanf("%d",&n);
	int now=n,left,right,a=1,all=0;
	while(now>=10){
		now=now/10;
		a=a*10;
	}
	left=0;
	right=n%a;
	while(a>=1){
		if(now==0){
			all+=left*a;
		}else if(now==1){
			all+=left*a+right+1;
		}else {
			all+=(left+1)*a;
		}
		
		
		left=left*10+now;
		a=a/10;
		now=(right>=10)?(right/a):right;
		right=(right>=10)?right%a:0;
		
		
	}
	printf("%d",all);
	return 0;
}