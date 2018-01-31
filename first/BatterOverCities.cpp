#include<stdio.h>
int edges[1001][1001];
bool visited[1001] ;
int n;
void dfs( int v) {
		// ��v��ʼ������ȱ���ͼ
		visited[v] = true;
		for (int i = 1; i < n+1; i++) {
			if (!visited[i] && edges[v][i] == 1) {
				
				dfs( i);
			}
		}

	}
int main(){
	/*
	˵ʵ����������N�겻�õ�C++���Ǿܾ��ģ�����û�취��java�������������20�౶�������ǹ����ˡ�
	����java�߼���C++һģһ��java�������г�ʱ�ڴ泬�ޡ�
	��Ȼ������ѧC++���ܻ��ʹ�࣬����û�취��������Ӧ��������д�������Ҳ��������
	����ѧϰ��
	1����scanf,printf��Ϊ���������scanf(��ʽ���Ʒ�����ַ�б�),��ʱҪinclude<stdio.h>
	2��main�����践��int
	3�����õ��ĺ�����Ҫ�����ڸú���֮ǰ
	*/
	int m,k;
	scanf("%d%d%d",&n,&m,&k);//scanf(��ʽ���Ʒ�����ַ�б�)
	
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d%d",&x,&y);
		edges[x][y] = edges[y][x] = 1;
	}
	
	int nowv, diff;
	for (int i = 0; i < k; i++) {
		scanf("%d",&nowv);

		for (int j = 0; j < n + 1; j++) {
			visited[j] = false;
		}
		diff = 0;// ����ͨ��������
		visited[nowv] = true;// �����µ��ڽӾ���
		for (int j = 1; j < n + 1; j++) {
			if ( !visited[j]) {
				dfs(j);
				diff++;
			}
		}
		printf("%d\n",diff - 1);
	}
	return 0;
}
 