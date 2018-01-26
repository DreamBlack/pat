package first;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class CountLeaves {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 最令人不知所措的是不知道用什么来保存树的结构，参考了网上选择用二维数组
		// 以及什么时候就知道以及遍历到了树的下一层，查了一下，有一种是每当一层结束时就在队列插入一个-1,表示一层结束
		//哈哈哈哈哈哈，超级开心，一次提交全部通过。感觉自己棒棒哒
		Scanner sc = new Scanner("1 0");
		int n = sc.nextInt();
		int m = sc.nextInt();

		int[][] nodes = new int[n + 1][n + 1];
		for (int i = 0; i < m; i++) {
			int nodeid = sc.nextInt();
			int childnum = sc.nextInt();
			nodes[nodeid][0] = childnum;// 表示该结点是非叶节点
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
					ck++;// 叶节点
				} else {

					for (int i = 1; i < n + 1; i++) {
						if (nodes[now][i] == 1) {// 把各个孩子加入队列
							q.offer(i);
						}

					}
				}

			} else {
				// 一层遍历结束

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
