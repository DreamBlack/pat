#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct Person{
	int id;
	int talent;
	int virtue;
	int type;
};
bool cmp(Person a,Person b){
	if(a.type>b.type){
		return true;
	}else if(a.type==b.type){
		if(a.talent+a.virtue>b.talent+b.virtue){
			return true;
		}else if(a.talent+a.virtue==b.talent+b.virtue){
			if(a.virtue>b.virtue){
				return true;
			}else if(a.virtue==b.virtue){
				if(a.id<b.id){
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
			
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main(){
	/*
	��Ŀ���⣺�����1�и���3�����������ֱ�Ϊ��NΪ����������LΪ¼ȡ��ͷ����ߣ����·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��
	HΪ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ������򣻲ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���
	Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮�󣻵²ŷ־�����H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ�����
	�����ڵڶ��࿼��֮�������ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮�������1�����ȸ����ﵽ��ͷ����ߵĿ�������M��
	���M�У�ÿ�а��������ʽ���һλ��������Ϣ��������������˵���Ĺ���Ӹߵ������򡣵�ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У�
	���·�Ҳ���У���׼��֤�ŵ����������
	����˼·���ṹ��������
	Ҫע�������Ŀһ��Ҫ��ϸ������һ��û����foolman�ĵºͲſ�����ͬ���������������Ե�û�����ŵ�16�֡���ֱ̫��
	*/
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	vector<Person> p;
	for(int i=0;i<n;i++){
		Person temp;
		scanf("%d%d%d",&(temp.id),&(temp.virtue),&(temp.talent));
		if(temp.talent>=l&&temp.virtue>=l){
			if(temp.talent>=h&&temp.virtue>=h){//sage
				temp.type=3;
			}else if(temp.talent<h&&temp.virtue>=h){//nobleman
				temp.type=2;
			}else if(temp.talent<h&&temp.virtue<h&&temp.virtue>=temp.talent){//foolman
				temp.type=1;
			}else{
				temp.type=0;
			}
			p.push_back(temp);
		}
	}
	if(p.empty()){
		printf("0");
	}else{
		sort(p.begin(),p.end(),cmp);
		printf("%d\n",p.size());
		for(int i=0;i<p.size();i++){
			printf("%d %d %d",p[i].id,p[i].virtue,p[i].talent);
			if(i!=p.size()-1){
				printf("\n");
			}
		}
	}
	return 0;
}