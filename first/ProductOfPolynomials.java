package first;

import java.util.Scanner;

public class ProductOfPolynomials {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * 多项式乘法刚开始一直没搞懂不同底数的两个幂相乘该怎么做。。 后来发现我没搞懂题目的意思1 2.4 0 3.2不是说 1^2.4+0^3.2，而是
		 * 2.4*x^1+3.2*x^0 这样就是通底数的幂了，只要把系数相乘，指数相加即可
		 * 唯一需要注意的是两个指数最大为1000的多项式相乘的指数最大可能为2000
		 * 
		 */
		double[] in1 = new double[1001];
		double[] result = new double[2001];
		Scanner sc = new Scanner("2 1 2.4 0 3.2 2 2 1.5 1 0.5");
		int m = sc.nextInt();
		for (int i = 0; i < m; i++) {
			int exp = sc.nextInt();
			double coe = sc.nextDouble();
			in1[exp] = coe;
		}
		int n = sc.nextInt();

		for (int i = 0; i < n; i++) {
			int exp = sc.nextInt();
			double coe = sc.nextDouble();
			for (int j = 0; j < 1001; j++) {
				if (in1[j] != 0) {
					result[exp + j] += coe * in1[j];
				}
			}
		}
		sc.close();
		int count = 0;
		for (int i = 2000; i >= 0; i--) {
			if (result[i] != 0) {
				count++;
			}
		}
		System.out.print(count);
		for (int i = 2000; i >= 0; i--) {
			if (result[i] != 0) {
				// String.format("%.1f", c)保留一位小数
				System.out.print(" " + i + " " + (double) (Math.round(result[i] * 10)) / 10);
			}
		}
	}

}
