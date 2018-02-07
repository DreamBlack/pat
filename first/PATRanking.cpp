#include<string>
#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct Testee{
	string number;
	int grade;
	int loc_number;
	int loc_rank;
	int all_rank;
};

bool cmp(Testee a,Testee b){
	if(a.grade>b.grade){//先比较分数
		return true;
	}else if(a.grade==b.grade){//分数相同比较number
		if(a.number.compare(b.number)<0){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int allnum=0,nowlocnum=0;
	vector<Testee> tmp;
	vector<Testee> alltestees;
	for(int i=0;i<n;i++){
		scanf("%d",&nowlocnum);
		allnum+=nowlocnum;
		for(int j=0;j<nowlocnum;j++){
			Testee te;
			cin>>te.number;
			cin>>te.grade;
			te.loc_number=(i+1);
			tmp.push_back(te);
		}
		//处理完一个考场的之后
		sort(tmp.begin(),tmp.end(),cmp);
		int rank=1,nowrank=1;
		tmp.at(0).loc_rank=rank;
		//处理考场内成绩
		for(int j=1;j<tmp.size();j++){
			if(tmp.at(j).grade==tmp.at(j-1).grade){
				tmp.at(j).loc_rank=nowrank;
				rank++;
			}else{

				tmp.at(j).loc_rank=++rank;
				nowrank=rank;
			}
		}
		if(i==0){
			alltestees=tmp;
		}else{
			alltestees.insert(alltestees.begin(),tmp.begin(),tmp.end());
		}
		tmp.clear();
	}
	//最后计算总排名
	sort(alltestees.begin(),alltestees.end(),cmp);
	int rank=1,nowrank=1;
	alltestees.at(0).all_rank=rank;
	//处理考场内成绩
	for(int j=1;j<alltestees.size();j++){
		if(alltestees.at(j).grade==alltestees.at(j-1).grade){
			alltestees.at(j).all_rank=nowrank;
			rank++;
		}else{

			alltestees.at(j).all_rank=++rank;
			nowrank=rank;
		}
	}
	printf("%d\n",allnum);
	string number;
	for(int j=0;j<alltestees.size();j++){
		number=alltestees.at(j).number;
		cout<<(alltestees.at(j).number)<<" "<<(alltestees.at(j).all_rank)<<" "<<(alltestees.at(j).loc_number)<<" "<<(alltestees.at(j).loc_rank)<<endl;
	}

	return 0;
}