#include<stdio.h>
double num[100000];
int main(){
	/*
	题目大意：给一串正数，可以构成很多个子序列。求构成的子序列们的和的总和
	解题思路：
	数学问题找规律。
	当有n个数的时候. 计算第i个数的时候，第0个数 算了 n 次，第1个数 算了 (n-1) * 2，第2个数 算了 (n-2) * 3
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",num+i);
	}
	double all=0;
	for(int i=0;i<n;i++){
		all+=num[i]*(i+1)*(n-i);
	}
	printf("%0.2f",all);
	return 0;
}