#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> stds[26*26*26*10+10];
int hashName(char* name){
	return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
}
int main(){
	/*
	��Ŀ���⣺��N��ѧ����K�ſΣ�����ѡ��ÿ�ſε�ѧ�������������ڸ�����N��ѧ����������ѡ���������ѯ�ʣ�
	Ҫ��˳�����ÿ��ѧ����ѡ�������
	����˼·��
	1���տ�ʼֱ�Ӽ�д�˸�map<string, vector<int> > ֱ���������һ��case��ʱ
	2������˵���ָ�ʽ�ܱ�׼��ֻ��4λ����ǰ��λΪ��д��ĸ���һλΪ���飬
	��Ϊ�ַ����ĸ��ֲ���cin,cout�����൱��ʱ�ģ�����ܽ����ֹ�ϣΪ��Ӧ��һ��Ψһ���������ٶȿ�ܶ�
	3��name��3����д��ĸ��һλ������ɣ��������MAX=26*26*26*10��ѧ������Ҫ��name������id֮���ӳ��
	*/
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		int courseNum,stdsNum;
		scanf("%d%d",&courseNum,&stdsNum);
		for(int j=0;j<stdsNum;j++){
			char stdName[5];
			scanf("%s",stdName);
			stds[hashName(stdName)].push_back(courseNum);
		}
	}
	for(int i=0;i<n;i++){
		char stdName[5];
		scanf("%s",stdName);
		printf("%s %d",stdName,stds[hashName(stdName)].size());
		sort(stds[hashName(stdName)].begin(),stds[hashName(stdName)].end());
		for(int i=0;i<stds[hashName(stdName)].size();i++){
			printf(" %d",stds[hashName(stdName)][i]);
		}
		if(i!=n-1){
			printf("\n");
		}
	}
	return 0;
}