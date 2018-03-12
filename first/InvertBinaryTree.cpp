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
	��Ŀ���⣺��תһ�ö�����������ԭ��������ÿ���������Һ��ӣ�������Ĳ����ǰ�����
	����˼·��
	1�����ڷ�ת����������ʱ�����ҽ�㻥������
	2���Ҹ���㡣һ������һ�����ּ�¼ÿ������˫�ף�˫��Ϊ-1�ļ�Ϊ���ڵ㡣���ߣ�û������Ů�г��ֵļ�Ϊ���ڵ�
	3��Ȼ���α����ٵݹ��������
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