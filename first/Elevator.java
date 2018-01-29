package first;

import java.util.Scanner;

public class Elevator {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner("3 2 3 1");
		int n = sc.nextInt();
		int[] nums = new int[n + 1];
		nums[0] = 0;
		for (int i = 1; i <= n; i++) {
			nums[i] = sc.nextInt();
		}

		sc.close();

		int sum = 0;
		for (int i = 1; i <= n; i++) {
			int diff = nums[i] - nums[i - 1];
			sum = sum + ((diff >= 0) ? 6 * diff : 4 * (-diff)) + 5;
		}
		System.out.print(sum);

	}

}
