package first;

import java.util.Scanner;

public class dijkstraEmergency {
	private static int[] cities;
	private static int[][] roads;
	private static int n;
	private static int start;
	private static int target;
	private static int[] pathLength;
	private static boolean[] isMin;

	private static int[] pathNum;
	private static int[] teamNum;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		firstVersion();

	}

	public static void firstVersion() {
		Scanner sc = new Scanner("5 6 0 2 1 2 1 5 3 0 1 1 0 2 2 0 3 1 1 2 1 2 4 1 3 4 1");
		n = sc.nextInt();
		int m = sc.nextInt();
		start = sc.nextInt();
		target = sc.nextInt();
		cities = new int[n];
		pathLength = new int[n];
		isMin = new boolean[n];

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

		for (int i = 0; i < n; i++) {
			pathLength[i] = Integer.MAX_VALUE;
		}
		pathLength[start] = 0;

		for (int i = 0; i < n; i++) {
			isMin[i] = false;
		}
		isMin[start] = true;

		// 居然去掉那些特殊点的判断就对了。。关键是我另一种方法也用了这种判断但是也对了呀
		norecord();
		/*
		 * 输入完成之后使用dijkstra算法，本来是想用原来算法里用path[i]记录最短路径上到i点之前的那个城市，但是其实题目里并没有需要具体的路径
		 * 因此，可以只记录pathnum[i]到i点的最短路径的条数,teamNum[i]记录到i点的最短路径上救援队总数
		 * 另一种使用链表记录路径上的parent然后再用从target深度优先遍历的方法得到路径，这次就不写了
		 */

	}

	public static void norecord() {
		// 不记录路径，有一个测试点错误
		pathNum = new int[n];
		teamNum = new int[n];
		pathNum[start] = 1;
		teamNum[start] = cities[start];

		int now = start;
		while (now != target) {
			int min = -1;
			int minnum = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				if (roads[now][i] != 0 && isMin[i] == false) {// 已经找到最短路径的点就不用再去看了
					// 找到一个邻接点
					if (pathLength[i] > pathLength[now] + roads[now][i]) {
						// 找到了比原来更短的路
						pathLength[i] = pathLength[now] + roads[now][i];
						pathNum[i] = pathNum[now];
						teamNum[i] = teamNum[now] + cities[i];
					} else if (pathLength[i] == pathLength[now] + roads[now][i]) {
						// 找到了另一条最短路径
						pathNum[i] = pathNum[now] + pathNum[i];
						if (teamNum[i] < teamNum[now] + cities[i]) {
							// 这条路径上救援队数量更多
							teamNum[i] = teamNum[now] + cities[i];
						}
					}

				}
			}
			for (int i = 0; i < n; i++) {
				if (isMin[i] == false && minnum > pathLength[i]) {
					min = i;
					minnum = pathLength[i];
				}
			}
			isMin[min] = true;
			now = min;
		}
		System.out.println(pathNum[target] + " " + teamNum[target]);
	}

}
