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
	题目大意：给出一个链表，将链表排序，然后把链表上的结点按照data值的从小到大顺序输出
	解题思路：又是格式奇葩的链表题。
	1、一开始直接对key排序，然后重排链表，有两个点错误。网上说因为有的结点根本不在链表中，给出的数据有不在链表中的结点
	2、针对1的情况，遍历一遍链表用vector记录链表中有的元素。然后进行排序，最后一个测试点仍然段错误
	3、针对2，很容易想到最后一个测试点应该为表头结点即为-1的情况，注意输出-1时，不需要五位数不足补齐的格式
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