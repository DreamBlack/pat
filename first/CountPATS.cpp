#include<stdio.h>
#include<string>
using namespace std;
char str[100001];
int main(){
	/*
	��Ŀ���⣺��һ��ֻ��P\A\T�����ַ��Ĵ�����¼�ܹ��ɶ��ٸ�pat�Ӵ�
	����˼·��
	1����ʼ�õı�����������ָ�룬���β���O(N^3)��ȫ����ʱ
	2����ʵ����ϸ���룬Ҫ��֪�����ɶ��ٸ�PAT����ô�����ַ��������ÿһA����ǰ���P�ĸ������������T�ĸ����ĳ˻������ܹ��ɵ�PAT�ĸ�����
	ǰ���P�ĸ����ܺý����������ʱ���¼���С������T�ĸ��������ȱ���һ���¼�ܵ�T�ĸ�������ڶ��α�����ʱ��ÿ����һ��T�ͼ�һ��
	���֪�������ж��ٸ�T
	3�������Ҫ�úÿ����õ���ѧ˼��,������ϡ���Ҫ����
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