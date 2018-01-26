package first;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Scanner;

public class SigninSignout {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * 注意Next而不是nextline 以及字符串比较compareTo函数
		 */

		Scanner sc = new Scanner("3 CS301111 15:30:28 17:00:10 SC3021234 08:00:00 11:25:25 CS301133 21:45:00 21:58:40");
		int n = sc.nextInt();
		String[][] records = new String[n][3];
		long[][] time = new long[n][2];
		try {
			for (int i = 0; i < n; i++) {
				Calendar c = Calendar.getInstance();
				records[i][0] = sc.next();// 注意是Next而不是nextline
				records[i][1] = sc.next();
				records[i][2] = sc.next();
				c.setTime(new SimpleDateFormat("yyyy-mm-dd hh:mm:ss").parse("2018-01-01 " + records[i][1]));
				time[i][0] = c.getTimeInMillis();
				c.setTime(new SimpleDateFormat("yyyy-mm-dd hh:mm:ss").parse("2018-01-01 " + records[i][2]));
				time[i][1] = c.getTimeInMillis();

			}
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		sc.close();
		String unlock = records[0][0], lock = records[0][0];
		long early = time[0][0], last = time[0][1];
		for (int i = 1; i < n; i++) {
			if (time[i][0] < early) {
				early = time[i][0];
				unlock = records[i][0];
			}
			if (time[i][1] > last) {
				last = time[i][1];
				lock = records[i][0];
			}
		}
		System.out.print(unlock + " " + lock);

	}

	public static void simple() {
		// 简单字符串比较
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[][] records = new String[n][3];
		for (int i = 0; i < n; i++) {
			records[i][0] = sc.next();
			records[i][1] = sc.next();
			records[i][2] = sc.next();
		}
		sc.close();
		String unlock = records[0][0], lock = records[0][0];
		String early = records[0][1], last = records[0][2];
		for (int i = 0; i < n; i++) {
			if (early.compareTo(records[i][1]) > 0) {
				early = records[i][1];
				unlock = records[i][0];
			}
			if (last.compareTo(records[i][2]) < 0) {
				last = records[i][2];
				lock = records[i][0];
			}
		}
		System.out.print(unlock + " " + lock);
	}

}
