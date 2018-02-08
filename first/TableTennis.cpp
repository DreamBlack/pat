#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int k,m;
bool isEmptab[101]={true};
bool isVipTab[101]={false};
int tabSevdNum[101]={0};
int tabEmptyTime[101]={0};
struct Player{
	int arriveTime;
	int useTime;
	int waitTime;
	int serveTime;
	int isvip;
};
vector<Player> plys;
Player nowPlayer[101];
bool cmp(Player a,Player b){
	return (a.arriveTime<b.arriveTime)?true:false;
}
int findEmpVIPTab(){//找一张空的vip桌子
	for(int i=1;i<k+1;i++){
		if(isVipTab[i]&&isEmptab[i]){
			return i;
		}
	}
	return -1;
}
int findEmpTab(){//找一张空的桌子
	for(int i=1;i<k+1;i++){
		if(isEmptab[i]){
			return i;
		}
	}
	return -1;
}
int findVIPPlayer(int nowtime){
	for(int i=0;i<plys.size();i++){
		if(plys[i].serveTime!=0&&plys[i].isvip&&plys[i].arriveTime<=nowtime){
			return i;
		}
		if(plys[i].arriveTime>nowtime){
			return -1;
		}
	}

	return -1;
}
int findPlayer(int nowtime){
	for(int i=0;i<plys.size();i++){
		if(plys[i].serveTime!=0&&plys[i].arriveTime<=nowtime){
			return i;
		}
		if(plys[i].arriveTime>nowtime){
			return -1;
		}
	}

	return -1;
}

int main(){
	/*
	vector删除指定位置的元素
	*/
	scanf("%d",&n);
	int hour=0,min=0,sed=0;
	for(int i=0;i<n;i++){
		Player tmp;
		scanf("%d:%d:%d %d %d",&hour,&min,&sed,&(tmp.useTime),&(tmp.isvip));
		tmp.arriveTime=sed+min*60+(hour-8)*3600;
		tmp.useTime*=60;//单位换为秒
		plys.push_back(tmp);
	}
	int tid;
	scanf("%d%d",&k,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&tid);
		isVipTab[tid]=true;
	}
	fill(isEmptab,isEmptab+101,true);
	sort(plys.begin(),plys.end(),cmp);
	int nowtime=0,curPlyNum=0;
	while(nowtime<=13*3600){
		//先看看这个时候有没有桌子空闲
		for(int i=0;i<k;i++){
			if(!isEmptab[i]&&tabEmptyTime[i]==nowtime){
				isEmptab[i]=true;
			}
		}
		Player curPlayer;
		int emVipT=findEmpVIPTab();
		int vipPly=findVIPPlayer(nowtime);
		int empTab=findEmpTab();
		int playernum,tabid;
		if(emVipT!=-1&&vipPly!=-1){//找到了空的vip桌子，并且找到了一个在排队的vip客户，先处理这个VIP
			tabid=emVipT;
			playernum=vipPly;
			
		}else if(empTab!=-1){//没找到空的vip桌子，或者没有要处理的vip。但找到了空桌子，所有用户按普通用户处理
			tabid=empTab;
			playernum=findPlayer(nowtime);
			
		}else{
			tabid=-1;
			playernum=-1;
		}
		if(tabid!=-1&&playernum!=-1){//有空桌子
			auto it=plys.begin()+playernum;
				curPlayer=plys[playernum];
				plys.erase(it);//将该用户出队
				tabSevdNum[tabid]++;
				curPlayer.serveTime=nowtime;//设置开始服务时间
				tabEmptyTime[tabid]=nowtime+curPlayer.useTime;//设置桌子下次为空的时间
				isEmptab[tabid]=false;
				int wait=((nowtime%3600)/60)-((curPlayer.arriveTime)%3600)/60;
				wait+=((nowtime)/3600-(curPlayer.arriveTime)/3600)*60;
				
				printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",(curPlayer.arriveTime)/3600+8,
					((curPlayer.arriveTime)%3600)/60,((curPlayer.arriveTime)%3660)%60,
					nowtime/3600+8,(nowtime%3600)/60,(nowtime%3600)%60,(nowtime-curPlayer.arriveTime)/60);
		}
		nowtime++;
	}
	return 0;
}