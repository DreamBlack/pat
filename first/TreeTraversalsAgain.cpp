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
	int i=ini;//iΪ���������е�λ��
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
	��Ŀ���⣺��ջ����ʽ����һ�ö������Ľ�����˳������ö������ĺ������
	����˼·��
	1��էһ����ȫû��˼·����ʵջʵ�ַǵݹ�����������������push��Ԫ��˳���Ƕ�������ǰ���������ջ��˳���Ƕ��������������
	2�����Ը�������ö�����ǰ�������ת����ķ�����
	*/
	scanf("%d",&n);
	stack<int> ino;
	int cnti=1,cntp=1;
	for(int i=0;i<n*2;i++){
		char op[8];
		scanf("%s",op);
		if(op[1]=='o'){//pop��˳���������
			inorder[cnti++]=ino.top();
			ino.pop();
		}else{//push��˳�����ǰ��
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