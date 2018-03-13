#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct Node{
	int id,father,mother,estate,area;
};
struct Family{
	int number;
	int id;
	double avernum,avearea;
};
bool cmp(Family a,Family b){
	if(a.avearea>b.avearea){
		return true;
	}else if(a.avearea==b.avearea){
		return a.id<b.id;
	}else{
		return false;
	}
}
int n=0;
Node nodes[10000];
int father[10000];
bool exist[10000];
bool hasestate[10000];
void intial(){
	for(int i=0;i<10000;i++){
		father[i]=i;
	}
}
int findFather(int x){
	int a=x;
	while(father[x]!=x){
		x=father[x];
	}
	while(a!=father[a]){
		int t=father[a];
		father[a]=x;
		a=t;
	}
	return x;
}
void Union(int x,int y){
	int fx=findFather(x);
	int fy=findFather(y);
	if(fx!=fy)father[fy]=fx;
}
int main(){
	/*
	��Ŀ���⣺����ÿ���˵ļ�ͥ��Ա�����Լ����µķ���������ͳ�Ƴ�ÿ����ͥ���˿������˾�������������������������ڵ�һ�������ͥ����
	��������������ϵ���˶�����ͬһ����ͥ����������и�ʽ���ÿ����ͥ����Ϣ����ͥ��Ա����С��� ��ͥ�˿��� �˾��������� �˾�����
	����������˾�ֵҪ����С�����3λ����ͥ��Ϣ���Ȱ��˾����������������в��У��򰴳�Ա��ŵ����������
	����˼·��
	1������ʹ���ڵ�ΪȺ��id��С�Ľڵ㣬������Union��ʱ�����һЩ�Ƚϲ������ýڵ�id��Ĳ����ڵ�idС������
	2��findFather(i);//�������ÿ��Ԫ�ص���һ��findFather����ʹ����Ԫ����ȷ
	*/
	scanf("%d",&n);
	intial();
	int cnt=0;
	for(int i=0;i<n;i++){
		int id,fa,ma,k;
		scanf("%d%d%d%d",&id,&fa,&ma,&k);
		if(fa!=-1){
			Union(findFather(id),findFather(fa));
			exist[fa]=true;
		}
		if(ma!=-1){
			Union(findFather(id),findFather(ma));
			exist[ma]=true;
		}
		if(k!=0){
			for(int j=0;j<k;j++){
				int tmp;
				scanf("%d",&tmp);
				Union(findFather(id),findFather(tmp));
				exist[tmp]=true;
			}
		}
		int area,estate;
		scanf("%d%d",&estate,&area);
		Node tmp={id,fa,ma,estate,area};
		nodes[tmp.id]=tmp;
		exist[id]=true;
		hasestate[id]=true;
	}
	vector<int>vn(10000);
	map<int,set<int>>m;
	for(int i=0;i<10000;i++){
		if(exist[i]){
			findFather(i);//�����ÿ��Ԫ�ص���һ��findFather����ʹ����Ԫ����ȷ
		}
	}
	for(int i=0;i<10000;i++){
		if(exist[i]){
			m[father[i]].insert(i);
		}
	}
	//Ȼ�����ÿ����ͥ��ƽ�������ƽ��
	printf("%d\n",m.size());
	vector<Family>fm;
	for(auto it=m.begin();it!=m.end();it++){
		Family tmp;
		tmp.id=*(it->second.begin());
		tmp.number=it->second.size();
		double totalnum=0,totalarea=0;
		for(auto iit=it->second.begin();iit!=it->second.end();iit++){
			if(hasestate[*(iit)]==true){
				totalnum+=nodes[*iit].estate;
				totalarea+=nodes[*iit].area;
			}
		}
		tmp.avearea=totalarea/tmp.number;
		tmp.avernum=totalnum/tmp.number;
		fm.push_back(tmp);
	}
	
	sort(fm.begin(),fm.end(),cmp);
	for(int i=0;i<fm.size();i++){
		printf("%04d %d %.3f %.3f\n",fm[i].id,fm[i].number,fm[i].avernum,fm[i].avearea);
	}
	return 0;
}