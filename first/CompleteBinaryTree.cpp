#include<stdio.h>
#include<algorithm>
#include<cctype>
#include<queue>
#include<cmath>
using namespace std;
struct Node{
	int left;
	int right;
};
int parent[20];
int tree[21];
Node nodes[20];
int main(){
	/*
	题目大意：给出一个n表示有n个结点，这n个结点为0~n-1，给出这n个结点的左右孩子，求问这棵树是不是完全二叉树
	解题思路：
	1、先用结构体tree[i].left和tree[i].right保存第i结点的左右孩子，然后遍历找出没有出现过的结点，这个结点就是根节点
	2、已知根结点和每个结点的左右孩子，根据二叉树的层序遍历的方法（广度优先搜索，使用队列）遍历这棵二叉树，每遍历一个结点就cnt++，如果发现有-1，
	判断当前cnt是否和n相等，如果不等，说明该结点不是最后一个结点，返回NO，否则YES
	3、开始的时候两个测试点错误
	其中一个是只有一个结点的情况应该输出"YES 0"
	还有一个是，最后一层不满，且不符合最左下角比右下角满的情况
	*/
	int n;
	scanf("%d",&n);
	fill(parent,parent+n,-1);
	fill(tree,tree+n,-1);
	for(int i=0;i<n;i++){
		char n2[3];
		char n1[3];
		Node t;
		scanf("%s%s",n1,n2);
		if(n1[0]!='-'){
			int a=atoi(n1);
			parent[a]=i;
			t.left=a;
		}else{
			t.left=-1;
		}
		if(n2[0]!='-'){
			int a=atoi(n2);
			parent[a]=i;
			t.right=a;
		}else{
			t.right=-1;
		}
		nodes[i]=t;
	}
	if(n==1){
		printf("YES 0");
		return 0;
	}
	int root=-1;
	for(int i=0;i<n;i++){
		if(parent[i]==-1){
			root=i;
			break;
		}
	}
	int cnt=1,last=-1,nowcnt=0,level=0,allcnt=0;
	bool iscbt=true;
	queue<int>q;
	q.push(root);
	q.push(-1);
	tree[1]=root;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now!=-1){
			nowcnt++;
			allcnt++;
			if(nodes[now].left==-1&&nodes[now].right!=-1){//有右子树却没有左子树
				iscbt=false;
				break;
			}
			if(nodes[now].left!=-1){
				q.push(nodes[now].left);
				last=nodes[now].left;
				tree[allcnt*2]=last;
			}
			if(nodes[now].right!=-1){
				q.push(nodes[now].right);
				last=nodes[now].right;
				tree[allcnt*2+1]=last;
			}
		}else{
			if(!q.empty()){
				if(nowcnt<pow((double)2,level)){
					iscbt=false;
					break;
				}
				nowcnt=0;
				q.push(-1);
			}else{//队列已经空了，证明是最后一层

			}
			level++;
		}
	}
	if(iscbt){
		for(int i=1;i<=n;i++){
			if(tree[i]==-1){
				printf("NO %d",root);
				return 0;
			}
		}
		printf("YES %d",last);
	}else{
		printf("NO %d",root);
	}
	return 0;
}