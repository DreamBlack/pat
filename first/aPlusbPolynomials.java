package first;

import java.util.Scanner;

public class aPlusbPolynomials {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * �Ҹо�����ʵ֤���� �����Դ𰸲�����ȷû�дﵽ��ȫ��ȷ֤�����õķ����������˼��������õķ���
		 * �����ı�׼������������һ����Ϊ1001�����飬�ڶ�ȡ�����ʱ�򣬸��ݵ������ӵ�������Ӧ��λ�ã� ��a[����]+=�����ָ��������hash��
		 * 
		 * ���⣬Ҫ��ס 1��double������λС���ķ��� (double) (Math.round(a[m]* 10)) /
		 * 10��10��ʾ����һλС����100��ʾ������λС�� 2������С�����ֵ�double��������� if (result[m] - (int)
		 * (result[m]) == 0) { System.out.print((int) (result[m])); } else {
		 * System.out.print(result[m]); }
		 */

	}

	public static void allCorrect() {
		Scanner sc = new Scanner("2 1 2.4 0 3.2 2 2 1.5 1 0.5");
		int lengtha = (sc.nextInt()) * 2;
		int i = 0;
		int k = 0;
		double[] a = new double[1001];// ��Ϊָ����[0,1000]֮��
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
		 * �о�������������ͨ����ԭ���ǣ������ʱ�򲢲��ǰ�exp����������˳������ģ� �ҵ���Ӻ�ָ������Ϊ0����ʱ�Ͳ���Ҫ����� ���������ظ�����
		 * ���������Ӻ����Ϊ0����ʱ������1 ����ĿΪ0ʱ��ֻ�����������Ҫ�ӿո� ������һ�Ҫ�ӿո� ���յĽ������ʽ�������Ϊ20
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
			// ��α�����λС��
			// �Լ���ν�С�����û�ж�����С�����������
			// floatתInt
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
