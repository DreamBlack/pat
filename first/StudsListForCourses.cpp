#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
map<int,vector<string>> courses;
int main(){
	/*
	��Ŀ���⣺����ѡ�������Ϳγ���Ŀ��Ȼ���ٸ���ÿ���˵�ѡ������������ÿ�ſγ����ѡ�������Լ�����ѡ�ÿε�ѧ�������������ֵ���
	����˼·����ʵ�Ǻܼ򵥵�һ���⡣�������ڶ�c��c++���ַ������˽��˷��˺ܶ�ʱ��
	1����ʼʹ��map<int,set<char*>>,char*s��Ϊc���ַ���,s��ʵ��һ��ָ�룬����ÿ��insert�Ķ���ͬһ��ָ�룬ͬһ��name
	2��<string>��c++��string��<string.h>��c��string��ͷ�ļ�д���ˣ�����sort����û��ִ��
	3�����ڱ����ʱ������ƽϴ����к���Ȼ���뵽��ʹ��cin,��ʹ��char*��scanf����˼ά��ʽ��1�ϣ���֪��զ�죬��ʵ������Ȼʹ��string��ֻ��
	����������ʱ��ʹ��char*.string s(cstr);ʹ��c���ַ�����ʼ��c++���ַ�����s.c_str();ʹc++��stringת��Ϊchar*
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
