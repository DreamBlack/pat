#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
	int add;
	int val;
	int next;
};
Node nodes[100000];
int main(){
	/*
	题目大意：链表中每K个元素进行翻转，小于k个的不翻转
	解题思路：
	1、注意要记录翻转后的链表的表头和表尾，及时把链表的链连起来
	2、最大的坑在于有无效结点，也就是说除了从头结点走到-1的所有结点外，还有其他子链表，要先遍历一遍获得表的实际节点数
	*/
	int first,n,k;
	scanf("%d%d%d",&first,&n,&k);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		Node tmp={a,b,c};
		nodes[a]=tmp;
	}
	vector<Node>result;
	int i=0,now=first,last=first,cnt=0;
	for(int i=0;i<n&&now!=-1;i++){
		result.push_back(nodes[now]);
		now=nodes[now].next;
		cnt++;
	}
	n=cnt;
	i=0;
	while(n-i>=k){
		reverse(result.begin()+i,result.begin()+i+k);
		i=i+k;
	}
	if(first==-1){
		printf("-1");
	}else{
		for(int j=0;j<n-1;j++){
			printf("%05d %d %05d\n",result[j].add,result[j].val,result[j+1].add);
		}
		printf("%05d %d %d",result[n-1].add,result[n-1].val,-1);
	}

	return 0;
}