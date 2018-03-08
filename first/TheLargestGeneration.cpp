#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> nodes(100);
int main(){
	/*
	��Ŀ���⣺�������Ľ�����N�������Ϊ1~N����Ҷ�ӽ�����M��Ȼ�����M����Ҷ�ӽ����ӵĺ��ӽ��ı�ţ������������һ�㣬
	�����Ĳ��Ϊ1������ò�Ľ������Լ����
	����˼·��
	����BFS��¼ÿһ��ڵ������
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