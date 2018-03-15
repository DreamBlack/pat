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
	if(root==NULL){//树为空
		root=new Node();
		root->left=NULL;
		root->right=NULL;
		root->key=key;
	}else{
		if(key<root->key){//在左子树上插入
			root->left=insert(root->left,key);//在左子树上插入而不是root上插入
			if(getHeight(root->left)-getHeight(root->right)==2){//需要旋转
				root=(key<root->left->key)?rightRotate(root):leftRightRotate(root);//是和root左子树上的key比较
			}
		}else{//在右子树上插入
			root->right=insert(root->right,key);
			if(getHeight(root->left)-getHeight(root->right)==-2){//需要旋转
				root=(key>root->right->key)?leftRotate(root):rightLeftRotate(root);
			}
		}
	}
	return root;
}
int main(){
	/*
	题目大意：给一串数，按序插入AVL树，输出最后树的层次遍历并判断其是否是完全二叉树
	解题思路：
	1、一个是AVL树的插入
	2、完全二叉树的判断：1、如果出现一个孩子数少于2的结点后，又出现有孩子的结点，或者有一个节点没有左孩子但是有右孩子则不是完全树
	*/
	int n;
	scanf("%d",&n);
	Node* root=NULL;
	for(int i=0;i<n;i++){
		int key;
		scanf("%d",&key);
		root=insert(root,key);
	}
	//树插入好，进行层次遍历
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
		if(now->left==NULL||now->right==NULL){//出现了孩子结点少于二的节点
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