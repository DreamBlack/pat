#include<stdio.h>
#include<climits>
int edges[500][500];
int costs[500][500];
int path[500];
bool visited[500];
int distance[500];
int nowcost[500];
int main(){
	/*
	题目大意：求起点到终点的最短路径最短距离和花费，要求首先路径最短，其次花费最少，要输出完整路径。
	解题思路：
	dijkstra的变形，很简单。
	但是提交之后有一个测试点没过，后来发现初始化distance数组时候有点问题，有边的话会初始化没边值
	没边会初始化为0，这就导致之后找最短边的时候误把没边（0）误认为是最小边。
	正确的做法时初始化为int_max
	*/
	int n,m,s,d;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	int row,col,dis,cost;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&row,&col,&dis,&cost);
		edges[row][col]=edges[col][row]=dis;
		costs[row][col]=costs[col][row]=cost;
	}
	//初始化数组
	for(int i=0;i<n;i++){
		if(edges[s][i]!=0){
			distance[i]=edges[s][i];
		}else{
			distance[i]=INT_MAX;//very important
		}
		nowcost[i]=costs[s][i];

		path[i]=s;
	}
	
	visited[s]=true;
	int lastD=s;
	while(true){
		int minD=-1;
		int max=INT_MAX;
		//找最短的那条
		for(int i=0;i<n;i++){
			if(!visited[i]&&distance[i]<max){
				minD=i;
				max=distance[i];
			}
		}
		if(minD==-1) break;
		visited[minD]=true;
		nowcost[minD]=nowcost[path[minD]]+costs[path[minD]][minD];
		if(minD==d) break;
		for(int i=0;i<n;i++ ){//更新
			if(!visited[i]&&edges[minD][i]!=0){
				if(distance[minD]+edges[minD][i]<distance[i]){
					distance[i]=distance[minD]+edges[minD][i];
					nowcost[i]=nowcost[minD]+costs[minD][i];
					path[i]=minD;
				}else if(distance[minD]+edges[minD][i]==distance[i]){
					if(nowcost[i]>nowcost[minD]+costs[minD][i]){
						nowcost[i]=nowcost[minD]+costs[minD][i];
						path[i]=minD;
					}
				}
			}
		}

	}
	int allPath[500];
	int now=d,i=0;
	allPath[i++]=d;
	while(path[now]!=s){
		allPath[i++]=path[now];
		now=path[now];
	}
	allPath[i]=s;
	for(int j=i;j>=0;j--){
		printf("%d ",allPath[j]);
	}
	printf("%d %d",distance[d],nowcost[d]);
	return 0;
}