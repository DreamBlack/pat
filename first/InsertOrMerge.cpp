#include<stdio.h>
#include<algorithm>
using namespace std;
int num[100];
int num2[100];
int main(){
	/*
	题目大意：现给定原始序列和由某排序算法产生的中间序列，请你判断该算法是插入算法还是归并算法。首先在第1行中输出“Insertion Sort”表示插入排序、
	或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列
	解题思路：
	1、一开始没有使用初始序列，想直接用输出序列判断，写了一会发现没办法继续了
	2、先从中间序列0开始找到第一个未排序的元素的位置，比较中间序列和初始序列之后的元素，相同则是插入排序，不同则是归并排序
	3、对归并排序，本来是用看中间序列经过几次归并才变成这样的（找出中间序列的最小归并长度），然后从最小长度翻倍再归并一次输出，
	最后两个测试点错误。后来网上说应该对初始序列从1到n的归并长度进行归并，同时看和中间序列是否相同，从而找到归并长度。
	法一找的是最小归并长度不太准
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",num+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",num2+i);
	}
	bool ismerge=true,issort=true;
	int i=0;//先从0开始找到第一个未排序的元素的位置
	for(;i<n-1;i++){
		if(num2[i]>num2[i+1]){
			break;
		}
	}
	for(int j=i+1;j<n;j++){//比较未排序后部分元素是否与初始位置一一对应，对应的话就是插入排序
		if(num2[j]!=num[j]){
			issort=false;
			break;
		}
	}
	if(issort){
		printf("Insertion Sort\n");
		sort(num2,num2+i+2);
	}else{
		printf("Merge Sort\n");
		int size=2;
		bool flag=true;
		//对Num，size从2开始进行每size个元素进行归并排序，归并完比较与Num2是否相同，相同的话退出，否则size翻倍继续
		while(flag&&size<=n){
			flag=false;
			for(int j=0;j<n;j=j+size){
				if(j+size<n){
					sort(num+j,num+j+size);
				}else{
					sort(num+j,num+n);
				}
			}
			for(int i=0;i<n;i++){
				if(num[i]!=num2[i]){
					flag=true;
					break;
				}
			}
			size=(size*2>n)?n:size*2;
			if(!flag){
				break;
			}
		}
		for(int j=0;j<n;j=j+size){
			if(j+size<n){
				sort(num2+j,num2+j+size);
			}else{
				sort(num2+j,num2+n);
			}

		}
	}
	for(int a=0;a<n;a++){
		printf("%d",num2[a]);
		if(a!=n-1){
			printf(" ");
		}
	}
	return 0;
}