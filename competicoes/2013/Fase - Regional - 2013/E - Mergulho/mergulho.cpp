#include <iostream>
using namespace std;
int main(){
	int n,r,i,j,x;
	bool mer[10000];
	while(cin>>n>>r){
		
		for(i=0;i<n;i++){
			mer[i]=false;
		}
		
		for(j=0;j<r;j++){
			cin>>x;
			mer[x-1]=true;
		}
		
		if(n==r){
			cout<<"*"<<endl;
			continue;
		}
		
		
		x=n-r;
		j=0;
		for(i=0;i<n;i++){
			if(!mer[i]){
				j++;
				if(j!=x){
					cout<<i+1<<" ";
				}
				else{
					cout<<i+1<<" "<<endl;
				}
			}
		}
		
	}
	return 0;
}
