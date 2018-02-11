#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Station{
	double uprice;
	double distance;
};
bool cmp(Station a,Station b){
	return (a.distance<b.distance)?true:false;
}
vector<Station> stns;
int main(){
	/*
	题目大意：从S到D一路有N个加油站（油价各异），计算最省钱的加油策略
	解题思路：
	这题很明显的贪心算法，不过这个是真不会。看了一下网上的分析最后做了出来。
	贪心综述：为了达到花最少的钱到达终点或是跑最远距离的目的，我们很难整体的去把握这个问题，通过贪心算法，
	可以把整体问题化为局部问题，只站在当前的角度分析最贪婪（最优）的抉择，从而得到问题的最优解，
	贪心问题的困难之处在于对问题的分析和情况分类，一旦情况考虑的不够周全，就可能满盘皆输。
	算法：（每一个nowStn都是选择的最合适的那个）
	1、从nowStn开始(初始为出发地0，必须加油不然走不了），看自己可达的加油站们：
		a.有比自己便宜的加油站，便只加能走到那个离自己最近且比自己便宜的加油站的油量。（又便宜的尽量在贵的地方少加）
		b.没有比自己便宜的加油站，赶紧原地加满，然后选择那些可达加油站中最近的那个
		c.可达加油站中有终点，直接加可到终点的油量
	2、至于无论怎么走都无法达到终点的情况可能发生在，从nowStn开始，没有可达站（即使加满了油也到不了最近的站）
	问题：
	1、由于可能在某处加满了油之后，走到下一个站的时候没有用完，所有要记录没过一个站后leftGas（剩余油量），
	之后加油的时候要把剩余的油量考虑进去
	2、提交之后有一个测试点过不了。因为忽略了起点没有加油站的情况。
	*/
	double cmax,ddis,price;
	int n;
	scanf("%lf%lf%lf%d",&cmax,&ddis,&price,&n);
	for(int i=1;i<=n;i++){
		Station tmp;
		scanf("%lf%lf",&(tmp.uprice),&(tmp.distance));
		stns.push_back(tmp);
	}
	sort(stns.begin(),stns.end(),cmp);
	Station t={0,ddis};
	stns.push_back(t);
	if(stns[0].distance>0){
		printf("The maximum travel distance = %0.2f\n",0);
		return 0;
	}
	double totalPrice=0,leftGas=0,totalDis=0;;
	int nowGas=0;
	double maxdis=cmax*price;
	while(nowGas<stns.size()-1){
		int nexGas=-1;
		int i=nowGas+1;
		for(;i<stns.size();i++){
			if(stns[i].distance-stns[nowGas].distance>maxdis){
				break;
			}
			if(stns[i].uprice<stns[nowGas].uprice){
				nexGas=i;
				break;
			}
		}
		if(nexGas==stns.size()-1){//能到终点

			totalPrice+=(stns[nowGas].uprice)*((stns[nexGas].distance-stns[nowGas].distance)/price-leftGas);
			totalDis=stns[nexGas].distance;
			break;

		}else if(nexGas!=-1){//可达范围内有一个价格更低的就去那里加油
			totalPrice+=(stns[nowGas].uprice)*((stns[nexGas].distance-stns[nowGas].distance)/price-leftGas);
			totalDis=stns[nexGas].distance;

			leftGas=0;
			nowGas=nexGas;
			totalDis=stns[nowGas].distance;
		}else{//可达范围内没有比自己低的，赶紧加满，然后去可达范围内相对价格最低的站

			totalPrice+=(cmax-leftGas)*stns[nowGas].uprice;
			if(stns[nowGas+1].distance-stns[nowGas].distance>maxdis){
				//可达范围没有比自己低的,并且即使现在加满了也到不了下一个站
				totalDis+=cmax*price;
				break;
			}

			int minGastn=nowGas+1;
			for(int j=nowGas+2;j<i;j++){
				if(stns[j].uprice<stns[minGastn].uprice){
					minGastn=j;
				}
			}
			leftGas=cmax-(stns[minGastn].distance-stns[nowGas].distance)/price;
			nowGas=minGastn;
			totalDis=stns[nowGas].distance;
		}
	}
	if(totalDis<ddis){
		printf("The maximum travel distance = %0.2f\n",totalDis);
	}else{
		printf("%0.2f",totalPrice);
	}
	return 0;
}