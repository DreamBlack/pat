#include<stdio.h>
#include<algorithm>
using namespace std;
int coins[100000];
int main(){
	/*
	��Ŀ���⣺����n����������һ��������m����n���������Ƿ����һ������a��b(a <= b),ʹa+b=m����������ж�������a��С����һ�ԡ�
	����˼·��
	����������Ȼ��˫ָ�뷨
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&(coins[i]));
	}
	sort(coins,coins+n);
	int i=0,j=n-1;
	bool isSlvd=false;
	while(i<j){
		if(coins[i]+coins[j]>m){
			j--;
		}else if(coins[i]+coins[j]<m){
			i++;
		}else{
			isSlvd=true;
			break;
		}
	}
	if(isSlvd){
		printf("%d %d",coins[i],coins[j]);
	}else{
		printf("No Solution");
	}
	return 0;
}