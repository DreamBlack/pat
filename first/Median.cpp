#include<stdio.h>
long num1[1000000];
long num2[1000000];
int main(){
	/*
	题目大意：给出两个已排序序列，求这两个序列合并后的中间数
	解题思路：
	1、该开始想用动态规划的方法来做，后来说实话这个方法还是不太会。这个题时间要求不高所以就用普通的双指针的方法了
	2、但是用双指针时候，忘了其中一个数组处理完的情况，导致第一次有三个测试点错误
	3、还有一点要注意的是，这题有1000000的数组必须作为全局变量声明，否则会报错
	*/
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%ld",&(num1[i]));
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%ld",&(num2[i]));
	}
	int i=0,j=0,cnt=0;
	int target=(m+n-1)/2;
	int temp=0;
	while(cnt<=target&&i<n&&j<m){
		if(num1[i]<num2[j]){
			temp=num1[i++];
		}else{
			temp=num2[j++];
		}
		cnt++;
	}
	if(cnt<=target){
		if(i==n){
			while(cnt<=target){
				temp=num2[j++];
				cnt++;
			}
		}else{
			while(cnt<=target){
				temp=num1[i++];
				cnt++;
			}
		}
	}
	printf("%ld",temp);
	return 0;
}