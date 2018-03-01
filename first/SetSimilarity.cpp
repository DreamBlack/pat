#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
#include<functional>
#include<iterator>
using namespace std;
int main(){
	/*
	题目大意：给定两个整数集合，它们的相似度定义为：Nc/Nt*100%。其中Nc是两个集合都有的不相等整数的个数，
	Nt是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。
	nc是两个集合的公共元素个数，nt是两个集合的所有包含的元素个数（其中元素个数表示各个元素之间互不相同）。
	解题思路：
	1、一开始用普通的set,nc=0,nt=a.size()将b里面的元素插入到a中，如果a中已经有了nc++,否则nt++。
	但是这样超时了
	2、到网上查了一下，使用了set_intersection，inserter将a,b交集的元素放到tmp里面，nc=tmp.size(),nt=a.size()+b.size()-nc;
	*/
	int n;
	scanf("%d",&n);
	vector<set<int>> all;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k); 
		set<int> s;
		for(int j=0;j<k;j++){
			int temp;
			scanf("%d",&temp);
			s.insert(temp);
		}
		all.push_back(s);
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		set<int> temp;
		
		set_intersection(all[a].begin(),all[a].end(),all[b].begin(),all[b].end(),inserter(temp,temp.begin()));
		int nt=all[a].size()+all[b].size()-temp.size(),nc=temp.size();
		double r=(double)nc/nt*100;
		printf("%.1f%%\n",r);
	}
	return 0;
}