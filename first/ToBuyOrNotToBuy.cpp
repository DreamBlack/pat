#include<stdio.h>
#include<set>
#include<string>
using namespace std;
char s1[1001];
char s2[1001];
int main(){
	/*
	��Ŀ���⣺�������ַ��������ڶ������е�����Ԫ�أ���ͬԪ���м���1��ҲҪ�м������Ƿ���1�ж��У��еĻ����1�ж�����
	��Ԫ�ظ��������Ƕ��еĻ����1��ȱʧ�ĸ���
	����˼·
	1��һ��ʼû���Լ��ֶ�ģ��һ�����ӣ������㷨�������˷��˺þá�
	2����ʵֻҪ���ڴ�2��ÿһ��Ԫ�أ����1���оͽ������е�Ԫ��ɾ�������2���ˣ�1��ʣ��Ԫ�ظ������Ƕ�����ġ�2û����2��ʣ��
	Ԫ�ظ�������1���ٵĸ�����
	3����ʵ������Ļ���1��Ԫ�ظ���-2��Ԫ�ظ�������1������ġ����Կ���ɨ��1����ͬʱ�������м�¼1��ÿ��Ԫ�س��ֵĴ�����hash����
	��ɨ��2��ÿ��Ԫ�أ���1�������Ԫ�أ����ü�¼�����һ��û�У����ʾ1ȱ�ˣ�����Miss++�����Miss=0��ʾ�������1lenth-2length,miss!=0
	��ʾȱʧ�����miss
	*/
	scanf("%s",s1);
	scanf("%s",s2);
	string shop(s1);
	string eva(s2);
	multiset<char> m1;
	for(int i=0;i<eva.size();i++){
		m1.insert(eva[i]);
	}
	multiset<char> m2;
	for(int i=0;i<shop.size();i++){
		if(m1.count(shop[i])!=0){//m1����
			m1.erase(m1.lower_bound(shop[i]));
		}else{//m1��û��
			m2.insert(shop[i]);
		}
	}
	int miss=0,extra=0;
	
	if(m1.empty()){
		extra=(m2.empty())?0:m2.size();
		printf("Yes %d",extra);
	}else{
		miss=m1.size();
		printf("No %d",miss);
	}
	return 0;
}