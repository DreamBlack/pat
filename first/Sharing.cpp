#include<stdio.h>
struct Node{
	char data;
	int next;
	bool isvisited;
};
Node nodes[100000];
int main(){
	/*
	��Ŀ���⣺������������׸���ͬ���ĵ�ַ�����û�У������-1
	����˼·��
	1�������֮ǰ���Ե�ʱ����������������������������ʽ�Ƚ����⣬ֱ�Ӹ����˽���ַ����һ������ַ
	2���տ�ʼ��˼·�ǣ�ֱ���ж���û��ĳ����������н����µ�ַ�г��������Ρ����ǵ����������Ե�һֱ�����ˡ�
	������������һ�����Ե��Ǵӱ�ͷ�Ϳ�ʼ���н���������������һ�����ǹ�����
	3��������������Ŀӵ����ڣ���������������ж����֧�㣨�����㹲��ͬһ���µ�ַ������Ŀ���������׸������Ľ�㣬
	���԰�2��˼·���һ�����Ե��ǹ����˵�
	4�������뵽����struct���ڵ��Ǳ��浽vector�У�Ȼ��������������������󰴳����������������һ�����Ե㳬ʱ��
	5����ʵһ��ʼ��������ô�������ʱ�����������������hash��ʹ�ò��ҽ���ú��������ǿ��ǵ��еĽ����ܻ��������
	��̫����set֮��ġ����ǣ���ʵ���������εĽ���ַֻ�����µ�ַ�г��֣���������N������ַ���ǲ�ͬ�ģ���˿����õ�ַ
	��Ϊhash�������ʹ�ò��ҽ���÷ǳ�Ѹ�١�Ȼ�󰴵�һ�������˳����ʣ�ͬʱ���÷��ʱ�־Ϊtrue��֮������ʵڶ�������
	�����ĵ�һ�����ʱ�־Ϊtrue�Ľ������ˡ����������3��4������
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
	//������һ�����
	int now=head1;

	while(now!=-1){
		nodes[now].isvisited=true;
		now=nodes[now].next;
	}
	//�����ڶ�������
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