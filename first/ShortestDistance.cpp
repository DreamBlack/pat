#include<stdio.h>
#include<climits>
#include<cmath>
using namespace std;
int length[100001];
int oneToEach[100001];
int main(){
	/*
	题目大意：简单模拟。所有结点连起来会形成一个环形。给出几对点，求各对顶点路径的最小值。
	解题思路：这题居然浪费了这么久简直不可理喻。。
	1、开始对每一对顶点使用从a到b，再计算从b到a的距离，复杂度为N,导致超时
	2、其实只要算出送a到b的距离，用整个环的总距离再减去a到b的距离就是b到a的距离了，我在那儿瞎捣鼓半天也没弄出来
	*/
	int n;
	scanf("%d",&n);
	int count=0;
	for(int i=1;i<n+1;i++){
		scanf("%d",&(length[i]));
		oneToEach[i]=count;
		count=count+length[i];
	}
	int totalLength=oneToEach[n]+length[n];
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int s,d;
		scanf("%d%d",&s,&d);
		int min=(abs(oneToEach[s]-oneToEach[d])>totalLength-abs(oneToEach[s]-oneToEach[d]))?totalLength-abs(oneToEach[s]-oneToEach[d]):abs(oneToEach[s]-oneToEach[d]);
		if(s==d){
			printf("%d\n",0);
		}else{
			printf("%d\n",min);
		}
	}
	return 0;
}