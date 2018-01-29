package first;

import java.util.Scanner;

public class ProductOfPolynomials {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * ����ʽ�˷��տ�ʼһֱû�㶮��ͬ��������������˸���ô������ ����������û�㶮��Ŀ����˼1 2.4 0 3.2����˵ 1^2.4+0^3.2������
		 * 2.4*x^1+3.2*x^0 ��������ͨ���������ˣ�ֻҪ��ϵ����ˣ�ָ����Ӽ���
		 * Ψһ��Ҫע���������ָ�����Ϊ1000�Ķ���ʽ��˵�ָ��������Ϊ2000
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
				// String.format("%.1f", c)����һλС��
				System.out.print(" " + i + " " + (double) (Math.round(result[i] * 10)) / 10);
			}
		}
	}

}
