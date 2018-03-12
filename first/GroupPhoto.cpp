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
	��Ŀ���⣺���⣺n���ˣ�Ҫ�ĳ�k���Ŷӣ�ÿ�� n/k�ˣ�����Ķ������һ�š��ӵ�һ�ŵ����һ�Ÿ����������ߵģ�����һ�����
	�ĸ���Ҫ>=ǰһ�ŵ�������ÿ�����й������£�1.�м�m/2+1Ϊ������ߣ�2.�����˰����Խ���˳�������ŵ��м���ߵ���ߺ��ұߣ�
	3.������һ����ʱ�����ְ��ֵ���˳�򣬿�ǰ����������顣
	����˼·��
	1��һ��ʼ�ȴ�����ߵ���һ�ţ�֮��������ŷֱ����������δ�������һ���ǵ�ֻ�ų�һ�ŵ�ʱ��
	2���ο������ϵĴ��룬����k�ţ�ÿһ��һ��ͬ�ʵĴ����ȷ��м�λ�õ��ˣ���������ָ��ֱ���м���������
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
		if(k==nowr){//��ǰΪ���һ��
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