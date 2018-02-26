#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
map<int,vector<string>> courses;
int main(){
	/*
	题目大意：给出选课人数和课程数目，然后再给出每个人的选课情况，请针对每门课程输出选课人数以及所有选该课的学生姓名，按照字典序
	解题思路：其实是很简单的一道题。但是由于对c和c++的字符串不了解浪费了很多时间
	1、开始使用map<int,set<char*>>,char*s作为c的字符串,s其实是一个指针，导致每次insert的都是同一个指针，同一个name
	2、<string>是c++的string，<string.h>是c的string，头文件写错了，导致sort函数没法执行
	3、由于本题对时间的限制较大，所有很自然的想到不使用cin,而使用char*，scanf。就思维定式在1上，不知道咋办，其实可以仍然使用string，只是
	在输出输入的时候使用char*.string s(cstr);使用c的字符串初始化c++的字符串；s.c_str();使c++的string转换为char*
	*/
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		char name[5];
		int cc;
		scanf("%s %d",name,&cc);
		string strname(name);
		for(int j=0;j<cc;j++){
			int c;
			scanf("%d",&c);
			courses[c].push_back(strname);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,courses[i].size());
		sort(courses.at(i).begin(),courses.at(i).end());
		for(auto it=courses.at(i).begin();it!=courses.at(i).end();it++){
			printf("%s\n",(*it).c_str());
		}
	}
	return 0;
}
