#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> paths;
int weights[100];
vector<int> children[100];
int w;

void preOrder(int r,int&nowlength,vector<int>&path){
	nowlength+=weights[r];
	path.push_back(weights[r]);
	if(nowlength>w){
		return;
	}else if(nowlength==w){
		if(children[r].empty()){//没有孩子
			if(paths.empty()){
				paths.push_back(path);
			}else{
				int pos=-1;
				for(int i=0;i<paths.size();i++){
					for(int j=0;j<paths[i].size()&&j<path.size();j++){
						if(paths[i][j]>path[j]){
							break;
						}else if(paths[i][j]<path[j]){
							pos=i;
							break;
						}
					}
					if(pos!=-1){
						break;
					}
				}
				if(pos!=-1){
					paths.insert(paths.begin()+pos,path);
				}else{
					paths.push_back(path);
				}
				
			}
			
		}else{
			return;
		}
	}else{
		if(children[r].empty()){//没有孩子
			return;
		}else{
			for(int i=0;i<children[r].size();i++){
				preOrder(children[r][i],nowlength,path);
				nowlength=nowlength-weights[children[r][i]];
				path.pop_back();
			}
		}
	}
}
int main(){
	/*
	题目大意：给出树的结构和权值，找从根结点到叶子结点的路径上的权值相加之和等于给定目标数的路径，并且从大到小（路径序列的大小）输出路径
	解题思路：
	1、图的遍历或者说是树的遍历题。常规题型，固定格式解法
	2、本题有一点比较烦的时输出的时候按序列顺序输出。本来写了个cmp打算用sort结果并不行。所有每次在保存路径的时候就保存路径有序。
	3、在2的时候有一个测试点错误。主要是比大小时候的逻辑有点问题
	*/
	int n,m;
	scanf("%d%d%d",&n,&m,&w);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		weights[i]=tmp;
	}
	for(int i=0;i<m;i++){
		int node,k;
		scanf("%d%d",&node,&k);
		for(int i=0;i<k;i++){
			int tm;
			scanf("%d",&tm);
			children[node].push_back(tm);
		}
	}
	int nowlength=0;
	vector<int>path;
	preOrder(0,nowlength,path);
	
	for(int i=0;i<paths.size();i++){
		for(int j=0;j<paths[i].size();j++){
			printf("%d",paths[i][j]);
			if(j!=paths[i].size()-1){
				printf(" ");
			}
		}
		if(i!=paths.size()-1){
			printf("\n");
		}
	}
	return 0;

}