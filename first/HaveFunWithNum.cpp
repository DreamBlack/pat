#include<stdio.h>
int main(){
	/*
	��Ŀ���⣺����һ�����Ȳ�����20��������������������������λ�Ƿ�Ϊԭ��λ��һ�����С�
	������yes����no���Ҫ�����������2�Ľ��
	����˼·��
	����էһ��ͦ�򵥵ġ�������������������֣�ʮ���ƣ�������20λ��int,long,long long,doubleʲô�ĸ���
	û�취��ʾ��ok�����������ˣ���string������ˣ�������ôʵ��double(�˶�������������)�ļ����أ���������ӷ�
	�ÿ��Լ����������
	���������⣺
	1��һ��ʼΪ�˷������佫��������Ҷ��루��λ����Ӧ��19��λ���ϣ���ͬʱ��ԭ��λ���ϵ�Ԫ����0
	��������û���뵽���������ĸպ���20λ�ģ���һ�����ԭ��λ����0�Ĳ�����ʹ���������鶼Ϊ0
	2��������ͽ��λ����ͬ���Բ�������Ŀ����ʱ���������no
	3����֪��Ϊɶ����������20λ����ʱ�����к�ᱨ������ȴͨ����Oj
	stack around the variable ipt was corrupted
	*/

	int ipt[20]={0};//�������
	int opt[20]={0};
	int counti[10]={0};
	int counto[10]={0};//��¼�����double��0-9���ֵĴ���
	char c;
	int pos=0,blength,alength;
	do{
		c=getchar();
		ipt[pos++]=c-'0';
	}while(c!='\n');
	blength=alength=pos-1;
	//����
	int nowpos=19;

	for(int i=blength-1;i>=0&&nowpos>=0;i--){
		ipt[nowpos--]=ipt[i];
		counti[ipt[i]]++;
	}

	//���nowposָ�����λ��ǰһ���±�

	//����n+n
	int add=0,cnt=0;//addλ��ǰλ��ӵĺ�cntΪǰһλ�����Ľ�λ
	for(int i=19;i>nowpos&&i>=0;i--){
		add=ipt[i]*2+cnt;
		if(add>9){//
			cnt=1;
			opt[i]=add%10;
		}else{
			cnt=0;
			opt[i]=add;
		}
		counto[opt[i]]++;
	}
	if(cnt==1){//���ϼӷ��ɹ�
		opt[nowpos]=1;
		alength++;
		nowpos--;
		printf("No\n");
	}else{
		//�ж��ǲ���0-9���ֵĴ�������ͬ
		bool isfun=true;
		for(int i=0;i<10;i++){
			if(counti[i]!=counto[i]){
				isfun=false;
			}
		}
		if(isfun){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	for(int i=nowpos+1;i<20;i++){
		printf("%d",opt[i]);
	}
	return 0;

}