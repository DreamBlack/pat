package first;

import java.util.Scanner;

public class APlusBFormat {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * 心累。这么一道简单的题写了好久好久。总是部分正确，不知道为啥
		 * 没办法最后只好改成了在字符串中加逗号，然后输出字符串的方法，其实这个方法显然更简单，但是对字符串的操作不太熟，需要好好学，好好积累总结
		 * 浙大的题，必须写成这种格式
		 * import java.util.Scanner; 
		 * public class Main { public static void
		 * 	main(String[] args){
		 *  输入输出用system.in和system.out
		 *  
		 * }
		 * 唉
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
				sb.insert(i, ",");// 在第i个位置加上字符串
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
				System.out.printf("%03d", sum / i);// 0表示前面填充0,3表示数字宽度
				System.out.print(",");// 这里出错了，没有考虑到，如果sum/1000不是三位数，而只是两位数，就会使之前的一些0失去，比如输入1000，输出的会是0

				sum = sum % i;
				i = i / 1000;
			}
			System.out.printf("%03d", sum);
		}
		sc.close();
	}

}
