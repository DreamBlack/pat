#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> stds[26*26*26*10+10];
int hashName(char* name){
	return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
}
int main(){
	/*
	题目大意：有N个学生，K门课，给出选择每门课的学生姓名，最后对于给出的N个学生的姓名的选课情况进行询问，
	要求按顺序给出每个学生的选课情况～
	解题思路：
	1、刚开始直接简单写了个map<string, vector<int> > 直接做，最后一组case超时
	2、网上说名字格式很标准，只有4位而且前三位为大写字母最后一位为数组，
	因为字符串的各种操作cin,cout都是相当费时的，如果能将名字哈希为对应的一个唯一的整数就速度快很多
	3、name由3个大写字母和一位数字组成，即最多有MAX=26*26*26*10个学生。需要做name到数字id之间的映射
	*/
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		int courseNum,stdsNum;
		scanf("%d%d",&courseNum,&stdsNum);
		for(int j=0;j<stdsNum;j++){
			char stdName[5];
			scanf("%s",stdName);
			stds[hashName(stdName)].push_back(courseNum);
		}
	}
	for(int i=0;i<n;i++){
		char stdName[5];
		scanf("%s",stdName);
		printf("%s %d",stdName,stds[hashName(stdName)].size());
		sort(stds[hashName(stdName)].begin(),stds[hashName(stdName)].end());
		for(int i=0;i<stds[hashName(stdName)].size();i++){
			printf(" %d",stds[hashName(stdName)][i]);
		}
		if(i!=n-1){
			printf("\n");
		}
	}
	return 0;
}