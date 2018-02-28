#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
char s[10000000];
char* week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	/*
	题目大意：给定两个字符串，最先同一个位置共同出现的A-G之间的字母代表星期几。接着最先共同位置出现的0..9或者A-N之间的字符表示时间的小时。
	再给两个字符串，最先共同位置同时出现的字母，位置表示时间的分钟，最后输出星期几个，几点几分，作为约会时间。
	解题思路：这题花了一个多小时。简直气死了
	1、一开始题目没读懂。
	2、最后改好一个有一个测试点错了。怎么找都不知道。后来发现week数组里面的字符串写错了简直气死
	*/
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	char first,second;
	int cnt=0;
	for(int i=0;i<s2.length()&&i<s1.length();i++){
		if(cnt==0&&s2[i]>='A'&&s2[i]<='G'&&s1[i]==s2[i]){//大写
			cnt++;
			first=s1[i];
			
		}else if(cnt==1&&s1[i]==s2[i]){
			if((s2[i]>='A'&&s2[i]<='N')||(s2[i]>='0'&&s2[i]<='9')){//大写
				second=s2[i];
				break;
			}
		}
	}
	
	int third;
	for(int i=0;i<s4.length()&&i<s3.length();i++){
		if(s3[i]==s4[i]){
			if((s4[i]>='A'&&s4[i]<='Z')||(s4[i]>='a'&&s4[i]<='z')){
				third=i;
			break;
			}
		}
	}
	

	printf("%s ",week[first-'A']);
	if(second>'9'){
		printf("%02d:",10+second-'A');
	}else{
		printf("%02d:",second-'0');
	}
	printf("%02d",third);
	return 0;
}