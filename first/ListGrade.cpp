#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Record{
	char name[11];
	char id[11];
	int grade;
};
bool cmp(Record a,Record b){
	return (a.grade>b.grade)?true:false;
}
int main(){
	/*
	题目大意：给出n个考生的信息，按照分数从高到低排序，并且输出给定区间的考生信息。如果不存在满足条件的考生就输出NONE。
	解题思路：最简单的排序题
	*/
	int n;
	scanf("%d",&n);
	int gradelow,gradehigh;
	vector<Record> rds;
	for(int i=0;i<n;i++){
		Record tmp;
		scanf("%s%s%d",tmp.name,tmp.id,&(tmp.grade));
		rds.push_back(tmp);
	}
	scanf("%d%d",&gradelow,&gradehigh);
	
	vector<Record> out;
	for(int i=0;i<rds.size();i++){
		if(rds[i].grade<=gradehigh&&rds[i].grade>=gradelow){
			out.push_back(rds[i]);
		}
	}
	if(out.empty()){
		printf("NONE");
		return 0;
	}
	sort(out.begin(),out.end(),cmp);
	for(int i=0;i<out.size();i++){
		printf("%s %s",out[i].name,out[i].id);
		if(i!=out.size()-1){
			printf("\n");
		}
	}
	return 0;
}