package first;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BatterOverCities {

	public static void main(String[] args) {
		/*
		 * 这题从思路上来说很简单，求去掉某顶点和其对应边之后图中连通分量的个数即可 但是测试的时候有一个测试点提示内存超限，这就头疼了
		 * 还有，学到二维数组的clone函数仍然是浅拷贝（引用），只有对二维数组中每一行进行clone才是深拷贝
		 * 刚开始对于k个点中每一个点，又复制了一个二维数组用来构造去掉这个点后的邻接矩阵。其实不需要这样，只要将这个点visited设置为true就可以了
		 * 但是又有一个运行超时
		 */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			String read = br.readLine();
			String[] rs = read.split(" ");
			int n, m, k;
			n = Integer.parseInt(rs[0]);
			m = Integer.parseInt(rs[1]);
			k = Integer.parseInt(rs[2]);

			int[][] edges = new int[n + 1][n + 1];
			int x, y;
			for (int i = 0; i < m; i++) {
				read = br.readLine();
				rs = read.split(" ");
				x = Integer.parseInt(rs[0]);
				y = Integer.parseInt(rs[1]);
				edges[x][y] = edges[y][x] = 1;
			}
			read = br.readLine();
			rs = read.split(" ");
			br.close();
			int[] mv = new int[k];
			for (int i = 0; i < k; i++) {
				mv[i] = Integer.parseInt(rs[i]);
			}
			
			// 处理完图的保存
			// 下面对k个顶点分别进行连通分量个数的计算
			boolean[] visited = new boolean[n + 1];
			int nowv, diff;
			for (int i = 0; i < k; i++) {
				nowv = mv[i];

				for (int j = 0; j < n + 1; j++) {
					visited[j] = false;
				}
				diff = 0;// 求连通分量个数
				visited[nowv] = true;// 构造新的邻接矩阵
				for (int j = 1; j < n + 1; j++) {
					if ( !visited[j]) {
						dfs(visited, edges, j);
						diff++;
					}
				}
				System.out.println(diff - 1);
			}

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public static void dfs(boolean[] visited, int[][] edges, int v) {
		// 从v开始深度优先遍历图
		visited[v] = true;
		for (int i = 1; i < edges[0].length; i++) {
			if (!visited[i] && edges[v][i] == 1) {
				
				dfs(visited, edges, i);
			}
		}

	}

}
