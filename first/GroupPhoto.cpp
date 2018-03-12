#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct Person{
	char name[10];
	int height;
};
bool cmp(Person a,Person b){
	if(a.height>b.height){
		return true;
	}else if(a.height<b.height){
		return false;
	}else{
		return (strcmp(a.name,b.name)<0)?true:false;
	}
}
int main(){
	/*
	题目大意：题意：n个人，要拍成k行排队，每行 n/k人，多余的都在最后一排。从第一排到最后一排个子是逐渐增高的，即后一排最低
	的个子要>=前一排的所有人每排排列规则如下：1.中间m/2+1为该排最高；2.其他人按各自降序顺序，轮流排到中间最高的左边和右边；
	3.当个子一样高时，名字按字典序顺序，靠前的先排入队伍。
	解题思路：
	1、一开始先处理最高的那一排，之后对其他排分别处理。有三个段错误。其中一个是当只排成一排的时候。
	2、参考了网上的代码，对于k排，每一排一视同仁的处理，先放中间位置的人，后用两个指针分别从中间向两边排
	*/
	int n,k;
	scanf("%d%d",&n,&k);
	vector<Person> people;
	people.resize(n);
	for(int i=0;i<n;i++){
		Person p;
		scanf("%s %d",p.name,&(p.height));
		people.push_back(p);
	}
	sort(people.begin(),people.end(),cmp);
	int m=n/k;
	int lastm=n-(k-1)*m;
	int nowr=k;
	int cnt=0;
	while(nowr>0){
		vector<Person> nowrow;
		int mid;
		if(k==nowr){//当前为最后一排
			nowrow.resize(lastm);
			mid=lastm/2;
		}else{
			nowrow.resize(m);
			mid=m/2;
		}
		int left=mid-1,right=mid+1;
		nowrow[mid]=people[cnt++];
		int nowcount=1;
		while(left>=0&&right<nowrow.size()){
			if(left>=0){
				nowrow[left--]=people[cnt++];
				nowcount++;
			}
			if(right<nowrow.size()){
				nowrow[right++]=people[cnt++];
				nowcount++;
			}
		}
		for(int i=0;i<nowrow.size();i++){
			printf("%s",nowrow[i].name);
			if(i!=nowrow.size()-1){
				printf(" ");
			}
		}
		if(nowr!=1){
			printf("\n");
		}
		nowr--;
	}
	return 0;
}