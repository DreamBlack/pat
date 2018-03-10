#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int num[100000];
vector<vector<int>> matrix(100);
int cnt=0;
int an,am;
int l;
bool cmp(int a,int b){
	return (a>b)?true:false;
}
void fun(int x,int y,int n,int m){
	if(x>n||y>m)return;
	int ta=x,tb=y;
	while(x<=n){
		if(matrix[y][x]==0){
			matrix[y][x++]=num[cnt++];
		}
	}
	x--;
	y++;
	while(y<=m){
		if(matrix[y][x]==0){
			matrix[y++][x]=num[cnt++];
		}
	}
	y--;
	x--;
	while(x>=ta){
		if(matrix[y][x]==0){
			matrix[y][x--]=num[cnt++];
		}
	}
	x++;
	y--;
	if(cnt>=l)return;//必须加上这句，不然会超时
	while(y>tb){
		if(matrix[y][x]==0){
			matrix[y--][x]=num[cnt++];
		}
	}
}

int main(){
	/*
	题目大意：给n个数，螺旋矩阵填充并输出矩阵
	解题思路：有两个两分的测试点运行超时
	1、计算矩阵长宽的时候，对于质数会超时
	2、在调用填充函数的内部，cnt>=l的时候就该立即输出，否则如果数据总量很大，刚好是整数int的最大值，已经全部填充好了，但是没有退出,
	此时cnt+1,又回来了
	*/
	
	scanf("%d",&l);
	for(int i=0;i<l;i++){
		scanf("%d",num+i);
	}
	sort(num,num+l,cmp);

	an=am=sqrt((double)l);
	while(an>=1&&l%an!=0){//开始没有an>=1会导致死循环
		an--;
	}
	am=l/an;
	matrix.resize(am);
	for(int i=0;i<am;i++){
		matrix[i].resize(an);
	}
	int x=0,y=0,m=am,n=an;
	if(an==1){
		for(int i=0;i<l;i++){
			printf("%d",num[i]);
			if(i!=l-1){
				printf("\n");
			}
		}
	}else{
		an--,am--;
		while(cnt<l&&an>=x&&am>=y){
			fun(x,y,an,am);
			an--;
			am--;
			x++,y++;
		}

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				printf("%d",matrix[i][j]);
				if(j!=n-1){
					printf(" ");
				}
			}
			if(i!=m-1){
				printf("\n");
			}
		}
	}
	return 0;
}