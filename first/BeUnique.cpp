#include<stdio.h>
#include<climits>
int bets[10001];
int first[10001];
int main(){
	/*
	��Ŀ���⣺��n�����֣����ն���˳���ĸ������ǵ�һ��������������ֻ����һ�ε����֡�
	����������ֳ��ֶ�������һ�Σ������None
	����˼·��
	1��һ��ʼ�õ���O(n^2)���㷨����������ĳ�ʱ��
	2��Ϊ�������ٶȣ�ʹ��hash��ͬʱ����һ�������¼���ݵ�һ�γ��ֵ�ʱ�䣬������ɺ󣬱�����¼ʱ������飬�ҵ�������ֵ��Ǹ�
	3�����ѵĽⷨҲ��������һ�����飬�洢ÿ�����ֳ��ֵĴ�����Ȼ�����һ�������˳���Ƿ��г��ִ���Ϊ1������
	m[a[i]]++;��a[i]�����¼n�����֣�m��¼ÿ�����ֳ��ֵĴ�����
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int bet;
		scanf("%d",&bet);
		if(bets[bet]==0){
			first[bet]=i;
		}
		bets[bet]++;
	}
	int firstone=INT_MAX;
	int firstindex=-1;
	for(int i=1;i<10001;i++){
		if(bets[i]==1&&first[i]<firstone){
			firstone=first[i];
			firstindex=i;
		}
	}

	if(firstone!=INT_MAX){
		printf("%d",firstindex);

	}else{
		printf("None");
	}

	return 0;
}