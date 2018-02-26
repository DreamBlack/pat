#include<stdio.h>
#include<vector>
#include<climits>
using namespace std;
struct Pair{
	int i;
	int j;
};
int diamonds[100001];
vector<Pair> ways;
int main(){
	/*
	��Ŀ����:��һ����������������һ�Σ�ʹ����������Ķ������ֵĺ�ǡ�õ�����������ֵm��
	��������ҵ�ǡ�õ��ڣ��������Լ��������ٵļ۸��ܺͱ�����ڵ�������ֵ�����Ƕ����䡣�����п��ܵĽ����
	����˼·��
	�������˳�������ʱ�䣬����Լ�д�Ĵ�����Ȼû�г�ʱ��������һ��7�ֵĲ��Ե�û������֪��Ϊɶ��
	�о���֪���ǲ��Ǻܾ�ûд�ˣ��Դ������˳������뷨֮����ʵ���������ر��á�ֱ�������˼Ҹ��Լ�ͬ˼·�Ľ��
	�Ű����������߼���������㡣
	1���ҵ�˼·�Ǵӵ�һ������n��Ԫ�أ�ά��һ�����ڣ��Լ����������������������mС����ʹj++����m��ʹi++��
	����m��i++,j++������ͬʱ���´���������

	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int a=1;a<=n;a++){
		scanf("%d",&(diamonds[a]));
	}
	int nowTotal=0,vectorTotal=INT_MAX;
	int i=1,j=0;
	while(j<=n){
		if(nowTotal<m){
			nowTotal+=diamonds[++j];
		}else {
			if(nowTotal<vectorTotal){
				ways.clear();
				Pair p={i,j};
				ways.push_back(p);
				vectorTotal=nowTotal;
			}else if(nowTotal==vectorTotal){
				Pair p={i,j};
				ways.push_back(p);
			}
			if(nowTotal==m){
				nowTotal=nowTotal-diamonds[i]+diamonds[++j];
				i++;
			}else{
				nowTotal=nowTotal-diamonds[i];
				i++;
			}
		}
	}
	for(int i=0;i<ways.size();i++){
		printf("%d-%d",ways[i].i,ways[i].j);
		if(i!=ways.size()-1){
			printf("\n");
		}
	}
	return 0;
}