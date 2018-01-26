package first;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class CountLeaves {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// �����˲�֪������ǲ�֪����ʲô���������Ľṹ���ο�������ѡ���ö�ά����
		// �Լ�ʲôʱ���֪���Լ���������������һ�㣬����һ�£���һ����ÿ��һ�����ʱ���ڶ��в���һ��-1,��ʾһ�����
		//���������������������ģ�һ���ύȫ��ͨ�����о��Լ�������
		Scanner sc = new Scanner("1 0");
		int n = sc.nextInt();
		int m = sc.nextInt();

		int[][] nodes = new int[n + 1][n + 1];
		for (int i = 0; i < m; i++) {
			int nodeid = sc.nextInt();
			int childnum = sc.nextInt();
			nodes[nodeid][0] = childnum;// ��ʾ�ý���Ƿ�Ҷ�ڵ�
			for (int j = 0; j < childnum; j++) {
				nodes[nodeid][sc.nextInt()] = 1;
			}

		}

		int[] leaves = new int[100];
		int level = 0;
		Queue<Integer> q = new LinkedList<>();
		q.offer(1);
		q.offer(-1);
		int ck = 0;
		while (!q.isEmpty()) {

			int now = q.poll();
			if (now != -1) {
				if (nodes[now][0] == 0) {
					ck++;// Ҷ�ڵ�
				} else {

					for (int i = 1; i < n + 1; i++) {
						if (nodes[now][i] == 1) {// �Ѹ������Ӽ������
							q.offer(i);
						}

					}
				}

			} else {
				// һ���������

				leaves[level] = ck;
				level++;
				ck = 0;
				if (q.isEmpty()) {
					break;
				} else {
					q.offer(-1);
				}

			}

		}
		for (int i = 0; i < level - 1; i++) {
			System.out.print(leaves[i] + " ");
		}
		System.out.print(leaves[level - 1]);
	}

}
