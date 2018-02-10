#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
	/*
	题目大意：用所给字符串按U型输出。n1和n3是左右两条竖线从上到下的字符个数，n2是底部横线从左到右的字符个数。
	要求：
	1. n1 == n3
	2. n2 >= n1
	3. n1为在满足上述条件的情况下的最大值
	解题思路：
	1、我的思路是，既有公式n=2*n1+n2-2,n已知，只有找最大的n1(n1<=n2)使之满足这个公式即可，所有可以从N1=1开始
	慢慢增加到比n1小的那个即可。但是有一个测试点错误，因为漏掉了n1可以刚好等于n2
	2、后来看了网上的解法，可以说相当棒了。既然要使n1和n2尽量相等，如果n+2能被3整除的话，刚好n1=n2，如果余1或者余2
	因为要保证n2>=n1，所以只能让多出来的那个放给n2
	3、对于最后的打印，那位的解法也相当棒。把它们存储到二维字符数组中，一开始初始化字符数组为空格，然后按照u型填充进去，最后输出这个数组u
	*/
	string s;
	cin>>s;
	int n1=2;
	int n=s.length();
	int n2=n-2*n1+2;
	int temp=n2;
	while(n1<=n2){
		temp=n1;
		n1++;
		n2=n-2*n1+2;
	}
	n1=temp;
	n2=n-2*n1+2;
	for(int i=0;i<n1-1;i++){
		cout<<s[i];
		for(int j=0;j<n2-2;j++){
			cout<<" ";
		}
		cout<<s[n-1-i]<<endl;
	}
	for(int i=n1-1;i<=n-n1;i++){
		cout<<s[i];
	}
	return 0;
}