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
		if(children[r].empty()){//û�к���
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
		if(children[r].empty()){//û�к���
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
	��Ŀ���⣺�������Ľṹ��Ȩֵ���ҴӸ���㵽Ҷ�ӽ���·���ϵ�Ȩֵ���֮�͵��ڸ���Ŀ������·�������ҴӴ�С��·�����еĴ�С�����·��
	����˼·��
	1��ͼ�ı�������˵�����ı����⡣�������ͣ��̶���ʽ�ⷨ
	2��������һ��ȽϷ���ʱ�����ʱ������˳�����������д�˸�cmp������sort��������С�����ÿ���ڱ���·����ʱ��ͱ���·������
	3����2��ʱ����һ�����Ե������Ҫ�Ǳȴ�Сʱ����߼��е�����
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