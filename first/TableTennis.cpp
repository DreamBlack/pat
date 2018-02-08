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
int findEmpVIPTab(){//��һ�ſյ�vip����
	for(int i=1;i<k+1;i++){
		if(isVipTab[i]&&isEmptab[i]){
			return i;
		}
	}
	return -1;
}
int findEmpTab(){//��һ�ſյ�����
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
	vectorɾ��ָ��λ�õ�Ԫ��
	*/
	scanf("%d",&n);
	int hour=0,min=0,sed=0;
	for(int i=0;i<n;i++){
		Player tmp;
		scanf("%d:%d:%d %d %d",&hour,&min,&sed,&(tmp.useTime),&(tmp.isvip));
		tmp.arriveTime=sed+min*60+(hour-8)*3600;
		tmp.useTime*=60;//��λ��Ϊ��
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
		//�ȿ������ʱ����û�����ӿ���
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
		if(emVipT!=-1&&vipPly!=-1){//�ҵ��˿յ�vip���ӣ������ҵ���һ�����Ŷӵ�vip�ͻ����ȴ������VIP
			tabid=emVipT;
			playernum=vipPly;
			
		}else if(empTab!=-1){//û�ҵ��յ�vip���ӣ�����û��Ҫ�����vip�����ҵ��˿����ӣ������û�����ͨ�û�����
			tabid=empTab;
			playernum=findPlayer(nowtime);
			
		}else{
			tabid=-1;
			playernum=-1;
		}
		if(tabid!=-1&&playernum!=-1){//�п�����
			auto it=plys.begin()+playernum;
				curPlayer=plys[playernum];
				plys.erase(it);//�����û�����
				tabSevdNum[tabid]++;
				curPlayer.serveTime=nowtime;//���ÿ�ʼ����ʱ��
				tabEmptyTime[tabid]=nowtime+curPlayer.useTime;//���������´�Ϊ�յ�ʱ��
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