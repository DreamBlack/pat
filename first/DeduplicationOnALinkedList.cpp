#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
struct Node{
	int add;
	int key;
	int next;
};
int book[10010];
Node nodes[100000];
int main(){
	/*
	题目大意：给一个链表，去重（去掉值或者绝对值相等的），先输出删除后的链表，再输出删除了的链表。
	解题思路：
	1、链表题全部先遍历一遍链表去除无用节点
	2、输出重排的时候可以不要想着改每个结点的next指针，只是用vector按序存储即可，输出的时候结点的next地址选择vector下一元素的地址即可
	3、用绝对值函数要#include<stdlib.h>。vector.size()不会检查vector是否为空，用之前要检查否则发生段错误
	*/
	int n,cnt=0,head;
	scanf("%d%d",&head,&n);
	vector<Node> intial;
	for(int i=0;i<n;i++){
		Node tmp;
		scanf("%d%d%d",&(tmp.add),&(tmp.key),&(tmp.next));
		nodes[tmp.add]=tmp;
	}
	int now=head;
	while(now!=-1){
		intial.push_back(nodes[now]);
		cnt++;
		now=nodes[now].next;
	}
	vector<Node> sep;
	vector<Node> l;
	for(int i=0;i<cnt;i++){
		if(book[abs(intial[i].key)]==0){//第一次出现
			book[abs(intial[i].key)]=1;
			l.push_back(intial[i]);
		}else{
			sep.push_back(intial[i]);
		}
	}
	for(int i=0;i<l.size()-1;i++){
		printf("%05d %d %05d\n",l[i].add,l[i].key,l[i+1].add);
	}
	printf("%05d %d %d\n",l[l.size()-1].add,l[l.size()-1].key,-1);
	if(!sep.empty()){
		for(int i=0;i<sep.size()-1;i++){
			printf("%05d %d %05d\n",sep[i].add,sep[i].key,sep[i+1].add);
		}
		printf("%05d %d %d",sep[sep.size()-1].add,sep[sep.size()-1].key,-1);
	}
	return 0;
}
