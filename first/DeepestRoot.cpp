#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int edges[10001][10001];
int deepestLvl[10001];
int n;
set<int> s;
bool visited[10001]={false};
void dfs(int now,int l){//l��ʾ��ǰ������
	int temp=l;
	visited[now]=true;
	for(int i=1;i<n+1;i++){
		if(!visited[i]&&edges[now][i]==1){
			l=l+1;
			dfs(i,l);//�ӵ�ǰ�����DFSʱ��lҪ+1
			deepestLvl[i]=l;//��ĳ��������ʱ��¼��ǰ��ľ���
			l=temp;//������Ҫ���ص�֮ǰ�Ľ��ʱ����ǰ�����ȱ���ҲҪ�ص�ԭ��������
		}
	}
}
int main(){
	/*
	��Ŀ���⣺����n����㣨1~n��֮���n-1���ߣ����Ƿ��ܹ���һ������������ܹ�����������е���ͨ����������
	����ܹ���һ����������ܹ�����������ĸ߶�ʱ�����ĸ���㡣����ж�������մ�С���������
	���⣺
	1��һ��ʼʹ�õķ����ǣ��ȶ�����ͼ����һ��������ȱ����ж��Ƿ�����ͨͼ��
	�������ͨͼ���Ͷ�ͼ��ÿһ�������ٽ���һ��������ȱ������ҵ�n��������������ȣ��ܼ�n+1��������ȱ���
	��ˣ���һ�����Ե����г�ʱ
	2�����������ѵİ취���������ж����Ƿ�Ϊ��ͨͼ��ֻ������������ȱ�����������г�������Ķ��㡣
	���ȴ���һ��������ȱ�������¼�����������Զ����Щ�㣨��Զֻ��ȱ���ʱ��һ�η��صĵ㣩
	�ڶ��δ�������¼�µĵ�����ѡһ�����ٽ���������ȱ�������¼�����������Զ�ĵ㣨��������㣩��
	�������㼯���еĲ�����ע���ǲ������ǽ���������Ҫ��ĵ㣬SET��Ԫ�ز����ظ������ѡ��set
	3��Ȼ������2��ʱ�򣬶������������Զ�ĵ㣬���ô�ĳ�㿪ʼ���������һ�������ټ��������ĵ㷵�ص�����
	void dfs(int now){
	bool longest=true;
	visited[now]=true;
	for(int i=1;i<n+1;i++){
	if(!visited[i]&&edges[now][i]==1){
	longest=false;
	dfs(i);
	}
	}
	if(longest){
	v.insert(now);
	}
	}   ����ʵ���������ҳ����Ĳ�������Զ�ĵ㣬Ӧ����ר�ŵ���������¼���룬���ѡ�����ġ�
	*/
	scanf("%d",&n);
	int from,to;
	//N����N-1���߱�֤�ˣ�ֻ���л���Ȼ����ͨ������ֻ�����Ƿ���ͨ���ɣ����ÿ����л������
	for(int i=0;i<n-1;i++){
		scanf("%d",&from);
		scanf("%d",&to);
		edges[from][to]=edges[to][from]=1;
	}
	int div=0;
	//�Ƚ�����ȱ���������ͨ����
	for(int j=1;j<n+1;j++){
		if(!visited[j]){
			dfs(j,0);
			div++;
		}
	}
	if(div>1){
		cout<<"Error: ";
		cout<<div;
		cout<<" components";
	}else{
		//�������ǵ�����visited
		for(int i=1;i<n+1;i++){
			visited[i]=false;
			deepestLvl[i]=0;
		}
		dfs(1,0);
		int max=0;
		for(int i=1;i<n+1;i++){
			if(deepestLvl[i]>max){
				max=deepestLvl[i];
			}
		}
		for(int i=1;i<n+1;i++){
			if(deepestLvl[i]==max){
				s.insert(i);
			}
		}
		for(int i=1;i<n+1;i++){
			visited[i]=false;
			deepestLvl[i]=0;
		}

		auto it=s.begin();
		dfs(*it,0);
		max=0;
		for(int i=1;i<n+1;i++){
			if(deepestLvl[i]>max){
				max=deepestLvl[i];
			}
		}
		for(int i=1;i<n+1;i++){
			if(deepestLvl[i]==max){
				s.insert(i);
			}
		}
		for(auto iit=s.begin();iit!=s.end();iit++){
			printf("%d\n",*iit);
		}
	}

	return 0;
}