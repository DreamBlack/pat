#include<stdio.h>
#include<string>
#include<iostream>
#include<cctype>
using namespace std;
string gewei[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string shiwei[13]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int findgewei(string s){
	for(int i=0;i<13;i++){
		if(gewei[i].compare(s)==0){
			return i;
		}
	}
	return -1;
}
int findshiwei(string s){
	for(int i=1;i<13;i++){
		if(shiwei[i].compare(s)==0){
			return i;
		}
	}
	return -1;
}
int main(){
	/*
	题目大意：火星上数字是13进制，并且1-12有自己火星上的叫法。如果超过了13，十位数的数也有相应的叫法。对于0-169内的数，给出n个
	地球叫法或者火星叫法，翻译出来
	解题思路：这道题大坑。
	1、首先是地球数字转火星数字。对除以13和模13的结果进行处理，找到表中对应字符即可。要注意的是0的读法，和能被13整除的数（不需要输出
	tret只要输出是13的几倍在大于13的里面选择字符串即可）
	2、其次是火星转地球。也要注意能被13整除的数（是那些明明只有一个字符但是在个位表里面却找不到的要*13）
	*/
	int n;
	cin>>n;
	string a;
	getline(cin,a);
	for(int i=0;i<n;i++){
		getline(cin,a);
		if(isdigit(a[0])){//数字
			int k=atoi(a.c_str());
			int ge=0,shi=0;
			ge=k%13;
			shi=k/13;
			if(k==13){
				printf("tam\n");
			}else{
				if(shi!=0){
					cout<<shiwei[shi];
				}
				if(ge!=0){
					if(shi!=0){
						cout<<" ";
					}
					cout<<gewei[ge]<<endl;
				}else{
					if(k==0){
						printf("tret");
					}
					cout<<endl;
				}
			}
		}else{
			int pos=a.find(" ");
			if(pos==-1){//只有一位数
				if(findgewei(a)==-1){
					cout<<findshiwei(a)*13<<endl;
				}else{
					cout<<findgewei(a)<<endl;
				}
			}else{
				string sshi=a.substr(0,pos);
				string sge=a.substr(pos+1,a.size()-pos-1);
				cout<<findshiwei(sshi)*13+findgewei(sge)<<endl;
			}
		}
	}
	return 0;
}