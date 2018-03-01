#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
struct Node{
	int key;
	Node* left;
	Node* right;
};

Node* leftRotate(Node*root){//��������������µĸ�
	Node*t=root->right;
	root->right=t->left;
	t->left=root;
	return t;
}
Node* rightRotate(Node* root){
	Node*t=root->left;
	root->left=t->right;
	t->right=root;
	return t;
}
Node* leftRightRotate(Node* root){//����˫����ͬ���������������������ø�����
	root->left=leftRotate(root->left);
	return rightRotate(root);
}
Node* rightLeftRotate(Node* root){
	root->right=rightRotate(root->right);
	return leftRotate(root);
}
int getHeight(Node* r){
	if(r==NULL){
		return 0;
	}
	int left=getHeight(r->left);
	int right=getHeight(r->right);
	return(left>right)?left+1:right+1;
}
Node* insert(Node* root,int key){//���ز���������㣬�����ݹ������ʱ��ոհ�����½ڵ�����Ӧ��������������������Ҳ��֤��ֻ�ڿսڵ㴦����
	//���ص��ǲ�����µĽڵ�֮����������¸�
	if(root==NULL){
		root=new Node();
		root->key=key;
		root->left=NULL;
		root->right=NULL;
	}else{
		if(key<root->key){
			root->left=insert(root->left,key);//�Ե�ǰroot��������Ϊ�����룬���ص����µ��������ĸ�
			//ÿ�β���һ���ڵ��ʱ��Ϳ��Ƿ�ƽ�⣬����˳��պ��ǵݹ���õ�˳�򣬸�ջ������ͬ
			if(getHeight(root->left)-getHeight(root->right)==2){//����߲���ֻ������߱��,��Ҫ������ǰ�ڵ�Ϊ������������������������µĸ�
				//����µ��������ĸ�ֵ�Ȳ����key��֤���µĽڵ�����˵�ǰ��������������������Ҫ������
				//�µ��������ĸ�ֵ�Ȳ����keyС��֤���µĽڵ�����˵�ǰ�ڵ������������������
				root=(key<root->left->key)?rightRotate(root):leftRightRotate(root);
			}
		}else{
			root->right=insert(root->right,key);
			if(getHeight(root->left)-getHeight(root->right)==-2){//����߲���ֻ������߱��,��Ҫ������ǰ�ڵ�Ϊ������������������������µĸ�
				root=(key>root->right->key)?leftRotate(root):rightLeftRotate(root);
			}
		}
	}
	return root;
}
int main(){
	/*
	��Ŀ���⣺����ƽ�����Ĳ��롣
	����˼·�����ȷʵ��̫�ᡣ
	1�����úõݹ顣
	2����Ϊÿ�������ϲ���֮�����ĸ��ڵ㶼���ܻ�仯��
	*/

	int n;
	scanf("%d",&n);
	Node* root=NULL;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		root=insert(root,t);
	}
	printf("%d",root->key);
	return 0;
}