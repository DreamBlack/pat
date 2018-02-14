#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
bool isSym(string str,int head,int tail){
	int i=head,j=tail;
	while(i<j){
		if(str[i]!=str[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main(){
	/*
	��Ŀ���⣺�����ַ�����������Ӵ��ĳ���
	����˼·��
	1��O(n^3)
	����ÿһ���ַ���ѡ�������ͬ���ַ���Ȼ����ж��������ַ�֮��Ĵ��Ƿ��ǻ��Ĵ�
	ע�����û�ҵ���Ӧ����1
	2���Ľ����㷨����̬�滮���������ַ��������ͷ��β��ͬ��
	��ô���������������һ����ȥͷȥβ֮��Ĳ��ֵ�����������м���ͷ��β��
	���ͷ��β��ͬ����ô�����������������ȥͷ�Ĳ��ֵ�����������к�ȥβ�Ĳ��ֵ�����������еĽϳ�����һ����
	3��Manacher �㷨

	*/
	string str;
	getline(cin,str);
	int maxLength=-1;
	for(int i=0;i<str.length();i++){
		for(int j=i+1;j<str.length();j++){
			bool findSym=false;
			if(str[j]==str[i]){
				findSym=isSym(str,i,j);
				if(findSym&&maxLength<j-i+1){
					maxLength=j-i+1;
				}
			}
		}
	}
	if(str.length()==1){
	}
	if(maxLength==-1){
		printf("%d",1);
	}else{
		printf("%d",maxLength);
	}
	
	return 0;
}