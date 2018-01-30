package first;

import java.util.Scanner;

public class Radix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * �����õ�java�Դ��Ľ���ת�������Ǻö����������ܹ� Ȼ����һ�±��˵Ĵ𰸣����ֽ��ƿ��ܳ���java����֧�ֵ�������36�����Ի��ǵ��Լ�д
		 * ��������˵�ǻ���ʱ�����һ�����ˡ����ҵ��������һ�����Ե�û�������ۣ������ٲ�һ��
		 * �ؼ��㣺
		 * 1��int�����������long
		 * 2��radix���ܵ��Ͻ���½죬�½�϶��ǳ��ֵ�����Ǹ��ַ�+1���Ͻ���಻���ܳ���n1��ֵ
		 * 3������2����Ҫ����n1��ֵ�ͱ��½�<=���������ʱ����ֲ��ҵ��Ҳ�͵����½�+1��������N1��
		 * 4���ö��ֲ��ң�����ʱ
		 * 5�����ֲ���ʱ���п��ܳ���ĳһ��������Ӧ����ֵ������������ʱ��Ӧ�������ұ߼���������ֲ��ң���һ��û�뵽��
		 */
		Scanner sc = new Scanner("10 5 1 5");
		String m = sc.next();
		String n = sc.next();
		int ab = sc.nextInt();
		int radix = sc.nextInt();
		sc.close();

		long a = 0, b = 0, radix2 = 0;
		boolean possible = false;
		if (ab == 2) {
			String temp = m;
			m = n;
			n = temp;

		}

		a = radixToDec(m, radix);
		// ���radixΪ��m��ֵ���ߣ�n������ַ�+1
		int max = Integer.parseInt(findmaxdigit(n), Character.MAX_RADIX) + 1;
		long high = (radixToDec(m, radix) > max) ? radixToDec(m, radix) + 1 : max + 2;
		long ret = binarySearch(max, high, n, a);
		if (ret != -1) {
			possible = true;
			radix2 = ret;

		}

		if (!possible) {
			System.out.print("Impossible");
		} else {
			System.out.print(radix2);
		}
	}

	public static int cmp(String s, long radix, long target) {
		long temp = radixToDec(s, radix);
		if (temp < 0)
			return 1;
		if (temp < target)
			return -1;
		return (temp == target) ? 0 : 1;
	}

	public static long binarySearch(long low, long high, String s, long a) {
		if (low > high)
			return -1;
		long mid = (low + high) / 2;
		long temp = cmp(s, mid, a);
		if (0 == temp) {
			return mid;
		} else if (temp == 1) {// �ۼ����������mid����
			return binarySearch(low, mid - 1, s, a);

		} else {
			return binarySearch(mid + 1, high, s, a);
		}

	}

	public static String findmaxdigit(String s) {
		int max = 0;
		char a = '0';
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) - '0' > max) {
				max = s.charAt(i) - '0';
				a = s.charAt(i);

			}
		}
		if (a == '0')
			return String.valueOf('1');
		return String.valueOf(a);
	}

	public static long radixToDec(String s, long radix) {

		long temp = 0;
		for (int j = s.length() - 1; j >= 0; j--) {
			temp = temp + Integer.parseInt(String.valueOf(s.charAt(j)), Character.MAX_RADIX)
					* ((int) Math.pow(radix, s.length() - j - 1));
		}
		return temp;

	}

}
