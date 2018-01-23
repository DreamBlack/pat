package remember;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class InputAndOutput {
	/*
	 * System.out.printf("%03d", sum / i);
	 *  0��ʾǰ�����0,3��ʾ���ֿ�� println�ǻ��У�print�ǲ�����
	 *  ���������ַ�����iλ�ϲ���һ���ַ����ķ���
	 *  	String s = String.valueOf(sum);
			StringBuilder sb = new StringBuilder(s);
			sb.insert(i, ",");// �ڵ�i��λ�ü����ַ���
			s = sb.toString();
	*  ������ʹ��scanner�ӱ�׼����������		
		Scanner sc = new Scanner("-10999999 200");
		int a = sc.nextInt();
		int b = sc.nextInt();
		
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CharTest(); // ����System.in����
		ReadTest(); // ����ReadTest����
		ScannerTest();// ����ScannerTest����
	}
	/*
	 * ��һ����System.out��System.in ȱ��1���ܻ�ȡ�Ӽ���������ַ�����ֻ�ܻ�ȡһ���ַ� ȱ��2����ȡ����char���͵ġ�
	 */

	public static void CharTest() {
		System.out.println("Enter a Char:");
		char i;
		try {
			i = (char) System.in.read();
			System.out.println("Your Enter Char is:" + i);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	/*
	 * ����������InputStreamReader��BufferedReader �ŵ㣺���Ի�ȡ����������ַ���
	 * ȱ�㣺���Ҫ��ȡint,float��������Ҫת��
	 */
	public static void ReadTest() {
		System.out.println("ReadTest, Please Enter Data:");
		InputStreamReader is = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(is);
		String name;
		try {
			name = br.readLine();
			System.out.println("ReadTest Output:" + name);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	/*
	 * Scanner���еķ��� �ŵ�һ�����Ի�ȡ����������ַ��� �ŵ�������ֳɵ�int,float����������
	 */
	public static void ScannerTest() {
		Scanner sc = new Scanner(System.in);
		System.out.println("ScannerTest, Please Enter Name:");
		String name = sc.nextLine();// ��ȡ�ַ�������
		System.out.println("ScannerTest, Please Enter Age:");
		int age = sc.nextInt();// ��ȡ��������
		System.out.println("ScannerTest, Please Enter Salary:");
		float salary = sc.nextFloat();// ��ȡfloat������
		System.out.println("Your Information is as below:");
		System.out.println("Name:" + name + "\n" + "Age:" + age + "\n" + "Salary:" + salary);

	}

}
