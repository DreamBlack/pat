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
	string id;//应该用string，因为如果是0000001，用Int的话之前的0会被抹掉
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
	题目大意：模拟数字图书馆的查询功能。会给出n本书的信息，以及m个需要查询的命令，数字标号对应相应的命令，
	数字编号后面的字符串是查询的搜索词，要求输出这行命令以及输出满足条件的书的id，如果一个都没有找到，输出Not Found
	解题思路：
	最开始：思路是用一个vector存储所有的书籍，然后对每一个查询调用sort对本次查询的关键字进行二分查找。总计m*排序+m*二分查找
	的时间。虽然使用了二分查找，但其实效率还是不高，比较需要m次排序O(m*nlogn+m*logn)
	网上第一种思路：只对vector进行一次按id的排序，然后进行顺序检索。总计1*排序+m*查找O(nlogn+m*n),还是这种复杂度好一点
	网上第二种思路：struct中不保存keywords，关键词单独用Map存储以提高检索效率
	最终决定采用网上第二种思路，因为不但有第一种思路的想法，而且顺带学习了Map
	此外，此题还有一点需要注意，多个数量不定的关键词排在一行，以空格分隔，怎样将关键词正确输入的问题需要记录。
	做题中的问题：
	1、首先都是一堆输入的问题
	getline(istream&& is, string& str, char delim);从cin中读取字符到str中，直到遇到delim
	scanf()按用户指定的格式从键盘上把数据输入到指定的变量之中
	getchar()接受一个字符
	cin:接受一个字符串，遇“空格”、“TAB”、“回车”都结束或者输入一个数字、会过滤掉不可见字符（如 空格 回车，TAB 等）
	cin遇到空格会结束！！！
	对于题目中这种一行全都是关键字，但不知道有几个，只知道他们按空格隔开，要想分别保存每个关键字可以用两种方法：
	a:使用while(cin >> s)并且判断c = getchar()(用这句读空格或者\n)，c是否等于\n，如果是再退出循环
	b:使用istringstream
	2、第一次提交时最后一个测试点运行超时了.
	后来发现，我使用的key的map，是根据id的不同，将同一个id的key插入到同一个id下，这样查找的时候需要两次循环比较慢
	其实可以根据key的不同，将同一个key的id插入到这个key对于的键值对值中，这样检索的时候利用map的key唯一的特性就快的。
	且如果其值用set，则更使同一个key的id自动排序，更加方便
	*/
	int n;
	string keyword,tmps;
	scanf("%d",&n);
	getchar();//必须有这一句，因为刚刚用的是scanf，并没有读入\n，如果没有这句下面id读的会是空的。用这句把换行符读掉
	string id,title,author,pub;
	for(int i=0;i<n;i++){
		Book temp;
		getline(cin,id,'\n');
		temp.id=id;
		getline(cin,title,'\n');//书名作者等之前可能有空格，不能用cin
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
	//书籍内容输入完毕,按id升序排列
	sort(books.begin(),books.end(),cmp);
	//处理每一行query
	int m;
	scanf("%d",&m);
	int type;//查询类型
	string queryword;//查询关键字
	for(int i=0;i<m;i++){
		scanf("%d: ",&type);
		getline(cin,queryword,'\n');
		printf("%d: ",type);
		cout<<queryword<<endl;//第一次输出
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
			break;//书名
		case 2:
			for(int j=0;j<books.size();j++){
				if((books.at(j).author).compare(queryword)==0){
					cout<<books.at(j).id<<endl;
					isfound=true;
				}
			}break;//作者名
		case 3:
			if(keywords[queryword].size()>0){//n本书中有一本书的关键字是要查询的这个
				for(auto itk=keywords[queryword].begin();itk!=keywords[queryword].end();itk++){
					cout<<*itk<<endl;
					isfound=true;
				}
			}

			break;//关键词
		case 4:
			for(int j=0;j<books.size();j++){
				if((books.at(j).publisher).compare(queryword)==0){
					cout<<books.at(j).id<<endl;
					isfound=true;
				}
			}
			break;//出版社
		case 5:
			for(int j=0;j<books.size();j++){
				if((books.at(j).year).compare(queryword)==0){
					cout<<books.at(j).id<<endl;
					isfound=true;
				}
			}
			break;//年份
		default:break;
		}
		if(isfound==false){
			cout<<"Not Found"<<endl;
		}

	}
	return 0;
}