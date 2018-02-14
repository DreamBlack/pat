#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
int prenodes[1000];
int innodes[1000];
stack<int> postOrd;
bool isTree;
bool cmp(int a,int b){
	return (a>b)?true:false;
}
void postOrder(bool mirror,int prehead,int pretail,int inhead,int intail){
	if(!isTree) return;
	if(prehead>pretail||inhead>intail) return;
	if(inhead==intail||prehead==pretail) {
		if(innodes[inhead]==prenodes[prehead]){
			postOrd.push(innodes[inhead]);
		}else{
			isTree=false;
		}
		return;
	}
	int root=prenodes[prehead];
	postOrd.push(root);
	int i=inhead;
	if(!mirror){
		for(;i<=intail;i++){
			if(innodes[i]==root){break;}
		}
	}else{
		int temp=i;
		for(;i<=intail;i++){
			if(innodes[i]==root){temp=i;}
		}
		i=temp;
	}

	if(innodes[i]!=root){
		isTree=false;
		return;
	}
	postOrder(mirror,prehead+i-inhead+1,pretail,i+1,intail);
	postOrder(mirror,prehead+1,prehead+i-inhead,inhead,i-1);
}
int main(){
	/*
	题目大意：给定一个整数键值序列，现请你编写程序，判断这是否是对一棵二叉搜索树或其镜像进行前序遍历的结果。
	若是，输出其后序遍历的结果
	解题思路：
	1、一开始没想起来对于一棵BST，其中序遍历是递增或者递减的。浪费了半小时
	2、解决1之后这其实就是根据前序中序求后序的变形。先假设不是mirror，递归（注意先递归右边再递归左边，刚好栈最后出栈的就是
	后序序列）。若栈里面的大小和节点数不等，假设是mirror再递归（此时，中序序列改为降序，root改为最后一个查找到的）
	3、提交之后一个都不对。发现，YES被写成了Yes,NO写成了No。
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&(prenodes[i]));
		innodes[i]=prenodes[i];
	}
	sort(innodes,innodes+n);
	isTree=true;
	postOrder(false,0,n-1,0,n-1);
	if(postOrd.size()!=n||!isTree){
		while(!postOrd.empty()){
			postOrd.pop();
		}
		isTree=true;
		sort(innodes,innodes+n,cmp);
		postOrder(true,0,n-1,0,n-1);
	}
	if(isTree==false||postOrd.size()!=n){
		printf("NO");
	}else{
		printf("YES\n");
		while(!postOrd.empty()){
			printf("%d",postOrd.top());
			postOrd.pop();
			if(!postOrd.empty()){
				printf(" ");
			}
		}
	}

	return 0;
}