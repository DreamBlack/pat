#include<stdio.h>
#include<algorithm>
using namespace std;
long long int num[100000];
int maxn=0;
long long int n,p;
int main(){
	/*
	题目大意：给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。
	现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。输入第一行给出两个正整数N（输入正数的个数）和p
	（给定的参数），第二行给出N个正整数。在一行中输出最多可以选择多少个数可以用它们组成一个完美数列
	解题思路：
	1、一开始把公式改写成了p>=M/m;这样固定p，找符合条件的M，m.两个参数导致不知道怎么优化
	2、其实就是排为升序后从对于i从0到n-1，对每一个i寻找第一个比m*p大的数。（因为若那个数比m*p还大一定不满足条件，而第一个比m*p打的数的前面那个
	肯定就是最大的可能的M）
	3、另外需要注意的是m*p可能超过Int范围，应该使用long long int
	4、或者可以使用双指针法
	首先将数列从小到大排序，设当前结果为result = 0，当前最长长度为temp = 0；从i = 0～n，j从i + result到n，
	【因为是为了找最大的result，所以下一次j只要从i的result个后面开始找就行了】每次计算temp若大于result则更新result，最后输出result的值～
	*/
	scanf("%lld%lld",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%lld",num+i);
	}
	sort(num,num+n);
	
	for(int i=0;i<n;i++){
		long long int q=num[i]*p;
		int tmplength=distance(num+i,upper_bound(num,num+n,q)-1)+1;
		if(tmplength>maxn){
			maxn=tmplength;
		}
	}
	printf("%d",maxn);		
	return 0;
}