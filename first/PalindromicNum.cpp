#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string bigNumAdd(string s1,string s2){
	//有进位返回true,否则返回false
	int cnt=0,res=0;
	string ret=s1;
	int l1=s1.size()-1,l2=s2.size()-1;
	for(int i=l1;i>=0;i--){
		ret[i]=s1[i]+s2[i]+cnt-'0';//int转换为char时，只是把int的值理解为一个asii码，所以只要减一个‘0’就行
		if(ret[i]>'9'){//超过9
			cnt=1;
			ret[i]=ret[i]-10;//一个大于10的数减去10就相当于%10的余数
		}else{
			cnt=0;
		}
	}
	if(cnt==1){
		ret.insert(0,"1");
	}
	return ret;
}

int main(){
	/*
	题目大意：给定一个数字，和允许翻转后相加的次数cnt，求要多少次才能变成一个回文数字，
	输出那个回文数字和翻转相加了多少次，如果本身就是回文数字就输出0次，如果超过给定的次数cnt了，
	就输出那个不是回文的结果，并且输出给定的次数cnt
	解题思路：
	1、本来是觉得Int不够用所以用了Long long。打算提交后发现还是有两个用例过不了。原因是Longlong还是不够大，溢出了
	输入的num最大为10000000000,经过k（100）次
	2、所以只好改为int数组处理
	3、结果用int的时候，提交到牛客是对的，提交到PAT的就发生了段错误。。不知道哪里错了。
	好吧，直接改用string吧，比较string自带reverse
	总结：对于数很大没法用基本类型表示的时候，尽量直接用string表示方便快捷
	*/
	string s;
	cin>>s;
	int k;
	scanf("%d",&k);
	int step=0;
	bool ispal=false;
	string rev=s;
	while(step<k){
		rev=s;
		reverse(rev.begin(),rev.end());
		if(s.compare(rev)==0){
			break;
		}else{
			step++;
			s=bigNumAdd(s,rev);
			
		}
	}
	
	
	cout<<s<<endl;
	printf("%d",step);
	return 0;

}