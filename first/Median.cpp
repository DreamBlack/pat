#include<stdio.h>
long num1[1000000];
long num2[1000000];
int main(){
	/*
	��Ŀ���⣺�����������������У������������кϲ�����м���
	����˼·��
	1���ÿ�ʼ���ö�̬�滮�ķ�������������˵ʵ������������ǲ�̫�ᡣ�����ʱ��Ҫ�󲻸����Ծ�����ͨ��˫ָ��ķ�����
	2��������˫ָ��ʱ����������һ�����鴦�������������µ�һ�����������Ե����
	3������һ��Ҫע����ǣ�������1000000�����������Ϊȫ�ֱ�������������ᱨ��
	*/
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%ld",&(num1[i]));
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%ld",&(num2[i]));
	}
	int i=0,j=0,cnt=0;
	int target=(m+n-1)/2;
	int temp=0;
	while(cnt<=target&&i<n&&j<m){
		if(num1[i]<num2[j]){
			temp=num1[i++];
		}else{
			temp=num2[j++];
		}
		cnt++;
	}
	if(cnt<=target){
		if(i==n){
			while(cnt<=target){
				temp=num2[j++];
				cnt++;
			}
		}else{
			while(cnt<=target){
				temp=num1[i++];
				cnt++;
			}
		}
	}
	printf("%ld",temp);
	return 0;
}