#include<stdio.h>
#include<algorithm>
using namespace std;
int num1[101];
int num2[101];
void swap(int&a,int&b){
	int tmp=a;
	a=b;
	b=tmp;
}
void shiftUpToDown(int now,int end){
	if(now*2<=end){
		if(now*2+1>end){//没有右孩子
			if(num2[now]<num2[now*2]){
				swap(num2[now],num2[now*2]);
				shiftUpToDown(now*2,end);
			}
		}else{
			int max,lor;
			if(num2[now*2]<num2[now*2+1]){
				max=num2[now*2+1];
				lor=1;
			}else{
				lor=0;
				max=num2[now*2];
			}
			if(max>num2[now]){
				if(lor==0){
					swap(num2[now],num2[now*2]);
					shiftUpToDown(now*2,end);
				}else{
					swap(num2[now],num2[now*2+1]);
					shiftUpToDown(now*2+1,end);
				}
			}
		}
	}
}
int main(){
	/*
	题目大意：给出n和n个数的序列a和b，a为原始序列，b为排序其中的一个步骤，问b是a经过了堆排序还是插入排序的，并且输出它的下一步~~
	解题思路：
	1、对于插入排序跟之前那道题一个意思
	2、对于堆排序本来使用的是上次快排的方法，对原始序列做堆排序，没做一次跟中间数据对比结果超时了。后来网上说可以直接在中间序列
	从后往前找到第一个并未放到位置上的元素，将其放到表头进行一次自上而下调整即可。（即使在建堆的时候自下而上调整的时候也要用到自上而下
	才能保证堆的结构正确）。之后果然不超时了。
	3、但是有一个错误。后来发现是在处理插入排序的时候，应该从前往后找到第一个比后面元素大那个，即小于等于而不能只写小于
	*/
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",num1+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",num2+i);
	}
	bool insert=true;
	int i=1;
	while(i<=n-1&&num2[i]<=num2[i+1]){
		//这里应该是小于等于而不是小于
		i++;
	}
	for(int j=i+1;j<=n;j++){
		if(num1[j]!=num2[j]){
			insert=false;
			break;
		}
	}
	if(insert){
		printf("Insertion Sort\n");
		sort(num2+1,num2+i+2);
		for(int i=1;i<=n;i++){
			printf("%d",num2[i]);
			if(i!=n){
				printf(" ");
			}
		}
	}else{
		printf("Heap Sort\n");
		sort(num1+1,num1+n+1);
		int q=n;
		for(;q>0;q--){
			if(num2[q]!=num1[q]){
				break;
			}
		}
		swap(num2[1],num2[q]);
		shiftUpToDown(1,q-1);
		for(int i=1;i<=n;i++){
			printf("%d",num2[i]);
			if(i!=n){
				printf(" ");
			}
		}
	}

	return 0;
}