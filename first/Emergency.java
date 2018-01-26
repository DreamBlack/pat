package first;

import java.util.Scanner;

public class Emergency {
	private static int[] cities;
	private static int[][] roads;
	private static boolean[] visited;
	private static int n;
	private static int start;
	private static int target;
	private static int minLength = Integer.MAX_VALUE;
	private static int minNum = Integer.MAX_VALUE;
	private static int maxTeams;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * ǧ�����������дdijkstra��ʱ���ҵ��˴���
		 * �ף���������ͼ������������ͼ���ڽӾ����ǶԳƵ�ѽ�������ֻд�˸�ֵ���������ǵģ����������ǶԳƵĲ���ҲҪ��ֵ��ѽ����䵼�¼������Ե�ͨ������ɣ������
		 */
		firstVersion();
	}

	public static void firstVersion() {
		Scanner sc = new Scanner("5 6 0 2 1 2 1 5 3 0 1 1 0 2 2 0 3 1 1 2 1 2 4 1 3 4 1");
		n = sc.nextInt();
		int m = sc.nextInt();
		start = sc.nextInt();
		target = sc.nextInt();
		cities = new int[n];
		visited = new boolean[n];
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		for (int i = 0; i < n; i++) {
			cities[i] = sc.nextInt();
		}
		roads = new int[n][n];
		for (int i = 0; i < m; i++) {
			int from = sc.nextInt();
			int to = sc.nextInt();
			roads[from][to] = sc.nextInt();
			roads[to][from] = roads[from][to];
		}
		sc.close();
		if (n == 1 || start == target) {
			System.out.print("0 " + cities[0]);
			return;
		}
		if (n == 0) {
			System.out.print("0 0");
			return;
		}
		visited[start] = true;
		dfs(start, 0, cities[start]);

		System.out.print(minNum + " " + maxTeams);

	}

	public static void dfs(int i, int length, int teams) {
		if (i == target) {
			// ֱ�ӵ����յ�
			if (length < minLength) {
				minNum = 1;
				minLength = length;
				maxTeams = teams;
			} else if (length == minLength) {
				minNum++;
				if (maxTeams < teams) {
					maxTeams = teams;
				}
			}
			return;
		}
		if (length > minLength)
			return;// ������������ٽ���·�����ұ�����ֱ�ӷ��ؼ���
		// û���յ㣬��ʼ��i��ȱ���,��ʹ��ԭ��dfs���ڽӵ����������Ϊ��ԭ���ķ���ÿ���ʹ�һ����visited�ͻᱻ����Ϊfalse���Ժ��˻�����������·��ʱ���ͻ��Ҳ���
		// ����ÿ��ÿһ����Ϊ�����㣬��һ��forѭ����������֤��ÿһ�������������ÿ���ڽӵ����ֻ�ᱻ����һ�Σ����ң��Ӹõ������ĳһ·�����ص�ʱ�򣬸�·���ϳ��˳�����֮ǰ·���ϵĵ�ļ�¼���ᱻ����
		// ����Ҫ��ס�����ʱ���β����length��teamsҪ���³�ʼ��
		for (int k = 0; k < n; k++) {
			if (visited[k] == false && roads[i][k] != 0) {
				visited[k] = true;
				dfs(k, length + roads[i][k], teams + cities[k]);
				visited[k] = false;

			}

		}

	}

}
