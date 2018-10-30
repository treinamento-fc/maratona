#include <iostream>
using namespace std;
int main(){
	int n,i,j,k; // de 3 a 100000
	double pontos[100000],d,count; // de 1*n a 1000*n
	while(cin>>n){
		cin>>pontos[0];
		count=0;
		for(i=1;i<n;i++){
			cin>>pontos[i];
			pontos[i] = pontos[i]+pontos[i-1];
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					if(i>=j){
						continue;
					}
					if(j>=k){
						continue;
					}
					d = pontos[j]-pontos[i];
					//cout<<"d i-j ="<<d<<endl;
					if (d==(pontos[k]-pontos[j])){
						//cout<<"d j-k ="<<d<<endl;
						if (d==(pontos[i]+pontos[n-1]-pontos[k])){
							count++;
							//cout<<"i ="<<i<<" j ="<<j<<" k ="<<k<<endl;
						}
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
