#include<stdio.h>
#include<stack>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
stack<int> s;
multiset<int> mset1,mset2;
void adjust(){
	
	if(mset1.size()>mset2.size()+1){//a����Ԫ�ض࣬�ŵ�b����
		auto eit=mset1.end();
		eit--;
		int tmp=*(eit);
		mset1.erase(eit);//��a���һ��Ԫ��ɾ������b����������Ԫ��
		mset2.insert(tmp);
	}else if(mset1.size()<mset2.size()){//a����Ԫ���٣���b�����һ���ŵ�a����
		auto bit=mset2.begin();//2������С�ģ���һ����Ԫ�طŵ�1����
		int tmp=*(bit);
		mset1.insert(tmp);
		mset2.erase(bit);//erase������ָ���ʾɾ����ǰָ��Ԫ�أ�������key����ʾɾ������key
	}
}
void pushS(int i){
	//push�ȷŵ�stack�У�Ȼ�����ֵ��mset1�����С��ѡ��ŵ�mset2����mset1��
	s.push(i);
	if(mset1.empty()&&mset2.empty()){//���߶���
		mset1.insert(i);
	}else if(mset2.empty()){//1����(��1�����ֻ��1��)2��
		int s1=*(mset1.begin());
		if(i>s1){
			mset2.insert(i);
		}else{
			mset1.insert(i);
			adjust();
		}
	}else{//���߶�����
		auto ita=mset1.end();
		ita--;
		auto itb=mset2.begin();
		if(i<=*(ita)){//Ӧ�÷ŵ�a����
			mset1.insert(i);
		}else{//Ӧ�÷ŵ�b����
			mset2.insert(i);
		}
		adjust();
	}

}
int popS(){
	if(s.empty()){
		return -1;
	}else{
		int r=s.top();
		s.pop();
		auto ita=mset1.end();
		if(mset1.size()==1){
			ita=mset1.begin();
		}else{
			ita--;
		}
		
		if(r<=*(ita)||mset2.empty()){//ɾ��Ԫ����a����
			auto it=mset1.find(r);
			mset1.erase(it);
		}else{//ɾ��Ԫ����b����;
			auto it=mset2.find(r);
			mset2.erase(it);
		}
		adjust();
		return r;
	}
}

int peekMedian(){
	if(s.empty()){
		return -1;
	}else{
		auto it=mset1.end();
		if(mset1.size()==1){
			it=mset1.begin();
		}else{
			it--;
		}
		
		return *(it);
	}
}
int main(){
	/*
	��Ŀ���⣺������ʵ��һ������Ķ�ջ��������һ�ֲ����С�����ֵ���������ض�ջ������Ԫ�ص���ֵ��
	����N��Ԫ�أ���N��ż��������ֵ����Ϊ��N/2����СԪ����N������������ֵ����Ϊ��(N+1)/2����СԪ��
	����˼·��
	1���ҵķ�����ֱ����������ֵ��������ʱ
	2��Ҫע��n��Ԫ���е�i��ĺ������е�i-1��Ԫ�ض�Ӧ�������Ǻ͵�i��Ԫ�ض�Ӧ
	3����ʵ��������ʵ��һ��������ͷ��������������ܷ�����λ�������ݽṹ��������˵���߶���������״����Ŀ�����
	4��������һ�ַ�����ʹ��һ��stackģ��ջ������multiset���ջ�е�����Ԫ�أ���֤a�Ĵ�С��b��1���ߺ�bһ��������Multiset���������������ظ�
	�����a���������Ǹ�Ԫ�ؾ�����λ����ע�����Ҫʵʱ��������Mutltset�Ĵ�С
	*/
	int n;
	scanf("%d",&n);
	string pop="Pop";
	string push="Push";
	string peek="PeekMedian";
	for(int i=0;i<n;i++){
		char ord[10];
		scanf("%s",ord);
		string order(ord);
		if(order.compare(pop)==0){
			int ret=popS();
			if(ret==-1){
				printf("Invalid\n");
			}else{
				printf("%d\n",ret);
			}
		}else if(order.compare(push)==0){
			int c;
			scanf("%d",&c);
			pushS(c);
		}else if(order.compare(peek)==0){
			int ret=peekMedian();
			if(ret==-1){
				printf("Invalid\n");
			}else{
				printf("%d\n",ret);
			}
		}
	}
	return 0;
}