#include<stdio.h>
int father[10001];
int n;
bool exist[10001];
void intial(){
	for(int i=1;i<=10000;i++){
		father[i]=i;
	}
}
int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=father[a];
		father[a]=x;
		a=z;
	}
	return x;
}
void Uninon(int x,int y){
	int fa=findFather(x);
	int fb=findFather(y);
	if(fa!=fb)father[fa]=fb;
}
int main(){
	/*
	��Ŀ���⣺һ�����������Ϊͬһ�����ϵģ����ж��ٿ����Ͷ���ֻ���Լ�������ֻ���ж��Ƿ���ͬһ������~
	����˼·��
	1�����鼯�ϲ���ͬһ�����ϵ���
	2��exist��¼idΪi�����Ƿ����
	*/
	scanf("%d",&n);
	intial();
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		int last;
		for(int j=0;j<k;j++){
			int birdId;
			scanf("%d",&birdId);
			exist[birdId]=true;
			if(j==0){
				last=birdId;
			}else{
				Uninon(birdId,last);
			}
		}
	}
	int birdnum=1;
	while(exist[birdnum]){
		birdnum++;
	}
	birdnum--;
	for(int i=1;i<=birdnum;i++){
		findFather(i);
	}
	int cnt=0;
	for(int i=1;i<=birdnum;i++){
		if(father[i]==i){
			cnt++;
		}
	}
	printf("%d %d\n",cnt,birdnum);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(findFather(a)==findFather(b)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}