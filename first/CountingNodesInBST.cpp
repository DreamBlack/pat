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
	题目大意：输出一个二叉搜索树的最后两层结点个数a和b，以及他们的和c：“a + b = c”
	解题思路：用链表存储，递归构建二叉搜索树，深度优先搜索，传入的参数为结点和当前结点的深度depth，如果当前结点为NULL就更新最大深度
	maxdepth的值并return，将每一层所对应的结点个数存储在数组num中，输出数组的最后两个的值~~~~
	注意：
	1、使用Node*指针时候必须使用new，并且不要用&否则会始终指向最后修改的那个元素
	2、计算每层结点的个数，cnt++必须写在入队的时候，否则会把最后一层的漏掉
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