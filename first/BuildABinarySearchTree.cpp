#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
	int left,right,key;
};
Node nodes[100];
int num[100];
int cnt=0;
void inOrder(int now){
	if(now==-1) return;
	inOrder(nodes[now].left);
	nodes[now].key=num[cnt++];
	inOrder(nodes[now].right);
}
int main(){
	/*
	题目大意：给出一棵二叉搜索树（给出每个结点的左右孩子），且已知根结点为0，求并且给出应该插入这个二叉搜索树的数值，求这棵二叉树的层序遍历
	解题思路：30min解决，树的常规题
	1、二叉搜索树中序遍历结果递增。根据树的结构进行中序遍历的同时填写上数据
	2、之后层次遍历输出每个结点的数据即可
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Node tmp;
		scanf("%d%d",&(tmp.left),&(tmp.right));
		nodes[i]=tmp;
	}
	for(int i=0;i<n;i++){
		scanf("%d",num+i);
	}
	sort(num,num+n);
	//中序遍历树
	inOrder(0);
	//层次遍历并输出
	queue<int> q;
	q.push(0);
	q.push(-1);
	int count=1;
	printf("%d",nodes[0].key);
	if(count<n-1){
		printf(" ");
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now!=-1){
			if(nodes[now].left!=-1){
				printf("%d",nodes[nodes[now].left].key);
				q.push(nodes[now].left);
				if(count<n-1){
					printf(" ");
				}
				count++;
			}
			if(nodes[now].right!=-1){
				printf("%d",nodes[nodes[now].right].key);
				q.push(nodes[now].right);
				if(count<n-1){
					printf(" ");
				}
				count++;
			}
		}else{
			if(!q.empty()){
				q.push(-1);
			}
		}
	}
	return 0;
}