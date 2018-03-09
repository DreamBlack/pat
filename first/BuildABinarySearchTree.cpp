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
	��Ŀ���⣺����һ�ö���������������ÿ���������Һ��ӣ�������֪�����Ϊ0�����Ҹ���Ӧ�ò��������������������ֵ������ö������Ĳ������
	����˼·��30min��������ĳ�����
	1�����������������������������������Ľṹ�������������ͬʱ��д������
	2��֮���α������ÿ���������ݼ���
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
	//���������
	inOrder(0);
	//��α��������
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