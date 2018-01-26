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

		// ��Ȼȥ����Щ�������жϾͶ��ˡ����ؼ�������һ�ַ���Ҳ���������жϵ���Ҳ����ѽ
		norecord();
		/*
		 * �������֮��ʹ��dijkstra�㷨������������ԭ���㷨����path[i]��¼���·���ϵ�i��֮ǰ���Ǹ����У�������ʵ��Ŀ�ﲢû����Ҫ�����·��
		 * ��ˣ�����ֻ��¼pathnum[i]��i������·��������,teamNum[i]��¼��i������·���Ͼ�Ԯ������
		 * ��һ��ʹ�������¼·���ϵ�parentȻ�����ô�target������ȱ����ķ����õ�·������ξͲ�д��
		 */

	}

	public static void norecord() {
		// ����¼·������һ�����Ե����
		pathNum = new int[n];
		teamNum = new int[n];
		pathNum[start] = 1;
		teamNum[start] = cities[start];

		int now = start;
		while (now != target) {
			int min = -1;
			int minnum = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				if (roads[now][i] != 0 && isMin[i] == false) {// �Ѿ��ҵ����·���ĵ�Ͳ�����ȥ����
					// �ҵ�һ���ڽӵ�
					if (pathLength[i] > pathLength[now] + roads[now][i]) {
						// �ҵ��˱�ԭ�����̵�·
						pathLength[i] = pathLength[now] + roads[now][i];
						pathNum[i] = pathNum[now];
						teamNum[i] = teamNum[now] + cities[i];
					} else if (pathLength[i] == pathLength[now] + roads[now][i]) {
						// �ҵ�����һ�����·��
						pathNum[i] = pathNum[now] + pathNum[i];
						if (teamNum[i] < teamNum[now] + cities[i]) {
							// ����·���Ͼ�Ԯ����������
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
