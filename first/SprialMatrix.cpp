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
	if(cnt>=l)return;//���������䣬��Ȼ�ᳬʱ
	while(y>tb){
		if(matrix[y][x]==0){
			matrix[y--][x]=num[cnt++];
		}
	}
}

int main(){
	/*
	��Ŀ���⣺��n����������������䲢�������
	����˼·�����������ֵĲ��Ե����г�ʱ
	1��������󳤿��ʱ�򣬶��������ᳬʱ
	2���ڵ�����亯�����ڲ���cnt>=l��ʱ��͸��������������������������ܴ󣬸պ�������int�����ֵ���Ѿ�ȫ�������ˣ�����û���˳�,
	��ʱcnt+1,�ֻ�����
	*/
	
	scanf("%d",&l);
	for(int i=0;i<l;i++){
		scanf("%d",num+i);
	}
	sort(num,num+l,cmp);

	an=am=sqrt((double)l);
	while(an>=1&&l%an!=0){//��ʼû��an>=1�ᵼ����ѭ��
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