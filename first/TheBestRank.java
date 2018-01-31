package first;

import java.util.Scanner;

public class TheBestRank {
	private static String[] studs;

	public static void main(String[] args) {
		/*
		 * �ܵ���˵�أ��������ʵͦ�򵥵ġ�����д��ʱ������˺ö�ë�������˺þò�ͨ��
		 * 1��String����ֱ�Ӹ������⡣ֱ���õȺŸ��ƵĻ���ʵ�ǰ������ָ�븳ֵ������һ�����飬��ʵ��Ȼ��ͬһ������
		 * 2����ͨ����������Ϊ�β��Ǵ�ֵ�����飨������int,����String�����Ǵ�����
		 * 3����������partionʱ��while���������ϵȺţ���Ȼ�ᵼ����ѭ��
		 * 4��������˵���ڴ���������ʹ��Scanner��Ƚ��������׳�ʱ
		 * 5�������Ǿ仰����Ҫ�������±������˷�ʱ�䣬�Ȱ������㷨����ѡ�õ����ݽṹ���������һ������Ч�ʻ����
		 */
		Scanner sc = new Scanner(
				"5 6 310101 98 85 88 310102 70 95 88 310103 82 87 94 310104 91 91 91 310105 85 90 94 310101 310102 310103 310104 310105 999999");
		int n = sc.nextInt();
		int m = sc.nextInt();
		studs = new String[n];
		String[] rankcs = new String[n];// String[] rankcs=studs��������ô���������ǰ�studs�ĵ�ַ����rankcs��ʵ����ָ�����ͬһ������
		String[] rankms = new String[n];
		String[] rankes = new String[n];
		String[] rankavs = new String[n];
		int[] cs = new int[n];
		int[] ms = new int[n];
		int[] es = new int[n];
		int[] avs = new int[n];
		for (int i = 0; i < n; i++) {
			studs[i] = sc.next();
			rankcs[i] = studs[i];
			rankms[i] = studs[i];
			rankes[i] = studs[i];
			rankavs[i] = studs[i];
			cs[i] = sc.nextInt();
			ms[i] = sc.nextInt();
			es[i] = sc.nextInt();
			avs[i] = (cs[i] + ms[i] + es[i]) / 3;

		}

		// �����ÿ������n��ѧ�����ſε�������Ū����
		quickSort(cs, rankcs, 0, cs.length - 1);

		quickSort(ms, rankms, 0, ms.length - 1);

		quickSort(es, rankes, 0, es.length - 1);

		quickSort(avs, rankavs, 0, avs.length - 1);

		String[] results = new String[m];
		for (int i = 0; i < m; i++) {
			String id = sc.next();
			if (findID(studs, id) == -1) {// �Ҳ���ѧ��
				results[i] = "N/A";
			} else {
				// �������������ҵ����ȼ�������������ߵ�����
				int[] ranks = new int[4];
				ranks[0] = findRank(rankavs, avs, id);
				ranks[1] = findRank(rankcs, cs, id);
				ranks[2] = findRank(rankms, ms, id);
				ranks[3] = findRank(rankes, es, id);

				int min = 0;
				for (int j = 0; j < 4; j++) {
					if (ranks[j] < ranks[min]) {
						min = j;
					}
				}
				String a = "";
				switch (min) {
				case 0:
					a = "A";
					break;
				case 1:
					a = "C";
					break;
				case 2:
					a = "M";
					break;
				case 3:
					a = "E";
					break;

				}
				results[i] = ranks[min] + " " + a;
			}
		}
		sc.close();
		for (int i = 0; i < m - 1; i++) {
			System.out.println(results[i]);
		}
		System.out.print(results[m - 1]);
	}

	public static int findID(String[] studs, String id) {
		for (int i = 0; i < studs.length; i++) {
			if (id.equals(studs[i])) {
				return i + 1;
			}
		}
		return -1;
	}

	public static int findRank(String[] studs, int[] grades, String id) {
		int rank = findID(studs, id);
		if (rank == -1)
			return -1;
		int r = rank - 1;
		for (int i = r - 1; i >= 0; i--) {
			if (grades[rank - 1] == grades[i]) {
				r--;
			}
		}
		return r + 1;
	}

	public static void quickSort(int[] nums, String[] id, int left, int right) {
		if (left >= right) {
			return;
		}
		int pivot = partion(nums, id, left, right);
		quickSort(nums, id, left, pivot - 1);
		quickSort(nums, id, pivot + 1, right);
	}

	public static int partion(int[] nums, String[] id, int left, int right) {

		int pivot = nums[left];
		String pid = id[left];
		int i = left, j = right;
		while (i < j) {
			while (i < j && nums[j] <= pivot) {// �����е��ں�
				j--;
			}
			nums[i] = nums[j];
			id[i] = id[j];
			while (i < j && nums[i] >= pivot) {
				i++;
			}
			nums[j] = nums[i];
			id[j] = id[i];
		}
		nums[i] = pivot;
		id[i] = pid;
		return i;

	}

}
