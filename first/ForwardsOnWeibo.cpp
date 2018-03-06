#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int graph[1001][1001];
bool visited[1001];
int n,l;

void bfs(int s,int now,int &level,int &all){
	queue<int> q;
	visited[now]=true;
	q.push(now);
	q.push(-1);
	while(!q.empty()){
		
		now=q.front();
		q.pop();
		if(now!=-1){
			for(int i=1;i<=n;i++){
				if(!visited[i]&&graph[i][now]!=0&&level<=l){
					q.push(i);
					visited[i]=true;
					all++;
				}
			}
		}else{
			level++;
			if(!q.empty()){
				q.push(-1);
			}else{
				break;
			}
		}
		
	}
}
int main(){
	/*
	��Ŀ���⣺����ÿ���û���ע���˵�id����ת�����Ĳ�������һ��id������΢�������ж��ٸ���ת��
	����˼·��
	1��һ��ʼ�õ�dfs�������в��Ե�û������������������ȵ���Ӧ��ʹ��bfs
	2��bfsҪע�����˵��һ�����
	*/
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int tmp;
			scanf("%d",&tmp);
			graph[i][tmp]=1;
		}
	}
	int now,k,nlevel=1,all=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&now);
		bfs(now,now,nlevel,all);
		printf("%d\n",all);
		all=0;
		nlevel=1;
		fill(visited,visited+n+1,false);
	}
	
	return 0;
}