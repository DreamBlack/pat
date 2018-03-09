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
	if(x<0||x>=m||y<0||y>=n||z<0||z>=l)return false;//����Խ��
	if(visited[x][y][z]||graph[x][y][z]==0)return false;//�Ѿ����ʹ����ߣ�ͼ�е�Ϊ0
	return true;
}
int bfs(int i,int j,int k){
	visited[i][j][k]=true;
	int cnt=0;
	queue<Node> q;
	Node now={i,j,k};
	q.push(now);
	visited[i][j][k]=true;//������
	while(!q.empty()){
		Node nenode=q.front();
		q.pop();
		cnt++;//���ʵ�ʱ����������
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
	��Ŀ���⣺����һ����ά���飬0��ʾ����1��ʾ��������������Ĵ�С���ڵ���t���������������ü�����������������Ĵ�С
	����˼·��
	1����ά�Ĺ����������~~XYZ���������жϷ��򣬶�ÿһ�����������ۼ�������Ĵ�С��������ڵ���t�Ͱѽ���ۼӡ�
	��visit�����ǵ�ǰ�ĵ���û�б����ʹ��������ʹ��Ľ���ǲ����ٷ��ʵġ���judge�ж��Ƿ񳬹��˱߽磬�����Ƿ�ǰ���Ϊ0��������~
	2�����Ҫѧһѧ������������һ�����Ǹ����顣
	*/
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				scanf("%d",&(graph[j][k][i]));
			}
		}
	}
	//�������ڸ�����t���ϵ���ͨ��������Щ��ͨ�������ܵĵ����
	int all=0;
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(graph[j][k][i]==1&&!visited[j][k][i]){//ֻ��û������������Ϊ1������²Ż����
					all+=bfs(j,k,i);//j,k,i��˳��Ҫ����
				}
			}
		}
	}
	printf("%d",all);
	return 0;
}