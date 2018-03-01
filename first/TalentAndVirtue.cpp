#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct Person{
	int id;
	int talent;
	int virtue;
	int type;
};
bool cmp(Person a,Person b){
	if(a.type>b.type){
		return true;
	}else if(a.type==b.type){
		if(a.talent+a.virtue>b.talent+b.virtue){
			return true;
		}else if(a.talent+a.virtue==b.talent+b.virtue){
			if(a.virtue>b.virtue){
				return true;
			}else if(a.virtue==b.virtue){
				if(a.id<b.id){
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
			
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main(){
	/*
	题目大意：输入第1行给出3个正整数，分别为：N为考生总数；L为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；
	H为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，
	也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，
	但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。输出第1行首先给出达到最低分数线的考生人数M，
	随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；
	若德分也并列，则按准考证号的升序输出。
	解题思路：结构体排序题
	要注意的是题目一定要仔细看。第一次没看到foolman的德和才可以相同，导致有三个测试点没过，才的16分。简直太坑
	*/
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	vector<Person> p;
	for(int i=0;i<n;i++){
		Person temp;
		scanf("%d%d%d",&(temp.id),&(temp.virtue),&(temp.talent));
		if(temp.talent>=l&&temp.virtue>=l){
			if(temp.talent>=h&&temp.virtue>=h){//sage
				temp.type=3;
			}else if(temp.talent<h&&temp.virtue>=h){//nobleman
				temp.type=2;
			}else if(temp.talent<h&&temp.virtue<h&&temp.virtue>=temp.talent){//foolman
				temp.type=1;
			}else{
				temp.type=0;
			}
			p.push_back(temp);
		}
	}
	if(p.empty()){
		printf("0");
	}else{
		sort(p.begin(),p.end(),cmp);
		printf("%d\n",p.size());
		for(int i=0;i<p.size();i++){
			printf("%d %d %d",p[i].id,p[i].virtue,p[i].talent);
			if(i!=p.size()-1){
				printf("\n");
			}
		}
	}
	return 0;
}