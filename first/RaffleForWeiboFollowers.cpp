#include<stdio.h>
#include<string>
#include<set>
#include<iostream>
using namespace std;
string name[1001];
int main(){
	/*
	��Ŀ���⣺С��PAT�������֣�����֮���������΢��ת���齱�����ת���������а�˳��ÿ��N���˾ͷ���һ������������д���������ȷ���н�������
	ע�⣺��������ת����Σ��������н���Ρ�����������ڵ�ǰ�н�λ�õ������Ѿ��й�������������˳��ȡ��һλ�����������˳������н�������ÿ��
	�ǳ�ռһ�С����û�����н����������Keep going����
	����˼·��
	1����ʼ��һ���δ������鿪��ͺ���
	2��������һ����ֵĵ���󡣼���������
	*/
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	for(int i=1;i<=m;i++){
		char tmp[21];
		scanf("%s",tmp);
		string st(tmp);
		name[i]=st;
	}
	int now=s;
	if(s>m){//��������⡣����д����s>m||s>n��һ����û��
		printf("Keep going...");
		return 0;
	}
	set<string>winner;
	while(now<=m){
		if(winner.count(name[now])==0){
			winner.insert(name[now]);
			cout<<name[now]<<endl;
			now+=n;
		}else{
			while(now<=m&&winner.count(name[now])!=0){
				now++;
			}
		}
		
	}
	return 0;
}