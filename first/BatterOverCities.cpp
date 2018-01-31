#include<stdio.h>
int edges[1001][1001];
bool visited[1001] ;
int n;
void dfs( int v) {
		// 从v开始深度优先遍历图
		visited[v] = true;
		for (int i = 1; i < n+1; i++) {
			if (!visited[i] && edges[v][i] == 1) {
				
				dfs( i);
			}
		}

	}
int main(){
	/*
	说实话，让我用N年不用的C++我是拒绝的，可是没办法，java在这儿性能折了20多倍，还老是过不了。
	明明java逻辑跟C++一模一样java就是运行超时内存超限。
	虽然现在再学C++可能会很痛苦，但是没办法，估计适应个两三天写四五道题也就上手了
	今天学习到
	1、用scanf,printf作为输入输出，scanf(格式控制符，地址列表),此时要include<stdio.h>
	2、main函数需返回int
	3、调用到的函数需要声明在该函数之前
	*/
	int m,k;
	scanf("%d%d%d",&n,&m,&k);//scanf(格式控制符，地址列表)
	
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
		diff = 0;// 求连通分量个数
		visited[nowv] = true;// 构造新的邻接矩阵
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
 