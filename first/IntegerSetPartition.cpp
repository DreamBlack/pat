#include<stdio.h>
#include<algorithm>
using namespace std;
long long int num[100000];
int main(){
	/*
	题目大意：要求把一个集合分成两个不相交的集合，使得这两个集合的元素个数相差最小的前提下，两个集合的总和之差最大
	解题思路：先把集合内n个元素排序，计算前n/2个元素的总和，然后用总的总和sum – 2 * halfsum即为 |S1 – S2|。
	|n1 – n2|就是n % 2的结果，奇数为1，偶数为0。（总和sum的值其实可以在输入的时候就累加得到啦~~~~
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",num+i);
	}
	sort(num,num+n);
	if(n%2==0){
		printf("0 ");
	}else{
		printf("1 ");
	}
	long long int sum1=0,sum2=0;
	for(int i=0;i<n/2;i++){
		sum1+=num[i];
	}
	for(int i=n/2;i<n;i++){
		sum2+=num[i];
	}
	printf("%lld",sum2-sum1);
	return 0;
}