#include<stdio.h>
#include<stack>
using namespace std;
int preorder[31];
int inorder[31];
int n;
stack<int> postorder;
void inpreToPost(int prei,int prej,int ini,int inj){
	if(prei>prej||ini>inj)return;
	if(prei==prej||ini==inj){
		postorder.push(inorder[ini]);
		return;
	}
	int root=preorder[prei];
	int i=ini;//i为根在中序中的位置
	for(;i<=inj;i++){
		if(inorder[i]==root){
			break;
		}
	}
	postorder.push(root);
	inpreToPost(prej-(inj-i)+1,prej,i+1,inj);
	inpreToPost(prei+1,prei+i-ini,ini,i-1);
}
int main(){

	/*
	题目大意：用栈的形式给出一棵二叉树的建立的顺序，求这棵二叉树的后序遍历
	解题思路：
	1、乍一看完全没有思路，其实栈实现非递归二叉树的中序遍历，push的元素顺序是二叉树的前序遍历，出栈的顺序是二叉树的中序遍历
	2、所以该题可以用二叉树前序和中序转后序的方法做
	*/
	scanf("%d",&n);
	stack<int> ino;
	int cnti=1,cntp=1;
	for(int i=0;i<n*2;i++){
		char op[8];
		scanf("%s",op);
		if(op[1]=='o'){//pop的顺序就是中序
			inorder[cnti++]=ino.top();
			ino.pop();
		}else{//push的顺序就是前序
			int t;
			scanf("%d",&t);
			ino.push(t);
			preorder[cntp++]=t;
		}
	}
	inpreToPost(1,n,1,n);
	while(!postorder.empty()){
		if(postorder.size()>1){
			printf("%d ",postorder.top());
			postorder.pop();
		}else{
			printf("%d",postorder.top());
			postorder.pop();
		}
	}
	return 0;
}