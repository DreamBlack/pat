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
	题目大意：给出1000条以内的通话记录A B和权值w，和阈值k，如果一个团伙人数超过2人并且通话总权值超过k，
	令团伙里面的自身权值的最大值为头目，输出所有满足条件的团伙的头目，和他们团伙里面的人数
	解题思路：
	1、这算是图的遍历算法里面比较烦的一道了。要找连通分量的个数，对于每个连通分量计算边权值之和，以及里面度数最大的那个顶点
	2、输入输出也挺烦。因为顶点编号不是0-n，而是string。一开始用map<char*,int>后来发现不行，改用map<string,int>
	3、计算每个连通分量的边权值之和方法，是，遍历的时候记下所有的顶点，之后在上三角矩阵里计算所有边值之和
	4、计算每个连通分量里面度数最大的那个顶点的方法，是，在dfs的时候把最大值作为传引用参数放进去。
	5、注意输出要按字母表顺序，第一次提交后有几个错就是因为这个
	6、m（<1000）条边可能对于2m(2000)个顶点，开始的时候数组只开到了1000导致了段错误，开到2010就可以了
	7、对于4，网友有一个
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
	//计算各个顶点的度数
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
			//计算当前连通分量的边权值之和
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