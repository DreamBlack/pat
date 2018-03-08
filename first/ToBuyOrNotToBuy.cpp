#include<stdio.h>
#include<set>
#include<string>
using namespace std;
char s1[1001];
char s2[1001];
int main(){
	/*
	题目大意：给两个字符串，看第二个串中的所有元素（相同元素有几个1中也要有几个）是否在1中都有，有的话输出1中额外多出
	的元素个数；不是都有的话输出1中缺失的个数
	解题思路
	1、一开始没有自己手动模拟一遍例子，导致算法有问题浪费了好久。
	2、其实只要对于串2中每一个元素，如果1中有就将各自中的元素删除。最后2空了，1的剩余元素个数就是多出来的。2没空则2中剩余
	元素个数就是1中少的个数。
	3、其实如果够的话，1的元素个数-2的元素个数就是1多出来的。所以可以扫描1串，同时在数组中记录1中每个元素出现的次数（hash），
	再扫描2中每个元素，若1中有这个元素，就让记录数组减一，没有（则表示1缺了），让Miss++；最后Miss=0表示够，输出1lenth-2length,miss!=0
	表示缺失，输出miss
	*/
	scanf("%s",s1);
	scanf("%s",s2);
	string shop(s1);
	string eva(s2);
	multiset<char> m1;
	for(int i=0;i<eva.size();i++){
		m1.insert(eva[i]);
	}
	multiset<char> m2;
	for(int i=0;i<shop.size();i++){
		if(m1.count(shop[i])!=0){//m1中有
			m1.erase(m1.lower_bound(shop[i]));
		}else{//m1中没有
			m2.insert(shop[i]);
		}
	}
	int miss=0,extra=0;
	
	if(m1.empty()){
		extra=(m2.empty())?0:m2.size();
		printf("Yes %d",extra);
	}else{
		miss=m1.size();
		printf("No %d",miss);
	}
	return 0;
}