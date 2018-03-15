#include<stdio.h>
#include<queue>
using namespace std;
int nodes[100];

struct Node{
	int key;
	Node *left,*right;
};
int getHeight(Node* root){
	if(root==NULL){
		return 0;
	}else{
		int left=getHeight(root->left);
		int right=getHeight(root->right);
		return (left>right)?left+1:right+1;
	}
}
Node* leftRotate(Node* root){
	Node*tmp=root->right;
	root->right=tmp->left;
	tmp->left=root;
	return tmp;
}
Node* rightRotate(Node* root){
	Node*tmp=root->left;
	root->left=tmp->right;
	tmp->right=root;
	return tmp;
}
Node* leftRightRotate(Node* root){
	root->left=leftRotate(root->left);
	return rightRotate(root);
}
Node* rightLeftRotate(Node* root){
	root->right=rightRotate(root->right);
	return leftRotate(root);
}
Node* insert(Node* root,int key){
	if(root==NULL){//��Ϊ��
		root=new Node();
		root->left=NULL;
		root->right=NULL;
		root->key=key;
	}else{
		if(key<root->key){//���������ϲ���
			root->left=insert(root->left,key);//���������ϲ��������root�ϲ���
			if(getHeight(root->left)-getHeight(root->right)==2){//��Ҫ��ת
				root=(key<root->left->key)?rightRotate(root):leftRightRotate(root);//�Ǻ�root�������ϵ�key�Ƚ�
			}
		}else{//���������ϲ���
			root->right=insert(root->right,key);
			if(getHeight(root->left)-getHeight(root->right)==-2){//��Ҫ��ת
				root=(key>root->right->key)?leftRotate(root):rightLeftRotate(root);
			}
		}
	}
	return root;
}
int main(){
	/*
	��Ŀ���⣺��һ�������������AVL�������������Ĳ�α������ж����Ƿ�����ȫ������
	����˼·��
	1��һ����AVL���Ĳ���
	2����ȫ���������жϣ�1���������һ������������2�Ľ����ֳ����к��ӵĽ�㣬������һ���ڵ�û�����ӵ������Һ���������ȫ��
	*/
	int n;
	scanf("%d",&n);
	Node* root=NULL;
	for(int i=0;i<n;i++){
		int key;
		scanf("%d",&key);
		root=insert(root,key);
	}
	//������ã����в�α���
	queue<Node*>q;
	q.push(root);
	nodes[1]=root->key;
	int cnt=1;
	bool flag=true,isexist=false;
	while(!q.empty()){
		Node* now=q.front();
		q.pop();
		nodes[cnt++]=now->key;
		if(isexist&&(now->left!=NULL||now->right!=NULL)){
			flag=false;
		}
		if(now->left==NULL||now->right==NULL){//�����˺��ӽ�����ڶ��Ľڵ�
			isexist=true;
		}
		if(now->left==NULL&&now->right!=NULL){
			flag=false;
		}
		if(now->left!=NULL){
			q.push(now->left);
		}
		if(now->right!=NULL){
			q.push(now->right);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",nodes[i]);
		if(i!=n){
			printf(" ");
		}
	}
	if(flag){
		printf("\nYES");
	}else{
		printf("\nNO");
	}
	return 0;
}