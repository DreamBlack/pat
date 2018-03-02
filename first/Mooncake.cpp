#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Mooncake{
	double amount;
	double price;
	double pprice;
};
vector<Mooncake> cakes(1000);
int cmp(Mooncake a,Mooncake b){
	return(a.pprice>b.pprice)?true:false;
}
int main(){
	/*
	小学数学题
	*/
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++){
		double t;
		scanf("%lf",&t);
		cakes[i].amount=t;
	}
	for(int i=0;i<n;i++){
		double t;
		scanf("%lf",&t);
		cakes[i].price=t;
		cakes[i].pprice=t/(cakes[i].amount);
	}
	double profit=0,nowAmount=0;
	int i=0;
	sort(cakes.begin(),cakes.begin()+n,cmp);
	while(d!=0&&i<n){
		nowAmount=(d>cakes[i].amount)?cakes[i].amount:d;
		d=d-nowAmount;
		profit+=cakes[i].pprice*nowAmount;
		i++;
	}
	printf("%.2f",profit);
	return 0;
}