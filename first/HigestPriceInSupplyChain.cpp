#include<stdio.h>
#include<vector>
using namespace std;
int n,root;
double p,r,maxprice=0;
vector<vector<int>> graph(100000);
vector<int> maxnode;
bool visited[100000];
void dfs(int now,double price){
	visited[now]=true;
	
	if(graph[now].empty()){//叶子结点
		if(price>maxprice){
			maxprice=price;
			maxnode.clear();
			maxnode.push_back(now);
		}else if(price==maxprice){
			maxnode.push_back(now);
		}
	}
	for(int i=0;i<graph[now].size();i++){
		if(!visited[graph[now][i]]){
			dfs(graph[now][i],price*r/100+price);
		}
	}
}
int main(){
	/*
	题目大意：给一棵树，在树根处货物的价格为p，然后每往下走一层，价格增加r%，求所有叶子结点的最高价格，以及这个价格的叶子结点个数。
	题目分析：用二维数组v[i][j]存储，对于每一个结点i，它的孩子结点的下标push_back存储在v[i]中。用深度优先搜索dfs，保存当前结点的下
	标index以及当前结点所在层数，当 当前结点的孩子结点个数为0的时候说明是叶子结点，更新maxdepth和maxnum的值，最后输出～
	*/
	scanf("%d%lf%lf",&n,&p,&r);
	graph.clear();
	graph.resize(n);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp==-1){
			root=i;
		}else{
			graph[tmp].push_back(i);
		}
	}
	double nprice=p;
	dfs(root,p);
	printf("%0.2f %d",maxprice,maxnode.size());
	return 0;
}