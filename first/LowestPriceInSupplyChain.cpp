#include<stdio.h>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> graph;
bool visited[100000];
double minprice=INT_MAX;
int minnum=0;
int n;
double p,r;
void dfs(int now,double nowprice){
	visited[now]=true;
	if(graph[now].empty()){
		if(nowprice<minprice){
			minprice=nowprice;
			minnum=1;
		}else if(nowprice==minprice){
			minnum++;
		}
	}else{
		for(int i=0;i<graph[now].size();i++){
			if(!visited[graph[now][i]]){
				dfs(graph[now][i],nowprice+nowprice*r/100);
			}
		}
	}
}
int main(){
	/*
	��Ŀ���⣺�ṩһ������������������ļ۸�Ϊp���Ӹ���㿪ʼÿ����һ�㣬�ò����۸񽫻��ڸ��׽��ļ۸�������r%��
	��Ҷ�ӽ����ܻ�õ���ͼ۸��Լ����ṩ��ͼ۸��Ҷ�ӽ����
	����˼·��dfs
	*/
	scanf("%d%lf%lf",&n,&p,&r);
	graph.resize(n);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				int tmp;
				scanf("%d",&tmp);
				graph[i].push_back(tmp);
			}
		}
	}
	dfs(0,p);
	printf("%.4f %d",minprice,minnum);
	return 0;
}
