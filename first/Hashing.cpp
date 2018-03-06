#include<stdio.h>
#include<vector>
using namespace std;
bool nume[10000];
int numpos[10000]={-1};

bool isPrime(int num){
	if(num==1)return false;
	for(int i=2;i<num;i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
int minPrime(int m){
	while(!isPrime(m)){
		m++;
	}
	return m;
}
int main(){
	/*
	��Ŀ���⣺����ɢ�б���Ҫ�����Ԫ�أ�����ЩԪ�ذ��ն����˳�����ɢ�б��У�����ɢ�к���Ϊh(key) = key % TSize��
	�����ͻ����ֻ���������ӵĶ��η�̽�鷨��������и�����TSize������������ȡ��һ����TSize���������ΪTSize
	��Ŀ������
	1��ע��1����������Ӧ��ʹ�������Ϊ2����ʼ�����ûŪ�õ���һ�����Ե����
	2������̽�鹫ʽע����(key + step * step) % size ������(key % size + step * step)������˵������һ��5�ֵĵ�û��
	*/
	int msize,n;
	scanf("%d%d",&msize,&n);
	if(!isPrime(msize)){
		msize=minPrime(msize);
	}
	
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		int pos=tmp%msize;
		if(nume[pos]){
			int k=1,newpos=(tmp+k*k)%msize;
			while(newpos<msize&&nume[newpos]){
				newpos=(tmp+k*k)%msize;
				k++;
			}
			if(newpos<msize&&!nume[newpos]){
				pos=newpos;
				nume[pos]=true;
				numpos[i]=pos;
			}else{
				numpos[i]=-1;
			}
		}else{
			nume[pos]=true;
			numpos[i]=pos;
		}
	}
	for(int i=0;i<n;i++){
		if(numpos[i]!=-1){
			printf("%d",numpos[i]);
		}else{
			printf("%s","-");
		}
		if(i!=n-1){
			printf(" ");
		}
	}
	return 0;
}