#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
bool isIn[1001];
int outSeq[10001];
stack<int> sk;
int main(){
	/*
	题目大意：有个容量限制为m的栈，分别把1，2，3，…，n入栈,给出一个系列出栈顺序，问这些出栈顺序是否可能.
	解题思路：
	这道题在初试的时候手动模拟的，一直没有写成代码的形式。
	感觉自己写代码还是不熟练，虽然过了，但是用时比较长
	*/
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<k;i++){
		while(!sk.empty()){//清空栈
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