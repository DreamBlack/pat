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
	��Ŀ���⣺��һ������ȥ�أ�ȥ��ֵ���߾���ֵ��ȵģ��������ɾ��������������ɾ���˵�����
	����˼·��
	1��������ȫ���ȱ���һ������ȥ�����ýڵ�
	2��������ŵ�ʱ����Բ�Ҫ���Ÿ�ÿ������nextָ�룬ֻ����vector����洢���ɣ������ʱ�����next��ַѡ��vector��һԪ�صĵ�ַ����
	3���þ���ֵ����Ҫ#include<stdlib.h>��vector.size()������vector�Ƿ�Ϊ�գ���֮ǰҪ���������δ���
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
		if(book[abs(intial[i].key)]==0){//��һ�γ���
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
