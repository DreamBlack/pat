#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
bool isIn[1001];
int outSeq[10001];
stack<int> sk;
int main(){
	/*
	��Ŀ���⣺�и���������Ϊm��ջ���ֱ��1��2��3������n��ջ,����һ��ϵ�г�ջ˳������Щ��ջ˳���Ƿ����.
	����˼·��
	������ڳ��Ե�ʱ���ֶ�ģ��ģ�һֱû��д�ɴ������ʽ��
	�о��Լ�д���뻹�ǲ���������Ȼ���ˣ�������ʱ�Ƚϳ�
	*/
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<k;i++){
		while(!sk.empty()){//���ջ
			sk.pop();
		}
		fill(outSeq,outSeq+n+1,false);
		for(int j=1;j<=n;j++){
			scanf("%d",&(outSeq[j]));
		}
		sk.push(0);
		int now=outSeq[1],nowIn=1;
		bool isAc=true;
		int j=1;
		while(j<=n){
			if(now>sk.top()){
				while(nowIn<=now){
					sk.push(nowIn++);
				}
				if(sk.size()>m+1){
					isAc=false;
					break;
				}
			}else if(now==sk.top()){
				sk.pop();
				now=outSeq[++j];
			}else{
				isAc=false;
				break;
			}
		}
		if(isAc){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}