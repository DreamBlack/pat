#include<stdio.h>
#include<vector>
#include<climits>
#include<string>
using namespace std;
int nodeid[26*26*26+10];
string nodename[200];
int happys[200]; 
int graph[200][200];
bool visited[200];
int length[200];
int maxhappy[200];
vector<vector<int>> path(200);
int nameToID(char*name){//nodeid存放的是，对于一个名字，转为数字之后作为下标对应的0-n-1的编号
	return nodeid[(name[0]-'A')*26*26+(name[1]-'A')*26+(name[2]-'A')];
}
int n,k;
int start=0;
int e=0;
int totalRoutes=0;
vector<int> finalPath;
int maxHappy=0;
void dfs(int now,int &nowHappy,vector<int>& tmpPath){
	if(now==start){
		totalRoutes++;
		if(nowHappy>maxHappy){
			maxHappy=nowHappy;
			finalPath.clear();
			finalPath.assign(tmpPath.begin(),tmpPath.end());
		}else if(nowHappy==maxHappy){
			if(nowHappy/tmpPath.size()>maxHappy/(finalPath.size())){
				finalPath.clear();
				finalPath.assign(tmpPath.begin(),tmpPath.end());
			}
		}
		return;
	}
	
	for(int i=0;i<path[now].size();i++){
		tmpPath.push_back(now);
		nowHappy+=happys[now];
		dfs(path[now][i],nowHappy,tmpPath);
		tmpPath.pop_back();
		nowHappy-=happys[now];
	}
}
int main(){
	/*
	题目大意：有N个城市，M条无向边，从某个给定的起始城市出发，前往名为ROM的城市。每个城市（除了起始城市）都有一个点权（称为幸福值），
	和边权（每条边所需的花费）。求从起点到ROM所需要的最少花费，并输出其路径。如果路径有多条，给出幸福值最大的那条。如果仍然不唯一，
	选择路径上的城市平均幸福值最大的那条路径。
	解题思路：
	1、先dijikstra求最短路径
	2、从终点dfs遍历。同时计算路径条数并记录幸福度最大的平均幸福最高那条路
	3、vector拷贝finalPath.assign(tmpPath.begin(),tmpPath.end());
	*/
	char name[4];
	scanf("%d%d%s",&n,&k,name);
	start=nameToID(name);
	nodename[0]=name;
	nodeid[start]=0;
	for(int i=1;i<n;i++){
		char tmp[4];
		int tint;
		scanf("%s %d",tmp,&tint);
		string st(tmp);
		if(st.compare("ROM")==0){
			e=i;
		}
		nodeid[(tmp[0]-'A')*26*26+(tmp[1]-'A')*26+(tmp[2]-'A')]=i;
		happys[i]=tint;
		nodename[i]=st;
	}
	for(int i=0;i<k;i++){
		char n1[4];
		char n2[4];
		int tint;
		scanf("%s %s %d",n1,n2,&tint);
		int a,b;
		a=nameToID(n1);
		b=nameToID(n2);
		graph[a][b]=graph[b][a]=tint;
	}
	if(start==e){
		printf("0 0 0 0\n");
		return 0;
	}
	for(int i=1;i<n;i++){
		if(graph[0][i]!=0){
			length[i]=graph[0][i];
			path[i].push_back(0);
		}else{
			length[i]=INT_MAX;
		}
	}
	visited[0]=true;
	while(true){
		int minlength=INT_MAX,minIndex=-1;
		for(int i=1;i<n;i++){
			if(!visited[i]&&length[i]<minlength){
				minlength=length[i];
				minIndex=i;
			}
		}
		if(minIndex==-1)break;
		visited[minIndex]=true;
		if(minIndex==e)break;
		for(int i=1;i<n;i++){
			if(!visited[i]&&graph[i][minIndex]!=0){
				int newlength=length[minIndex]+graph[i][minIndex];
				if(newlength<length[i]){
					path[i].clear();
					path[i].push_back(minIndex);
					length[i]=newlength;
				}else if(newlength==length[i]){
						path[i].push_back(minIndex);
					
				}
			}
		}
	}
	int nowhappy=0;
	vector<int>tmp;
	dfs(e,nowhappy,tmp);
	printf("%d %d %d %d\n",totalRoutes,length[e],maxHappy,maxHappy/finalPath.size());
	printf("%s->",nodename[start].c_str());
	for(int i=finalPath.size()-1;i>=0;i--){
		printf("%s",nodename[finalPath[i]].c_str());
		if(i!=0){
			printf("->");
		}
	}
	return 0;
}