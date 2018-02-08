#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct Stud{
	char id[8];
	char name[9];
	int grade;
};
bool cmpId(Stud a,Stud b){
	if(strcmp(a.id,b.id)<0){
		return true;
	}else{
		return false;
	}
}
bool cmpName(Stud a,Stud b){
	if(strcmp(a.name,b.name)<0){
		return true;
	}else if(strcmp(a.name,b.name)==0){
		if(strcmp(a.id,b.id)<0){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}

}
bool cmpGrade(Stud a,Stud b){
	if(a.grade<b.grade){
		return true;
	}else if(a.grade==b.grade){
		if(strcmp(a.id,b.id)<0){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}

}
int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	vector<Stud> stds;
	for(int i=0;i<n;i++){
		Stud temp;
		scanf("%s %s %d",temp.id,temp.name,&temp.grade);
		stds.push_back(temp);
	}
	switch(c){
	case 1:
		sort(stds.begin(),stds.end(),cmpId);
		break;
	case 2:
		sort(stds.begin(),stds.end(),cmpName);
		break;
	case 3:
		sort(stds.begin(),stds.end(),cmpGrade);
		break;
	default:break;
	}
	for(int i=0;i<n;i++){
		printf("%s %s %d\n",stds[i].id,stds[i].name,stds[i].grade);
	}
	return 0;
}