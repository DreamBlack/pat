package first;

import java.util.Scanner;

public class Radix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * 本来用的java自带的进制转换，但是好多用例都不能过 然后看了一下别人的答案，发现进制可能超过java本身支持的最大进制36，所以还是得自己写
		 * 这道题可以说是花的时间最长的一道题了。而且到最后还是有一个测试点没过。心累，明天再查一遍
		 * 关键点：
		 * 1、int会溢出必须用long
		 * 2、radix可能的上届和下届，下界肯定是出现的最大那个字符+1，上届最多不可能超过n1的值
		 * 3、对于2，需要考虑n1的值和比下届<=的情况，这时候二分查找的右侧就得是下届+1，而不是N1了
		 * 4、用二分查找，否则超时
		 * 5、二分查找时，有可能出现某一个基数对应的数值溢出的情况，这时候应该削掉右边继续往左二分查找（这一点没想到）
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
		// 最大radix为，m的值或者，n中最大字符+1
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
		} else if (temp == 1) {// 累加溢出，不行mid往左
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
