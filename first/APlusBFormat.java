package first;

import java.util.Scanner;

public class APlusBFormat {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * ���ۡ���ôһ���򵥵���д�˺þúþá����ǲ�����ȷ����֪��Ϊɶ
		 * û�취���ֻ�øĳ������ַ����мӶ��ţ�Ȼ������ַ����ķ�������ʵ���������Ȼ���򵥣����Ƕ��ַ����Ĳ�����̫�죬��Ҫ�ú�ѧ���úû����ܽ�
		 * �����⣬����д�����ָ�ʽ
		 * import java.util.Scanner; 
		 * public class Main { public static void
		 * 	main(String[] args){
		 *  ���������system.in��system.out
		 *  
		 * }
		 * ��
		 */
		stringCorrect();

	}

	public static void stringCorrect() {
		Scanner sc = new Scanner("-10999999 200");
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();
		int sum = a + b;
		if (sum < 1000 && sum > -1000) {
			System.out.print(sum);
		} else {
			if (sum < 0) {
				System.out.print("-");
				sum = 0 - sum;
			}
			String s = String.valueOf(sum);
			StringBuilder sb = new StringBuilder(s);
			int length = s.length();
			int i = length - 3;
			while (i > 0) {
				sb.insert(i, ",");// �ڵ�i��λ�ü����ַ���
				i = i - 3;
			}
			s = sb.toString();
			System.out.print(s);
		}
	}

	public static void partCorrect() {
		Scanner sc = new Scanner("-10999999 200");
		int a = sc.nextInt();
		int b = sc.nextInt();

		int sum = a + b;
		if (sum < 1000 && sum > -1000) {
			System.out.print(sum);
		} else {
			if (sum < 0) {
				System.out.print("-");
				sum = 0 - sum;
			}
			int i = 1000;
			while (sum / i >= 1000) {
				i = 1000 * i;
			}
			System.out.print(sum / i + ",");
			sum = sum % i;
			i = i / 1000;
			while (i > 1) {
				System.out.printf("%03d", sum / i);// 0��ʾǰ�����0,3��ʾ���ֿ��
				System.out.print(",");// ��������ˣ�û�п��ǵ������sum/1000������λ������ֻ����λ�����ͻ�ʹ֮ǰ��һЩ0ʧȥ����������1000������Ļ���0

				sum = sum % i;
				i = i / 1000;
			}
			System.out.printf("%03d", sum);
		}
		sc.close();
	}

}
