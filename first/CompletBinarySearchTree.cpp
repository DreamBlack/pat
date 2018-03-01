#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1001];
int b[1001];
int c=1,n;
void inOrder(int i){
	if(i*2>n){//没有孩子
		a[i]=b[c++];
	}else{
		inOrder(2*i);
		a[i]=b[c++];
		if(2*i+1<=n){
			inOrder(2*i+1);
		}
	}
}
int main(){
	/*
	题目大意：给一串构成树的序列，已知该树是完全二叉搜索树，求它的层序遍历的序列
	解题思路：乍一看完全没思路。在考场上可能就要紧张歇菜了。
	1、其实，已知二叉搜索树的所有节点排序后便得到其中序的序列。即根据二叉搜索树中序以及完全二叉树求层次
	2、完全二叉树从1开始编号的话其层次序列顺序存在数组中第i个的节点的孩子是2*i和2*i+1。
	3、已知树的结构。中序遍历用中序结果填数组。该数组便是层次
	4、简而言之，将已经排好序的序列按照中序遍历存储
	*/
	scanf("%d",&n);
	for(int i=1;i<n+1;i++){
		int t;
		scanf("%d",&t);
		b[i]=t;
	}
	sort(b+1,b+n+1);
	inOrder(1);
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
		if(i!=n){
			printf(" ");
		}
	}
	return 0;
}