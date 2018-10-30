#include <bits/stdc++.h>
using namespace std;
int main(){
	int s,b,i,e,d,j;
	vector<int> esq;
	vector<int> dir;
	while(cin>>s>>b){
		if((s+b)==0) //n de soldados  // n de relatorio de baixa
			break;
		esq.clear();
		dir.clear();
		for(i=0;i<s;i++){
			esq.push_back(i-1);
			dir.push_back(i+1);
		}
		dir[s-1]=-1;
		for(i=0;i<b;i++){
			cin>>e>>d;
			e--;d--;
			if(esq[e]!=-1){
				cout<<esq[e]+1<<" ";
			}else{
				cout<<"* ";
			}
			if(dir[d]!=-1){
				cout<<dir[d]+1<<endl;
			}else{
				cout<<"*"<<endl;
			}
			
			if(esq[e]>=0)
			dir[esq[e]]=dir[d];
			
			if(dir[d]>=0)
			esq[dir[d]]=esq[e];
			
			
			
		}
		cout<<"-"<<endl;
	}
	return 0;
}
