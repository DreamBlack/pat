#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
struct Record{
	int intime,outtime,status;
	string carid;
};
bool cmp(Record a,Record b){
	return (a.intime<b.intime)?true:false;
}
bool cmp2(Record a,Record b){
	if(a.intime<b.intime){
		return true;
	}else if(a.intime==b.intime){
		if(a.carid.compare(b.carid)<0){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
map<string,vector<Record>>rds;
int main(){
	/*
	��Ŀ���⣺����n�����ƺš�ʱ��㡢����״̬�ļ�¼��Ȼ���ѯk��ʱ�����ʱУ԰�ڵĳ������������Ҫ�����У԰�������ʱ����ĳ��ĳ��ƺţ�
	�Լ����˶�õ�ʱ�䡣����ж������Ͱ���������ĸ��С����������ơ�
	����˼·�������������ͷ��
	1����һ��struct��¼����ʱ�䣬�ߵ�ʱ�䣬��¼���ͣ������������ƺ�
	2��ɨ�����Լ�¼һ����idΪkey����¼��map<string,vector<Record>>�С�
	3��Ȼ��������map��map��ÿһ��key��Ӧĳ�������յ����н�����¼����ÿ�������д����޳���Ч��¼������Ч�Ľ�����¼��ŵ�vector<Record> iords
	���������ʱ����������ͬʱ������ÿ����һ������ͣ����ʱ�䣬��¼��vector<Record> carrds��
	4��֮����ÿһ����ѯ����һ������vector<Record> lastv��¼����ǰʱ����У԰�ڵĳ���lastindex��¼�ϴ����һ���ڹ涨ʱ���ڽ�԰�ĳ����±ꡣ
	�ȴ�lastindex(��ʼΪ0)��size()-1���ҵ�ǰ��ѯʱ���ڵ�һ������԰�еĳ����±꣬��Ϊj����lastv�е����ݽ��д������䴦��ʱ�����ڵ�ǰʱ������ɾ����
	����������֮���lastindex��j�еļ�¼���д��������Ժʱ��ȵ�ǰʱ��٣������lastv�����lastv�Ĵ�С���ǵ�ǰ��Ժ�ڵĳ�����Ŀ
	*/
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		Record tmp;
		char id[8];
		char stat[4];
		int hour,min,sed;
		scanf("%s %d:%d:%d %s",id,&hour,&min,&sed,stat);
		if(strcmp(stat,"in")==0){
			tmp.status=0;
		}else{
			tmp.status=1;
		}
		tmp.intime=sed+min*60+hour*60*60;
		string cid(id);
		tmp.carid=cid;
		rds[cid].push_back(tmp);
	}
	vector<Record> carrds;//��¼����m����������ͣ������ʱ��
	vector<Record> iords;//��¼����p�������Ľ�����¼
	for(auto it=rds.begin();it!=rds.end();it++){
		sort(it->second.begin(),it->second.end(),cmp);
		int totalTime=0;
		Record totmp;
		totmp.carid=it->first;
		stack<Record>stmp;
		for(int i=0;i<it->second.size();i++){
			if(stmp.empty()){//��0
				if(it->second[i].status==0){
					stmp.push(it->second[i]);
				}
			}else{//��1
				if(it->second[i].status==1){
					Record ir=stmp.top();
					stmp.pop();
					ir.outtime=(it->second[i]).intime;
					iords.push_back(ir);
					totalTime+=ir.outtime-ir.intime;
				}else{
					stmp.pop();
					stmp.push(it->second[i]);
				}
			}
		}
		totmp.intime=totalTime;
		carrds.push_back(totmp);
	}
	
	sort(iords.begin(),iords.end(),cmp);
	vector<Record> lastv;
	int lasttime=0,nowtime=0,lastindex=0,cnt=0;
	for(int i=0;i<k;i++){
		int hour,min,sed,time,j=lastindex;
		scanf("%d:%d:%d",&hour,&min,&sed);
		time=sed+min*60+hour*60*60;
		while(j<iords.size()&&iords[j].intime<=time){//�ҵ���һ������ʱ���time���
			j++;
		}
		
		for(int q=0;q<lastv.size();q++){
			if(lastv[q].outtime<=time){
				lastv.erase(lastv.begin()+q);
				q--;
				cnt--;
			}
		}
		for(int q=lastindex;q<j;q++){
			if(iords[q].outtime>time){
				lastv.push_back(iords[q]);
				cnt++;
			}
		}
		lastindex=j;
		printf("%d\n",cnt);
	}
	sort(carrds.begin(),carrds.end(),cmp2);
	int c=0,o=carrds.size()-1;
	while(o>=0&&carrds[o].intime==carrds[carrds.size()-1].intime){
		o--;
	}
	for(int j=o+1;j<carrds.size();j++){
		printf("%s ",carrds[j].carid.c_str());
	}
	printf("%02d:%02d:%02d",carrds[carrds.size()-1].intime/3600,carrds[carrds.size()-1].intime%3600/60,carrds[carrds.size()-1].intime%3600%60);
	return 0;
}