#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;
struct User{
	int id;
	int totalSore;
	bool exist;
	bool isSolved[6];
	int score[6];
	int totalSolved;
};
int problems[6];
vector<User> all;
map<int,User> in;
bool cmp(User a,User b){
	if(a.totalSore<b.totalSore){
		return false;
	}else if(a.totalSore>b.totalSore){
		return true;
	}else{
		if(a.totalSolved<b.totalSolved){
			return false;
		}else if(a.totalSolved>b.totalSolved){
			return true;
		}else{
			return (a.id<b.id)?true:false;
		}
	}
}
int main(){
	/*
	题目大意：n个用户,k到题目，共m次提交。对那些提交过并且并有某道题目通过编译的人进行排名。按总得分降序、完美AC的题目个数降序，ID升序进行排序排名
	解题思路：烦在题目的理解，要注意以下两点
	1、虽然有某题提交过，但是都没通过编译。不应该输出
	2、虽然有某题提交了，但是分数为0，也是应该输出在排行榜的
	*/
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);

	for(int i=1;i<=k;i++){
		int t;
		scanf("%d",&t);
		problems[i]=t;
	}
	for(int i=0;i<m;i++){
		int id,pro,s;
		scanf("%d%d%d",&id,&pro,&s);
		in[id].id=id;
		if(!in[id].exist){
			fill(in[id].score,in[id].score+k+1,-1);
			in[id].exist=true;
		}
		if(!in[id].isSolved[pro]){
			in[id].isSolved[pro]=true;
		}
		if(in[id].score[pro]<s){
			in[id].score[pro]=s;
		}
	}
	int allnum=0;
	for(auto it=in.begin();it!=in.end();it++){
		if(it->second.exist){
			int at=0,sn=0;
			bool isout=false,hasnozero=true;
			for(int j=1;j<=k;j++){
				if(it->second.score[j]!=-1){
					at+=it->second.score[j];
				}
				if(it->second.isSolved[j]==true&&it->second.score[j]!=-1){//提交了且成绩不是-1
					isout=true;
				}
				if(it->second.score[j]==problems[j]){
					sn++;
				}
			}
			it->second.totalSolved=sn;
			it->second.totalSore=at;
			if(!isout){
				it->second.exist=false;
			}else{
				all.push_back(it->second);
				allnum++;
			}
		}
	}
	sort(all.begin(),all.end(),cmp);
	int rank=1,nows=all[0].totalSore;
	printf("%d %05d %d ",rank,all[0].id,all[0].totalSore);
	for(int j=1;j<=k;j++){
		if(all[0].isSolved[j]){
			if(all[0].score[j]==-1){
				printf("%d",0);
			}else{
				printf("%d",all[0].score[j]);
			}
		}else{
			printf("-");
		}
		if(j!=k){
			printf(" ");
		}else{
			printf("\n");
		}
	}
	for(int i=1;i<all.size();i++){
		if(all[i].totalSore==nows){
			printf("%d %05d %d ",rank,all[i].id,all[i].totalSore);
		}else{
			printf("%d %05d %d ",i+1,all[i].id,all[i].totalSore);
			rank=i+1;
			nows=all[i].totalSore;
		}
		for(int j=1;j<=k;j++){
			if(all[i].isSolved[j]){
				if(all[i].score[j]==-1){
					printf("%d",0);
				}else{
					printf("%d",all[i].score[j]);
				}
			}else{
				printf("-");
			}
			if(j!=k){
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}
	return 0;
}