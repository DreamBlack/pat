#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<algorithm>
using namespace std;
int graph[1011][1011];
int minPath[1011];
bool visited[1011];
int n,m,k,ds;
bool dfs(int now){
	visited[now]=true;
	//�ҳ�path��������С���Ǹ�
	while(true){
		int minIndex=-1,minLength=INT_MAX;
		for(int i=1;i<=n+m;i++){
			if(!visited[i]&&minPath[i]<minLength){
				minIndex=i;
				minLength=minPath[i];
			}
		}
		//�����С����Ϊ�µĳ����㣬����path����
		if(minIndex<=n&&minPath[minIndex]>ds){
			return false;
		}
		if(minIndex==-1){
			break;
		}
		visited[minIndex]=true;
		for(int i=1;i<=n+m;i++){
			if(!visited[i]&&graph[i][minIndex]!=0){
				if(graph[i][minIndex]+minPath[minIndex]<minPath[i]){
					minPath[i]=graph[i][minIndex]+minPath[minIndex];
				}
			}
		}
	}
	return true;
}
int main(){
	/*
	��Ŀ���⣺��m������վ����ѡȡ1��վ�㣬����������������������Զ������û�г�������Χds֮�ڡ�����кܶ����Զ�ļ���վ��
	����������о���������ƽ��ֵ��С���Ǹ������ƽ��ֵ����һ�������������˳�����м���վ�����С���Ǹ�
	����˼·��
	1�����������Ķ���⡣��ʵ����dijsktra��m���㵽����n��������·����ѡȡm�����е�����ĵ������Զ���Ǹ�������ж����ѡ�ܾ���������Ǹ���
	���ж����ѡ�±�С��
	2�������Ŀ�ͺܼ���
	*/
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	for(int i=0;i<k;i++){
		char node1[5];
		char node2[5];
		int a,b,length;
		scanf("%s%s%d",node1,node2,&length);
		if(node1[0]=='G'){//����վ��
			a=atoi(node1+1)+n;
		}else{
			a=atoi(node1);
		}
		if(node2[0]=='G'){//����վ��
			b=atoi(node2+1)+n;
		}else{
			b=atoi(node2);
		}
		graph[a][b]=graph[b][a]=length;
	}
	int maxAll=-1,goodG=-1,minH=-1;
	for(int i=1+n;i<=n+m;i++){
		int min=INT_MAX,all=0;
		//��ʼ��path����
		fill(minPath,minPath+m+n+1,INT_MAX);
		fill(visited,visited+m+n+1,false);
		for(int j=1;j<=n+m;j++){
			if(j!=i&&graph[i][j]!=0){//�б�
				minPath[j]=graph[i][j];
			}
		}

		if(dfs(i)){
			for(int j=1;j<=n;j++){
				all+=minPath[j];
				if(min>minPath[j]){
					min=minPath[j];
				}
			}
			if(minH<min){
				maxAll=all;
				goodG=i;
				minH=min;
			}else if(minH==min){
				if(maxAll>all){
					maxAll=all;
					goodG=i;
					minH=min;
				}
			}
		}else{//�ú�ѡ��Ҫ
		}

	}
	if(goodG==-1){
		printf("No Solution");
	}else{
		printf("G%d\n",goodG-n);
		double average=(double)maxAll/n;
		printf("%.1f %.1f",(double)(minH),average);
	}
	return 0;
}