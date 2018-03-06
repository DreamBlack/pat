#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
	/*
	题目大意：给定N给字符串，求他们的公共后缀，如果不存在公共后缀，就输出“nai”
	解题思路：
	1、开始的时候看题目说its sentence ending particles，以为是每句话最后一个词找公共后缀。结果一提交两个错的
	2、后来改成句子总的公共后缀就很简单一次过了
	*/
	int n;
	cin>>n;
	string suffix="";
	getline(cin,suffix);
	suffix="";
	bool ishas=true;
	for(int i=0;i<n;i++){
		string s,nowsuffix;
		getline(cin,s);
		nowsuffix=s;
		if(i==0){
			suffix=nowsuffix;
		}else{
			int p=nowsuffix.size()-1,q=suffix.size()-1;
			while(p>=0&&q>=0&&nowsuffix[p]==suffix[q]){
				p--;
				q--;
			}
			if(p==nowsuffix.size()-1){
				printf("nai");
				return 0;
			}else{
				suffix=nowsuffix.substr(p+1,nowsuffix.size()-p-1);
			}
		}

	}
	cout<<suffix;
	return 0;
}