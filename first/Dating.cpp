#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
char s[10000000];
char* week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	/*
	��Ŀ���⣺���������ַ���������ͬһ��λ�ù�ͬ���ֵ�A-G֮�����ĸ�������ڼ����������ȹ�ͬλ�ó��ֵ�0..9����A-N֮����ַ���ʾʱ���Сʱ��
	�ٸ������ַ��������ȹ�ͬλ��ͬʱ���ֵ���ĸ��λ�ñ�ʾʱ��ķ��ӣ����������ڼ��������㼸�֣���ΪԼ��ʱ�䡣
	����˼·�����⻨��һ����Сʱ����ֱ������
	1��һ��ʼ��Ŀû������
	2�����ĺ�һ����һ�����Ե���ˡ���ô�Ҷ���֪������������week����������ַ���д���˼�ֱ����
	*/
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	char first,second;
	int cnt=0;
	for(int i=0;i<s2.length()&&i<s1.length();i++){
		if(cnt==0&&s2[i]>='A'&&s2[i]<='G'&&s1[i]==s2[i]){//��д
			cnt++;
			first=s1[i];
			
		}else if(cnt==1&&s1[i]==s2[i]){
			if((s2[i]>='A'&&s2[i]<='N')||(s2[i]>='0'&&s2[i]<='9')){//��д
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