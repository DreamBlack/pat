#include<stdio.h>
#include<climits>
#include<cmath>
using namespace std;
int length[100001];
int oneToEach[100001];
int main(){
	/*
	��Ŀ���⣺��ģ�⡣���н�����������γ�һ�����Ρ��������Ե㣬����Զ���·������Сֵ��
	����˼·�������Ȼ�˷�����ô�ü�ֱ������������
	1����ʼ��ÿһ�Զ���ʹ�ô�a��b���ټ����b��a�ľ��룬���Ӷ�ΪN,���³�ʱ
	2����ʵֻҪ�����a��b�ľ��룬�����������ܾ����ټ�ȥa��b�ľ������b��a�ľ����ˣ������Ƕ�Ϲ���İ���ҲûŪ����
	*/
	int n;
	scanf("%d",&n);
	int count=0;
	for(int i=1;i<n+1;i++){
		scanf("%d",&(length[i]));
		oneToEach[i]=count;
		count=count+length[i];
	}
	int totalLength=oneToEach[n]+length[n];
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int s,d;
		scanf("%d%d",&s,&d);
		int min=(abs(oneToEach[s]-oneToEach[d])>totalLength-abs(oneToEach[s]-oneToEach[d]))?totalLength-abs(oneToEach[s]-oneToEach[d]):abs(oneToEach[s]-oneToEach[d]);
		if(s==d){
			printf("%d\n",0);
		}else{
			printf("%d\n",min);
		}
	}
	return 0;
}