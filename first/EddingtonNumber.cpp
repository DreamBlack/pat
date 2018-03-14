#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000000];
bool cmp1(int a, int b) {return a > b;}
int main() {
	/*
	题目大意：给出n天的骑车距离，求出爱丁顿数，其实就是求出E，这个E表示E天的骑行距离超过E英里。
	解题思路：
	1、对题目的理解问题。刚开始的理解是n天中有e天在当天骑行的路程比当天的天数序号大，结果有一个测试点错误
	2、其实题目理解错了。题目意思是说求一个最大的e，这个e表示，有e天骑行的距离比e大
	降序排列后，如果第i天骑行距离比i大，则前1-i-1天骑行距离比如也比i大。此时ans更新为i
	*/
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1, cmp1);
	int i=1;
    for(;i<=n;i++){//降序排序后数据总是越来越小
		if(a[i]<=i){//规定了是大于
			break;
		}
	}
	i--;
    printf("%d", i);
    return 0;
}