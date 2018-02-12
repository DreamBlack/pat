#include<stdio.h>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
map<string,int> vexs;
int vn=0;
int edges[2010][2010];
bool visited[1010];
int weight[1010];
int heads[1010];
struct Gang{
	int head;
	int memn;
};
vector<Gang> g;
vector<int> members;
void dfs(int now,int &head,int &num){
	visited[now]=true;
	members.push_back(now);
	num++;
	if(weight[now]>weight[head]){
		head=now;
	}
	for(int i=0;i<vn;i++){
		if(!visited[i]&&edges[i][now]){

			dfs(i,head,num);

		}
	}
}
bool cmp(Gang a,Gang b){
	return (a.head<b.head)?true:false;
}
int main(){
	/*
	��Ŀ���⣺����1000�����ڵ�ͨ����¼A B��Ȩֵw������ֵk�����һ���Ż���������2�˲���ͨ����Ȩֵ����k��
	���Ż����������Ȩֵ�����ֵΪͷĿ��������������������Ż��ͷĿ���������Ż����������
	����˼·��
	1��������ͼ�ı����㷨����ȽϷ���һ���ˡ�Ҫ����ͨ�����ĸ���������ÿ����ͨ���������Ȩֵ֮�ͣ��Լ�������������Ǹ�����
	2���������Ҳͦ������Ϊ�����Ų���0-n������string��һ��ʼ��map<char*,int>�������ֲ��У�����map<string,int>
	3������ÿ����ͨ�����ı�Ȩֵ֮�ͷ������ǣ�������ʱ��������еĶ��㣬֮���������Ǿ�����������б�ֵ֮��
	4������ÿ����ͨ����������������Ǹ�����ķ������ǣ���dfs��ʱ������ֵ��Ϊ�����ò����Ž�ȥ��
	5��ע�����Ҫ����ĸ��˳�򣬵�һ���ύ���м����������Ϊ���
	6��m��<1000�����߿��ܶ���2m(2000)�����㣬��ʼ��ʱ������ֻ������1000�����˶δ��󣬿���2010�Ϳ�����
	7������4��������һ��
	*/
	int n,k;

	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		string a,b;
		int min;
		cin>>a>>b>>min;

		if(vexs.count(a)==0){
			vexs[a]=vn++;
		}
		if(vexs.count(b)==0){
			vexs[b]=vn++;
		}
		edges[vexs[b]][vexs[a]]+=min;
		edges[vexs[a]][vexs[b]]=edges[vexs[b]][vexs[a]];
	}
	//�����������Ķ���
	for(int i=0;i<vn;i++){
		for(int j=0;j<vn;j++){
			weight[i]+=edges[i][j];
		}
	}
	int diff=0;
	for(int i=0;i<vn;i++){
		if(!visited[i]){
			int head=i,num=0,allweight=0;
			dfs(i,head,num);
			sort(members.begin(),members.end());
			//���㵱ǰ��ͨ�����ı�Ȩֵ֮��
			for(int i=0;i<members.size();i++){
				for(int j=i+1;j<members.size();j++){
					if(edges[members[i]][members[j]]!=0){
						allweight+=edges[members[i]][members[j]];
					}
				}
			}
			members.clear();
			if(allweight>k&&num>2){
				Gang tmp;
				tmp.head=head;
				tmp.memn=num;
				g.push_back(tmp);
			}

			diff++;
		}

	}
	sort(g.begin(),g.end(),cmp);
	if(g.empty()){
		printf("0");
	}else{
		printf("%d\n",g.size());
		map<string ,int> ou;
		for(int i=0;i<g.size();i++){
			auto it=vexs.begin();
			while(it!=vexs.end()){
				if(it->second==g[i].head){
					ou[it->first]=g[i].memn;
				}
				it++;
			}

		}
		for(auto it=ou.begin();it!=ou.end();it++){
			cout<<it->first<<" "<<it->second<<endl;
		}
	}

	return 0;
}