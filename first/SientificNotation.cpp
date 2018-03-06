#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
char num[80000];
int main(){
	/*
	题目大意：题目给出科学计数法的格式的数字A，要求输出普通数字表示法的A，并保证所有有效位都被保留，包括末尾的0
	解题思路：
	注意+1.234567E+03注意，虽然exp是正数，但是最后仍然可能有小数点
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
	//weishu用来记录包含的位数
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