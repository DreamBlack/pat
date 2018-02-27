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
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		Person p;
		scanf("%s %d %d",p.name,&(p.age),&(p.worth));
		persons.push_back(p);
	}
	sort(persons.begin(),persons.end(),cmpAge);
	for(int i=1;i<=k;i++){
		printf("Case #%d:\n",i);
		int m,left,right;
		scanf("%d%d%d",&m,&left,&right);
		int min=-1,max=-1;
		for(int j=0;j<persons.size();j++){
			if(persons[j].age<left){
				min=j;
			}
			if(persons[j].age>right){
				max=j;
				break;
			}
		}
		if(min==-1&&max==-1&&persons[0].age>left){
			printf("None\n");
		}else{
			if(min==-1){
				min=0;
			}else{
				++min;
			}
			if(max==-1){
				max=persons.size()-1;
			}else{
				max--;
			}
			
			if(min>max){
				printf("None\n");
			}else{
				
				sort(persons.begin()+min,persons.begin()+max+1,cmpAll);
				
				for(int i=min;i<=max;i++){
					printf("%s %d %d\n",persons[i].name,persons[i].age,persons[i].worth);
					if(i-min+1==m){
						break;
					}
				}
				sort(persons.begin()+min,persons.begin()+max+1,cmpAge);
			}

		}
	}
	return 0;
}