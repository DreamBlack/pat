#include<stdio.h>
#include<string>
using namespace std;
char a[10000];
char b[10000];
struct NFloat{
	string s;
	int exp;
};
using namespace std;
int main(){
	/*
	题目大意：给出两个数，问将它们写成保留N位小数的科学计数法后是否相等(小数第一位不为0)。如果相等，输出YES，输出他们的科学记数法表示方法。
	如果不相等输出NO，分别输出他们的科学计数法
	解题思路：
	1、除了123.11还有可能出现0.003这种真小数
	2、还有可能有00000,00001这种测试点。所以关键在于找到第一个非0的数字出现的位置以及小数点的位置
	3、因为没有考虑1有四个测试点错误，解决1和2之后还有一个测试点错误不知道为啥。后来推翻重写
	4、先找到第一个非0数的位置即为posvalid，以及‘.’小数点的位置即为posdot，注意哪个在前哪个在后
	5、见鬼了，最后还是有一个测试点错误
	*/
	int n;
	scanf("%d",&n);
	NFloat f[2];
	for(int i=0;i<2;i++){
		scanf("%s",a);
		string tmps(a);
		NFloat temp;
		int posvalid=-1,posdot=-1;
		for(int j=0;j<tmps.size();j++){
			if(tmps[j]!='0'&&tmps[j]!='.'){
				posvalid=j;
				break;
			}
		}
		posdot=tmps.find('.');
		if(posvalid==-1){//0
			temp.exp=0;
			tmps="0";
		}else{
			if(posvalid!=0){//第一位不是有效位
				tmps.erase(0,posvalid);
			}
			if(posdot!=-1){//有小数点
				if(posdot<posvalid){//小数点在有效位之前
					temp.exp=posdot-posvalid+1;
				}else{
					tmps.erase(posdot,1);
					temp.exp=posdot-posvalid;
				}
			}else{//没有小数点
				temp.exp=tmps.size();
			}
		}
		
		if(tmps.size()<n){
			while(tmps.size()<n){
				tmps.insert(tmps.size(),"0");
			}
			temp.s=tmps;
		}else{
			temp.s=tmps.substr(0,n);
		}
		if(n==0){
			temp.s="0";
			temp.exp=0;
		}
		f[i]=temp;
	}
	if(f[1].exp==f[0].exp&&f[0].s.compare(f[1].s)==0){
		printf("YES 0.%s*10^%d",f[0].s.c_str(),f[0].exp);
	}else{
		printf("NO 0.%s*10^%d 0.%s*10^%d",f[0].s.c_str(),f[0].exp,f[1].s.c_str(),f[1].exp);
	}

	return 0;
}