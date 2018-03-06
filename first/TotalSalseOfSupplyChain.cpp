#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	int type;
	int id;
	double price;
	double amount;
	vector<int> buyer;
};
bool visited[100000];
int n;
double p,r;
vector<Node> nodes(100000);
double bfs(int now){
	double sales=0;
	queue<Node> q;
	visited[now]=true;
	q.push(nodes[now]);
	Node null;
	null.type=-1;
	q.push(null);
	double np=p;
	Node newnow;
	while(!q.empty()){
		newnow=q.front();
		q.pop();
		if(newnow.type!=-1){
			newnow.price=np;
			if(newnow.type==2){
				sales+=newnow.amount*newnow.price;
			}else{
				for(int i=0;i<newnow.buyer.size();i++){
					if(!visited[(newnow.buyer[i])]){
						q.push(nodes[newnow.buyer[i]]);
						visited[(newnow.buyer[i])]=true;
					}
				}
			}

		}else{
			np=np+np*r/100;
			if(!q.empty()){
				q.push(null);
			}
			
		}
	}
	return sales;
}
int main(){
	/*
	��Ŀ���⣺��һ������������������ļ۸�Ϊp��Ȼ��Ӹ���㿪ʼÿ������һ�㣬�ò�Ļ���۸񽫻��ڸ��׽��ļ۸�������r%��
	����ÿ��Ҷ���Ļ������������ǵļ۸�֮��
	����˼·��
	bfs��ÿ���µ�һ����¼۸񡣵�Ҷ�Ӽ��������۶һ�ι�
	*/
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		Node tmp;
		int t;
		scanf("%d",&t);
		if(t==0){
			tmp.type=2;
			scanf("%d",&t);
			tmp.amount=t;
		}else{
			tmp.type=1;
			for(int j=0;j<t;j++){
				int c;
				scanf("%d",&c);
				tmp.buyer.push_back(c);
			}
		}
		if(i==0){
			tmp.price=p;
		}
		tmp.id=i;
		nodes[i]=tmp;
	}
	double sales=bfs(0);
	printf("%.1f",sales);
	return 0;
}
