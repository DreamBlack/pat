#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
struct Rational{
	long long int in;
	long long int a,b;
};
long long int gongyue(long long int a,long long int b){
	long long int ret=1;
	for(long long int i=2;i<=a&&i<b;i++){
		long long int ta=(a)%i;
		long long int tb=(b)%i;
		if(ta==0&&tb==0){
			a=a/i;
			b=b/i;
			ret=ret*i;
			i=1;
		}
	}
	return ret*a*b;
}
void yuefen(Rational &m){
	for(long long int i=2;i<=m.a&&i<=m.b;i++){
		long long int ta=(m.a)%i;
		long long int tb=(m.b)%i;
		if(ta==0&&tb==0){
			m.a=m.a/i;
			m.b=m.b/i;
			i=1;
		}
	}
}
Rational add(Rational a,Rational b){
	Rational tmp={0,0,0};
	yuefen(a);
	yuefen(b);
	int newfenmu=gongyue(a.b,b.b);
	a.a=a.a*(newfenmu/a.b);
	b.a=b.a*(newfenmu/b.b);
	a.b=newfenmu;
	b.b=newfenmu;
	tmp.b=newfenmu;
	tmp.a=a.a+b.a;
	yuefen(tmp);
	return tmp;

}
int main(){
	/*
	题目大意：给N个有理数（以分子/分母的形式给出），计算这N个数的总和，最后总和要以（整数 分子/分母）的形式给出～
	解题思路：
	1、这道题累死人。先对每个数约分再进行加减。加减之前先通分
	2、就是比较烦
	3、对于正负数可以直接用scanf("%lld/%lld", &a, &b);处理
	*/
	int n;
	scanf("%d",&n);
	vector<Rational> rs(n);
	for(int i=0;i<n;i++){
		Rational tmp;
		char num[100];
		scanf("%s",num);
		string s(num);
		int sep=-1;
		for(int j=0;j<s.size();j++){
			if(s[j]=='/'){
				sep=j;
				break;
			}
		}
		long long int a=0,b=0;
		string ts;
		if(s[0]=='-'){
			for(int j=1;j<sep;j++){
				a=a*10+(s[j]-'0');
			}
			tmp.a=-a;
		}else{
			for(int j=0;j<sep;j++){
				a=a*10+(s[j]-'0');
			}
			tmp.a=a;
		}
		for(int j=sep+1;j<s.size();j++){
				b=b*10+(s[j]-'0');
		}
		tmp.b=b;
		rs[i]=tmp;
	}
	Rational addone={0,0,1};
	for(int i=0;i<n;i++){
		addone=add(addone,rs[i]);
	}
	if(addone.a==0){
		printf("0");
	}else{
		int q=addone.a/addone.b;
		int z=addone.a%addone.b;
		if(q>0){
			printf("%d",q);
			addone.a=addone.a-q*addone.b;
		}
		if(z!=0){
			if(q!=0){
				printf(" ");
			}
			printf("%lld/",addone.a);
			printf("%lld",addone.b);
		}
	}
	return 0;
}