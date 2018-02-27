#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
	int key;
	int add;
	int next;
};
bool cmp(Node a,Node b){
	return(a.key<b.key)?true:false;
}
vector<Node> nodes;
Node heads[100000];
int main(){
	/*
	��Ŀ���⣺����һ����������������Ȼ��������ϵĽ�㰴��dataֵ�Ĵ�С����˳�����
	����˼·�����Ǹ�ʽ����������⡣
	1��һ��ʼֱ�Ӷ�key����Ȼ�������������������������˵��Ϊ�еĽ��������������У������������в��������еĽ��
	2�����1�����������һ��������vector��¼�������е�Ԫ�ء�Ȼ������������һ�����Ե���Ȼ�δ���
	3�����2���������뵽���һ�����Ե�Ӧ��Ϊ��ͷ��㼴Ϊ-1�������ע�����-1ʱ������Ҫ��λ�����㲹��ĸ�ʽ
	*/
	int n,head;
	scanf("%d%d",&n,&head);
	for(int i=0;i<n;i++){
		Node tmp;
		scanf("%d%d%d",&(tmp.add),&(tmp.key),&(tmp.next));
		heads[tmp.add]=tmp;
	}
	int cnt=0,nowNext=head;
	if(head==-1){
		printf("%d %d\n",0,-1);
	}else{
		while(nowNext!=-1){
			nodes.push_back(heads[nowNext]);
			nowNext=heads[nowNext].next;
		}
		sort(nodes.begin(),nodes.end(),cmp);
		int tail=-1;
		printf("%d %05d\n",nodes.size(),nodes[0].add);
		if(nodes.size()==1){
			printf("%05d %d %d",nodes[0].add,nodes[0].key,tail);
		}else{
			for(int i=0;i<nodes.size()-1;i++){
				printf("%05d %d %05d\n",nodes[i].add,nodes[i].key,nodes[i+1].add);

			}
			printf("%05d %d %d",nodes[nodes.size()-1].add,nodes[nodes.size()-1].key,tail);
		}
	}

	return 0;
}