#include<stdio.h>
int evas[201];
int given[10000];
int givenLength[10000];
int d[201][10001];
int n,m,l;
int maxLength=1;
int cnt=0;
int findMax(int k){

	int max=-1,maxindex=-1;;
	for(int j=k;j>=0;j--){
		if(given[j]<=given[k]&&givenLength[j]>max){
			max=givenLength[j];
			maxindex=j;
		}
	}
	return max;
}
int subSequence(){
	//������b(0,j)��Ϊb(1,j+1)
	for(int i=cnt;i>=1;i--){
		given[i]=given[i-1];
	}
	int max=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt;j++){
			if(evas[i]==evas[j]){
				d[i][j]=d[i-1][j-1]+1;
			}else{
				d[i][j]=(d[i-1][j]>d[i][j-1])?(d[i-1][j]):(d[i][j-1]);
			}
			if(max<d[i][j]){
				max=d[i][j];
			}
		}
	}
	return max;
}
int main(){
	/*
	��Ŀ���⣺����m����ɫ��Ϊϲ������ɫ��ͬʱҲ����˳�򣩣�Ȼ�����һ������ΪL����ɫ���У�����Ҫȥ����������еĲ�ϲ������ɫ��
	Ȼ����ʣ�����е�һ�������У�ʹ����������б�ʾ����ɫ˳������Լ�ϲ������ɫ��˳�򣬲�һ��Ҫ����ϲ������ɫ�����֡�
	����˼·������һ���Ͳ�����ͨ�취���Խ���ġ�ֱ���������Ƕ�̬�滮��ʵ���벻���������������
	1�����ڸ�������ɫ�����У������evas��ϲ����������ȫ�����޳���������Ŀ��һ����˳��Ҫ�󣬿��Խ�evasϲ������ɫ���б��
	2�������1֮������ʵ��������������л��߿���������������е����⣨�����в���Ҫ���ţ��Ӵ���Ҫ���ţ�
	3�����Լ�ʵ��������������еĶ�̬�滮������Ҫ�Ǵ�0��given�е�j��Ԫ�����jΪ��β������������У�һ����0~j-1�У���������j֮ǰ������Ϊ
	��β������м�1���˴�Ҫע�⣬���û���ҵ�����֮ǰҪ��ģ�Ӧʹj��������г���Ϊ1��һ��ʼû��д����һ�㣬����һ��3�ֵĵ�û�й���
	4�������3��˼·���õ��˶�̬�滮��˼·���������������ֽ�Ϊ�����⣬��¼��������Ĵ𰸣�����������õ�������Ľ��
	��̬�滮�㷨����η����ƣ������˼��Ҳ�ǽ����������ֽ�����ɸ������⣬����������⣬Ȼ�����Щ������Ľ�õ�ԭ����Ľ�.
	����η���ͬ���ǣ��ʺ����ö�̬�滮�������⣬���ֽ�õ��������������ǻ�������ġ�
	���÷��η������������⣬��ֽ�õ�����������Ŀ̫�࣬��Щ�����ⱻ�ظ������˺ܶ�Ρ�
	��������ܹ������ѽ����������Ĵ𰸣�������Ҫʱ���ҳ�����õĴ𰸣������Ϳ��Ա���������ظ����㣬��ʡʱ�䡣
	���ǿ�����һ��������¼�����ѽ��������Ĵ𰸡����ܸ��������Ժ��Ƿ��õ���ֻҪ������������ͽ�����������С�����Ƕ�̬�滮���Ļ���˼·��
	5������һ���Ƕ�������������еĽⷨ����������a(1~k),b(1-m)���㷨��d[i][j]��ʾ����a[0~i]������b[0~j]������������еĳ��ȡ�
	��i=0��j=0����d[i][j]=0;
	��a[i]=b[j],d[i][j]=d[i-1][j-1]+1����a[i]!=b[j],d[i][j]=max(d[i][j-1],d[i-1][j]);
	����i=0,j=0ʱ������������
	*/
	
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int c;
		scanf("%d",&c);
		evas[c]=i;
	}
	scanf("%d",&l);
	
	for(int i=0;i<l;i++){
		int now;
		scanf("%d",&now);
		if(evas[now]!=0){
			given[cnt++]=evas[now];
		}
	}
	givenLength[0]=1;
	for(int i=1;i<cnt;i++){
		int k=findMax(i);
		if(k!=-1){
			givenLength[i]=k+1;
			if(givenLength[i]>maxLength){
				maxLength=givenLength[i];
			}
		}else{
			givenLength[i]=1;
		}
		
	}
	printf("%d\n",maxLength);
	return 0;
}