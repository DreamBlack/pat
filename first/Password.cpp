#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
struct Account{
	bool isModified;
	char name[11];
	char password[11];
};
vector<Account> accs;
int main(){
	int n;
	scanf("%d",&n);
	int m=0;
	for(int i=0;i<n;i++){
		Account tmp;
		scanf("%s %s",tmp.name,tmp.password);
		tmp.isModified=false;
		char* tmpString=tmp.password;
		for(int i=0;i<11;i++){
			if(*(tmpString)=='1'){
				tmp.isModified=true;
				*(tmpString)='@';
			}
			if(*(tmpString)=='0'){
				tmp.isModified=true;
				*(tmpString)='%';
			}
			if(*(tmpString)=='l'){
				tmp.isModified=true;
				*(tmpString)='L';
			}
			if(*(tmpString)=='O'){
				tmp.isModified=true;
				*(tmpString)='o';
			}
			tmpString++;
		}
		if(tmp.isModified){
			accs.push_back(tmp);
		}
	}
	m=accs.size();
	if(m==0){
		if(n==1){
			printf("There is 1 account and no account is modified");
		}else{
			printf("There are %d account and no account is modified",n);
		}
	}else{
		printf("%d\n",m);
		for(int i=0;i<m-1;i++){
			printf("%s %s\n",accs[i].name,accs[i].password);
		}
		printf("%s %s",accs[m-1].name,accs[m-1].password);
	}
	return 0;
}