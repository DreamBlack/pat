#include<stdio.h>
#include<algorithm>
using namespace std;
long long int num[100000];
int main(){
	/*
	��Ŀ���⣺Ҫ���һ�����Ϸֳ��������ཻ�ļ��ϣ�ʹ�����������ϵ�Ԫ�ظ��������С��ǰ���£��������ϵ��ܺ�֮�����
	����˼·���ȰѼ�����n��Ԫ�����򣬼���ǰn/2��Ԫ�ص��ܺͣ�Ȼ�����ܵ��ܺ�sum �C 2 * halfsum��Ϊ |S1 �C S2|��
	|n1 �C n2|����n % 2�Ľ��������Ϊ1��ż��Ϊ0�����ܺ�sum��ֵ��ʵ�����������ʱ����ۼӵõ���~~~~
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",num+i);
	}
	sort(num,num+n);
	if(n%2==0){
		printf("0 ");
	}else{
		printf("1 ");
	}
	long long int sum1=0,sum2=0;
	for(int i=0;i<n/2;i++){
		sum1+=num[i];
	}
	for(int i=n/2;i<n;i++){
		sum2+=num[i];
	}
	printf("%lld",sum2-sum1);
	return 0;
}