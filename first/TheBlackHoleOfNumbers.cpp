#include<stdio.h>
#include<algorithm>
using namespace std;
int num[4];
int cmp(int a,int b){
	return(a>b)?true:false;
}
int main(){
	/*
	��Ŀ���⣺�θ�����λ��k0,�������ĸ������ɴ�С�������г�һ����λ��m,�ټ�ȥ���ķ�����rev(m),�ó���k1=m-rev(m),Ȼ�󣬼�����k1�ظ������任��
	����k2.��˽�����ȥ������Ү�����֣�����k0�Ƕ�����λ���� ֻҪ�ĸ����ֲ�ȫ��ͬ��������7�������任���ͻ������λ��6174.
	����˼·�����⡣����һ��ʼ�и����Ե㣨6174���������ҵ��˾ͺܺø���
	*/
	int n,na,nb;
	scanf("%d",&n);
	
	do{
		num[0]=n/1000;
		num[1]=(n%1000)/100;
		num[2]=((n%1000)%100)/10;
		num[3]=((n%1000)%100)%10;
		if(*num==*(num+1)&&*(num+2)==*(num+3)&&*num==*(num+2)){
			printf("%04d - %04d = 0000",n,n);
			break;
		}
		sort(num,num+4,cmp);
		na=num[0]*1000+num[1]*100+num[2]*10+num[3];
		nb=num[3]*1000+num[2]*100+num[1]*10+num[0];
		n=na-nb;
		printf("%04d - %04d = %04d\n",na,nb,n);

	}while(n!=6174);
	return 0;
}