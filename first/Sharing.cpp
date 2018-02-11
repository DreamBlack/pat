#include<stdio.h>
struct Node{
	char data;
	int next;
	bool isvisited;
};
Node nodes[100000];
int main(){
	/*
	题目大意：求两个链表的首个共同结点的地址。如果没有，就输出-1
	解题思路：
	1、这个题之前初试的时候遇见过，不过这道题给的链表形式比较奇葩，直接给出了结点地址和下一个结点地址
	2、刚开始的思路是，直接判断有没有某个结点在所有结点的下地址中出现了两次。但是倒数两个测试点一直过不了。
	后来发现其中一个测试点是从表头就开始共有结点的情况。但是最后一个还是过不了
	3、后来发现这题的坑点在于，这两个链表可能有多个分支点（多个结点共用同一个下地址），题目是想让找首个公共的结点，
	所以按2的思路最后一个测试点是过不了的
	4、于是想到先用struct将节点们保存到vector中，然后把两个链表构造出来，最后按常规链表处理，但是最后一个测试点超时了
	5、其实一开始在想在怎么保存结点的时候就想过，如果不能用hash会使得查找结点变得很慢。但是考虑到有的结点可能会出现两次
	不太好用set之类的。但是，其实，出现两次的结点地址只会在下地址中出现，但给出的N个结点地址都是不同的，因此可以用地址
	作为hash结果，就使得查找结点变得非常迅速。然后按第一条链表的顺序访问，同时设置访问标志为true。之后按序访问第二条链表
	遇到的第一个访问标志为true的结点就是了。完美解决了3和4的问题
	*/
	int n,head1,head2;
	scanf("%d%d",&head1,&head2);
	scanf("%d",&n);
	bool isfind=false;
	int head1index,head2index;
	for(int i=0;i<n;i++){
		Node temp;
		int add,next;
		char data;
		scanf("%d %c %d",&add,&data,&next);
		temp.data=data;
		temp.isvisited=false;
		temp.next=next;
		nodes[add] = temp;
	}
	//遍历第一条结点
	int now=head1;

	while(now!=-1){
		nodes[now].isvisited=true;
		now=nodes[now].next;
	}
	//遍历第二条链表
	now=head2;
	while(now!=-1){
		if((nodes[now]).isvisited){
			printf("%05d",now);
			return 0;
		}
		now=nodes[now].next;
	}

	printf("%d",-1);


	return 0;
}