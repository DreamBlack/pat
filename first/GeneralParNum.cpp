#include<stdio.h>
#include<vector>
using namespace std;
bool isPar(vector<int> s){
	if(s.size()==1){
		return true;
	}
	int i=0,j=s.size()-1;
	while(i<j){
		if(s.at(i)==s.at(j)){
			i++;
			j--;
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	/*
	��Ŀ���⣺������������a��b����ʮ���Ƶ�a��b�������Ƿ�Ϊ���������ǵĻ����Yes���������No��
	�������a��b�����µı�ʾ���Կո������

	˼·��
	1����ʼ��ʱ������һ��string��������Ľ�����������������⣬һ����intתstring�����⣬�ڶ����ǣ���Ŀ�и���base��Χ�ϴ���ܴ���10��
	������string��ÿһ��char������ak�ǲ��Ե�
	2�������뵽��vector�����档vector���Ƿ�����á�
	*/
	int n,b;
	vector<int> res;
	scanf("%d%d",&n,&b);
	if(n==0){
		printf("Yes\n");
		printf("0");
	}else{
		int divd=n,quo=0;
		while(divd!=0){
			quo=divd%b;
			divd=divd/b;
			res.push_back(quo);
		}
		bool isp=isPar(res);
		if(isp){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		for(int i=res.size()-1;i>0;i--){
			printf("%d ",res.at(i));
		}
		printf("%d",res.at(0));
	}
	return 0;
}