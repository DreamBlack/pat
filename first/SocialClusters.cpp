#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int hobby[1001]={0};
int n;
vector<int>father,isroot;
bool cmp(int a,int b){
	return (a>b)?true:false;
}
void intial(){
	for(int i=1;i<=n;i++){
		father[i]=i;//初始时候每个人都组成了一个集合
	}
}
int findFather(int x){
	int a=x;
	while(father[x]!=x){
		x=father[x];//只有树根father[i]才是自己
	}
	//为了加快查找速度，让同一棵树上的结点的父亲都保存为根节点
	//此外每个非根节点保存的都是所在树的根节点，则father相同的节点的个数就是所在树的节点个数
	while(a!=father[a]){
		int z=father[a];
		father[a]=x;
		a=z;
	}
	return x;
}
void uninon(int x,int y){
	int fx=findFather(x);
	int fy=findFather(y);
	if(fx!=fy)father[fx]=fy;
	//父亲结点不同，合并两棵树（注意合并的是树而不仅仅是结点，所以应该放father合并）
}
int main(){
	/*
	题目大意：有n个人，每个人喜欢k个活动，如果两个人有任意一个活动相同，就称为他们处于同一个社交网络。求这n个人一共形成了多少个社交网络。
	解题思路：
	1、刚开始想用Map<int,int>把爱好相同的人放到一起。但是有可能出现a喜欢1,2，b喜欢1,2.用这种方法会让他们产生两个cluster,但其实只有一个
	2、所以应该把人的id作为集合的元素。使用并查集，把爱好相同的人合并
	3、father[i]记录i个人所在树的根节点。初始为i。表示，自己就组成了一棵树；hobby[i]记录喜欢第i个爱好的某个人的id；isroot[i]记录如果i
	是某棵树的根，这棵树上共有多少个结点
	4、每输入某个人i的兴趣j的时候，如果兴趣j还是第一次有人喜欢就记录到数组hobby[j]=i中。之后将i和喜欢爱好j的人所在的树根合并
	5、最后对于每一个人记录，让它所在的树的根节点的isroot++即可
	*/
	scanf("%d",&n);
	father.resize(n+1);
	isroot.resize(n+1);
	intial();
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			int tmp;
			scanf("%d",&tmp);
			if(hobby[tmp]==0){//如果这个爱好之前还没有人喜欢过，就让当前这个人作为它的代表
				hobby[tmp]=i;
			}
			uninon(i,findFather(hobby[tmp]));//如果有了一个新的有共同爱好的人就合并他们所在的两棵树
		}
	}
	//isroot用来记录每个集合的元素个数
	for(int i=1;i<=n;i++){
		isroot[findFather(i)]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(isroot[i]!=0){
			cnt++;
		}
	}
	sort(isroot.begin(),isroot.end(),cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d",isroot[i]);
		if(i!=cnt-1){
			printf(" ");
		}
	}
	return 0;
}