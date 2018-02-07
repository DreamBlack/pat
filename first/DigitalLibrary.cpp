#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

struct Book{
	string id;//Ӧ����string����Ϊ�����0000001����Int�Ļ�֮ǰ��0�ᱻĨ��
	string title;
	string author;
	string publisher;
	string year;
};
bool cmp(Book a,Book b){
	if((a.id).compare(b.id)<0){
		return true;
	}else{
		return false;
	}
}
map<string,set<string>> keywords;
vector<Book> books;
int main(){
	/*
	��Ŀ���⣺ģ������ͼ��ݵĲ�ѯ���ܡ������n�������Ϣ���Լ�m����Ҫ��ѯ��������ֱ�Ŷ�Ӧ��Ӧ�����
	���ֱ�ź�����ַ����ǲ�ѯ�������ʣ�Ҫ��������������Լ�����������������id�����һ����û���ҵ������Not Found
	����˼·��
	�ʼ��˼·����һ��vector�洢���е��鼮��Ȼ���ÿһ����ѯ����sort�Ա��β�ѯ�Ĺؼ��ֽ��ж��ֲ��ҡ��ܼ�m*����+m*���ֲ���
	��ʱ�䡣��Ȼʹ���˶��ֲ��ң�����ʵЧ�ʻ��ǲ��ߣ��Ƚ���Ҫm������O(m*nlogn+m*logn)
	���ϵ�һ��˼·��ֻ��vector����һ�ΰ�id������Ȼ�����˳��������ܼ�1*����+m*����O(nlogn+m*n),�������ָ��ӶȺ�һ��
	���ϵڶ���˼·��struct�в�����keywords���ؼ��ʵ�����Map�洢����߼���Ч��
	���վ����������ϵڶ���˼·����Ϊ�����е�һ��˼·���뷨������˳��ѧϰ��Map
	���⣬���⻹��һ����Ҫע�⣬������������Ĺؼ�������һ�У��Կո�ָ����������ؼ�����ȷ�����������Ҫ��¼��
	�����е����⣺
	1�����ȶ���һ�����������
	getline(istream&& is, string& str, char delim);��cin�ж�ȡ�ַ���str�У�ֱ������delim
	scanf()���û�ָ���ĸ�ʽ�Ӽ����ϰ��������뵽ָ���ı���֮��
	getchar()����һ���ַ�
	cin:����һ���ַ����������ո񡱡���TAB�������س�����������������һ�����֡�����˵����ɼ��ַ����� �ո� �س���TAB �ȣ�
	cin�����ո�����������
	������Ŀ������һ��ȫ���ǹؼ��֣�����֪���м�����ֻ֪�����ǰ��ո������Ҫ��ֱ𱣴�ÿ���ؼ��ֿ��������ַ�����
	a:ʹ��while(cin >> s)�����ж�c = getchar()(�������ո����\n)��c�Ƿ����\n����������˳�ѭ��
	b:ʹ��istringstream
	2����һ���ύʱ���һ�����Ե����г�ʱ��.
	�������֣���ʹ�õ�key��map���Ǹ���id�Ĳ�ͬ����ͬһ��id��key���뵽ͬһ��id�£��������ҵ�ʱ����Ҫ����ѭ���Ƚ���
	��ʵ���Ը���key�Ĳ�ͬ����ͬһ��key��id���뵽���key���ڵļ�ֵ��ֵ�У�����������ʱ������map��keyΨһ�����ԾͿ�ġ�
	�������ֵ��set�����ʹͬһ��key��id�Զ����򣬸��ӷ���
	*/
	int n;
	string keyword,tmps;
	scanf("%d",&n);
	getchar();//��������һ�䣬��Ϊ�ո��õ���scanf����û�ж���\n�����û���������id���Ļ��ǿյġ������ѻ��з�����
	string id,title,author,pub;
	for(int i=0;i<n;i++){
		Book temp;
		getline(cin,id,'\n');
		temp.id=id;
		getline(cin,title,'\n');//�������ߵ�֮ǰ�����пո񣬲�����cin
		temp.title=title;
		getline(cin,author,'\n');
		temp.author=author;
		getline(cin,keyword,'\n');
		istringstream is(keyword);
		while(is>>tmps){
			(keywords[tmps]).insert(id);
		}

		getline(cin,pub,'\n');
		temp.publisher=pub;
		getline(cin,temp.year,'\n');;
		books.push_back(temp);
	}
	//�鼮�����������,��id��������
	sort(books.begin(),books.end(),cmp);
	//����ÿһ��query
	int m;
	scanf("%d",&m);
	int type;//��ѯ����
	string queryword;//��ѯ�ؼ���
	for(int i=0;i<m;i++){
		scanf("%d: ",&type);
		getline(cin,queryword,'\n');
		printf("%d: ",type);
		cout<<queryword<<endl;//��һ�����
		string nowid;
		bool isfound=false;
		switch(type){
		case 1:
			for(int j=0;j<books.size();j++){
				if((books.at(j).title).compare(queryword)==0){
					cout<<books.at(j).id<<endl;
					isfound=true;
				}
			}
			break;//����
		case 2:
			for(int j=0;j<books.size();j++){
				if((books.at(j).author).compare(queryword)==0){
					cout<<books.at(j).id<<endl;
					isfound=true;
				}
			}break;//������
		case 3:
			if(keywords[queryword].size()>0){//n��������һ����Ĺؼ�����Ҫ��ѯ�����
				for(auto itk=keywords[queryword].begin();itk!=keywords[queryword].end();itk++){
					cout<<*itk<<endl;
					isfound=true;
				}
			}

			break;//�ؼ���
		case 4:
			for(int j=0;j<books.size();j++){
				if((books.at(j).publisher).compare(queryword)==0){
					cout<<books.at(j).id<<endl;
					isfound=true;
				}
			}
			break;//������
		case 5:
			for(int j=0;j<books.size();j++){
				if((books.at(j).year).compare(queryword)==0){
					cout<<books.at(j).id<<endl;
					isfound=true;
				}
			}
			break;//���
		default:break;
		}
		if(isfound==false){
			cout<<"Not Found"<<endl;
		}

	}
	return 0;
}