#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string bigNumAdd(string s1,string s2){
	//�н�λ����true,���򷵻�false
	int cnt=0,res=0;
	string ret=s1;
	int l1=s1.size()-1,l2=s2.size()-1;
	for(int i=l1;i>=0;i--){
		ret[i]=s1[i]+s2[i]+cnt-'0';//intת��Ϊcharʱ��ֻ�ǰ�int��ֵ���Ϊһ��asii�룬����ֻҪ��һ����0������
		if(ret[i]>'9'){//����9
			cnt=1;
			ret[i]=ret[i]-10;//һ������10������ȥ10���൱��%10������
		}else{
			cnt=0;
		}
	}
	if(cnt==1){
		ret.insert(0,"1");
	}
	return ret;
}

int main(){
	/*
	��Ŀ���⣺����һ�����֣�������ת����ӵĴ���cnt����Ҫ���ٴβ��ܱ��һ���������֣�
	����Ǹ��������ֺͷ�ת����˶��ٴΣ����������ǻ������־����0�Σ�������������Ĵ���cnt�ˣ�
	������Ǹ����ǻ��ĵĽ����������������Ĵ���cnt
	����˼·��
	1�������Ǿ���Int��������������Long long�������ύ���ֻ������������������ˡ�ԭ����Longlong���ǲ����������
	�����num���Ϊ10000000000,����k��100����
	2������ֻ�ø�Ϊint���鴦��
	3�������int��ʱ���ύ��ţ���ǶԵģ��ύ��PAT�ľͷ����˶δ��󡣡���֪��������ˡ�
	�ðɣ�ֱ�Ӹ���string�ɣ��Ƚ�string�Դ�reverse
	�ܽ᣺�������ܴ�û���û������ͱ�ʾ��ʱ�򣬾���ֱ����string��ʾ������
	*/
	string s;
	cin>>s;
	int k;
	scanf("%d",&k);
	int step=0;
	bool ispal=false;
	string rev=s;
	while(step<k){
		rev=s;
		reverse(rev.begin(),rev.end());
		if(s.compare(rev)==0){
			break;
		}else{
			step++;
			s=bigNumAdd(s,rev);
			
		}
	}
	
	
	cout<<s<<endl;
	printf("%d",step);
	return 0;

}