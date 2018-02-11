#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Station{
	double uprice;
	double distance;
};
bool cmp(Station a,Station b){
	return (a.distance<b.distance)?true:false;
}
vector<Station> stns;
int main(){
	/*
	��Ŀ���⣺��S��Dһ·��N������վ���ͼ۸��죩��������ʡǮ�ļ��Ͳ���
	����˼·��
	��������Ե�̰���㷨������������治�ᡣ����һ�����ϵķ���������˳�����
	̰��������Ϊ�˴ﵽ�����ٵ�Ǯ�����յ��������Զ�����Ŀ�ģ����Ǻ��������ȥ����������⣬ͨ��̰���㷨��
	���԰��������⻯Ϊ�ֲ����⣬ֻվ�ڵ�ǰ�ĽǶȷ�����̰�������ţ��ľ��񣬴Ӷ��õ���������Ž⣬
	̰�����������֮�����ڶ�����ķ�����������࣬һ��������ǵĲ�����ȫ���Ϳ������̽��䡣
	�㷨����ÿһ��nowStn����ѡ�������ʵ��Ǹ���
	1����nowStn��ʼ(��ʼΪ������0��������Ͳ�Ȼ�߲��ˣ������Լ��ɴ�ļ���վ�ǣ�
		a.�б��Լ����˵ļ���վ����ֻ�����ߵ��Ǹ����Լ�����ұ��Լ����˵ļ���վ�����������ֱ��˵ľ����ڹ�ĵط��ټӣ�
		b.û�б��Լ����˵ļ���վ���Ͻ�ԭ�ؼ�����Ȼ��ѡ����Щ�ɴ����վ��������Ǹ�
		c.�ɴ����վ�����յ㣬ֱ�Ӽӿɵ��յ������
	2������������ô�߶��޷��ﵽ�յ��������ܷ����ڣ���nowStn��ʼ��û�пɴ�վ����ʹ��������Ҳ�����������վ��
	���⣺
	1�����ڿ�����ĳ����������֮���ߵ���һ��վ��ʱ��û�����꣬����Ҫ��¼û��һ��վ��leftGas��ʣ����������
	֮����͵�ʱ��Ҫ��ʣ����������ǽ�ȥ
	2���ύ֮����һ�����Ե�����ˡ���Ϊ���������û�м���վ�������
	*/
	double cmax,ddis,price;
	int n;
	scanf("%lf%lf%lf%d",&cmax,&ddis,&price,&n);
	for(int i=1;i<=n;i++){
		Station tmp;
		scanf("%lf%lf",&(tmp.uprice),&(tmp.distance));
		stns.push_back(tmp);
	}
	sort(stns.begin(),stns.end(),cmp);
	Station t={0,ddis};
	stns.push_back(t);
	if(stns[0].distance>0){
		printf("The maximum travel distance = %0.2f\n",0);
		return 0;
	}
	double totalPrice=0,leftGas=0,totalDis=0;;
	int nowGas=0;
	double maxdis=cmax*price;
	while(nowGas<stns.size()-1){
		int nexGas=-1;
		int i=nowGas+1;
		for(;i<stns.size();i++){
			if(stns[i].distance-stns[nowGas].distance>maxdis){
				break;
			}
			if(stns[i].uprice<stns[nowGas].uprice){
				nexGas=i;
				break;
			}
		}
		if(nexGas==stns.size()-1){//�ܵ��յ�

			totalPrice+=(stns[nowGas].uprice)*((stns[nexGas].distance-stns[nowGas].distance)/price-leftGas);
			totalDis=stns[nexGas].distance;
			break;

		}else if(nexGas!=-1){//�ɴﷶΧ����һ���۸���͵ľ�ȥ�������
			totalPrice+=(stns[nowGas].uprice)*((stns[nexGas].distance-stns[nowGas].distance)/price-leftGas);
			totalDis=stns[nexGas].distance;

			leftGas=0;
			nowGas=nexGas;
			totalDis=stns[nowGas].distance;
		}else{//�ɴﷶΧ��û�б��Լ��͵ģ��Ͻ�������Ȼ��ȥ�ɴﷶΧ����Լ۸���͵�վ

			totalPrice+=(cmax-leftGas)*stns[nowGas].uprice;
			if(stns[nowGas+1].distance-stns[nowGas].distance>maxdis){
				//�ɴﷶΧû�б��Լ��͵�,���Ҽ�ʹ���ڼ�����Ҳ��������һ��վ
				totalDis+=cmax*price;
				break;
			}

			int minGastn=nowGas+1;
			for(int j=nowGas+2;j<i;j++){
				if(stns[j].uprice<stns[minGastn].uprice){
					minGastn=j;
				}
			}
			leftGas=cmax-(stns[minGastn].distance-stns[nowGas].distance)/price;
			nowGas=minGastn;
			totalDis=stns[nowGas].distance;
		}
	}
	if(totalDis<ddis){
		printf("The maximum travel distance = %0.2f\n",totalDis);
	}else{
		printf("%0.2f",totalPrice);
	}
	return 0;
}