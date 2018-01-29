package first;

import java.util.Scanner;

public class MaximunSumSequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner("6 -2 -11 -4 0 -5 -2");
		int length = sc.nextInt();
		int[] nums = new int[length];
		for (int i = 0; i < length; i++) {
			nums[i] = sc.nextInt();
		}
		sc.close();

		int maxsum = 0, head = 0,  nowsum = 0,tail=0, nowhead = 0;
		/*
		 * 第五个测试点总是通不过，后来参考别人代码发现就把maxsum=0,初值0改为-1就可以了,
		 * 所有估计错误的那个测试点是里面只有一个0，其他都是负数，如果按原来的写法，就会忽略掉只有一个0的这个序列，反而认为
		 * 整个序列都是负数，显然是错误的
		 */
		
		for (int i = nowhead; i < length; i++) {
			nowsum += nums[i];
			if (nowsum < 0) {// 和为负，应该从下一元素开始再求序列和
				nowsum = 0;
				nowhead = i + 1;

			} else {// 和为正，可以继续往下加
				if (nowsum > maxsum) {// 找到了和更大的序列
					head = nowhead;
					maxsum = nowsum;
					tail = i;
				}  else {
					// 和并没有变大，继续下一步
				}
			}
		}
		boolean negative=true;
		for(int i=0;i<length;i++) {
			if(nums[i]>=0) {
				negative=false;
				break;
			}
		}
		if (negative) {// 全为负数
			System.out.print(0 + " " + nums[0] + " " + nums[length - 1]);
		} else {
			System.out.print(maxsum + " " + nums[head] + " " + nums[tail]);
		}

	}

}
