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
	��Ŀ���⣺��һЩ�ַ�����������ƴ������������С���ֵķ�ʽ
	����˼·��
	1����ʼ��ʱ��������һ��map<int,vector<Num>>(����ÿ������ͷ�����ֲ�ͬӳ�䵽��ͬ��map��)NUM{int n,string ns},
	Ȼ�����map��ÿ��vector�е�Ԫ�أ�����ͳһ����Ϊ��vector���Ԫ�صĳ��ȣ��������Լ���Ԫ�ز��룩��Ȼ��
	����num��string��С����ע��������������ֻ�ܵ�19��
	2�����е������n!�֡��������ǻ�������е�һ����ϣ�Ȼ�����������ڵ�����Ƭ��a,b
	��Ȼ�����Ǿ�Ҫ�룬��a��b�����ܲ���ʹ�������б�С�أ�����ʵ������дcmp������Ȼ���������
	3������2����֮�󣬻���һ���������󣬼�ȫ0�Ļ�Ӧ�����0.
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