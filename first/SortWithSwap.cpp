#include<stdio.h>
int num[100000];
int n;
int isSorted(int index){
	for(int i=index;i<n;i++){
		if(num[i]!=i){
			return i;
		}
	}
	return n;
}
int main(){
	/*
	��Ŀ���⣺����һ��n���������У�����Ϊ0~n-1������ÿ�������������ķ�ʽ����ֻ����0����һ����������ʹ���б������ģ���������Ҫ���ٲ��衣
	����˼·:
	1��Ӧ����0����ȷ��Ԫ�ػ����Լ���λ�ã����翪ʼ0��8λ�ã����8����������ԭ��8��λ�û���0����������ظ��Ϳ����Ԫ�صĹ�λ��
	��Ҫע����ǣ���;���ܳ���0������0λ�����������0��3��λ����3ǡ����0��λ����0����0λ�ã���������δ��������ʱ��Ӧ����0�������һ������
	λ��Ԫ�ؽ�����Ȼ���������Ĺ��̡�
	2��ʹ�÷���1֮�����������Ե㳬ʱ����Ϊÿ�ν���0,8��ʱ����Ҫ֪��0,8����������������λ��ҪO(N)��Ϊ�����Ч�ʣ������ڴ洢���ݵ�ʱ���ʹ��hash
	�ķ�ʽ����i��λ�ô����i��ǰ�������е��±꣬����ʵ��O(1)
	3��ʹ��2�ķ���֮�󣬽������߼�Ҫ��������罻��0,8ʵ���Ͼ��ǰ�num[0]��num[8]��λ�ý�������Ҫ��Ϳ�ˡ�
	4���������������ݵ�ʱ���¼�ж��ٸ�λ�ò��Ե�Ԫ�أ�ÿ�ΰ���һ��Ԫ�ص�λ��֮��ͽ�cnt--��cnt==0ʱ���˳�
	5����Σ���Ѱ�Һ�0�����һ��λ�ô����Ԫ��ʱ�򣬿�����index��¼0����Ŀǰ��index��Ԫ��û���źã�(index֮ǰ�Ķ����źõ�)��һÿ�δ�Index��ʼ����
	�����Ч��
	*/
	scanf("%d",&n);
	int unsorted=0;;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		num[t]=i;
		if(num[t]!=t){
			unsorted++;
		}
	}
	int funSorted,cnt=0,index=1;
	while(unsorted!=0){
		if(num[0]==0){
			funSorted=isSorted(index);
			index=funSorted;
			if(funSorted==n){
				break;
			}
			int tmp=num[funSorted];
			num[funSorted]=0;
			num[0]=tmp;
		}else{
			int tmp=num[num[0]];
			num[num[0]]=num[0];
			num[0]=tmp;
			unsorted--;
		}
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}