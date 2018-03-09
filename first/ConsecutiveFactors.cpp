#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
long long int m,larg;
int main(){
	/*
	题目大意：一个正整数N的因子中可能存在若干连续的数字。例如630可以分解为3*5*6*7，其中5、6、7就是3个连续的数字。给定任一正整数N，
	要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。
	解题思路：这题用了好久，感觉我这种多重循环的简单题老是写不好。好不容易写了个递归函数有个测试点堆栈溢出了。后来发现一个数的因子
	最多不可能超过这个数本身的开方。我一开始给的最大值是数本身，做了好多无用递归，该成开方后的值就可以了
	*/
	scanf("%lld",&m);
	larg=sqrt((double)m)+1;
	long long int first=2;
	int now,n,cnt,maxcnt=0,maxfirst=2;
	while(first<=larg){
		now=first;
		n=m;
		cnt=0;
		while(n%now==0){
			cnt++;
			n=n/now;
			now++;
		}
		if(cnt>maxcnt){
			maxcnt=cnt;
			maxfirst=first;
		}
		first++;
	}
	if(maxcnt==0){//质数
		printf("1\n%d",m);
	}else{
		printf("%d\n%d",maxcnt,maxfirst);
		int k=maxfirst+1;
		while(k<=maxfirst+maxcnt-1){
			printf("*%d",k);
			k++;
		}
	}

	
	return 0;
}