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
int nameToID(char*name){//nodeid��ŵ��ǣ�����һ�����֣�תΪ����֮����Ϊ�±��Ӧ��0-n-1�ı��
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
	��Ŀ���⣺��N�����У�M������ߣ���ĳ����������ʼ���г�����ǰ����ΪROM�ĳ��С�ÿ�����У�������ʼ���У�����һ����Ȩ����Ϊ�Ҹ�ֵ����
	�ͱ�Ȩ��ÿ��������Ļ��ѣ��������㵽ROM����Ҫ�����ٻ��ѣ��������·�������·���ж����������Ҹ�ֵ���������������Ȼ��Ψһ��
	ѡ��·���ϵĳ���ƽ���Ҹ�ֵ��������·����
	����˼·��
	1����dijikstra�����·��
	2�����յ�dfs������ͬʱ����·����������¼�Ҹ�������ƽ���Ҹ��������·
	3��vector����finalPath.assign(tmpPath.begin(),tmpPath.end());
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