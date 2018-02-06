#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int edges[10001][10001];
int deepestLvl[10001];
int n;
set<int> s;
bool visited[10001]={false};
void dfs(int now,int l){//l表示当前点的深度
	int temp=l;
	visited[now]=true;
	for(int i=1;i<n+1;i++){
		if(!visited[i]&&edges[now][i]==1){
			l=l+1;
			dfs(i,l);//从当前点进行DFS时，l要+1
			deepestLvl[i]=l;//从某点遍历完成时记录当前点的距离
			l=temp;//这句很重要，回到之前的结点时，当前结点深度必须也要回到原来的样子
		}
	}
}
int main(){
	/*
	题目大意：给出n个结点（1~n）之间的n-1条边，问是否能构成一棵树，如果不能构成则输出它有的连通分量个数，
	如果能构成一棵树，输出能构成最深的树的高度时，树的根结点。如果有多个，按照从小到大输出。
	解题：
	1、一开始使用的方法是，先对整个图进行一次深度优先遍历判断是否是连通图。
	如果是连通图，就对图中每一个顶点再进行一次深度优先遍历，找到n个点出发的最大深度，总计n+1次深度优先遍历
	因此，有一个测试点运行超时
	2、后看了下网友的办法，可以在判断完是否为连通图后，只需两次深度优先遍历边求出所有出发点最长的顶点。
	首先从任一点深度优先遍历，记录下离这个点最远的那些点（最远只深度遍历时第一次返回的点）
	第二次从上述记录下的点中任选一个，再进行深度优先遍历，记录下离这个点最远的点（包括这个点）。
	这两个点集合中的并集（注意是并集不是交集）就是要求的点，SET里元素不能重复，因此选用set
	3、然后在用2的时候，对于离出发点最远的点，是用从某点开始遍历到最后一个不能再继续遍历的点返回的如下
	void dfs(int now){
	bool longest=true;
	visited[now]=true;
	for(int i=1;i<n+1;i++){
	if(!visited[i]&&edges[now][i]==1){
	longest=false;
	dfs(i);
	}
	}
	if(longest){
	v.insert(now);
	}
	}   但其实这种做法找出来的并不是最远的点，应该用专门的数组来记录距离，最后选择最大的。
	*/
	scanf("%d",&n);
	int from,to;
	//N个点N-1条边保证了，只有有环必然不连通，所有只考虑是否连通即可，不用考虑有环的情况
	for(int i=0;i<n-1;i++){
		scanf("%d",&from);
		scanf("%d",&to);
		edges[from][to]=edges[to][from]=1;
	}
	int div=0;
	//先进行深度遍历计算连通分量
	for(int j=1;j<n+1;j++){
		if(!visited[j]){
			dfs(j,0);
			div++;
		}
	}
	if(div>1){
		cout<<"Error: ";
		cout<<div;
		cout<<" components";
	}else{
		//是树，记得重置visited
		for(int i=1;i<n+1;i++){
			visited[i]=false;
			deepestLvl[i]=0;
		}
		dfs(1,0);
		int max=0;
		for(int i=1;i<n+1;i++){
			if(deepestLvl[i]>max){
				max=deepestLvl[i];
			}
		}
		for(int i=1;i<n+1;i++){
			if(deepestLvl[i]==max){
				s.insert(i);
			}
		}
		for(int i=1;i<n+1;i++){
			visited[i]=false;
			deepestLvl[i]=0;
		}

		auto it=s.begin();
		dfs(*it,0);
		max=0;
		for(int i=1;i<n+1;i++){
			if(deepestLvl[i]>max){
				max=deepestLvl[i];
			}
		}
		for(int i=1;i<n+1;i++){
			if(deepestLvl[i]==max){
				s.insert(i);
			}
		}
		for(auto iit=s.begin();iit!=s.end();iit++){
			printf("%d\n",*iit);
		}
	}

	return 0;
}