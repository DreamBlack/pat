#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
	/*
	��Ŀ���⣺���������������У��������������зֱ�ѡȡ��ͬ������Ԫ�ؽ���һ��һ��ˣ����ܵõ��ĳ˻�֮�����Ϊ����
	����˼·��
	1�����͵�̰���㷨
	2��Ҫ���Ż�ȯ��ϵ����ֵ����������һ����ʵ�������ߵ��Ż�ȯ��������˳���źã�Ȼ��ѡȡ���Ǿ���ֵ��������������ˣ�
	Ҳ����ѡ�����ֵ��������������ˣ�����ֱ��û�п�����Եģ��õ����ۼӺ;������ġ�
	3����һ���ȴ�������֮�����ˣ����ڸ���ҲӦ���ǰѾ���ֵ������˶����ǽ�������
	4��дcmp������ʱ�򣬷���true��ʱ��Ҫ�ӵ��ںŵ�ʱ�򣬲�Ȼ�ͳ�ʱ��
	*/
	int nc;
	scanf("%d",&nc);
	vector<int> coupons(nc);

	for(int a=0;a<nc;a++){
		scanf("%d",&(coupons[a]));
	}
	sort(coupons.begin(),coupons.end());
	int np;
	scanf("%d",&np);
	vector<int> products(np);
	for(int a=0;a<np;a++){
		scanf("%d",&(products[a]));
	}
	int i=0,j=0,all=0;
	sort(products.begin(),products.end());
	
	while(i<coupons.size()&&j<products.size()&&coupons[i]<0&&products[j]<0){
		all+=coupons[i]*products[j];
		i++;
		j++;
	}
	int p=coupons.size()-1,q=products.size()-1;
	while(p>=0&&q>=0&&coupons[p]>0&&products[q]>0){
		all+=coupons[p]*products[q];
		p--;
		q--;
	}
	printf("%d",all);
	return 0;
}