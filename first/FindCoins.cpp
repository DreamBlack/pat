#include<stdio.h>
#include<algorithm>
using namespace std;
int coins[100000];
int main(){
	/*
	题目大意：给出n个正整数和一个正整数m，问n个数字中是否存在一对数字a和b(a <= b),使a+b=m成立。如果有多个，输出a最小的那一对。
	解题思路：
	先升序排序，然后双指针法
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&(coins[i]));
	}
	sort(coins,coins+n);
	int i=0,j=n-1;
	bool isSlvd=false;
	while(i<j){
		if(coins[i]+coins[j]>m){
			j--;
		}else if(coins[i]+coins[j]<m){
			i++;
		}else{
			isSlvd=true;
			break;
		}
	}
	if(isSlvd){
		printf("%d %d",coins[i],coins[j]);
	}else{
		printf("No Solution");
	}
	return 0;
}