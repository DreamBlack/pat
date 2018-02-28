#include<stdio.h>
#include<map>
using namespace std;
map<int,int> pix;
int main(){
	/*
	题目大意：选取主色调，就是M列N行的矩阵里面出现次数多余一半的那个数字。
	解题思路：
	由于题目对时间效率要求比较高。因此使用map(自带hash)，用值记录每种颜色出现的次数，同时保存出现次数最多的那次最后输出
	*/
	int m,n;
	scanf("%d%d",&m,&n);
	int max=-1,maxColor=-1;;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int tmp;
			scanf("%d",&tmp);
			pix[tmp]+=1;
			if(pix[tmp]>max){
				max=pix[tmp];
				maxColor=tmp;
			}
		}
	}
	printf("%d",maxColor);
	return 0;
}