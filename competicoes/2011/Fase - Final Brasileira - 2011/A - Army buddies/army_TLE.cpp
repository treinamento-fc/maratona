#include <bits/stdc++.h>
using namespace std;
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int s,b,i,e,d,j;
	vector<int> soldiers;
	while(cin>>s>>b){
		if((s+b)==0) //n de soldados  // n de relatorio de baixa
			break;
		soldiers.clear();
		for(i=0;i<s;i++){
			soldiers.push_back(i);
		}
		for(i=0;i<b;i++){
			cin>>e>>d;
			e--;d--;
			for(j=0;j<soldiers.size();j++){
				if(soldiers[j]==e){
					break;
				}
			}
			soldiers.erase(soldiers.begin()+j,soldiers.begin()+j+(d-e)+1);
			if(j==0){
				cout<<"* ";
			}else{
				cout<<soldiers[j-1]+1<<" ";
			}
			if(j==soldiers.size()){
				cout<<"*"<<endl;
			}else{
				cout<<soldiers[j]+1<<endl;
			}
		}
		cout<<"-"<<endl;
	}
	return 0;
}
