#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
char num[80000];
int main(){
	/*
	��Ŀ���⣺��Ŀ������ѧ�������ĸ�ʽ������A��Ҫ�������ͨ���ֱ�ʾ����A������֤������Чλ��������������ĩβ��0
	����˼·��
	ע��+1.234567E+03ע�⣬��Ȼexp�����������������Ȼ������С����
	*/
	scanf("%s",num);
	string s(num);
	bool postive=false;
	if(s[0]=='+'){
		postive=true;
	}
	int epos=s.find("E");
	bool exppostive=false;
	if(s[epos+1]=='+'){
		exppostive=true;
	}
	int exppos=-1,weishu=0;
	//weishu������¼������λ��
	for(int i=3;i<s.size();i++){
		if(s[i]=='E'){
			break;
		}
		weishu++;
	}
	weishu++;
	for(int i=epos+2;i<s.size();i++){
		if(s[i]!='0'){
			exppos=i;
			break;
		}
	}
	int exp=0;
	if(exppos!=-1){
		exp=atoi(s.substr(exppos,s.size()-exppos).c_str());
	}
	s=s.substr(0,2+weishu);
	if(exp!=0){
		s.erase(0,1);
		s.erase(1,1);
		if(exppostive){
			if(weishu-1>exp){
				s.insert(exp+1,".");
			}else{
				for(int i=0;i<exp-(weishu-1);i++){
					s.insert(s.size(),"0");
				}
			}
			
		}else{
			for(int i=0;i<exp-1;i++){
				s.insert(0,"0");
			}
			s.insert(0,"0.");
		}
	}else{
		if(postive){
			s.erase(0,1);
		}
	}
	if(!postive){
		s.insert(0,"-");
	}
	printf("%s",s.c_str());
	return 0;
}