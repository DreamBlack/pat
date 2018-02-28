#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
struct Mice{
	int weight;
	int rank;
	int seq;
};
int main(){
	/*
	��Ŀ���⣺npΪ�����������ngΪÿ�����g�������ȸ���np��������������ٸ�������ĳ�ʼ˳�򣨵�i���������ǵ�j�ţ�j��0��ʼ����
	ÿng�������Ϊһ�飬����ÿ������ѡ�����ص��Ǹ���������һ�ֱ�����Ȼ����������np������һ����࣬Ȼ��ѡ���������ġ�����ֱ��ֻʣ��һֻ��������Ϊ1.
	���Ϊ�������������������ǰ���ԭ���������˳������ġ�
	����˼·��
	1������һ��ʼ�����ж�ʮ����Ҳû���������������������һ���˳������ô���ġ��������ֵ����и�����0~np-qָ���ǵ�һ�а��������np���������š�
	Ȼ�󰴵����е�˳������ѡȡng�����󣬽��б���
	2������һ�㿪ʼû�㶮���ǣ������������ʵ�������ֻ����Np�������Ϊk�飬ÿ��ng(������һ�鲻��Ng��)��ÿ��С����ÿһʤ��������Ϊ����η�����k+1��
	3���������Ŀ�ͱȽϺ����ˣ�ʹ��quene��ÿ�����ng��Ҳ�п��ܲ���ng�������󣬸���ʧ�ܵ�������ͬʱ����������������Ϊʤ���ٷŵ�queue�Ķ�β��
	4��Ҫע����Ǽ�¼ÿһ��ʲôʱ�����
	*/
	vector<Mice> mice;
	queue<Mice> gs;
	int np,ng;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++){
		int weight;
		scanf("%d",&weight);
		Mice c={weight,0,i};
		mice.push_back(c);
	}
	for(int i=0;i<np;i++){
		int now;
		scanf("%d",&now);
		gs.push(mice[now]);
	}
	int nowG=0,nowc=gs.size();
	while(!gs.empty()){
		if(gs.size()==1){
			mice[gs.front().seq].rank=1;
			break;
		}
		nowc=gs.size();
		nowG=(gs.size()%ng==0)?gs.size()/ng:gs.size()/ng+1;
		while(nowc>0){
			Mice maxMice=gs.front();
			for(int i=0;i<ng&&i<nowc;i++){
				mice[gs.front().seq].rank=nowG+1;
				if(gs.front().weight>maxMice.weight){
					maxMice=gs.front();
				}
				gs.pop();
			}
			nowc=(nowc>=ng)?nowc-ng:0;
			gs.push(maxMice);
		}
	}
	for(int i=0;i<np;i++){
		if(i<np-1){
			printf("%d ",mice[i].rank);
		}else{
			printf("%d",mice[i].rank);
		}
	}
	return 0;
}