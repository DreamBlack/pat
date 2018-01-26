package first;

import java.util.Scanner;

public class SpellItRight {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * 这题主要是把数字看成String比较简单，
		 * 要记住，char转Int和int转String
		 * 以及switch
		 */
		Scanner sc = new Scanner("0");
		String num = sc.nextLine();
		sc.close();
		int sum = 0;
		for (int i = 0; i < num.length(); i++) {
			sum += num.charAt(i) - '0';
		}
		String ret = String.valueOf(sum);
		for (int i = 0; i < ret.length() - 1; i++) {
			System.out.print(digitTOEnglish(ret.charAt(i) - '0') + " ");
		}
		System.out.print(digitTOEnglish(ret.charAt(ret.length() - 1) - '0'));
	}

	public static String digitTOEnglish(int i) {
		String ret = null;
		if (i > 9 || i < 0) {
			return "";
		}
		switch (i) {
		case 0:
			ret = "zero";
			break;
		case 1:
			ret = "one";
			break;
		case 2:
			ret = "two";
			break;
		case 3:
			ret = "three";
			break;
		case 4:
			ret = "four";
			break;
		case 5:
			ret = "five";
			break;
		case 6:
			ret = "six";
			break;
		case 7:
			ret = "seven";
			break;
		case 8:
			ret = "eight";
			break;
		case 9:
			ret = "nine";
			break;

		}
		return ret;
	}

}
