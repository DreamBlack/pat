#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
#include<functional>
#include<iterator>
using namespace std;
int main(){
	/*
	��Ŀ���⣺���������������ϣ����ǵ����ƶȶ���Ϊ��Nc/Nt*100%������Nc���������϶��еĲ���������ĸ�����
	Nt����������һ���еĲ���������ĸ��������������Ǽ�������һ�Ը������ϵ����ƶȡ�
	nc���������ϵĹ���Ԫ�ظ�����nt���������ϵ����а�����Ԫ�ظ���������Ԫ�ظ�����ʾ����Ԫ��֮�以����ͬ����
	����˼·��
	1��һ��ʼ����ͨ��set,nc=0,nt=a.size()��b�����Ԫ�ز��뵽a�У����a���Ѿ�����nc++,����nt++��
	����������ʱ��
	2�������ϲ���һ�£�ʹ����set_intersection��inserter��a,b������Ԫ�طŵ�tmp���棬nc=tmp.size(),nt=a.size()+b.size()-nc;
	*/
	int n;
	scanf("%d",&n);
	vector<set<int>> all;
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k); 
		set<int> s;
		for(int j=0;j<k;j++){
			int temp;
			scanf("%d",&temp);
			s.insert(temp);
		}
		all.push_back(s);
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		set<int> temp;
		
		set_intersection(all[a].begin(),all[a].end(),all[b].begin(),all[b].end(),inserter(temp,temp.begin()));
		int nt=all[a].size()+all[b].size()-temp.size(),nc=temp.size();
		double r=(double)nc/nt*100;
		printf("%.1f%%\n",r);
	}
	return 0;
}