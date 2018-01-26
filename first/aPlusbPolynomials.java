package first;

import java.util.Scanner;

public class aPlusbPolynomials {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * 我感觉，事实证明， 如果你对答案部分正确没有达到完全正确证明你用的方法，不是人家想让你用的方法
		 * 这道题的标准方法，就是用一个长为1001的数组，在读取输入的时候，根据底数，加到数组相应的位置， 即a[底数]+=输入的指数，算是hash吧
		 * 
		 * 这题，要记住 1、double保留几位小数的方法 (double) (Math.round(a[m]* 10)) /
		 * 10，10表示保留一位小数，100表示保留两位小数 2、将无小数部分的double按整数输出 if (result[m] - (int)
		 * (result[m]) == 0) { System.out.print((int) (result[m])); } else {
		 * System.out.print(result[m]); }
		 */

	}

	public static void allCorrect() {
		Scanner sc = new Scanner("2 1 2.4 0 3.2 2 2 1.5 1 0.5");
		int lengtha = (sc.nextInt()) * 2;
		int i = 0;
		int k = 0;
		double[] a = new double[1001];// 因为指数在[0,1000]之间
		while (i < lengtha) {
			a[sc.nextInt()] = sc.nextDouble();
			i += 2;
			k++;
		}

		int lengthb = (sc.nextInt()) * 2;
		int j = 0;
		int temp = 0;
		while (j < lengthb) {
			temp = sc.nextInt();
			if (a[temp] == 0) {
				a[temp] = sc.nextDouble();
				j += 2;
				k++;
			} else {
				a[temp] += sc.nextDouble();
				j += 2;
				if (a[temp] == 0) {
					k--;
				}
			}
		}
		sc.close();
		System.out.print(k);
		for (int m = 1000; m >= 0; m--) {
			if (a[m] != 0) {
				System.out.print(" " + m + " ");
				System.out.print((double) (Math.round(a[m] * 10)) / 10);
			}
		}
	}

	public static void partCorrect() {
		/*
		 * 感觉这种做法不能通过的原因是，输入的时候并不是按exp单调递增的顺序输入的， 且当相加后指数可能为0，此时就不需要输出了 可以输入重复的项
		 * 输入的项相加后可能为0，此时项数减1 当项目为0时，只输出项数，不要加空格 输出最后一项不要加空格 最终的结果多项式项数最多为20
		 */
		Scanner sc = new Scanner("2 1 2.4 0 3.2 2 2 1.5 1 0.5");
		int lengtha = (sc.nextInt()) * 2;
		int i = 0;
		double[] a = new double[lengtha];
		while (i < lengtha) {
			a[i++] = sc.nextFloat();
		}
		int lengthb = (sc.nextInt()) * 2;
		int j = 0;
		double[] b = new double[lengthb];
		while (j < lengthb) {
			b[j++] = sc.nextFloat();
		}
		sc.close();
		double[] result = new double[lengtha + lengthb];
		i = 0;
		j = 0;
		int p = 0;
		while (i < lengtha && j < lengthb) {
			// 如何保留两位小数
			// 以及如何将小数点后没有东西的小数按整数输出
			// float转Int
			if (a[i] == b[j]) {
				result[p] = (double) (Math.round(a[i] * 10)) / 10;
				result[p + 1] = (double) (Math.round((a[i + 1] + b[j + 1]) * 10)) / 10;
				i += 2;
				j += 2;
				p += 2;
			} else if (a[i] < b[j]) {
				result[p] = (double) (Math.round(b[j] * 10)) / 10;
				result[p + 1] = (double) (Math.round(b[j + 1] * 10)) / 10;
				j += 2;
				p += 2;
			} else {
				result[p] = (double) (Math.round(a[i] * 10)) / 10;
				result[p + 1] = (double) (Math.round(a[i + 1] * 10)) / 10;
				i += 2;
				p += 2;
			}
		}
		if (i < lengtha) {
			while (i < lengtha) {
				result[p] = (double) (Math.round(a[i] * 10)) / 10;
				result[p + 1] = (double) (Math.round(a[i + 1] * 10)) / 10;
				i += 2;
				p += 2;
			}
		}
		if (j < lengthb) {
			while (j < lengthb) {
				result[p] = (double) (Math.round(b[j] * 10)) / 10;
				result[p + 1] = (double) (Math.round(b[j + 1] * 10)) / 10;
				j += 2;
				p += 2;
			}
		}
		System.out.print(p / 2);
		for (int m = 0; m < p; m++) {
			System.out.print(" ");
			if (result[m] - (int) (result[m]) == 0) {
				System.out.print((int) (result[m]));
			} else {
				System.out.print(result[m]);
			}

		}
	}

}
