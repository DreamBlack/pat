#include<stdio.h>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> graph;
bool visited[100000];
double minprice=INT_MAX;
int minnum=0;
int n;
double p,r;
void dfs(int now,double nowprice){
	visited[now]=true;
	if(graph[now].empty()){
		if(nowprice<minprice){
			minprice=nowprice;
			minnum=1;
		}else if(nowprice==minprice){
			minnum++;
		}
	}else{
		for(int i=0;i<graph[now].size();i++){
			if(!visited[graph[now][i]]){
				dfs(graph[now][i],nowprice+nowprice*r/100);
			}
		}
	}
}
int main(){
	/*
	题目大意：提供一棵树，在树根处货物的价格为p，从根结点开始每往下一层，该层货物价格将会在父亲结点的价格上增加r%。
	求叶子结点出能获得的最低价格以及能提供最低价格的叶子结点数
	解题思路：dfs
	*/
	scanf("%d%lf%lf",&n,&p,&r);
	graph.resize(n);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				int tmp;
				scanf("%d",&tmp);
				graph[i].push_back(tmp);
			}
		}
	}
	dfs(0,p);
	printf("%.4f %d",minprice,minnum);
	return 0;
}
