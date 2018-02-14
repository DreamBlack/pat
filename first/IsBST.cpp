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
	��Ŀ���⣺����һ��������ֵ���У��������д�����ж����Ƿ��Ƕ�һ�ö������������侵�����ǰ������Ľ����
	���ǣ�������������Ľ��
	����˼·��
	1��һ��ʼû����������һ��BST������������ǵ������ߵݼ��ġ��˷��˰�Сʱ
	2�����1֮������ʵ���Ǹ���ǰ�����������ı��Ρ��ȼ��費��mirror���ݹ飨ע���ȵݹ��ұ��ٵݹ���ߣ��պ�ջ����ջ�ľ���
	�������У�����ջ����Ĵ�С�ͽڵ������ȣ�������mirror�ٵݹ飨��ʱ���������и�Ϊ����root��Ϊ���һ�����ҵ��ģ�
	3���ύ֮��һ�������ԡ����֣�YES��д����Yes,NOд����No��
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