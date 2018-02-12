#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct Student{
	char name[11];
	char id[11];
	int grade;
	char gender;
};
vector<Student> girls;
vector<Student> boys;
bool cmp(Student a,Student b){
	return (a.grade<b.grade)?true:false;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Student tmp;
		scanf("%s %c %s %d",tmp.name,&tmp.gender,tmp.id,&tmp.grade);
		if(tmp.gender=='M'){
			boys.push_back(tmp);
		}else{
			girls.push_back(tmp);
		}
	}
	int ng=0,nb=0;
	if(!girls.empty()){
		ng=girls.size();
		sort(girls.begin(),girls.end(),cmp);
	}
	if(!boys.empty()){
		nb=boys.size();
		sort(boys.begin(),boys.end(),cmp);
	}
	bool diff=true;
	if(ng==0){
		printf("Absent\n");
		diff=false;
	}else{
		printf("%s %s\n",girls[ng-1].name,girls[ng-1].id);
	}
	if(nb==0){
		printf("Absent\n");
		diff=false;
	}else{
		printf("%s %s\n",boys[0].name,boys[0].id);
	}
	if(diff){
		printf("%d",girls[ng-1].grade-boys[0].grade);
	}else{
		printf("NA");
	}
	
	return 0;
}