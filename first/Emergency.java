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
		 * 千辛万苦终于在写dijkstra的时候找到了错误
		 * 亲，这是无向图！！！！无向图的邻接矩阵是对称的呀，结果我只写了赋值成了上三角的，忘了下三角对称的部分也要赋值的呀，这句导致几个测试点通不过，桑心至极
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
			// 直接到了终点
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
			return;// 这种情况无需再进行路径查找遍历，直接返回即可
		// 没到终点，开始从i深度遍历,不使用原来dfs找邻接点的做法，因为，原来的方法每访问过一个点visited就会被设置为false，以后退回找另外的最短路径时，就会找不到
		// 所有每以每一个点为出发点，用一个for循环，这样保证从每一个点出发，它的每个邻接点最多只会被访问一次，而且，从该点出发的某一路径返回的时候，该路径上除了出发点之前路径上的点的记录都会被擦掉
		// 但是要记住，这个时候，形参里的length和teams要重新初始化
		for (int k = 0; k < n; k++) {
			if (visited[k] == false && roads[i][k] != 0) {
				visited[k] = true;
				dfs(k, length + roads[i][k], teams + cities[k]);
				visited[k] = false;

			}

		}

	}

}
