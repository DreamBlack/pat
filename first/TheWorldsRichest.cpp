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
	��Ŀ���⣺����n���˵������������ӵ�е�Ǯ��Ȼ�����k�β�ѯ��ÿ�β�ѯ��������������ڵĲƸ�ֵ�ĴӴ�С��ǰm���˵���Ϣ��
	����Ƹ�ֵ��ͬ�;����������С�ģ����������ͬ�Ͱ����ְ����ֵ������������
	����˼·��
	1����ʼ��˼·���ȶ������˵�����������򣬶���ÿһ����ѯ�ҵ���Ӧ���䷶Χ���ˣ��ٶ������Χ���˵�Ǯ������������������Ե����һ����ʱ
	2����1��ʱ��ÿ�ζ���ĳ�����䷶Χ�ڵ��˽��������������ܴﵽ100000�����е��³�ʱ������ʵÿ�����䷶ΧҪ�����������100���ڵģ�100���ڵ��������
	��ܶࡣ�����ȶ������˽���һ���ʲ����������������������֮���������������һ������query[201]����¼��0,200]��ÿ�������Ӧ��������
	��ĳ���������������100��ʱ��Ͳ���¼���µ��޳��˲���������������б��У�����100�Ժ����ʲ����ٵľ��Բ�����Ҫ�������
	��Ϊ�޳��˺ܶ�Ԫ�أ������ٶ���ÿ����ѯ���������������Ѱ�������������������ʱ��ͻ��С���������ֻ��һ������
	3�����������������ͣ��뵽��hash��
	4��Ч��Ҫ��ߵ����򡣾���һ������ﵽ���󡣿��Զ�α���
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
			np.push_back(persons[i]);//�����������֤np�е�Ҳ������ĵ�������˺ܶ�������������Ҫ�����Ԫ��
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