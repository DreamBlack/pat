#include<stdio.h>
#include<ctype.h>
#include<string>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;
char input[1048577];
map<string,int> strs;
int main(){
	/*
	注意如果整个字符串就是一个单词（一开始这个错了）
	*/
	string s,strinput;
	getline(cin,s);
	transform(s.begin(),s.end(),back_inserter(strinput),::tolower);
	
	int front=0,end=0,i=0;
	while(i<strinput.size()){
		string temp;
		while(i<strinput.size()){
			if(isdigit(strinput[i])==0&&isalpha(strinput[i])==0){//跳过不是字母或者数字的{
				i++;
			}else{
				break;
			}
		}
		front=i;
		if(i>=strinput.size()){
			break;
		}
		while(i<strinput.size()){
			if(isdigit(strinput[i])||isalpha(strinput[i])){//跳过字母或者数字,找到第一个不是字母或者数字的{
				i++;
			}else{
				break;
			}
		}
		end=i;
		
		if(i<=strinput.size()){
			if(front<end){
				temp=strinput.substr(front,end-front);
				strs[temp]++;
			}else{
				if(i>=strinput.size()){
					break;
				}
			}
		}
	}
	int max=0;
	string maxStr;
	for(auto it=strs.begin();it!=strs.end();it++){
		if(it->second>max){
			max=it->second;
			maxStr=it->first;
		}
	}
	printf("%s %d",maxStr.c_str(),max);
	return 0;
}