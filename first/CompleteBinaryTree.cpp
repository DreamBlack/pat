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
	��Ŀ���⣺����һ��n��ʾ��n����㣬��n�����Ϊ0~n-1��������n���������Һ��ӣ�����������ǲ�����ȫ������
	����˼·��
	1�����ýṹ��tree[i].left��tree[i].right�����i�������Һ��ӣ�Ȼ������ҳ�û�г��ֹ��Ľ�㣬��������Ǹ��ڵ�
	2����֪������ÿ���������Һ��ӣ����ݶ������Ĳ�������ķ������������������ʹ�ö��У�������ö�������ÿ����һ������cnt++�����������-1��
	�жϵ�ǰcnt�Ƿ��n��ȣ�������ȣ�˵���ý�㲻�����һ����㣬����NO������YES
	3����ʼ��ʱ���������Ե����
	����һ����ֻ��һ���������Ӧ�����"YES 0"
	����һ���ǣ����һ�㲻�����Ҳ����������½Ǳ����½��������
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
			if(nodes[now].left==-1&&nodes[now].right!=-1){//��������ȴû��������
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
			}else{//�����Ѿ����ˣ�֤�������һ��

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