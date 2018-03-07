#include<stdio.h>
#include<set>
#include<string>
#include<cctype>
using namespace std;
char in[82];
char out[82];
int main(){
	/*
	题目大意：旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，
	请你列出肯定坏掉的那些键～
	解题思路：
	1、遍历第二行，使用set1记录下所有出现过的字符，用set2保存那些第二行中没有的元素
	2、遍历第一行，看set1中是否有这个元素，没有的话，并且set2中还没有记录，就把它放到vector中
	3、使用set2保证输出中每个元素只出现一次且按照发现顺序输出
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