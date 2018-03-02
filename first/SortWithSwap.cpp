#include<stdio.h>
int num[100000];
int n;
int isSorted(int index){
	for(int i=index;i<n;i++){
		if(num[i]!=i){
			return i;
		}
	}
	return n;
}
int main(){
	/*
	题目大意：给出一个n个数的序列，数字为0~n-1的乱序，每次用两两交换的方式而且只能用0和另一个数交换，使序列变成有序的，问最少需要多少步骤。
	解题思路:
	1、应该让0把正确的元素换到自己的位置，例如开始0在8位置，则把8换过来，让原来8的位置换成0，这样多次重复就可完成元素的归位。
	需要注意的是，中途可能出现0出现在0位的情况，例如0在3号位，而3恰好在0号位，则0到了0位置，但是排序并未结束。这时候应该让0和最近的一个错误
	位置元素交换，然后继续上面的过程。
	2、使用方法1之后有两个测试点超时。因为每次交换0,8的时候需要知道0,8现在在数组中所在位置要O(N)。为了提高效率，可以在存储数据的时候就使用hash
	的方式，第i个位置存放数i当前在数组中的下标，即可实现O(1)
	3、使用2的方法之后，交换的逻辑要搞清楚，如交换0,8实际上就是把num[0]和num[8]的位置交换。不要糊涂了。
	4、可以在输入数据的时候记录有多少个位置不对的元素，每次摆正一个元素的位置之后就将cnt--，cnt==0时候退出
	5、其次，在寻找和0最近的一个位置错误的元素时候，可以用index记录0后面目前第index个元素没有排好，(index之前的都是排好的)这一每次从Index开始查找
	提高了效率
	*/
	scanf("%d",&n);
	int unsorted=0;;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		num[t]=i;
		if(num[t]!=t){
			unsorted++;
		}
	}
	int funSorted,cnt=0,index=1;
	while(unsorted!=0){
		if(num[0]==0){
			funSorted=isSorted(index);
			index=funSorted;
			if(funSorted==n){
				break;
			}
			int tmp=num[funSorted];
			num[funSorted]=0;
			num[0]=tmp;
		}else{
			int tmp=num[num[0]];
			num[num[0]]=num[0];
			num[0]=tmp;
			unsorted--;
		}
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}
