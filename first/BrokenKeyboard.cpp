#include<stdio.h>
#include<set>
#include<string>
#include<cctype>
using namespace std;
char in[82];
char out[82];
int main(){
	/*
	��Ŀ���⣺�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ�ʵ�ʱ���������֣�
	�����г��϶���������Щ����
	����˼·��
	1�������ڶ��У�ʹ��set1��¼�����г��ֹ����ַ�����set2������Щ�ڶ�����û�е�Ԫ��
	2��������һ�У���set1���Ƿ������Ԫ�أ�û�еĻ�������set2�л�û�м�¼���Ͱ����ŵ�vector��
	3��ʹ��set2��֤�����ÿ��Ԫ��ֻ����һ���Ұ��շ���˳�����
	*/
	scanf("%s",in);
	scanf("%s",out);
	string sin(in);
	string sout(out);
	set<char> have;
	set<char> miss;
	for(int i=0;i<sout.size();i++){
		char now=sout[i];
		if(isalpha(now)){
			have.insert(toupper(sout[i]));
		}else{
			have.insert(now);
		}
	}
	for(int i=0;i<sin.size();i++){
		char now=sin[i];
		if(isalpha(now)){
			if(have.count(toupper(sin[i]))==0&&miss.count(toupper(sin[i]))==0){
				printf("%c",toupper(sin[i]));
				miss.insert(toupper(sin[i]));
			}
		}else{
			if(have.count(sin[i])==0&&miss.count(sin[i])==0){
				printf("%c",sin[i]);
				miss.insert(sin[i]);
			}
		}
	}
	return 0;
}