#include<stdio.h>
bool exist[10001];
bool isquery[10001];
int num[10001];
bool isPrime(int a){
	if(a==2)return true;
	for(int i=2;i<a;i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	/*
	题目大意：题意要求我们输出每个问询同学的对应的奖励。
	解题思路：很简单的题
	*/
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		num[tmp]=i;
		exist[tmp]=true;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int tmpid;
		scanf("%d",&tmpid);
		if(!exist[tmpid]){//不存在排名中
			printf("%04d: Are you kidding?\n",tmpid);
		}else{//排名中有
			if(isquery[tmpid]){//之前已经查询过
				printf("%04d: Checked\n",tmpid);
			}else{
				isquery[tmpid]=true;
				int rank=num[tmpid];
				if(rank==1){
					printf("%04d: Mystery Award\n",tmpid);
				}else if(isPrime(rank)){
					printf("%04d: Minion\n",tmpid);
				}else{
					printf("%04d: Chocolate\n",tmpid);
				}
			}
		}
	}
	return 0;
}