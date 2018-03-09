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
	��Ŀ���⣺������������13���ƣ�����1-12���Լ������ϵĽз������������13��ʮλ������Ҳ����Ӧ�Ľз�������0-169�ڵ���������n��
	����з����߻��ǽз����������
	����˼·��������ӡ�
	1�������ǵ�������ת�������֡��Գ���13��ģ13�Ľ�����д����ҵ����ж�Ӧ�ַ����ɡ�Ҫע�����0�Ķ��������ܱ�13��������������Ҫ���
	tretֻҪ�����13�ļ����ڴ���13������ѡ���ַ������ɣ�
	2������ǻ���ת����ҲҪע���ܱ�13��������������Щ����ֻ��һ���ַ������ڸ�λ������ȴ�Ҳ�����Ҫ*13��
	*/
	int n;
	cin>>n;
	string a;
	getline(cin,a);
	for(int i=0;i<n;i++){
		getline(cin,a);
		if(isdigit(a[0])){//����
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
			if(pos==-1){//ֻ��һλ��
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