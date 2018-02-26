#include<stdio.h>
#include<vector>
#include<climits>
using namespace std;
struct Pair{
	int i;
	int j;
};
int diamonds[100001];
vector<Pair> ways;
int main(){
	/*
	题目大意:求一串的数字中连续的一段，使得这个连续的段内数字的和恰好等于所期望的值m。
	如果不能找到恰好等于，就找让自己付出最少的价格（总和必须大于等于所给值）的那段区间。求所有可能的结果。
	解题思路：
	这题用了超级长的时间，最后自己写的代码虽然没有超时，但是有一个7分的测试点没过，不知道为啥。
	感觉不知道是不是很久没写了，脑袋里有了初步的想法之后落实到代码里特别烂。直到看了人家跟自己同思路的解答，
	才把这个代码的逻辑搞得清晰点。
	1、我的思路是从第一个到第n个元素，维持一个窗口，以及窗口内总数，如果总数比m小，则使j++；比m大，使i++；
	等于m，i++,j++这样。同时更新窗口内总数

	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int a=1;a<=n;a++){
		scanf("%d",&(diamonds[a]));
	}
	int nowTotal=0,vectorTotal=INT_MAX;
	int i=1,j=0;
	while(j<=n){
		if(nowTotal<m){
			nowTotal+=diamonds[++j];
		}else {
			if(nowTotal<vectorTotal){
				ways.clear();
				Pair p={i,j};
				ways.push_back(p);
				vectorTotal=nowTotal;
			}else if(nowTotal==vectorTotal){
				Pair p={i,j};
				ways.push_back(p);
			}
			if(nowTotal==m){
				nowTotal=nowTotal-diamonds[i]+diamonds[++j];
				i++;
			}else{
				nowTotal=nowTotal-diamonds[i];
				i++;
			}
		}
	}
	for(int i=0;i<ways.size();i++){
		printf("%d-%d",ways[i].i,ways[i].j);
		if(i!=ways.size()-1){
			printf("\n");
		}
	}
	return 0;
}