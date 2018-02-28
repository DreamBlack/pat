#include<stdio.h>
#include<stack>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
stack<int> s;
multiset<int> mset1,mset2;
void adjust(){
	
	if(mset1.size()>mset2.size()+1){//a里面元素多，放到b里面
		auto eit=mset1.end();
		eit--;
		int tmp=*(eit);
		mset1.erase(eit);//把a最后一个元素删除，在b里面加上这个元素
		mset2.insert(tmp);
	}else if(mset1.size()<mset2.size()){//a里面元素少，把b里面第一个放到a里面
		auto bit=mset2.begin();//2里面最小的（第一个）元素放到1里面
		int tmp=*(bit);
		mset1.insert(tmp);
		mset2.erase(bit);//erase参数是指针表示删除当前指向元素，参数是key，表示删除所有key
	}
}
void pushS(int i){
	//push先放到stack中，然后根据值比mset1大或者小，选择放到mset2或者mset1中
	s.push(i);
	if(mset1.empty()&&mset2.empty()){//二者都空
		mset1.insert(i);
	}else if(mset2.empty()){//1不空(且1中最多只有1个)2空
		int s1=*(mset1.begin());
		if(i>s1){
			mset2.insert(i);
		}else{
			mset1.insert(i);
			adjust();
		}
	}else{//二者都不空
		auto ita=mset1.end();
		ita--;
		auto itb=mset2.begin();
		if(i<=*(ita)){//应该放到a里面
			mset1.insert(i);
		}else{//应该放到b里面
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
		
		if(r<=*(ita)||mset2.empty()){//删除元素在a里面
			auto it=mset1.find(r);
			mset1.erase(it);
		}else{//删除元素在b里面;
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
	题目大意：现请你实现一种特殊的堆栈，它多了一种操作叫“查中值”，即返回堆栈中所有元素的中值。
	对于N个元素，若N是偶数，则中值定义为第N/2个最小元；若N是奇数，则中值定义为第(N+1)/2个最小元。
	解题思路：
	1、我的方法，直接排序找中值，三个超时
	2、要注意n个元素中第i大的和数组中第i-1个元素对应，而不是和第i个元素对应
	3、其实这个题就是实现一个可以在头输入输出，并且能返回中位数的数据结构。网上有说用线段树或者树状数组的看不懂
	4、用了另一种方法。使用一个stack模拟栈，两个multiset存放栈中的所有元素，保证a的大小比b大1或者和b一样大。由于Multiset本身有序且允许重复
	，因此a里面最大的那个元素就是中位数。注意的是要实时调整两个Mutltset的大小
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