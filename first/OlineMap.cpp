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
	if(now==start){//���˿�ʼ���
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
	if(now==start){//���˿�ʼ���
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
	��Ŀ���⣺��һ�ŵ�ͼ����������м��о���Ҳ��ʱ�䣬�еĵ����е�˫��Ҫ����ݵ�ͼ�Ƽ�����·�ߣ�һ������쵽��·�ߣ�һ������̾����·�ߡ�
	��һ�и�����������N��M����ʾ��ͼ�еص�ĸ�����·������������������M��ÿһ�и�������·�����V1 ��·�����V2 �Ƿ����� ��·���� ����ʱ��
	Ҫ���һ�������쵽��ʱ��Time��·�����ڶ��������̾���Distance��·��
	дdijkstra��ʱ�������ڳ�ʼ����ʱ���·��Ҳ��ʼ��Ϊstart
	����˼·��
	������Dijkstra + DFS��һ�������·���������ͬ��ʱ����̵���������һ�������·���������ͬ��������С��������~~~�����
	·������ֱ����Dijkstra������ǰ�����pre����~~~�����·����ΪҪ��������С������������Ҫ��pre�Ķ�ά����洢���н������·��
	��Ȼ����DFS������������Ľ������С������~~~~
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	path.resize(n);
	pathtime.resize(n);
	for(int i=0;i<m;i++){
		int x,y,oway,length,time;
		scanf("%d%d%d%d%d",&x,&y,&oway,&length,&time);
		if(oway==0){//�ǵ�����
			glength[x][y]=glength[y][x]=length;
			gtime[x][y]=gtime[y][x]=time;
		}else{//������
			glength[x][y]=length;
			gtime[x][y]=time;
		}
	}
	
	scanf("%d%d",&start,&dest);
	//�������·��
	//��ʼ��
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
	//������·���󣬴�dest��ʼdfsֱ��start���ҳ�ʱ����̵�����·
	vector<int>tmpPath;
	dfsLength(dest,0,tmpPath);
	//����ʱ����̵�·��
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