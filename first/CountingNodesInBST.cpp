#include<stdio.h>
#include<queue>
#include<map>
using namespace std;
struct Node{
	int key;
	Node*left,*right;
};
Node*root;
Node* find(int x,Node*now){
	if(x>now->key){
		if(now->right!=NULL){
			return find(x,now->right);
		}else{
			return now;
		}
	}else{
		if(now->left!=NULL){
			return find(x,now->left);
		}else{
			return now;
		}
	}
}
int main(){
	/*
	��Ŀ���⣺���һ��������������������������a��b���Լ����ǵĺ�c����a + b = c��
	����˼·��������洢���ݹ鹹�������������������������������Ĳ���Ϊ���͵�ǰ�������depth�������ǰ���ΪNULL�͸���������
	maxdepth��ֵ��return����ÿһ������Ӧ�Ľ������洢������num�У������������������ֵ~~~~
	ע�⣺
	1��ʹ��Node*ָ��ʱ�����ʹ��new�����Ҳ�Ҫ��&�����ʼ��ָ������޸ĵ��Ǹ�Ԫ��
	2������ÿ����ĸ�����cnt++����д����ӵ�ʱ�򣬷��������һ���©��
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		Node* t=new Node();
		t->key=tmp;
		t->left=NULL;
		t->right=NULL;
		if(i==0){
			root=t;
		}else{
			Node* inse=find(tmp,root);
			if(tmp<=inse->key){
				inse->left=t;
			}else{
				inse->right=t;
			}
		}
	}
	map<int,int>m;
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	int level=0,nownum=0;
	m[0]=1;
	level++;
	while(!q.empty()){
		Node* now=q.front();
		q.pop();
		if(now!=NULL){
			if(now->left!=NULL){
				q.push(now->left);
				nownum++;
			}
			if(now->right!=NULL){
				q.push(now->right);
				nownum++;
			}
		}else{
			if(!q.empty()){
				m[level]=nownum;
				level++;
				nownum=0;
				q.push(NULL);
			}
		}
	}
	if(m.size()==1){
		printf("1 + 0 = 1");
	}else{
		auto it=m.end();
		it--;
		auto it2=it--;
		printf("%d + %d = %d",it2->second,it->second,it->second+it2->second);
	}
	return 0;
}