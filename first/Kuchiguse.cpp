#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
	/*
	��Ŀ���⣺����N���ַ����������ǵĹ�����׺����������ڹ�����׺���������nai��
	����˼·��
	1����ʼ��ʱ����Ŀ˵its sentence ending particles����Ϊ��ÿ�仰���һ�����ҹ�����׺�����һ�ύ�������
	2�������ĳɾ����ܵĹ�����׺�ͺܼ�һ�ι���
	*/
	int n;
	cin>>n;
	string suffix="";
	getline(cin,suffix);
	suffix="";
	bool ishas=true;
	for(int i=0;i<n;i++){
		string s,nowsuffix;
		getline(cin,s);
		nowsuffix=s;
		if(i==0){
			suffix=nowsuffix;
		}else{
			int p=nowsuffix.size()-1,q=suffix.size()-1;
			while(p>=0&&q>=0&&nowsuffix[p]==suffix[q]){
				p--;
				q--;
			}
			if(p==nowsuffix.size()-1){
				printf("nai");
				return 0;
			}else{
				suffix=nowsuffix.substr(p+1,nowsuffix.size()-p-1);
			}
		}

	}
	cout<<suffix;
	return 0;
}