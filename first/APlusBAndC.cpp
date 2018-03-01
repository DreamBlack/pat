#include<stdio.h>
int main(){
	/*
	题目大意：三个大小在大小为[-2^63, 2^63]内的数判断前两个相加是否大于第三个
	解题思路：用溢出判断
	但是遇到两个测试点过不了，可能是if判断里面用了a+b>c这个语句。换成sum=a+b,if(sum>c)即可
	*/
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long sum=a+b;
		if(a>0&&b>0&&sum<0){//两个正数相加溢出
			printf("Case #%d: true\n",i);
		}else if(a<0&&b<0&&sum>=0){//两个负数相加溢出
			printf("Case #%d: false\n",i);
		}else if(sum>c){
			printf("Case #%d: true\n",i);
		}else{
			printf("Case #%d: false\n",i);
		}
		
	}
	return 0;
}