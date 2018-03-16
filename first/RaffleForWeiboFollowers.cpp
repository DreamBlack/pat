#include<stdio.h>
#include<string>
#include<set>
#include<iostream>
using namespace std;
string name[1001];
int main(){
	/*
	题目大意：小明PAT考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔N个人就发出一个红包。请你编写程序帮助他确定中奖名单。
	注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。按照输入的顺序输出中奖名单，每个
	昵称占一行。如果没有人中奖，则输出“Keep going…”
	解题思路：
	1、开始有一个段错误，数组开大就好了
	2、后来有一个五分的点错误。见下面内容
	*/
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	for(int i=1;i<=m;i++){
		char tmp[21];
		scanf("%s",tmp);
		string st(tmp);
		name[i]=st;
	}
	int now=s;
	if(s>m){//这里的问题。本来写的是s>m||s>n有一个点没过
		printf("Keep going...");
		return 0;
	}
	set<string>winner;
	while(now<=m){
		if(winner.count(name[now])==0){
			winner.insert(name[now]);
			cout<<name[now]<<endl;
			now+=n;
		}else{
			while(now<=m&&winner.count(name[now])!=0){
				now++;
			}
		}
		
	}
	return 0;
}