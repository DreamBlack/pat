package remember;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class InputAndOutput {
	/*
	 * System.out.printf("%03d", sum / i);
	 *  0表示前面填充0,3表示数字宽度 println是换行，print是不换行
	 *  以下是在字符串第i位上插入一个字符串的方法
	 *  	String s = String.valueOf(sum);
			StringBuilder sb = new StringBuilder(s);
			sb.insert(i, ",");// 在第i个位置加上字符串
			s = sb.toString();
	*  以下是使用scanner从标准输入流输入		
		Scanner sc = new Scanner("-10999999 200");
		int a = sc.nextInt();
		int b = sc.nextInt();
		
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CharTest(); // 调用System.in方法
		ReadTest(); // 调用ReadTest方法
		ScannerTest();// 调用ScannerTest方法
	}
	/*
	 * 法一：用System.out和System.in 缺点1：能获取从键盘输入的字符，但只能获取一个字符 缺点2：获取的是char类型的。
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
	 * 方法二，用InputStreamReader和BufferedReader 优点：可以获取键盘输入的字符串
	 * 缺点：如果要获取int,float等类型需要转换
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
	 * Scanner类中的方法 优点一：可以获取键盘输入的字符串 优点二：有现成的int,float等类型数据
	 */
	public static void ScannerTest() {
		Scanner sc = new Scanner(System.in);
		System.out.println("ScannerTest, Please Enter Name:");
		String name = sc.nextLine();// 读取字符串类型
		System.out.println("ScannerTest, Please Enter Age:");
		int age = sc.nextInt();// 读取整型输入
		System.out.println("ScannerTest, Please Enter Salary:");
		float salary = sc.nextFloat();// 读取float型输入
		System.out.println("Your Information is as below:");
		System.out.println("Name:" + name + "\n" + "Age:" + age + "\n" + "Salary:" + salary);

	}

}
