package first;

import java.util.Scanner;

public class TheBestRank {
	private static String[] studs;

	public static void main(String[] args) {
		/*
		 * 总的来说呢，这个题其实挺简单的。但是写的时候出现了好多毛病，改了好久才通过
		 * 1、String数组直接复制问题。直接用等号复制的话其实是把数组的指针赋值给了另一个数组，其实仍然是同一个数组
		 * 2、普通数据类型作为形参是传值，数组（不论是int,还是String）都是传引用
		 * 3、快排序，在partion时，while里面必须加上等号，不然会导致死循环
		 * 4、据网上说对于大输入数据使用Scanner会比较慢，容易超时
		 * 5、还是那句话，不要上来就下笔容易浪费时间，先把所有算法，和选用的数据结构在脑子里过一遍再做效率会更高
		 */
		Scanner sc = new Scanner(
				"5 6 310101 98 85 88 310102 70 95 88 310103 82 87 94 310104 91 91 91 310105 85 90 94 310101 310102 310103 310104 310105 999999");
		int n = sc.nextInt();
		int m = sc.nextInt();
		studs = new String[n];
		String[] rankcs = new String[n];// String[] rankcs=studs不可以这么做，这样是把studs的地址给了rankcs，实际上指向的是同一个数组
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

		// 下面用快排序把n个学生各门课的排名都弄出来
		quickSort(cs, rankcs, 0, cs.length - 1);

		quickSort(ms, rankms, 0, ms.length - 1);

		quickSort(es, rankes, 0, es.length - 1);

		quickSort(avs, rankavs, 0, avs.length - 1);

		String[] results = new String[m];
		for (int i = 0; i < m; i++) {
			String id = sc.next();
			if (findID(studs, id) == -1) {// 找不到学生
				results[i] = "N/A";
			} else {
				// 在三个排名中找到优先级最大的且排名最高的排名
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
			while (i < j && nums[j] <= pivot) {// 必须有等于号
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
