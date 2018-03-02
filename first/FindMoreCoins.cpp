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
	题目大意：用n个硬币买价值为m的东西，输出使用方案，使得正好几个硬币加起来价值为m。从小到大排列，输出最小的那个排列方案
	1、属于典型的背包问题.  用动态规划(dp)做, 假设F(N, M)表示不超过面值M, 而且从前面N个硬币中挑选硬币值能得到的最大硬币面值总和, 那我们可以
	得到如下递归公式：F(N, M) = max{ F(N–1, M), F(N–1, M–c(N)) + c(N) }，c(N)表示第N个硬币的面值
	那么最后要是F(N, M)  == M， 那么就说明我们可以找到这样一组硬币, 使得他们的面值总和恰好等于M。 
	2、记录路径：若has(N, M)为真, 则表示从前面N个硬币中选出一组得到最多的不超过M的币值总和里面包括了第N个硬币。那么如果我们需要找到完整路径,
	我们就可以从N、M出发，一直回溯到最后一个硬币。
	解题思路：
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		coins[i]=t;
	}
	sort(coins+1,coins+n+1,cmp);

	for(int i=1;i<=n;i++){//背包容量为j，从1-i个物品中选择部分放入背包的时候，得到的最大容量
		for(int j=1;j<=m;j++){
			if(j<coins[i]||dp[i-1][j-coins[i]]+coins[i]<dp[i-1][j])//j<num[i]，说明只能从前i-1个里面找满足不大于j的最大数额  
				dp[i][j]=dp[i-1][j];  
			else{  
				dp[i][j]=dp[i-1][j-coins[i]]+coins[i];  
				put[i][j]=true;  

			}  
		}
	}
	if(dp[n][m]!=m){
		printf("No Solution");//没有
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