#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
	/*
	题目大意：给出两个字符串，在第一个字符串中删除第二个字符串中出现过的所有字符并输出。
	解题思路：
	1、我用的暴力法，一次性过了
	2、网上的hash也很好。用flag[256]数组变量标记str2出现过的字符为true，输出str1的时候根据flag[str1[i]]是否为true,如果是true就不输出
	*/
	string s1;
	getline(cin,s1,'\n');
	string s2;
	getline(cin,s2,'\n');
	for(int i=0;i<s1.size();i++){
		bool isdelete=false;
		for(int j=0;j<s2.size();j++){
			if(s1[i]==s2[j]){
				isdelete=true;
				break;
			}
		}
		if(isdelete){
			s1.erase(i,1);
			i--;
		}
	}
	cout<<s1;
	return 0;
}