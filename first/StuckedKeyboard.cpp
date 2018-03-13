#include<stdio.h>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main(){
	/*
	题目大意：键盘某些键卡住了，按一次重复k次，要求找出可能的键，并且输出正确的字符串顺序。可能的键要求按照被发现的顺序输出。
	解题思路：
	解题思路：一个两分的点错误。没找出来
	*/
	int k;
	scanf("%d",&k);
	char input[1001];
	scanf("%s",input);
	string in(input);
	char out[1001];
	set<char>stucked,unstucked;
	vector<char>s;
	int cnt=0;
	for(int j=0;j<in.size();j++){
		char tmp=in[j];
		int i=j+1,count=1;
		while(i<in.size()&&in[i]==tmp){
			i++;
			count++;
		}
		if(count%k==0&&unstucked.count(tmp)==0){
			j=i-1;
			while(count/k>0){
				out[cnt++]=tmp;
				count-=k;
			}
			if(stucked.count(tmp)==0){//之前没有出现过的
				stucked.insert(tmp);
				s.push_back(tmp);
			}
		}else{
			out[cnt++]=tmp;
			unstucked.insert(tmp);
		}
	}
	out[cnt]='\0';
		for(int i=0;i<s.size();i++){
			printf("%c",s[i]);
				
		}
		
	printf("\n");
	printf("%s",out);
	return 0;
}