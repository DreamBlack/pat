#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	int type;
	int id;
	double price;
	double amount;
	vector<int> buyer;
};
bool visited[100000];
int n;
double p,r;
vector<Node> nodes(100000);
double bfs(int now){
	double sales=0;
	queue<Node> q;
	visited[now]=true;
	q.push(nodes[now]);
	Node null;
	null.type=-1;
	q.push(null);
	double np=p;
	Node newnow;
	while(!q.empty()){
		newnow=q.front();
		q.pop();
		if(newnow.type!=-1){
			newnow.price=np;
			if(newnow.type==2){
				sales+=newnow.amount*newnow.price;
			}else{
				for(int i=0;i<newnow.buyer.size();i++){
					if(!visited[(newnow.buyer[i])]){
						q.push(nodes[newnow.buyer[i]]);
						visited[(newnow.buyer[i])]=true;
					}
				}
			}

		}else{
			np=np+np*r/100;
			if(!q.empty()){
				q.push(null);
			}
			
		}
	}
	return sales;
}
int main(){
	/*
	题目大意：给一棵树，在树根出货物的价格为p，然后从根结点开始每往下走一层，该层的货物价格将会在父亲结点的价格上增加r%，
	给出每个叶结点的货物量，求他们的价格之和
	解题思路：
	bfs，每到新的一层更新价格。到叶子计算总销售额。一次过
	*/
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		Node tmp;
		int t;
		scanf("%d",&t);
		if(t==0){
			tmp.type=2;
			scanf("%d",&t);
			tmp.amount=t;
		}else{
			tmp.type=1;
			for(int j=0;j<t;j++){
				int c;
				scanf("%d",&c);
				tmp.buyer.push_back(c);
			}
		}
		if(i==0){
			tmp.price=p;
		}
		tmp.id=i;
		nodes[i]=tmp;
	}
	double sales=bfs(0);
	printf("%.1f",sales);
	return 0;
}
