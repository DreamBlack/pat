#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int sorted[100000];
int num[100000];
int main(){
	/*
	��Ŀ���⣺���������У�����ͨ������ĳ�ַ���ȡһ��Ԫ����Ϊ��Ԫ��ͨ���������ѱ���ԪС��Ԫ�طŵ�������ߣ�����Ԫ���Ԫ�طŵ������ұߡ�
	�������ֺ��N��������ͬ�������������У������ж��ٸ�Ԫ�ؿ����ǻ���ǰѡȡ����Ԫ��
	����˼·��
	1����ʼ�ⷨ������Num[i]��ֻ������������Ԫ����λ�ú��м������е�λ����ͬ��ʱ��ſ�����privot�����ҵ�i��ߵ�Ԫ�ض�����С���ұߵ�Ԫ��
	���������ʱ�������Ԫ�ء�
	2��ʹ��1ʱ���������Ե㳬ʱ��һ�����Ե���󡣴���ĵ㾭��֤�ǵ����������ĵ�ֻ��0��ʱ����ʱ���Ӧ��Ϊ0\n\n����������0
	3��Ϊ�����ʱ���⡣1���仰˵���ǣ�i��0��i��Ԫ���������ֵ����iͬ��������iλ����Ԫ����ͬ���������ܱ�֤iͬʱ�Ǻ���n-i��Ԫ���е���Сֵ

	*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		num[i]=tmp;
		sorted[i]=tmp;
	}
	sort(sorted,sorted+n);
	int cnt=n;
	vector<int>last;
	int max=0;
	for(int i=0;i<n;i++){
		if(num[i]==sorted[i]&&num[i]>max){//���num[i]��֮ǰ�����ֵ����Ļ���֤��i֮ǰ��Ԫ�ض�û�е�ǰԪ�ش�
			last.push_back(num[i]);
		}
		if(num[i]>max){//���������ֵ���ܰ����������Ǹ�if���棬����max����ʼ�ձ�����max
			max=num[i];
		}

	}
	if(!last.empty()){
		printf("%d\n",last.size());
		for(int i=0;i<last.size();i++){
			printf("%d",last[i]);
			if(i!=last.size()-1){
				printf(" ");
			}
		}
	}else{
		printf("0\n\n");
	}
	return 0;
}