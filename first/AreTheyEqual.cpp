#include<stdio.h>
#include<string>
using namespace std;
char a[10000];
char b[10000];
struct NFloat{
	string s;
	int exp;
};
using namespace std;
int main(){
	/*
	��Ŀ���⣺�������������ʽ�����д�ɱ���NλС���Ŀ�ѧ���������Ƿ����(С����һλ��Ϊ0)�������ȣ����YES��������ǵĿ�ѧ��������ʾ������
	�����������NO���ֱ�������ǵĿ�ѧ������
	����˼·��
	1������123.11���п��ܳ���0.003������С��
	2�����п�����00000,00001���ֲ��Ե㡣���Թؼ������ҵ���һ����0�����ֳ��ֵ�λ���Լ�С�����λ��
	3����Ϊû�п���1���ĸ����Ե���󣬽��1��2֮����һ�����Ե����֪��Ϊɶ�������Ʒ���д
	4�����ҵ���һ����0����λ�ü�Ϊposvalid���Լ���.��С�����λ�ü�Ϊposdot��ע���ĸ���ǰ�ĸ��ں�
	5�������ˣ��������һ�����Ե����
	*/
	int n;
	scanf("%d",&n);
	NFloat f[2];
	for(int i=0;i<2;i++){
		scanf("%s",a);
		string tmps(a);
		NFloat temp;
		int posvalid=-1,posdot=-1;
		for(int j=0;j<tmps.size();j++){
			if(tmps[j]!='0'&&tmps[j]!='.'){
				posvalid=j;
				break;
			}
		}
		posdot=tmps.find('.');
		if(posvalid==-1){//0
			temp.exp=0;
			tmps="0";
		}else{
			if(posvalid!=0){//��һλ������Чλ
				tmps.erase(0,posvalid);
			}
			if(posdot!=-1){//��С����
				if(posdot<posvalid){//С��������Чλ֮ǰ
					temp.exp=posdot-posvalid+1;
				}else{
					tmps.erase(posdot,1);
					temp.exp=posdot-posvalid;
				}
			}else{//û��С����
				temp.exp=tmps.size();
			}
		}
		
		if(tmps.size()<n){
			while(tmps.size()<n){
				tmps.insert(tmps.size(),"0");
			}
			temp.s=tmps;
		}else{
			temp.s=tmps.substr(0,n);
		}
		if(n==0){
			temp.s="0";
			temp.exp=0;
		}
		f[i]=temp;
	}
	if(f[1].exp==f[0].exp&&f[0].s.compare(f[1].s)==0){
		printf("YES 0.%s*10^%d",f[0].s.c_str(),f[0].exp);
	}else{
		printf("NO 0.%s*10^%d 0.%s*10^%d",f[0].s.c_str(),f[0].exp,f[1].s.c_str(),f[1].exp);
	}

	return 0;
}