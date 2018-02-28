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
	题目大意：np为老鼠的数量，ng为每组最多g个老鼠。先给出np个老鼠的重量，再给出老鼠的初始顺序（第i名的老鼠是第j号，j从0开始）。
	每ng个老鼠分为一组，对于每组老鼠，选出最重的那个，晋级下一轮比赛，然后依次再以np个老鼠一组分类，然后选出重量最大的。。。直到只剩下一只老鼠，排名为1.
	输出为老鼠的排名，这个排名是按照原输入老鼠的顺序输出的。
	解题思路：
	1、这题一开始看了有二十分钟也没看懂。不懂这个几个老鼠一组的顺序是怎么来的。后来发现第三行给出的0~np-q指定是第一行按序给出的np个老鼠的序号。
	然后按第三行的顺序依次选取ng个老鼠，进行比赛
	2、还有一点开始没搞懂的是，这个排名。其实这个排名只的是Np个老鼠分为k组，每组ng(可能有一组不足Ng个)，每个小组中每一胜出的排名为。这次分组数k+1；
	3、理解了题目就比较好做了，使用quene。每次输出ng（也有可能不足ng）个老鼠，给出失败的排名，同时把重量最大的老鼠作为胜者再放到queue的队尾。
	4、要注意的是记录每一轮什么时候结束
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