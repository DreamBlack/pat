#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
struct Person{
	char name[9];
	int age;
	int worth;
};
vector<Person> persons;
bool cmpAge(Person a,Person b){
	return (a.age<b.age)?true:false;
}
bool cmpAll(Person a,Person b){
	if(a.worth<b.worth){
		return false;
	}else if(a.worth==b.worth){
		if(a.age<b.age){
			return true;
		}else if(a.age==b.age){
			if(strcmp(a.name,b.name)<0){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return true;
	}
}
int query[201];
int main(){
	/*
	题目大意：给出n个人的姓名、年龄和拥有的钱，然后进行k次查询，每次查询输出在年龄区间内的财富值的从大到小的前m个人的信息。
	如果财富值相同就就先输出年龄小的，如果年龄相同就把名字按照字典序排序输出～
	解题思路：
	1、开始的思路是先对所有人的年龄进行排序，对于每一个查询找到对应年龄范围的人，再对这个范围的人的钱降序排序，最后两个测试点错误，一个超时
	2、用1的时候，每次对于某个年龄范围内的人进行排序，人数可能达到100000，所有导致超时。但其实每个年龄范围要输出的人数是100以内的，100以内的排序相对
	快很多。所有先对所有人进行一个资产后年龄后姓名的排序。排序之后按序遍历所有人用一个数组query[201]来记录（0,200]这每个年龄对应的人数。
	当某个年龄段人数超过100的时候就不记录到新的剔除了不可能输出的人总列表中（超过100以后且资产较少的绝对不会需要输出）。
	因为剔除了很多元素，这样再对于每个查询输出遍历整个数组寻找满足符合条件的数据时间就会变小。这个过程只需一次排序
	3、对于年龄这种整型，想到用hash。
	4、效率要求高的排序。尽量一次排序达到需求。可以多次遍历
	*/
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		Person p;
		scanf("%s %d %d",p.name,&(p.age),&(p.worth));
		persons.push_back(p);
	}
	sort(persons.begin(),persons.end(),cmpAll);
	vector<Person> np;
	for(int i=0;i<n;i++){
		if(query[persons[i].age]<=100){
			query[persons[i].age]++;
			np.push_back(persons[i]);//已排序遍历保证np中的也是有序的但是提出了很多其他不可能需要输出的元素
		}
	}
	for(int i=1;i<=k;i++){
		printf("Case #%d:\n",i);
		int m,left,right;
		scanf("%d%d%d",&m,&left,&right);
		vector<Person> qn;
		for(int j=0;j<np.size();j++){
			if(np[j].age>=left&&np[j].age<=right){
				qn.push_back(np[j]);
			}
		}
		if(qn.empty()){
			printf("None\n");
		}else{
			for(int j=0;j<qn.size();j++){
				printf("%s %d %d\n",qn[j].name,qn[j].age,qn[j].worth);
				if(j==m-1){
					break;
				}
			}
		}	
	}
	return 0;
}