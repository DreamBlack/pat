#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int hobby[1001]={0};
int n;
vector<int>father,isroot;
bool cmp(int a,int b){
	return (a>b)?true:false;
}
void intial(){
	for(int i=1;i<=n;i++){
		father[i]=i;//��ʼʱ��ÿ���˶������һ������
	}
}
int findFather(int x){
	int a=x;
	while(father[x]!=x){
		x=father[x];//ֻ������father[i]�����Լ�
	}
	//Ϊ�˼ӿ�����ٶȣ���ͬһ�����ϵĽ��ĸ��׶�����Ϊ���ڵ�
	//����ÿ���Ǹ��ڵ㱣��Ķ����������ĸ��ڵ㣬��father��ͬ�Ľڵ�ĸ��������������Ľڵ����
	while(a!=father[a]){
		int z=father[a];
		father[a]=x;
		a=z;
	}
	return x;
}
void uninon(int x,int y){
	int fx=findFather(x);
	int fy=findFather(y);
	if(fx!=fy)father[fx]=fy;
	//���׽�㲻ͬ���ϲ���������ע��ϲ����������������ǽ�㣬����Ӧ�÷�father�ϲ���
}
int main(){
	/*
	��Ŀ���⣺��n���ˣ�ÿ����ϲ��k��������������������һ�����ͬ���ͳ�Ϊ���Ǵ���ͬһ���罻���硣����n����һ���γ��˶��ٸ��罻���硣
	����˼·��
	1���տ�ʼ����Map<int,int>�Ѱ�����ͬ���˷ŵ�һ�𡣵����п��ܳ���aϲ��1,2��bϲ��1,2.�����ַ����������ǲ�������cluster,����ʵֻ��һ��
	2������Ӧ�ð��˵�id��Ϊ���ϵ�Ԫ�ء�ʹ�ò��鼯���Ѱ�����ͬ���˺ϲ�
	3��father[i]��¼i�����������ĸ��ڵ㡣��ʼΪi����ʾ���Լ��������һ������hobby[i]��¼ϲ����i�����õ�ĳ���˵�id��isroot[i]��¼���i
	��ĳ�����ĸ���������Ϲ��ж��ٸ����
	4��ÿ����ĳ����i����Ȥj��ʱ�������Ȥj���ǵ�һ������ϲ���ͼ�¼������hobby[j]=i�С�֮��i��ϲ������j�������ڵ������ϲ�
	5��������ÿһ���˼�¼���������ڵ����ĸ��ڵ��isroot++����
	*/
	scanf("%d",&n);
	father.resize(n+1);
	isroot.resize(n+1);
	intial();
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			int tmp;
			scanf("%d",&tmp);
			if(hobby[tmp]==0){//����������֮ǰ��û����ϲ���������õ�ǰ�������Ϊ���Ĵ���
				hobby[tmp]=i;
			}
			uninon(i,findFather(hobby[tmp]));//�������һ���µ��й�ͬ���õ��˾ͺϲ��������ڵ�������
		}
	}
	//isroot������¼ÿ�����ϵ�Ԫ�ظ���
	for(int i=1;i<=n;i++){
		isroot[findFather(i)]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(isroot[i]!=0){
			cnt++;
		}
	}
	sort(isroot.begin(),isroot.end(),cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d",isroot[i]);
		if(i!=cnt-1){
			printf(" ");
		}
	}
	return 0;
}