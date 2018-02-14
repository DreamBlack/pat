#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
vector<string> temp(55);
vector<string> cards(55);
vector<int> order(55);
char hua[4]={'S','H','C','D'};
int main(){
	/*
	题目大意：给一个洗牌的规则，洗n次牌
	解题思路：
	很简单。
	*/

	int k;
	scanf("%d",&k);
	for(int i=1;i<55;i++){
		scanf("%d",&(order[i]));
	}
	int cnt=1;
	for(int i=0;i<4;i++){
		char c=hua[i];
		for(int j=1;j<14;j++){

			if(j>9){
				cards[cnt]="   ";
				cards[cnt][0]=c;
				cards[cnt][1]=j/10+'0';
				cards[cnt][2]=j%10+'0';
			}else{
				cards[cnt]="  ";
				cards[cnt][0]=c;
				cards[cnt][1]=j+'0';
			}
			cnt++;
		}
	}
	cards[cnt++]="J1";
	cards[cnt++]="J2";
	for(int i=0;i<k;i++){
		for(int j=1;j<55;j++){
			temp[order[j]]=cards[j];
		}
		cards=temp;
	}
	for(int j=1;j<55;j++){
		cout<<cards[j];
		if(j!=54){cout<<" ";}
	}
	return 0;
}