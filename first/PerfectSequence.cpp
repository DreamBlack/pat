#include<stdio.h>
#include<algorithm>
using namespace std;
long long int num[100000];
int maxn=0;
long long int n,p;
int main(){
	/*
	��Ŀ���⣺����һ�����������У���������p������������е����ֵ��M����Сֵ��m�����M <= m * p���������������������С�
	���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С������һ�и�������������N�����������ĸ�������p
	�������Ĳ��������ڶ��и���N������������һ�������������ѡ����ٸ����������������һ����������
	����˼·��
	1��һ��ʼ�ѹ�ʽ��д����p>=M/m;�����̶�p���ҷ���������M��m.�����������²�֪����ô�Ż�
	2����ʵ������Ϊ�����Ӷ���i��0��n-1����ÿһ��iѰ�ҵ�һ����m*p�����������Ϊ���Ǹ�����m*p����һ������������������һ����m*p�������ǰ���Ǹ�
	�϶��������Ŀ��ܵ�M��
	3��������Ҫע�����m*p���ܳ���Int��Χ��Ӧ��ʹ��long long int
	4�����߿���ʹ��˫ָ�뷨
	���Ƚ����д�С���������赱ǰ���Ϊresult = 0����ǰ�����Ϊtemp = 0����i = 0��n��j��i + result��n��
	����Ϊ��Ϊ��������result��������һ��jֻҪ��i��result�����濪ʼ�Ҿ����ˡ�ÿ�μ���temp������result�����result��������result��ֵ��
	*/
	scanf("%lld%lld",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%lld",num+i);
	}
	sort(num,num+n);
	
	for(int i=0;i<n;i++){
		long long int q=num[i]*p;
		int tmplength=distance(num+i,upper_bound(num,num+n,q)-1)+1;
		if(tmplength>maxn){
			maxn=tmplength;
		}
	}
	printf("%d",maxn);		
	return 0;
}