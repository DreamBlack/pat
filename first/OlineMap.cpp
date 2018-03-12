#include<stdio.h>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int glength[500][500];
int gtime[500][500];
bool visited[500];
int minlength[500];
vector<vector<int>>path(500);
int mintime[500];
vector<vector<int>>pathtime(500);
int start,dest;
int minTime=INT_MAX,minSize=INT_MAX;
vector<int>minLengthPath,minTimePath;
void dfsLength(int now,int nowtime,vector<int> &tmpPath){
	if(now==start){//到了开始结点
		if(nowtime<minTime){
			minLengthPath.clear();
			minLengthPath.assign(tmpPath.begin(),tmpPath.end());
			minTime=nowtime;
		}
	}else{
		for(int i=0;i<path[now].size();i++){
			tmpPath.push_back(path[now][i]);
			dfsLength(path[now][i],nowtime+gtime[path[now][i]][now],tmpPath);
			tmpPath.erase(tmpPath.begin()+tmpPath.size()-1);
		}
	}
}
void dfsTime(int now,vector<int> &tmpPath){
	if(now==start){//到了开始结点
		if(tmpPath.size()<minSize){
			minTimePath.clear();
			minTimePath.assign(tmpPath.begin(),tmpPath.end());
			minSize=tmpPath.size();
		}
	}else{
		for(int i=0;i<pathtime[now].size();i++){
			tmpPath.push_back(pathtime[now][i]);
			dfsTime(pathtime[now][i],tmpPath);
			tmpPath.erase(tmpPath.begin()+tmpPath.size()-1);
		}
	}
}
int main(){ 
	/*
	题目大意：给一张地图，两个结点中既有距离也有时间，有的单行有的双向，要求根据地图推荐两条路线：一条是最快到达路线，一条是最短距离的路线。
	第一行给出两个整数N和M，表示地图中地点的个数和路径的条数。接下来的M行每一行给出：道路结点编号V1 道路结点编号V2 是否单行线 道路长度 所需时间
	要求第一行输出最快到达时间Time和路径，第二行输出最短距离Distance和路径
	写dijkstra的时候忘记在初始化的时候把路径也初始化为start
	解题思路：
	用两个Dijkstra + DFS。一个求最短路径（如果相同求时间最短的那条），一个求最快路径（如果相同求结点数最小的那条）~~~求最短
	路径可以直接在Dijkstra里面求前驱结点pre数组~~~求最快路径因为要求结点数最小的那条，所以要用pre的二维数组存储所有结点的最快路径
	，然后用DFS求出满足条件的结点数最小的那条~~~~
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	path.resize(n);
	pathtime.resize(n);
	for(int i=0;i<m;i++){
		int x,y,oway,length,time;
		scanf("%d%d%d%d%d",&x,&y,&oway,&length,&time);
		if(oway==0){//非单行线
			glength[x][y]=glength[y][x]=length;
			gtime[x][y]=gtime[y][x]=time;
		}else{//单行线
			glength[x][y]=length;
			gtime[x][y]=time;
		}
	}
	
	scanf("%d%d",&start,&dest);
	//先求最短路径
	//初始化
	visited[start]=true;
	for(int i=0;i<n;i++){
		if(glength[start][i]==0){
			minlength[i]=INT_MAX;
		}else{
			minlength[i]=glength[start][i];
			path[i].push_back(start);
		}
	}
	while(true){
		int minl=INT_MAX,minindex=-1;
		for(int i=0;i<n;i++){
			if(!visited[i]&&minlength[i]<minl){
				minl=minlength[i];
				minindex=i;
			}
		}
		if(minindex==-1)break;
		if(minindex==dest)break;
		visited[minindex]=true;
		for(int i=0;i<n;i++){
			if(!visited[i]&&glength[minindex][i]!=0){
				int newlength=minlength[minindex]+glength[minindex][i];
				if(newlength<minlength[i]){
					path[i].clear();
					path[i].push_back(minindex);
					minlength[i]=newlength;
				}else if(newlength==minlength[i]){
					path[i].push_back(minindex);
				}
			}
		}
	}
	//求出最短路径后，从dest开始dfs直到start，找出时间最短的那条路
	vector<int>tmpPath;
	dfsLength(dest,0,tmpPath);
	//再求时间最短的路径
	fill(visited,visited+n,false);
	visited[start]=true;
	for(int i=0;i<n;i++){
		if(gtime[start][i]==0){
			mintime[i]=INT_MAX;
		}else{
			mintime[i]=gtime[start][i];
			pathtime[i].push_back(start);
		}
	}
	while(true){
		int minl=INT_MAX,minindex=-1;
		for(int i=0;i<n;i++){
			if(!visited[i]&&mintime[i]<minl){
				minl=mintime[i];
				minindex=i;
			}
		}
		if(minindex==-1)break;
		if(minindex==dest)break;
		visited[minindex]=true;
		for(int i=0;i<n;i++){
			if(!visited[i]&&gtime[minindex][i]!=0){
				int newlength=mintime[minindex]+gtime[minindex][i];
				if(newlength<mintime[i]){
					pathtime[i].clear();
					pathtime[i].push_back(minindex);
					mintime[i]=newlength;
				}else if(newlength==mintime[i]){
					pathtime[i].push_back(minindex);
				}
			}
		}
	}
	vector<int>tmpPath2;
	dfsTime(dest,tmpPath2);
	bool identy=true;
	if(minLengthPath.size()==minTimePath.size()){
		for(int i=0;i<minLengthPath.size();i++){
			if(minLengthPath[i]!=minTimePath[i]){
				identy=false;
			}
		}
	}else{
		identy=false;
	}
	int totalLength=0,totalTime=0,s=start;
	if(identy){
		printf("Distance = %d; Time = %d: ",minlength[dest],mintime[dest]); 
		for(int i=minLengthPath.size()-1;i>=0;i--){
			printf("%d -> ",minLengthPath[i]);
		}
		printf("%d",dest);
	}else{
		printf("Distance = %d: ",minlength[dest]);
		for(int i=minLengthPath.size()-1;i>=0;i--){
			printf("%d -> ",minLengthPath[i]);
		}
		printf("%d\n",dest);
		printf("Time = %d: ",mintime[dest]);
		for(int i=minTimePath.size()-1;i>=0;i--){
			printf("%d -> ",minTimePath[i]);
		}
		printf("%d",dest);
	}
	return 0;
}