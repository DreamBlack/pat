#include<stdio.h>
#include<algorithm>
using namespace std;
int num[100];
int num2[100];
int main(){
	/*
	��Ŀ���⣺�ָ���ԭʼ���к���ĳ�����㷨�������м����У������жϸ��㷨�ǲ����㷨���ǹ鲢�㷨�������ڵ�1���������Insertion Sort����ʾ��������
	��Merge Sort����ʾ�鲢����Ȼ���ڵ�2��������ø������㷨�ٵ���һ�ֵĽ������
	����˼·��
	1��һ��ʼû��ʹ�ó�ʼ���У���ֱ������������жϣ�д��һ�ᷢ��û�취������
	2���ȴ��м�����0��ʼ�ҵ���һ��δ�����Ԫ�ص�λ�ã��Ƚ��м����кͳ�ʼ����֮���Ԫ�أ���ͬ���ǲ������򣬲�ͬ���ǹ鲢����
	3���Թ鲢���򣬱������ÿ��м����о������ι鲢�ű�������ģ��ҳ��м����е���С�鲢���ȣ���Ȼ�����С���ȷ����ٹ鲢һ�������
	����������Ե���󡣺�������˵Ӧ�öԳ�ʼ���д�1��n�Ĺ鲢���Ƚ��й鲢��ͬʱ�����м������Ƿ���ͬ���Ӷ��ҵ��鲢���ȡ�
	��һ�ҵ�����С�鲢���Ȳ�̫׼
	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",num+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",num2+i);
	}
	bool ismerge=true,issort=true;
	int i=0;//�ȴ�0��ʼ�ҵ���һ��δ�����Ԫ�ص�λ��
	for(;i<n-1;i++){
		if(num2[i]>num2[i+1]){
			break;
		}
	}
	for(int j=i+1;j<n;j++){//�Ƚ�δ����󲿷�Ԫ���Ƿ����ʼλ��һһ��Ӧ����Ӧ�Ļ����ǲ�������
		if(num2[j]!=num[j]){
			issort=false;
			break;
		}
	}
	if(issort){
		printf("Insertion Sort\n");
		sort(num2,num2+i+2);
	}else{
		printf("Merge Sort\n");
		int size=2;
		bool flag=true;
		//��Num��size��2��ʼ����ÿsize��Ԫ�ؽ��й鲢���򣬹鲢��Ƚ���Num2�Ƿ���ͬ����ͬ�Ļ��˳�������size��������
		while(flag&&size<=n){
			flag=false;
			for(int j=0;j<n;j=j+size){
				if(j+size<n){
					sort(num+j,num+j+size);
				}else{
					sort(num+j,num+n);
				}
			}
			for(int i=0;i<n;i++){
				if(num[i]!=num2[i]){
					flag=true;
					break;
				}
			}
			size=(size*2>n)?n:size*2;
			if(!flag){
				break;
			}
		}
		for(int j=0;j<n;j=j+size){
			if(j+size<n){
				sort(num2+j,num2+j+size);
			}else{
				sort(num2+j,num2+n);
			}

		}
	}
	for(int a=0;a<n;a++){
		printf("%d",num2[a]);
		if(a!=n-1){
			printf(" ");
		}
	}
	return 0;
}