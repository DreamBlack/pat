#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
	/*
	题目大意：给出两个数字序列，从这两个序列中分别选取相同数量的元素进行一对一相乘，问能得到的乘积之和最大为多少
	解题思路：
	1、典型的贪心算法
	2、要求优惠券组合的最大值，基于这样一个事实，把两边的优惠券都按递增顺序排好，然后选取都是绝对值最大的两个负数相乘，
	也可以选择绝对值最大的两个正数相乘，依次直到没有可以配对的，得到的累加和就是最大的。
	3、第一次先处理正数之后忘了，对于负数也应该是把绝对值最大的相乘而不是仅仅按序
	4、写cmp函数的时候，返回true的时候不要加等于号的时候，不然就超时了
	*/
	int nc;
	scanf("%d",&nc);
	vector<int> coupons(nc);

	for(int a=0;a<nc;a++){
		scanf("%d",&(coupons[a]));
	}
	sort(coupons.begin(),coupons.end());
	int np;
	scanf("%d",&np);
	vector<int> products(np);
	for(int a=0;a<np;a++){
		scanf("%d",&(products[a]));
	}
	int i=0,j=0,all=0;
	sort(products.begin(),products.end());
	
	while(i<coupons.size()&&j<products.size()&&coupons[i]<0&&products[j]<0){
		all+=coupons[i]*products[j];
		i++;
		j++;
	}
	int p=coupons.size()-1,q=products.size()-1;
	while(p>=0&&q>=0&&coupons[p]>0&&products[q]>0){
		all+=coupons[p]*products[q];
		p--;
		q--;
	}
	printf("%d",all);
	return 0;
}