#include<stdio.h>
#include<string>
using namespace std;
char str[100001];
int main(){
	/*
	题目大意：给一串只有P\A\T三种字符的串。记录能构成多少个pat子串
	解题思路：
	1、开始用的暴力法，三个指针，三次查找O(N^3)，全部超时
	2、其实，仔细想想，要想知道构成多少个PAT，那么遍历字符串后对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。
	前面的P的个数很好解决，遍历的时候记录就行。后面的T的个数可以先遍历一遍记录总的T的个数，则第二次遍历的时候每遇到一个T就减一，
	则就知道后面有多少个T
	3、这个题要好好看，用到数学思想,排列组合。不要暴力
	*/
	scanf("%s",str);
	string ins(str);
	long long int cnt=0;
	int countp=0,countt=0;
	for(int i=0;i<ins.size();i++){
		if(ins[i]=='T'){
			countt++;
		}
	}
	for(int i=0;i<ins.size();i++){
		if(ins[i]=='T'){
			countt--;
		}else if(ins[i]=='P'){
			countp++;
		}else{
			cnt+=countp*countt;
		}
	}
	printf("%lld",(cnt)%1000000007);
	return 0;
}