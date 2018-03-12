#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
	int left,right;
	int id;
};
Node nodes[10];
int inOrder[10];
int levelOrder[10];
int cnt=0;
int node[10];
void inorder(Node now){
	if(now.left!=-1){
		inorder(nodes[now.left]);
	}
	inOrder[cnt++]=now.id;
	if(now.right!=-1){
		inorder(nodes[now.right]);
	}
}
int main(){
	/*
	题目大意：反转一棵二叉树，给出原二叉树的每个结点的左右孩子，输出它的层序和前序遍历
	解题思路：
	1、对于反转，保存树的时候，左右结点互换即可
	2、找根结点。一种是用一个数字记录每个结点的双亲，双亲为-1的即为根节点。或者，没有在子女中出现的即为根节点
	3、然后层次遍历再递归中序遍历
	*/
	int n;
	scanf("%d",&n);
	fill(node,node+n,-1);
	for(int i=0;i<n;i++){
		char a[3];
		char b[3];
		Node t;
		scanf("%s%s",a,b);
		if(a[0]!='-'){
			t.right=atoi(a);//#include<stdlib.h>
			node[t.right]=i;
		}else{
			t.right=-1;
		}
		if(b[0]!='-'){
			t.left=atoi(b);
			node[t.left]=i;
		}else{
			t.left=-1;
		}
		t.id=i;
		nodes[i]=t;
	}
	int root;
	for(int i=0;i<n;i++){
		if(node[i]==-1){
			root=i;
			break;
		}
	}
	queue<Node> q;
	q.push(nodes[root]);
	
	while(!q.empty()){
		Node now=q.front();
		q.pop();
		levelOrder[cnt++]=now.id;
		if(now.left!=-1){
			q.push(nodes[now.left]);
		}
		if(now.right!=-1){
			q.push(nodes[now.right]);
		}
	}
	for(int i=0;i<n;i++){
		printf("%d",levelOrder[i]);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n");
	cnt=0;
	inorder(nodes[root]);
	for(int i=0;i<n;i++){
		printf("%d",inOrder[i]);
		if(i!=n-1){
			printf(" ");
		}
	}
	return 0;
}