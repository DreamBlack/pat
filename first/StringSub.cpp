#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
	/*
	��Ŀ���⣺���������ַ������ڵ�һ���ַ�����ɾ���ڶ����ַ����г��ֹ��������ַ��������
	����˼·��
	1�����õı�������һ���Թ���
	2�����ϵ�hashҲ�ܺá���flag[256]����������str2���ֹ����ַ�Ϊtrue�����str1��ʱ�����flag[str1[i]]�Ƿ�Ϊtrue,�����true�Ͳ����
	*/
	string s1;
	getline(cin,s1,'\n');
	string s2;
	getline(cin,s2,'\n');
	for(int i=0;i<s1.size();i++){
		bool isdelete=false;
		for(int j=0;j<s2.size();j++){
			if(s1[i]==s2[j]){
				isdelete=true;
				break;
			}
		}
		if(isdelete){
			s1.erase(i,1);
			i--;
		}
	}
	cout<<s1;
	return 0;
}