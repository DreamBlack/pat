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
	��Ŀ���⣺������ÿK��Ԫ�ؽ��з�ת��С��k���Ĳ���ת
	����˼·��
	1��ע��Ҫ��¼��ת�������ı�ͷ�ͱ�β����ʱ���������������
	2�����Ŀ���������Ч��㣬Ҳ����˵���˴�ͷ����ߵ�-1�����н���⣬��������������Ҫ�ȱ���һ���ñ��ʵ�ʽڵ���
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