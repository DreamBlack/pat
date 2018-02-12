#include<stdio.h>
#include<climits>
int edges[500][500];
int costs[500][500];
int path[500];
bool visited[500];
int distance[500];
int nowcost[500];
int main(){
	/*
	��Ŀ���⣺����㵽�յ�����·����̾���ͻ��ѣ�Ҫ������·����̣���λ������٣�Ҫ�������·����
	����˼·��
	dijkstra�ı��Σ��ܼ򵥡�
	�����ύ֮����һ�����Ե�û�����������ֳ�ʼ��distance����ʱ���е����⣬�бߵĻ����ʼ��û��ֵ
	û�߻��ʼ��Ϊ0����͵���֮������̱ߵ�ʱ�����û�ߣ�0������Ϊ����С�ߡ�
	��ȷ������ʱ��ʼ��Ϊint_max
	*/
	int n,m,s,d;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	int row,col,dis,cost;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&row,&col,&dis,&cost);
		edges[row][col]=edges[col][row]=dis;
		costs[row][col]=costs[col][row]=cost;
	}
	//��ʼ������
	for(int i=0;i<n;i++){
		if(edges[s][i]!=0){
			distance[i]=edges[s][i];
		}else{
			distance[i]=INT_MAX;//very important
		}
		nowcost[i]=costs[s][i];

		path[i]=s;
	}
	
	visited[s]=true;
	int lastD=s;
	while(true){
		int minD=-1;
		int max=INT_MAX;
		//����̵�����
		for(int i=0;i<n;i++){
			if(!visited[i]&&distance[i]<max){
				minD=i;
				max=distance[i];
			}
		}
		if(minD==-1) break;
		visited[minD]=true;
		nowcost[minD]=nowcost[path[minD]]+costs[path[minD]][minD];
		if(minD==d) break;
		for(int i=0;i<n;i++ ){//����
			if(!visited[i]&&edges[minD][i]!=0){
				if(distance[minD]+edges[minD][i]<distance[i]){
					distance[i]=distance[minD]+edges[minD][i];
					nowcost[i]=nowcost[minD]+costs[minD][i];
					path[i]=minD;
				}else if(distance[minD]+edges[minD][i]==distance[i]){
					if(nowcost[i]>nowcost[minD]+costs[minD][i]){
						nowcost[i]=nowcost[minD]+costs[minD][i];
						path[i]=minD;
					}
				}
			}
		}

	}
	int allPath[500];
	int now=d,i=0;
	allPath[i++]=d;
	while(path[now]!=s){
		allPath[i++]=path[now];
		now=path[now];
	}
	allPath[i]=s;
	for(int j=i;j>=0;j--){
		printf("%d ",allPath[j]);
	}
	printf("%d %d",distance[d],nowcost[d]);
	return 0;
}