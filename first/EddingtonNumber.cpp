#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000000];
bool cmp1(int a, int b) {return a > b;}
int main() {
	/*
	��Ŀ���⣺����n����ﳵ���룬���������������ʵ�������E�����E��ʾE������о��볬��EӢ�
	����˼·��
	1������Ŀ���������⡣�տ�ʼ��������n������e���ڵ������е�·�̱ȵ����������Ŵ󣬽����һ�����Ե����
	2����ʵ��Ŀ������ˡ���Ŀ��˼��˵��һ������e�����e��ʾ����e�����еľ����e��
	�������к������i�����о����i����ǰ1-i-1�����о������Ҳ��i�󡣴�ʱans����Ϊi
	*/
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1, cmp1);
	int i=1;
    for(;i<=n;i++){//�����������������Խ��ԽС
		if(a[i]<=i){//�涨���Ǵ���
			break;
		}
	}
	i--;
    printf("%d", i);
    return 0;
}