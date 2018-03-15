#include<stdio.h>
#include<algorithm>
using namespace std;
int graph[201][201];
bool visited[201];
int cycle[201];
int sequence[201];
int main(){
	/*
	��Ŀ���⣺����һ������ͼ���Լ�K����ѯ����ѯ�ṹΪn(�������),�������У�����������ܷ񹹳ɹ��ܶٻ�·
	������⣺
	1���������Ҫ����ץס���ܶٻ�·�Ķ��壬һ���ǻ�·Ҫ�պϣ���λ�·��ÿ������ֻ����һ�Σ������������·Ҫ����
	ͼ�ϵ����ж���
	2��֪��1֮��ͺܼ���
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		graph[x][y]=graph[y][x]=1;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		fill(visited+1,visited+1+n,false);
		fill(cycle+1,cycle+1+n,0);
		fill(sequence+1,sequence+1+n,0);
		int num,first;
		scanf("%d%d",&num,&first);
		sequence[0]=first;
		for(int j=1;j<=num-1;j++){
			scanf("%d",sequence+j);
		}
		if(num<n){
			printf("NO\n");
		}else{
			int flag=1;
			if(sequence[num-1]!=first){//��·û�бպ�
				flag=0;
			}else{
				int next,last=first;
				for(int j=1;j<=num-1;j++){
					if(visited[sequence[j]]&&j<num-1){//�Ѿ����ʹ�
						flag=0;
						break;
					}else if(sequence[j]==first&&j<num-1){//��û�е�����β�������˻���ͷ��
						flag=0;
						break;
					}else if(graph[last][sequence[j]]==0){//û�б�
						flag=0;
						break;
					}
					visited[sequence[j]]=true;
					last=sequence[j];
				}
			}
			if(flag==1){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}