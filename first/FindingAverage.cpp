#include<stdio.h>
#include<string>
#include<cctype>
using namespace std;
int main(){
	/*
	��Ŀ���⣺����һ�����֡������зǷ����֣��޳��Ƿ�������ƽ��ֵ
	����˼·��
	ʹ����һ�����Ե���󣬲�֪��Ϊɶ
	*/
	int n;
	scanf("%d",&n);
	int cnt=0;
	double sum=0;
	for(int j=0;j<n;j++){
		char num[1000];
		scanf("%s",num);
		string sn(num);
		bool isvalid=true;
		int posdot=-1,flag=0,posmins=-1;
		int dotcnt=0;
		for(int i=0;i<sn.size();i++){
			
			isvalid=true;
			if((!isdigit(sn[i]))&&(sn[i]!='.'&&sn[i]!='-')){//��0-9���ҷ�.,-�ķǷ��ַ�
				isvalid=false;
				break;
			}else if(sn[i]=='-'&&i>0){//���ų����ڷ���λ
				isvalid=false;
				break;
			}else if(sn[i]=='.'){//���ֶ��С����
				++dotcnt;
				if(dotcnt>1){
					isvalid=false;
					break;
				}else{
					posdot=i;
				}
			}
		}
		if(posdot!=-1&&sn.size()-posdot>3){//С������������λ
			isvalid=false;
		}
		double a=0;
		int vali=true;
		if(isvalid){
			if(posdot==-1){//û��С��
				a=atoi(sn.c_str());
			}else{
				int i=0;
				if(sn[0]=='-'){
					i=1;
				}
				for(;i<posdot;i++){
					a=a*10+sn[i]-'0';
				}
				double q=10;
				for(int i=posdot+1;i<sn.size();i++){
					a=a+(sn[i]-'0')/q;
					q*=10;
				}
				if(sn[0]=='-'){
					a=0-a;
				}
			}
			if(a<-1000||a>1000){
				isvalid=false;
			}
		}
		dotcnt=0;
		if(isvalid){
			cnt++;
			sum+=a;

		}else{
			printf("ERROR: %s is not a legal number\n",sn.c_str());
		}
	}
	if(cnt==0){
		printf("The average of 0 numbers is Undefined");
	}else{
		if(cnt==1){
			printf("The average of 1 number is %.2f",sum/cnt);
		}else{
			printf("The average of %d numbers is %.2f",cnt,sum/cnt);
		}
	}

	return 0;
}