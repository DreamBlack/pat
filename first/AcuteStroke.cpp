#include<stdio.h>
#include<queue>
using namespace std;
struct Node{
	int x,y,z;
};
int m,n,l,t;
int graph[1300][130][70];
bool visited[1300][130][70];
int X[6]={1,0,0,-1,0,0};
int Y[6]={0,1,0,0,-1,0};
int Z[6]={0,0,1,0,0,-1};
bool judge(int x,int y,int z){
	if(x<0||x>=m||y<0||y>=n||z<0||z>=l)return false;//访问越界
	if(visited[x][y][z]||graph[x][y][z]==0)return false;//已经访问过或者，图中点为0
	return true;
}
int bfs(int i,int j,int k){
	visited[i][j][k]=true;
	int cnt=0;
	queue<Node> q;
	Node now={i,j,k};
	q.push(now);
	visited[i][j][k]=true;//不能忘
	while(!q.empty()){
		Node nenode=q.front();
		q.pop();
		cnt++;//访问的时候计算结点个数
		for(int i=0;i<6;i++){
			int tx=nenode.x+X[i];
			int ty=nenode.y+Y[i];
			int tz=nenode.z+Z[i];
			if(judge(tx,ty,tz)){
				visited[tx][ty][tz]=true;
				Node zn={tx,ty,tz};
				q.push(zn);
			}
		}
	}
	if(cnt>=t){
		return cnt;
	}else{
		return 0;
	}
}
int main(){
	/*
	题目大意：给定一个三维数组，0表示正常1表示有肿瘤，肿瘤块的大小大于等于t才算作是肿瘤，让计算所有满足肿瘤块的大小
	解题思路：
	1、三维的广度优先搜索~~XYZ三个数组判断方向，对每一个点广度优先累计肿瘤块的大小，如果大于等于t就把结果累加。
	用visit数组标记当前的点有没有被访问过，被访问过的结点是不会再访问的。。judge判断是否超过了边界，或者是否当前结点为0不是肿瘤~
	2、这个要学一学，尤其是找下一步的那个数组。
	*/
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				scanf("%d",&(graph[j][k][i]));
			}
		}
	}
	//求数量在个数在t以上的连通分量，这些连通分量中总的点个数
	int all=0;
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(graph[j][k][i]==1&&!visited[j][k][i]){//只有没遍历过并且是为1的情况下才会访问
					all+=bfs(j,k,i);//j,k,i的顺序要保持
				}
			}
		}
	}
	printf("%d",all);
	return 0;
}