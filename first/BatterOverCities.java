package first;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BatterOverCities {

	public static void main(String[] args) {
		/*
		 * �����˼·����˵�ܼ򵥣���ȥ��ĳ��������Ӧ��֮��ͼ����ͨ�����ĸ������� ���ǲ��Ե�ʱ����һ�����Ե���ʾ�ڴ泬�ޣ����ͷ����
		 * ���У�ѧ����ά�����clone������Ȼ��ǳ���������ã���ֻ�жԶ�ά������ÿһ�н���clone�������
		 * �տ�ʼ����k������ÿһ���㣬�ָ�����һ����ά������������ȥ����������ڽӾ�����ʵ����Ҫ������ֻҪ�������visited����Ϊtrue�Ϳ�����
		 * ��������һ�����г�ʱ
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
			
			// ������ͼ�ı���
			// �����k������ֱ������ͨ���������ļ���
			boolean[] visited = new boolean[n + 1];
			int nowv, diff;
			for (int i = 0; i < k; i++) {
				nowv = mv[i];

				for (int j = 0; j < n + 1; j++) {
					visited[j] = false;
				}
				diff = 0;// ����ͨ��������
				visited[nowv] = true;// �����µ��ڽӾ���
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
		// ��v��ʼ������ȱ���ͼ
		visited[v] = true;
		for (int i = 1; i < edges[0].length; i++) {
			if (!visited[i] && edges[v][i] == 1) {
				
				dfs(visited, edges, i);
			}
		}

	}

}
