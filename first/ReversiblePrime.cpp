#include <stdio.h>
#include<cmath>
#include "string"
using namespace std;
bool isPrime(int n){
	if(n==1) return false;
	for(int i=2;i<n-1;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int radixTras(int num,int d){
	//��numת��Ϊd���ƣ����䷴ת����ת��Ϊʮ���Ʒ���
	//����Ҫע�����1��������pow������cmath����
	if(num==1) return 1;
	if(d<=1)return -1;
	int s=num,m,i=0;
	int arr[100];
	while(s!=0){
		m=s%d;
		s=s/d;

		arr[i++]=m;
	}
	int result=0;
	for(int j=0;j<i;j++){
		result=result+arr[j]*(int)(pow((double)d,i-j-1));
	}
	return result;
}
int main(){
	int n,d,r;
	scanf("%d",&n);
	bool isprime=false;
	while(n>0){
		scanf("%d",&d);
		isprime=isPrime(n);
		if(!isprime){
			printf("No\n");
		}else{
			r=radixTras(n,d);
			isprime=isPrime(r);
			if(!isprime){
				printf("No\n");
			}else{
				printf("Yes\n");
			}
		}

		scanf("%d",&n);
	}
	return 0;
}



