#include<stdio.h>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> schools[100];
int quota[100];
struct Student{
	int ge,gi,rank;
	double gfinal;
	vector<int>prefers;
	int id;
};
vector<Student> stds(40000);
bool cmp(Student a,Student b){
	if(a.gfinal>b.gfinal){
		return true;
	}else if(a.gfinal==b.gfinal){
		if(a.ge>b.ge){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main(){
	/*
	题目大意：每个考生有两个成绩：GE和GI，最终成绩为(GE + GI) / 2;按照最终成绩排名，如果最终成绩相同，就按照GE排名，如果仍然相同，他们的排名就是相同的。
	每个申请者有K个选择院校，每个学校也有招生人数限制。
	按照排名先后，如果当前考生的第一个志愿学校的名额还没满，就录取进去；如果当前志愿名额满了但是该校最后一个录取的人的排名和当前考生相同，
	则不管招生人数限制，依旧应该被录取；否则考虑该生的下一个志愿。如果所有志愿都没有能被录取，则该生落榜
	解题思路：
	1、设立student结构体，存储学生的id（防止排序后id打乱了顺序），GE和GI的成绩，总评成绩，排名，志愿学校的列表数组。
	2、对stds数组进行排序。之后遍历这个数组，为每个学生分配志愿。当当前学生和之前的学生最终成绩相同，ge相同且志愿学校和之前那个学生的志愿学校相同时
	即使志愿学校人数已满也为其分配。
	3、一遍过。超开心！
	*/
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",quota+i);
	}
	for(int i=0;i<n;i++){
		Student tmp;
		scanf("%d%d",&(tmp.ge),&(tmp.gi));
		for(int j=0;j<k;j++){
			int t;
			scanf("%d",&t);
			tmp.prefers.push_back(t);
		}
		tmp.gfinal=(double)(tmp.ge+tmp.gi)/2;
		tmp.id=i;
		stds[i]=tmp;
	}
	//进行排名
	sort(stds.begin(),stds.begin()+n,cmp);
	int rank=0,lastsch=-1,lasfinal=INT_MAX,nowsch=0,nofg=0,lastge=INT_MAX;
	for(int i=0;i<n;i++){
		bool iskuozhao=false;
		if(stds[i].gfinal<lasfinal){
			rank++;
			lasfinal=stds[i].gfinal;
			lastge=stds[i].ge;
		}else if(stds[i].gfinal==lasfinal){
			if(stds[i].ge<lastge){
				rank++;
				lastge=stds[i].ge;
			}else if(stds[i].gfinal==lasfinal){
				//排名相同按志愿录取
				iskuozhao=true;
			}//不可能在最终成绩相同的情况下比上一个人的ge大
		}//不可能比上一个人的成绩大
		//按志愿录取，找到第一个没有满的志愿
		nowsch=-1;
		if(!iskuozhao){
			//不需要考虑扩招
			for(int j=0;j<k;j++){
				if(quota[stds[i].prefers[j]]>0){
					nowsch=stds[i].prefers[j];
					break;
				}
			}
		}else{
			for(int j=0;j<k;j++){
				if(stds[i].prefers[j]==lastsch){
					nowsch=stds[i].prefers[j];
					break;
				}
				if(quota[stds[i].prefers[j]]>0){
					nowsch=stds[i].prefers[j];
					break;
				}
			}
			
		}
		if(nowsch!=-1){
			schools[nowsch].push_back(stds[i].id);
			quota[nowsch]=(quota[nowsch]>0)?quota[nowsch]-1:0;
			lastsch=nowsch;
		}else{//
		}
	}
	for(int i=0;i<m;i++){
		if(schools[i].empty()){
			printf("\n");
		}else{
			sort(schools[i].begin(),schools[i].end());
			for(int j=0;j<schools[i].size();j++){
				printf("%d",schools[i][j]);
				if(j!=schools[i].size()-1){
					printf(" ");
				}
			}
			if(i!=m-1){
				printf("\n");
			}
		}
		
	}
	return 0;
}