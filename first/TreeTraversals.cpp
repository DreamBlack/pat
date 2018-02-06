#include <stdio.h>
int postOrder[30];
int inOrder[30];
int levelOrder[30];
int level[30];
int n;
int c=0;
void levelOrdered(int now,int from1,int end1,int from2,int end2,int l){
	/*
	now:��ǰ����������ĸ�����ں�����������е��±�
	from1,end1:��ǰ��������������н���ں����������������λ��
	from2,end2:��ǰ��������������н���������������������λ��
	l:��ǰ�����ĸ�������ڲ���
	ע���˳��ݹ�����Ϊ��������ֻ��һ�����򣬲�����from<end
	*/
	if(from1>end1||from2>end2){
		return;
	}
	if(from1==end1||from2==end2){
		levelOrder[c]=postOrder[from1];
		level[c++]=l;
		return;
	}
	int index=0;
	//�ҵ������������������λ�ã��Ի�����������������ͬʱ��¼��
	for(int i=from2;i<=end2;i++){
		if(inOrder[i]==postOrder[now]){
			index=i;
			break;
		}
	}
	levelOrder[c]=inOrder[index];
	level[c++]=l;
	levelOrdered(from1+index-from2-1,from1,from1+index-from2-1,from2,index-1,l+1);
	levelOrdered(end1-1,from1+index-from2,end1-1,index+1,end2,l+1);

}
int main(){
	/*
	��Ŀ���⣺����һ�ö������ĺ�������������������������������������С���������ֵ���ǻ�����ȵ���������

	���⣺�����ˡ�ÿ���������⣬����һ���ύ�ͳɹ���
	�Ͱ������������������㷨����Ϊ�˵õ�ÿ��������ڵĲ�κţ��ݹ�ͬʱ����ȴ�����ȥ��
	���������鰴��¼����ȵ�����������ڵݹ��ʱ�������ȴ����������ٴ����������������ܱ�֤��������������������ǰ�棬���α���
	��ʱ����������λ��һ�£�
	*/
	//��ʼ��
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",postOrder+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",inOrder+i);
	}
	//��ʼ����
	levelOrdered(n-1,0,n-1,0,n-1,0);
	int l=0,cnt=0;
	while(cnt<n){
		for(int j=0;j<n;j++){
			if(level[j]==l){
				postOrder[cnt++]=levelOrder[j];
			}
			if(cnt==n){
				break;
			}
		}
		l++;
	}
	for(int i=0;i<n-1;i++){
		printf("%d ",postOrder[i]);
	}
	printf("%d",postOrder[n-1]);
	return 0;
}