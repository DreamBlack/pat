#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string a,string b){
	return ((a+b).compare(b+a)<0)?true:false;
}
int main(){
	/*
	题目大意：给一些字符串，求它们拼接起来构成最小数字的方式
	解题思路：
	1、开始的时候是用了一个map<int,vector<Num>>(根据每个数开头的数字不同映射到不同的map里)NUM{int n,string ns},
	然后对于map中每个vector中的元素，长度统一调整为该vector中最长元素的长度（不足用自己的元素补齐），然后
	根据num的string大小排序。注意输出，但是最后只能得19分
	2、所有的组合有n!种。假设我们获得了其中的一个组合，然后有两个相邻的数字片段a,b
	。然后我们就要想，把a和b交换能不能使整个序列变小呢？。其实就是重写cmp函数，然后升序输出
	3、采用2方法之后，还有一个用例错误，即全0的话应该输出0.
	*/
	int n;
	scanf("%d",&n);
	vector<string> strs;
	bool allzero=true;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		strs.push_back(s);
	}
	sort(strs.begin(),strs.end(),cmp);
	string ret="";

	for(int i=0;i<n;i++){
		ret=ret+strs[i];
	}
	int i=0;
	for(;i<ret.length();i++){
		if(ret[i]!='0'){
			break;
		}
	}
	if(i==ret.length())
	{
		printf("0");
	}else{
		for(;i<ret.length();i++){
			printf("%c",ret[i]);
		}
	}
	return 0;
}