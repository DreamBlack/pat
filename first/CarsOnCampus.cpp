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
	题目大意：给出n个车牌号、时间点、进出状态的记录，然后查询k个时间点这时校园内的车辆个数。最后还要输出在校园里面呆的时间最长的车的车牌号，
	以及呆了多久的时间。如果有多辆车就按照它的字母从小到大输出车牌。
	解题思路：看到这种题就头大。
	1、用一个struct记录来的时间，走的时间，记录类型（进出），车牌号
	2、扫描所以记录一车辆id为key，记录在map<string,vector<Record>>中。
	3、然后遍历这个map，map中每一个key对应某个车牌照的所有进出记录。对每个车进行处理，剔除无效记录，将有效的进出记录存放到vector<Record> iords
	并按进入的时间升序排序。同时，计算每辆车一整天所停留的时间，记录到vector<Record> carrds中
	4、之后处理每一条查询，用一个数组vector<Record> lastv记录，当前时间在校园内的车。lastindex记录上次最后一个在规定时间内进园的车辆下标。
	先从lastindex(初始为0)到size()-1查找当前查询时间内第一辆不在园中的车辆下标，记为j；对lastv中的数据进行处理，若其处于时间早于当前时间则将其删除；
	否则不做处理；之后对lastindex到j中的记录进行处理如果出院时间比当前时间迟，则放入lastv。最后lastv的大小就是当前在院内的车辆数目
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
	vector<Record> carrds;//记录的是m个车辆各自停留的总时间
	vector<Record> iords;//记录的是p条车辆的进出记录
	for(auto it=rds.begin();it!=rds.end();it++){
		sort(it->second.begin(),it->second.end(),cmp);
		int totalTime=0;
		Record totmp;
		totmp.carid=it->first;
		stack<Record>stmp;
		for(int i=0;i<it->second.size();i++){
			if(stmp.empty()){//找0
				if(it->second[i].status==0){
					stmp.push(it->second[i]);
				}
			}else{//找1
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
		while(j<iords.size()&&iords[j].intime<=time){//找到第一个进来时间比time大的
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