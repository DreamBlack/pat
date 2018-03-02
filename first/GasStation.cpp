#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<algorithm>
using namespace std;
int graph[1011][1011];
int minPath[1011];
bool visited[1011];
int n,m,k,ds;
bool dfs(int now){
	visited[now]=true;
	//找出path数组中最小的那个
	while(true){
		int minIndex=-1,minLength=INT_MAX;
		for(int i=1;i<=n+m;i++){
			if(!visited[i]&&minPath[i]<minLength){
				minIndex=i;
				minLength=minPath[i];
			}
		}
		//这个最小的作为新的出发点，更新path数组
		if(minIndex<=n&&minPath[minIndex]>ds){
			return false;
		}
		if(minIndex==-1){
			break;
		}
		visited[minIndex]=true;
		for(int i=1;i<=n+m;i++){
			if(!visited[i]&&graph[i][minIndex]!=0){
				if(graph[i][minIndex]+minPath[minIndex]<minPath[i]){
					minPath[i]=graph[i][minIndex]+minPath[minIndex];
				}
			}
		}
	}
	return true;
}
int main(){
	/*
	题目大意：从m个加油站里面选取1个站点，让他离居民区的最近的人最远，并且没有超出服务范围ds之内。如果有很多个最远的加油站，
	输出距离所有居民区距离平均值最小的那个。如果平均值还是一样，就输出按照顺序排列加油站编号最小的那个
	解题思路：
	1、这个题更像阅读理解。其实就是dijsktra求m个点到其他n个点的最短路径。选取m个点中到最近的点距离最远的那个。如果有多个，选总距离最近的那个。
	再有多个，选下标小的
	2、理解题目就很简单了
	*/
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	for(int i=0;i<k;i++){
		char node1[5];
		char node2[5];
		int a,b,length;
		scanf("%s%s%d",node1,node2,&length);
		if(node1[0]=='G'){//汽车站点
			a=atoi(node1+1)+n;
		}else{
			a=atoi(node1);
		}
		if(node2[0]=='G'){//汽车站点
			b=atoi(node2+1)+n;
		}else{
			b=atoi(node2);
		}
		graph[a][b]=graph[b][a]=length;
	}
	int maxAll=-1,goodG=-1,minH=-1;
	for(int i=1+n;i<=n+m;i++){
		int min=INT_MAX,all=0;
		//初始化path数组
		fill(minPath,minPath+m+n+1,INT_MAX);
		fill(visited,visited+m+n+1,false);
		for(int j=1;j<=n+m;j++){
			if(j!=i&&graph[i][j]!=0){//有边
				minPath[j]=graph[i][j];
			}
		}

		if(dfs(i)){
			for(int j=1;j<=n;j++){
				all+=minPath[j];
				if(min>minPath[j]){
					min=minPath[j];
				}
			}
			if(minH<min){
				maxAll=all;
				goodG=i;
				minH=min;
			}else if(minH==min){
				if(maxAll>all){
					maxAll=all;
					goodG=i;
					minH=min;
				}
			}
		}else{//该候选不要
		}

	}
	if(goodG==-1){
		printf("No Solution");
	}else{
		printf("G%d\n",goodG-n);
		double average=(double)maxAll/n;
		printf("%.1f %.1f",(double)(minH),average);
	}
	return 0;
}