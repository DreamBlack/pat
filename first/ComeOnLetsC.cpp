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
	��Ŀ���⣺����Ҫ���������ÿ����ѯͬѧ�Ķ�Ӧ�Ľ�����
	����˼·���ܼ򵥵���
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
		if(!exist[tmpid]){//������������
			printf("%04d: Are you kidding?\n",tmpid);
		}else{//��������
			if(isquery[tmpid]){//֮ǰ�Ѿ���ѯ��
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