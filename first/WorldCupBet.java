package first;

import java.math.BigDecimal;
import java.util.Scanner;

public class WorldCupBet {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * 这题有一个四舍五入保留两位小数的问题
		 */
		Scanner sc = new Scanner("1.1  2.5  1.7 1.2  3.0  1.6 4.1  1.2  1.1");
		int[] wtl = new int[3];
		double[] odds = new double[3];
		for (int i = 0; i < 3; i++) {
			double max = -1, temp = -1;
			for (int j = 0; j < 3; j++) {
				temp = sc.nextDouble();
				if (temp > max) {
					max = temp;
					wtl[i] = j;
				}
			}
			odds[i] = max;
		}

		sc.close();
		double result = (odds[0] * odds[1] * odds[2] * 0.65 - 1) * 2 + 0.005;// +0.005是为了如果第三位小数大于5，直接产生进位，后来直接截断即可
		for (int i = 0; i < 3; i++) {
			int t = wtl[i];
			String m = null;
			switch (t) {
			case 0:
				m = "W";
				break;
			case 1:
				m = "T";
				break;
			case 2:
				m = "L";
				break;

			}
			System.out.print(m + " ");

		}
		BigDecimal bg = new BigDecimal(result);
		result = bg.setScale(2, BigDecimal.ROUND_DOWN).doubleValue();// 直接截取后2位
		System.out.print(result);// 2表示保留两位小数
	}

}
