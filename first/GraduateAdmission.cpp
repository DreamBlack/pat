#include<stdio.h>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> schools[100];
int quota[100];
struct Student{
	int ge,gi,rank;
	double gfinal;
	vector<int>prefers;
	int id;
};
vector<Student> stds(40000);
bool cmp(Student a,Student b){
	if(a.gfinal>b.gfinal){
		return true;
	}else if(a.gfinal==b.gfinal){
		if(a.ge>b.ge){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main(){
	/*
	��Ŀ���⣺ÿ�������������ɼ���GE��GI�����ճɼ�Ϊ(GE + GI) / 2;�������ճɼ�������������ճɼ���ͬ���Ͱ���GE�����������Ȼ��ͬ�����ǵ�����������ͬ�ġ�
	ÿ����������K��ѡ��ԺУ��ÿ��ѧУҲ�������������ơ�
	���������Ⱥ������ǰ�����ĵ�һ��־ԸѧУ�����û������¼ȡ��ȥ�������ǰ־Ը�������˵��Ǹ�У���һ��¼ȡ���˵������͵�ǰ������ͬ��
	�򲻹������������ƣ�����Ӧ�ñ�¼ȡ�������Ǹ�������һ��־Ը���������־Ը��û���ܱ�¼ȡ����������
	����˼·��
	1������student�ṹ�壬�洢ѧ����id����ֹ�����id������˳�򣩣�GE��GI�ĳɼ��������ɼ���������־ԸѧУ���б����顣
	2����stds�����������֮�����������飬Ϊÿ��ѧ������־Ը������ǰѧ����֮ǰ��ѧ�����ճɼ���ͬ��ge��ͬ��־ԸѧУ��֮ǰ�Ǹ�ѧ����־ԸѧУ��ͬʱ
	��ʹ־ԸѧУ��������ҲΪ����䡣
	3��һ����������ģ�
	*/
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",quota+i);
	}
	for(int i=0;i<n;i++){
		Student tmp;
		scanf("%d%d",&(tmp.ge),&(tmp.gi));
		for(int j=0;j<k;j++){
			int t;
			scanf("%d",&t);
			tmp.prefers.push_back(t);
		}
		tmp.gfinal=(double)(tmp.ge+tmp.gi)/2;
		tmp.id=i;
		stds[i]=tmp;
	}
	//��������
	sort(stds.begin(),stds.begin()+n,cmp);
	int rank=0,lastsch=-1,lasfinal=INT_MAX,nowsch=0,nofg=0,lastge=INT_MAX;
	for(int i=0;i<n;i++){
		bool iskuozhao=false;
		if(stds[i].gfinal<lasfinal){
			rank++;
			lasfinal=stds[i].gfinal;
			lastge=stds[i].ge;
		}else if(stds[i].gfinal==lasfinal){
			if(stds[i].ge<lastge){
				rank++;
				lastge=stds[i].ge;
			}else if(stds[i].gfinal==lasfinal){
				//������ͬ��־Ը¼ȡ
				iskuozhao=true;
			}//�����������ճɼ���ͬ������±���һ���˵�ge��
		}//�����ܱ���һ���˵ĳɼ���
		//��־Ը¼ȡ���ҵ���һ��û������־Ը
		nowsch=-1;
		if(!iskuozhao){
			//����Ҫ��������
			for(int j=0;j<k;j++){
				if(quota[stds[i].prefers[j]]>0){
					nowsch=stds[i].prefers[j];
					break;
				}
			}
		}else{
			for(int j=0;j<k;j++){
				if(stds[i].prefers[j]==lastsch){
					nowsch=stds[i].prefers[j];
					break;
				}
				if(quota[stds[i].prefers[j]]>0){
					nowsch=stds[i].prefers[j];
					break;
				}
			}
			
		}
		if(nowsch!=-1){
			schools[nowsch].push_back(stds[i].id);
			quota[nowsch]=(quota[nowsch]>0)?quota[nowsch]-1:0;
			lastsch=nowsch;
		}else{//
		}
	}
	for(int i=0;i<m;i++){
		if(schools[i].empty()){
			printf("\n");
		}else{
			sort(schools[i].begin(),schools[i].end());
			for(int j=0;j<schools[i].size();j++){
				printf("%d",schools[i][j]);
				if(j!=schools[i].size()-1){
					printf(" ");
				}
			}
			if(i!=m-1){
				printf("\n");
			}
		}
		
	}
	return 0;
}