#include <stdio.h>
#include <climits>
#include <vector>
using namespace std;

int edges[501][501];//,初始化全为最大值
int num[501];
bool visited[501]={false};
int minLength[501];//最短路径长度
vector<int> path[501];
vector<int> temp,minPath;
int nowSend=0;
int nowBack=0;
int ms=INT_MAX;
int mb=INT_MAX;
int cmax,n,sp,m;
void dfs(int now){

	for(int i=0;i<path[now].size();i++){
		int next=path[now].at(i);
		if(!visited[next]){

			visited[next]=true;
			temp.push_back(next);
			dfs(next);
			if(next==0){//找到了一条路径
				for(int j=temp.size()-2;j>=0;j--){//0也加进去了，所有应该从-2开始
					int nownum=cmax/2-num[temp.at(j)];

					if(nownum>0){//需要放send一些车
						if(nowBack>nownum){//back数量可以满足当前点的要求
							nowBack=nowBack-nownum;

						}else{//不能满足
							nowSend=nowSend+nownum-nowBack;
							nowBack=0;
						}
					}else{//需要back一些车
						nowBack+=0-(nownum);
					}
				}
				if(nowSend<ms){
					ms=nowSend;
					minPath=temp;
					mb=nowBack;
				}else if(nowSend==ms){
					if(nowBack<mb){
						minPath=temp;
						mb=nowBack;
					}
				}

				nowSend=0;
				nowBack=0;
			}
			visited[next]=false;
			temp.pop_back();//这句很重要

		}
	}
}
int main(){
	/*
	题目大意：每个自行车车站的最大容量为一个偶数cmax，如果一个车站里面自行车的数量恰好为cmax / 2，那么称处于完美状态。
	如果一个车展容量是满的或者空的，控制中心（处于结点0处）就会携带或者从路上手机一定数量的自行车前往该车站，
	一路上会让所有的车展沿途都达到完美。现在给出cmax，车站的数量n，问题车站sp，m条边，还有距离，求最短路径。
	如果最短路径有多个，求能带的最少的自行车数目的那条。如果还是有很多条不同的路，那么就找一个从车站带回的自行车数目最少的。
	带回的时候是不调整的
	对于dijkstra算法之前有一题写的挺好的这次有好多问题，改了好几遍才改对了。
	1、注意初始化时到底用什么代表没有路径，应该用int_max表示没有路径，不要用0
	2、并及时更新，path,以及send等信息。
	3、最后图的算法改好以后还是有一半的测试点没有通过，后来发现果然是对问题的理解有点出入。
	并不存在回头把目的地的车调度到之前走过的站点这种操作。此外，当从出发点带出的车同样多的时候，应选择回去的时候带的
	车数目最少的那条路径
	4、当解决了问题3的时候还是有一个测试点过不了。最后在网上看了下，原来只用dijkstra不能找到最优解。其实这个问题我一开始就想过，
	当时得到的是每一步贪心最后得到最优解的想法。但是现在是在3的条件下，很可能出现一开始带的车少，但是最终要带的车多的情况
	所以应该把每一种可能的路径（所有路径长最小的）求出来之后，再对每一条路径分别就send和back从而求最小（此处从sp往0使用DFS遍历）
	5、具体dfs思路。
	A.每个顶点用一个vector保存最短路径的上一个顶点号
	B.Dijkstra后，从sp开始回溯，一路上用vector temp保存经过的路径，当到根节点时，对temp遍历记录每过一个顶点之后的minsend和minback
	，保存最小的那条路径在minpath里面
	C.最后输出
	在这一步也出现了问题
	a.在保存路径的时候，dfs返回退回，直接清空temp会把分支点之前的路径也清空，这点不对
	应该在dfs遍历完成后判断是否到了根，同时将visited置为false，以及将之前走过的路径Pop掉
	b.使用了a改进的方法之后,temp路径里保存了0点，在计算send和back时，应该从0点之后那个店开始，不能包括0点
	*/

	scanf("%d%d%d%d",&cmax,&n,&sp,&m);
	int tmp=0;
	for(int i=1;i<n+1;i++){
		scanf("%d",&tmp);
		num[i]=tmp;
	}
	int row,col;
	for(int i=0;i<m;i++){
		scanf("%d",&row);
		scanf("%d",&col);
		scanf("%d",&tmp);
		edges[row][col]=edges[col][row]=tmp;
	}

	//初始化
	for(int i=0;i<n+1;i++){
		if(edges[0][i]!=0){
			minLength[i]=edges[0][i];
		}else{
			minLength[i]=INT_MAX;
		}
		path[i].push_back(0);

	}
	visited[0]=true;
	int now=0,nowlength=0;
	while(true){
		//找min中最小的那个
		int minindex=0,minedge=INT_MAX;
		for(int i=0;i<n+1;i++){
			if(!visited[i]&&minLength[i]!=INT_MAX&&minedge>minLength[i]){
				minindex=i;
				minedge=minLength[i];
			}
		}

		visited[minindex]=true;
		if(minindex==sp) break;
		if(minindex==0) break;
		for(int i=0;i<n+1;i++){
			if(!visited[i]&&edges[minindex][i]!=0){
				nowlength=minLength[minindex]+edges[minindex][i];
				if(nowlength<minLength[i]){//找到了一条更短的
					path[i].clear();
					minLength[i]=nowlength;
					path[i].push_back(minindex);
				}else if(nowlength==minLength[i]){//找到了一条同样短的
					path[i].push_back(minindex);
				}

			}
		}
	}
	//处理每一条最短路径
	for(int i=0;i<n+1;i++){
		visited[i]=false;
	}
	temp.push_back(sp);
	dfs(sp);
	printf("%d ",ms);
	for(int i=minPath.size()-1;i>0;i--){
		printf("%d->",minPath.at(i));
	}
	printf("%d ",sp);
	printf("%d",mb);
	return 0;
}