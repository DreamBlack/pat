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
	题目大意：给出散列表长和要插入的元素，将这些元素按照读入的顺序插入散列表中，其中散列函数为h(key) = key % TSize，
	解决冲突采用只向正向增加的二次方探查法。如果题中给出的TSize不是素数，就取第一个比TSize大的素数作为TSize
	题目分析：
	1、注意1不是素数，应该使其表容量为2，开始这个点没弄好导致一个测试点错误
	2、二次探查公式注意是(key + step * step) % size 而不是(key % size + step * step)这个错了导致最后一个5分的点没过
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