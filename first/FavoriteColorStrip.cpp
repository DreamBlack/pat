#include<stdio.h>
int evas[201];
int given[10000];
int givenLength[10000];
int d[201][10001];
int n,m,l;
int maxLength=1;
int cnt=0;
int findMax(int k){

	int max=-1,maxindex=-1;;
	for(int j=k;j>=0;j--){
		if(given[j]<=given[k]&&givenLength[j]>max){
			max=givenLength[j];
			maxindex=j;
		}
	}
	return max;
}
int subSequence(){
	//将序列b(0,j)变为b(1,j+1)
	for(int i=cnt;i>=1;i--){
		given[i]=given[i-1];
	}
	int max=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt;j++){
			if(evas[i]==evas[j]){
				d[i][j]=d[i-1][j-1]+1;
			}else{
				d[i][j]=(d[i-1][j]>d[i][j-1])?(d[i-1][j]):(d[i][j-1]);
			}
			if(max<d[i][j]){
				max=d[i][j];
			}
		}
	}
	return max;
}
int main(){
	/*
	题目大意：给出m中颜色作为喜欢的颜色（同时也给出顺序），然后给出一串长度为L的颜色序列，现在要去掉这个序列中的不喜欢的颜色，
	然后求剩下序列的一个子序列，使得这个子序列表示的颜色顺序符合自己喜欢的颜色的顺序，不一定要所有喜欢的颜色都出现。
	解题思路：这题一看就不是普通办法可以解决的。直觉告诉我是动态规划，实在想不出来，看了下题解
	1、对于给定的颜色序列中，如果我evas不喜欢的序列完全可以剔除；由于题目有一定的顺序要求，可以将evas喜欢的颜色序列编号
	2、解决了1之后，这其实就是最长递增子序列或者看成是最长公共子序列的问题（子序列不需要连着，子串需要连着）
	3、我自己实现了最长递增子序列的动态规划法。主要是从0到given中第j个元素里，以j为结尾的最长递增子序列，一定是0~j-1中，可以排在j之前且以其为
	结尾的最长序列加1（此处要注意，如果没有找到满足之前要求的，应使j对于最长序列长度为1，一开始没有写好这一点，导致一个3分的点没有过）
	4、由这个3的思路，得到了动态规划的思路。（将带求解问题分解为子问题，记录各子问题的答案，根据子问题得到新问题的解答）
	动态规划算法与分治法类似，其基本思想也是将待求解问题分解成若干个子问题，先求解子问题，然后从这些子问题的解得到原问题的解.
	与分治法不同的是，适合于用动态规划求解的问题，经分解得到子问题往往不是互相独立的。
	若用分治法来解这类问题，则分解得到的子问题数目太多，有些子问题被重复计算了很多次。
	如果我们能够保存已解决的子问题的答案，而在需要时再找出已求得的答案，这样就可以避免大量的重复计算，节省时间。
	我们可以用一个表来记录所有已解的子问题的答案。不管该子问题以后是否被用到，只要它被计算过，就将其结果填入表中。这就是动态规划法的基本思路。
	5、还有一种是对于最长公共子序列的解法。对于序列a(1~k),b(1-m)该算法用d[i][j]表示序列a[0~i]和序列b[0~j]的最长公共子序列的长度。
	若i=0或j=0，则d[i][j]=0;
	若a[i]=b[j],d[i][j]=d[i-1][j-1]+1；若a[i]!=b[j],d[i][j]=max(d[i][j-1],d[i-1][j]);
	其中i=0,j=0时用来辅助计算
	*/
	
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int c;
		scanf("%d",&c);
		evas[c]=i;
	}
	scanf("%d",&l);
	
	for(int i=0;i<l;i++){
		int now;
		scanf("%d",&now);
		if(evas[now]!=0){
			given[cnt++]=evas[now];
		}
	}
	givenLength[0]=1;
	for(int i=1;i<cnt;i++){
		int k=findMax(i);
		if(k!=-1){
			givenLength[i]=k+1;
			if(givenLength[i]>maxLength){
				maxLength=givenLength[i];
			}
		}else{
			givenLength[i]=1;
		}
		
	}
	printf("%d\n",maxLength);
	return 0;
}