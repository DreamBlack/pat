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
		 * ��������Ե�����ͨ�����������ο����˴��뷢�־Ͱ�maxsum=0,��ֵ0��Ϊ-1�Ϳ�����,
		 * ���й��ƴ�����Ǹ����Ե�������ֻ��һ��0���������Ǹ����������ԭ����д�����ͻ���Ե�ֻ��һ��0��������У�������Ϊ
		 * �������ж��Ǹ�������Ȼ�Ǵ����
		 */
		
		for (int i = nowhead; i < length; i++) {
			nowsum += nums[i];
			if (nowsum < 0) {// ��Ϊ����Ӧ�ô���һԪ�ؿ�ʼ�������к�
				nowsum = 0;
				nowhead = i + 1;

			} else {// ��Ϊ�������Լ������¼�
				if (nowsum > maxsum) {// �ҵ��˺͸��������
					head = nowhead;
					maxsum = nowsum;
					tail = i;
				}  else {
					// �Ͳ�û�б�󣬼�����һ��
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
		if (negative) {// ȫΪ����
			System.out.print(0 + " " + nums[0] + " " + nums[length - 1]);
		} else {
			System.out.print(maxsum + " " + nums[head] + " " + nums[tail]);
		}

	}

}
