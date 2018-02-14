#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
bool isSym(string str,int head,int tail){
	int i=head,j=tail;
	while(i<j){
		if(str[i]!=str[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main(){
	/*
	题目大意：返回字符串的最长回文子串的长度
	解题思路：
	1、O(n^3)
	对于每一个字符，选择和其相同的字符，然后后判断这两个字符之间的串是否是回文串
	注意如果没找到，应返回1
	2、改进的算法，动态规划：对任意字符串，如果头和尾相同，
	那么它的最长回文子序列一定是去头去尾之后的部分的最长回文子序列加上头和尾。
	如果头和尾不同，那么它的最长回文子序列是去头的部分的最长回文子序列和去尾的部分的最长回文子序列的较长的那一个。
	3、Manacher 算法

	*/
	string str;
	getline(cin,str);
	int maxLength=-1;
	for(int i=0;i<str.length();i++){
		for(int j=i+1;j<str.length();j++){
			bool findSym=false;
			if(str[j]==str[i]){
				findSym=isSym(str,i,j);
				if(findSym&&maxLength<j-i+1){
					maxLength=j-i+1;
				}
			}
		}
	}
	if(str.length()==1){
	}
	if(maxLength==-1){
		printf("%d",1);
	}else{
		printf("%d",maxLength);
	}
	
	return 0;
}