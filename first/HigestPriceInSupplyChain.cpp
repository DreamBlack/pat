#include<stdio.h>
#include<vector>
using namespace std;
int n,root;
double p,r,maxprice=0;
vector<vector<int>> graph(100000);
vector<int> maxnode;
bool visited[100000];
void dfs(int now,double price){
	visited[now]=true;
	
	if(graph[now].empty()){//Ҷ�ӽ��
		if(price>maxprice){
			maxprice=price;
			maxnode.clear();
			maxnode.push_back(now);
		}else if(price==maxprice){
			maxnode.push_back(now);
		}
	}
	for(int i=0;i<graph[now].size();i++){
		if(!visited[graph[now][i]]){
			dfs(graph[now][i],price*r/100+price);
		}
	}
}
int main(){
	/*
	��Ŀ���⣺��һ������������������ļ۸�Ϊp��Ȼ��ÿ������һ�㣬�۸�����r%��������Ҷ�ӽ�����߼۸��Լ�����۸��Ҷ�ӽ�������
	��Ŀ�������ö�ά����v[i][j]�洢������ÿһ�����i�����ĺ��ӽ����±�push_back�洢��v[i]�С��������������dfs�����浱ǰ������
	��index�Լ���ǰ������ڲ������� ��ǰ���ĺ��ӽ�����Ϊ0��ʱ��˵����Ҷ�ӽ�㣬����maxdepth��maxnum��ֵ����������
	*/
	scanf("%d%lf%lf",&n,&p,&r);
	graph.clear();
	graph.resize(n);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(tmp==-1){
			root=i;
		}else{
			graph[tmp].push_back(i);
		}
	}
	double nprice=p;
	dfs(root,p);
	printf("%0.2f %d",maxprice,maxnode.size());
	return 0;
}