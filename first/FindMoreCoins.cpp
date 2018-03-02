#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int coins[10001];
int dp[10001][101];
bool put[10001][101];

bool cmp(int i,int j){
	return(i>j)?true:false;
}
int main(){
	/*
	��Ŀ���⣺��n��Ӳ�����ֵΪm�Ķ��������ʹ�÷�����ʹ�����ü���Ӳ�Ҽ�������ֵΪm����С�������У������С���Ǹ����з���
	1�����ڵ��͵ı�������.  �ö�̬�滮(dp)��, ����F(N, M)��ʾ��������ֵM, ���Ҵ�ǰ��N��Ӳ������ѡӲ��ֵ�ܵõ������Ӳ����ֵ�ܺ�, �����ǿ���
	�õ����µݹ鹫ʽ��F(N, M) = max{ F(N�C1, M), F(N�C1, M�Cc(N)) + c(N) }��c(N)��ʾ��N��Ӳ�ҵ���ֵ
	��ô���Ҫ��F(N, M)  == M�� ��ô��˵�����ǿ����ҵ�����һ��Ӳ��, ʹ�����ǵ���ֵ�ܺ�ǡ�õ���M�� 
	2����¼·������has(N, M)Ϊ��, ���ʾ��ǰ��N��Ӳ����ѡ��һ��õ����Ĳ�����M�ı�ֵ�ܺ���������˵�N��Ӳ�ҡ���ô���������Ҫ�ҵ�����·��,
	���ǾͿ��Դ�N��M������һֱ���ݵ����һ��Ӳ�ҡ�
	����˼·��
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		coins[i]=t;
	}
	sort(coins+1,coins+n+1,cmp);

	for(int i=1;i<=n;i++){//��������Ϊj����1-i����Ʒ��ѡ�񲿷ַ��뱳����ʱ�򣬵õ����������
		for(int j=1;j<=m;j++){
			if(j<coins[i]||dp[i-1][j-coins[i]]+coins[i]<dp[i-1][j])//j<num[i]��˵��ֻ�ܴ�ǰi-1�����������㲻����j���������  
				dp[i][j]=dp[i-1][j];  
			else{  
				dp[i][j]=dp[i-1][j-coins[i]]+coins[i];  
				put[i][j]=true;  

			}  
		}
	}
	if(dp[n][m]!=m){
		printf("No Solution");//û��
	}else{
		vector<int> res;
		int i=n,j=m;
		while(j!=0){
			while(!put[i][j]){
				i--;
			}
			j=j-coins[i];
			res.push_back(coins[i]);
			i--;
		}
		for(int i=0;i<res.size();i++){
			printf("%d",res[i]);
			if(i!=res.size()-1){
				printf(" ");
			}
		}
	}
	return 0;
}