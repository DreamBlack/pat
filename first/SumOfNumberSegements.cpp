#include<stdio.h>
double num[100000];
int main(){
	/*
	��Ŀ���⣺��һ�����������Թ��ɺܶ�������С��󹹳ɵ��������ǵĺ͵��ܺ�
	����˼·��
	��ѧ�����ҹ��ɡ�
	����n������ʱ��. �����i������ʱ�򣬵�0���� ���� n �Σ���1���� ���� (n-1) * 2����2���� ���� (n-2) * 3
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",num+i);
	}
	double all=0;
	for(int i=0;i<n;i++){
		all+=num[i]*(i+1)*(n-i);
	}
	printf("%0.2f",all);
	return 0;
}