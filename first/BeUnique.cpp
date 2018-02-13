#include<stdio.h>
#include<climits>
int bets[10001];
int first[10001];
int main(){
	/*
	题目大意：给n个数字，按照读入顺序，哪个数字是第一个在所有数字中只出现一次的数字。
	如果所有数字出现都超过了一次，则输出None
	解题思路：
	1、一开始用的是O(n^2)的算法，毫不意外的超时了
	2、为了提升速度，使用hash，同时用另一个数组记录数据第一次出现的时间，输入完成后，遍历记录时间的数组，找到最早出现的那个
	3、网友的解法也不错。建立一个数组，存储每个数字出现的次数，然后遍历一遍输入的顺序看是否有出现次数为1的数字
	m[a[i]]++;（a[i]按序记录n个数字，m记录每个数字出现的次数）
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int bet;
		scanf("%d",&bet);
		if(bets[bet]==0){
			first[bet]=i;
		}
		bets[bet]++;
	}
	int firstone=INT_MAX;
	int firstindex=-1;
	for(int i=1;i<10001;i++){
		if(bets[i]==1&&first[i]<firstone){
			firstone=first[i];
			firstindex=i;
		}
	}

	if(firstone!=INT_MAX){
		printf("%d",firstindex);

	}else{
		printf("None");
	}

	return 0;
}