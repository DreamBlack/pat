#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
long long int m,larg;
int main(){
	/*
	��Ŀ���⣺һ��������N�������п��ܴ����������������֡�����630���Էֽ�Ϊ3*5*6*7������5��6��7����3�����������֡�������һ������N��
	Ҫ���д���������������ӵĸ������������С�������������С�
	����˼·���������˺þã��о������ֶ���ѭ���ļ�������д���á��ò�����д�˸��ݹ麯���и����Ե��ջ����ˡ���������һ����������
	��಻���ܳ������������Ŀ�������һ��ʼ�������ֵ�����������˺ö����õݹ飬�óɿ������ֵ�Ϳ�����
	*/
	scanf("%lld",&m);
	larg=sqrt((double)m)+1;
	long long int first=2;
	int now,n,cnt,maxcnt=0,maxfirst=2;
	while(first<=larg){
		now=first;
		n=m;
		cnt=0;
		while(n%now==0){
			cnt++;
			n=n/now;
			now++;
		}
		if(cnt>maxcnt){
			maxcnt=cnt;
			maxfirst=first;
		}
		first++;
	}
	if(maxcnt==0){//����
		printf("1\n%d",m);
	}else{
		printf("%d\n%d",maxcnt,maxfirst);
		int k=maxfirst+1;
		while(k<=maxfirst+maxcnt-1){
			printf("*%d",k);
			k++;
		}
	}

	
	return 0;
}