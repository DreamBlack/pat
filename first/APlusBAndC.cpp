#include<stdio.h>
int main(){
	/*
	��Ŀ���⣺������С�ڴ�СΪ[-2^63, 2^63]�ڵ����ж�ǰ��������Ƿ���ڵ�����
	����˼·��������ж�
	���������������Ե�����ˣ�������if�ж���������a+b>c�����䡣����sum=a+b,if(sum>c)����
	*/
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long sum=a+b;
		if(a>0&&b>0&&sum<0){//��������������
			printf("Case #%d: true\n",i);
		}else if(a<0&&b<0&&sum>=0){//��������������
			printf("Case #%d: false\n",i);
		}else if(sum>c){
			printf("Case #%d: true\n",i);
		}else{
			printf("Case #%d: false\n",i);
		}
		
	}
	return 0;
}