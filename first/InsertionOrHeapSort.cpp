#include<stdio.h>
#include<algorithm>
using namespace std;
int num1[101];
int num2[101];
void swap(int&a,int&b){
	int tmp=a;
	a=b;
	b=tmp;
}
void shiftUpToDown(int now,int end){
	if(now*2<=end){
		if(now*2+1>end){//û���Һ���
			if(num2[now]<num2[now*2]){
				swap(num2[now],num2[now*2]);
				shiftUpToDown(now*2,end);
			}
		}else{
			int max,lor;
			if(num2[now*2]<num2[now*2+1]){
				max=num2[now*2+1];
				lor=1;
			}else{
				lor=0;
				max=num2[now*2];
			}
			if(max>num2[now]){
				if(lor==0){
					swap(num2[now],num2[now*2]);
					shiftUpToDown(now*2,end);
				}else{
					swap(num2[now],num2[now*2+1]);
					shiftUpToDown(now*2+1,end);
				}
			}
		}
	}
}
int main(){
	/*
	��Ŀ���⣺����n��n����������a��b��aΪԭʼ���У�bΪ�������е�һ�����裬��b��a�����˶������ǲ�������ģ��������������һ��~~
	����˼·��
	1�����ڲ��������֮ǰ�ǵ���һ����˼
	2�����ڶ�������ʹ�õ����ϴο��ŵķ�������ԭʼ������������û��һ�θ��м����ݶԱȽ����ʱ�ˡ���������˵����ֱ�����м�����
	�Ӻ���ǰ�ҵ���һ����δ�ŵ�λ���ϵ�Ԫ�أ�����ŵ���ͷ����һ�����϶��µ������ɡ�����ʹ�ڽ��ѵ�ʱ�����¶��ϵ�����ʱ��ҲҪ�õ����϶���
	���ܱ�֤�ѵĽṹ��ȷ����֮���Ȼ����ʱ�ˡ�
	3��������һ�����󡣺����������ڴ�����������ʱ��Ӧ�ô�ǰ�����ҵ���һ���Ⱥ���Ԫ�ش��Ǹ�����С�ڵ��ڶ�����ֻдС��
	*/
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",num1+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",num2+i);
	}
	bool insert=true;
	int i=1;
	while(i<=n-1&&num2[i]<=num2[i+1]){
		//����Ӧ����С�ڵ��ڶ�����С��
		i++;
	}
	for(int j=i+1;j<=n;j++){
		if(num1[j]!=num2[j]){
			insert=false;
			break;
		}
	}
	if(insert){
		printf("Insertion Sort\n");
		sort(num2+1,num2+i+2);
		for(int i=1;i<=n;i++){
			printf("%d",num2[i]);
			if(i!=n){
				printf(" ");
			}
		}
	}else{
		printf("Heap Sort\n");
		sort(num1+1,num1+n+1);
		int q=n;
		for(;q>0;q--){
			if(num2[q]!=num1[q]){
				break;
			}
		}
		swap(num2[1],num2[q]);
		shiftUpToDown(1,q-1);
		for(int i=1;i<=n;i++){
			printf("%d",num2[i]);
			if(i!=n){
				printf(" ");
			}
		}
	}

	return 0;
}