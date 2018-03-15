#include<stdio.h>
#include<algorithm>
using namespace std;
int graph[201][201];
bool visited[201];
int cycle[201];
int sequence[201];
int main(){
	/*
	题目大意：给出一个无向图，以及K个查询。查询结构为n(顶点个数),顶点序列，问这个序列能否构成哈密顿回路
	解题大意：
	1、这道题主要在于抓住哈密顿回路的定义，一个是回路要闭合，其次回路上每个顶点只访问一次，最后是这条回路要包括
	图上的所有顶点
	2、知道1之后就很简单了
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		graph[x][y]=graph[y][x]=1;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		fill(visited+1,visited+1+n,false);
		fill(cycle+1,cycle+1+n,0);
		fill(sequence+1,sequence+1+n,0);
		int num,first;
		scanf("%d%d",&num,&first);
		sequence[0]=first;
		for(int j=1;j<=num-1;j++){
			scanf("%d",sequence+j);
		}
		if(num<n){
			printf("NO\n");
		}else{
			int flag=1;
			if(sequence[num-1]!=first){//回路没有闭合
				flag=0;
			}else{
				int next,last=first;
				for(int j=1;j<=num-1;j++){
					if(visited[sequence[j]]&&j<num-1){//已经访问过
						flag=0;
						break;
					}else if(sequence[j]==first&&j<num-1){//并没有到环的尾部出现了环的头部
						flag=0;
						break;
					}else if(graph[last][sequence[j]]==0){//没有边
						flag=0;
						break;
					}
					visited[sequence[j]]=true;
					last=sequence[j];
				}
			}
			if(flag==1){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}