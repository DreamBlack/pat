#include <stdio.h>
int postOrder[30];
int inOrder[30];
int levelOrder[30];
int level[30];
int n;
int c=0;
void levelOrdered(int now,int from1,int end1,int from2,int end2,int l){
	/*
	now:当前处理的子树的根结点在后序遍历数组中的下标
	from1,end1:当前处理的子树上所有结点在后序遍历数组中所在位置
	from2,end2:当前处理的子树上所有结点在中序遍历数组中所在位置
	l:当前子树的根结点所在层数
	注意退出递归条件为，子树中只有一个结点或，不满足from<end
	*/
	if(from1>end1||from2>end2){
		return;
	}
	if(from1==end1||from2==end2){
		levelOrder[c]=postOrder[from1];
		level[c++]=l;
		return;
	}
	int index=0;
	//找到子树根在中序遍历中位置，以划分左子树右子树，同时记录根
	for(int i=from2;i<=end2;i++){
		if(inOrder[i]==postOrder[now]){
			index=i;
			break;
		}
	}
	levelOrder[c]=inOrder[index];
	level[c++]=l;
	levelOrdered(from1+index-from2-1,from1,from1+index-from2-1,from2,index-1,l+1);
	levelOrdered(end1-1,from1+index-from2,end1-1,index+1,end2,l+1);

}
int main(){
	/*
	题目大意：给定一棵二叉树的后序遍历和中序遍历，请你输出其层序遍历的序列。这里假设键值都是互不相等的正整数。

	解题：神奇了。每次做树的题，总是一次提交就成功。
	就按中序后序构造二叉树的算法来，为了得到每个结点所在的层次号，递归同时将深度传递下去。
	最后遍历数组按记录的深度递增输出（由于递归的时候总是先处理左子树再处理右子树，所以能保证总是左子树在右子树的前面，与层次遍历
	的时候左右子树位置一致）
	*/
	//初始化
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",postOrder+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",inOrder+i);
	}
	//开始处理
	levelOrdered(n-1,0,n-1,0,n-1,0);
	int l=0,cnt=0;
	while(cnt<n){
		for(int j=0;j<n;j++){
			if(level[j]==l){
				postOrder[cnt++]=levelOrder[j];
			}
			if(cnt==n){
				break;
			}
		}
		l++;
	}
	for(int i=0;i<n-1;i++){
		printf("%d ",postOrder[i]);
	}
	printf("%d",postOrder[n-1]);
	return 0;
}