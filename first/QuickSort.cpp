#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int sorted[100000];
int num[100000];
int main(){
	/*
	题目大意：快速排序中，我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。
	给定划分后的N个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？
	解题思路：
	1、初始解法，对于Num[i]，只有它在已排序元素中位置和中间排序中的位置相同的时候才可能是privot。并且当i左边的元素都比它小，右边的元素
	都比他大的时候才是主元素。
	2、使用1时，两个测试点超时，一个测试点错误。错误的点经验证是当满足条件的点只有0个时，此时输出应该为0\n\n而不仅仅是0
	3、为解决超时问题。1换句话说就是，i在0到i个元素中是最大值并且i同已排序中i位置上元素相同，这样就能保证i同时是后面n-i个元素中的最小值

	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		num[i]=tmp;
		sorted[i]=tmp;
	}
	sort(sorted,sorted+n);
	int cnt=n;
	vector<int>last;
	int max=0;
	for(int i=0;i<n;i++){
		if(num[i]==sorted[i]&&num[i]>max){//如果num[i]比之前的最大值还大的话，证明i之前的元素都没有当前元素大
			last.push_back(num[i]);
		}
		if(num[i]>max){//但是找最大值不能包含在上面那个if里面，否则max不能始终保持是max
			max=num[i];
		}

	}
	if(!last.empty()){
		printf("%d\n",last.size());
		for(int i=0;i<last.size();i++){
			printf("%d",last[i]);
			if(i!=last.size()-1){
				printf(" ");
			}
		}
	}else{
		printf("0\n\n");
	}
	return 0;
}