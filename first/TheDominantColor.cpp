#include<stdio.h>
#include<map>
using namespace std;
map<int,int> pix;
int main(){
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