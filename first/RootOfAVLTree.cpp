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

Node* leftRotate(Node*root){//返回这棵子树的新的根
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
Node* leftRightRotate(Node* root){//左右双旋等同于先让左子树左旋，再让跟右旋
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
Node* insert(Node* root,int key){//返回插入的这个结点，这样递归回来的时候刚刚把这个新节点插入对应的左子树或者右子树。也保证了只在空节点处插入
	//返回的是插入好新的节点之后这棵树的新根
	if(root==NULL){
		root=new Node();
		root->key=key;
		root->left=NULL;
		root->right=NULL;
	}else{
		if(key<root->key){
			root->left=insert(root->left,key);//以当前root的左子树为根插入，返回的是新的左子树的根
			//每次插入一个节点的时候就看是否平衡，看的顺序刚好是递归调用的顺序，跟栈作用相同
			if(getHeight(root->left)-getHeight(root->right)==2){//在左边插入只可能左边变高,需要调整当前节点为根的子树，返回这棵子树的新的根
				//如果新的左子树的根值比插入的key大，证明新的节点插在了当前结点的左子树的左子树上要右旋；
				//新的左子树的根值比插入的key小，证明新的节点插在了当前节点的右子树的右子树上
				root=(key<root->left->key)?rightRotate(root):leftRightRotate(root);
			}
		}else{
			root->right=insert(root->right,key);
			if(getHeight(root->left)-getHeight(root->right)==-2){//在左边插入只可能左边变高,需要调整当前节点为根的子树，返回这棵子树的新的根
				root=(key>root->right->key)?leftRotate(root):rightLeftRotate(root);
			}
		}
	}
	return root;
}
int main(){
	/*
	题目大意：二叉平衡树的插入。
	解题思路：这个确实不太会。
	1、利用好递归。
	2、因为每次在树上插入之后，树的根节点都可能会变化。
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