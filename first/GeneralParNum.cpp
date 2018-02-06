#include<stdio.h>
#include<vector>
using namespace std;
bool isPar(vector<int> s){
	if(s.size()==1){
		return true;
	}
	int i=0,j=s.size()-1;
	while(i<j){
		if(s.at(i)==s.at(j)){
			i++;
			j--;
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	/*
	题目大意：给出两个整数a和b，问十进制的a在b进制下是否为回文数。是的话输出Yes，不是输出No。
	并且输出a在b进制下的表示，以空格隔开。

	思路：
	1、开始的时候是用一个string保存输出的结果。但是又两个问题，一个是int转string的问题，第二个是，题目中给的base范围较大可能大于10，
	所以用string中每一个char来保存ak是不对的
	2、于是想到用vector来保存。vector真是方便好用。
	*/
	int n,b;
	vector<int> res;
	scanf("%d%d",&n,&b);
	if(n==0){
		printf("Yes\n");
		printf("0");
	}else{
		int divd=n,quo=0;
		while(divd!=0){
			quo=divd%b;
			divd=divd/b;
			res.push_back(quo);
		}
		bool isp=isPar(res);
		if(isp){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		for(int i=res.size()-1;i>0;i--){
			printf("%d ",res.at(i));
		}
		printf("%d",res.at(0));
	}
	return 0;
}