#include <stdio.h>
#include <climits>
#include <vector>
using namespace std;

int edges[501][501];//,��ʼ��ȫΪ���ֵ
int num[501];
bool visited[501]={false};
int minLength[501];//���·������
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
			if(next==0){//�ҵ���һ��·��
				for(int j=temp.size()-2;j>=0;j--){//0Ҳ�ӽ�ȥ�ˣ�����Ӧ�ô�-2��ʼ
					int nownum=cmax/2-num[temp.at(j)];

					if(nownum>0){//��Ҫ��sendһЩ��
						if(nowBack>nownum){//back�����������㵱ǰ���Ҫ��
							nowBack=nowBack-nownum;

						}else{//��������
							nowSend=nowSend+nownum-nowBack;
							nowBack=0;
						}
					}else{//��ҪbackһЩ��
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
			temp.pop_back();//������Ҫ

		}
	}
}
int main(){
	/*
	��Ŀ���⣺ÿ�����г���վ���������Ϊһ��ż��cmax�����һ����վ�������г�������ǡ��Ϊcmax / 2����ô�ƴ�������״̬��
	���һ����չ���������Ļ��߿յģ��������ģ����ڽ��0�����ͻ�Я�����ߴ�·���ֻ�һ�����������г�ǰ���ó�վ��
	һ·�ϻ������еĳ�չ��;���ﵽ���������ڸ���cmax����վ������n�����⳵վsp��m���ߣ����о��룬�����·����
	������·���ж�������ܴ������ٵ����г���Ŀ����������������кܶ�����ͬ��·����ô����һ���ӳ�վ���ص����г���Ŀ���ٵġ�
	���ص�ʱ���ǲ�������
	����dijkstra�㷨֮ǰ��һ��д��ͦ�õ�����кö����⣬���˺ü���ŸĶ��ˡ�
	1��ע���ʼ��ʱ������ʲô����û��·����Ӧ����int_max��ʾû��·������Ҫ��0
	2������ʱ���£�path,�Լ�send����Ϣ��
	3�����ͼ���㷨�ĺ��Ժ�����һ��Ĳ��Ե�û��ͨ�����������ֹ�Ȼ�Ƕ����������е���롣
	�������ڻ�ͷ��Ŀ�ĵصĳ����ȵ�֮ǰ�߹���վ�����ֲ��������⣬���ӳ���������ĳ�ͬ�����ʱ��Ӧѡ���ȥ��ʱ�����
	����Ŀ���ٵ�����·��
	4�������������3��ʱ������һ�����Ե�����ˡ���������Ͽ����£�ԭ��ֻ��dijkstra�����ҵ����Ž⡣��ʵ���������һ��ʼ�������
	��ʱ�õ�����ÿһ��̰�����õ����Ž���뷨��������������3�������£��ܿ��ܳ���һ��ʼ���ĳ��٣���������Ҫ���ĳ�������
	����Ӧ�ð�ÿһ�ֿ��ܵ�·��������·������С�ģ������֮���ٶ�ÿһ��·���ֱ��send��back�Ӷ�����С���˴���sp��0ʹ��DFS������
	5������dfs˼·��
	A.ÿ��������һ��vector�������·������һ�������
	B.Dijkstra�󣬴�sp��ʼ���ݣ�һ·����vector temp���澭����·�����������ڵ�ʱ����temp������¼ÿ��һ������֮���minsend��minback
	��������С������·����minpath����
	C.������
	����һ��Ҳ����������
	a.�ڱ���·����ʱ��dfs�����˻أ�ֱ�����temp��ѷ�֧��֮ǰ��·��Ҳ��գ���㲻��
	Ӧ����dfs������ɺ��ж��Ƿ��˸���ͬʱ��visited��Ϊfalse���Լ���֮ǰ�߹���·��Pop��
	b.ʹ����a�Ľ��ķ���֮��,temp·���ﱣ����0�㣬�ڼ���send��backʱ��Ӧ�ô�0��֮���Ǹ��꿪ʼ�����ܰ���0��
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

	//��ʼ��
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
		//��min����С���Ǹ�
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
				if(nowlength<minLength[i]){//�ҵ���һ�����̵�
					path[i].clear();
					minLength[i]=nowlength;
					path[i].push_back(minindex);
				}else if(nowlength==minLength[i]){//�ҵ���һ��ͬ���̵�
					path[i].push_back(minindex);
				}

			}
		}
	}
	//����ÿһ�����·��
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