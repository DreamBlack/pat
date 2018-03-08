#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> nodes(100);
int main(){
	/*
	题目大意：输入树的结点个数N，结点编号为1~N，非叶子结点个数M，然后输出M个非叶子结点格子的孩子结点的编号，求结点个数最多的一层，
	根结点的层号为1，输出该层的结点个数以及层号
	解题思路：
	典型BFS记录每一层节点个数。
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	nodes.clear();
	nodes.resize(n+1);
	for(int i=0;i<m;i++){
		int node,num;
		scanf("%d%d",&node,&num);
		for(int j=0;j<num;j++){
			int tmp;
			scanf("%d",&tmp);
			nodes[node].push_back(tmp);
		}
	}
	queue<int> q;
	q.push(1);
	int level=2,lnum=0,maxnum=1,maxl=1;
	q.push(-1);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now!=-1){
			if(!nodes[now].empty()){
				for(int i=0;i<nodes[now].size();i++){
					lnum++;
					q.push(nodes[now][i]);
				}
			}
		}else{
			if(lnum>maxnum){
				maxnum=lnum;
				maxl=level;
			}
			level++;
			lnum=0;
			if(!q.empty()){
				q.push(-1);
			}
			
		}
	}

	printf("%d %d",maxnum,maxl);
	return 0;
}