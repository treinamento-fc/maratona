#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x,i,h,maior;
	cin>>n;
	vector<int> alturas(n);
	for(i=0;i<n;i++){
		cin>>alturas[i];
	}
	h=1;
	alturas[0]=1;
	alturas[n-1]=1;
	for(i=1;i<n;i++){
		if(alturas[i]>h){
			h++;
			alturas[i]=h;
		}else{
			h=alturas[i];
		}
	}
	h=1;
	for(i=n-2;i>=0;i--){
		if(alturas[i]>h){
			h++;
			alturas[i]=h;
		}else{
			h=alturas[i];
		}
	}
	maior=0;
	for(i=1;i<n;i++){
		if(alturas[i]>alturas[maior]){
			maior=i;
		}
	}
	cout<<alturas[maior]<<endl;
	return 0;
}
