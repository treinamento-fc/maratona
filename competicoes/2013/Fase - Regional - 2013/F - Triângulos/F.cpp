#include <iostream>
#include <set>
#include <math.h>
using namespace std;
int main(){
	int n,i,j,k,count; // de 3 a 100000
	double d,x,sum; // de 1*n a 1000*n
	while(cin>>n){
		set<double> pontos;
		
		cin>>x;
		pontos.insert(x);
		sum=x;
		for(i=1;i<n;i++){
			cin>>x;
			sum+=x;
			pontos.insert(sum);
		}
		d = sum/3.0;
		if(ceil(d)!=d){
			cout<<0<<endl;
			continue;
		}
		count=0;
		for(set<double>::iterator it=pontos.begin();it!=pontos.end();it++){
			//cout<<*it<<endl;
			if(pontos.find(*it+d)!=pontos.end()){
				if(pontos.find(*it+2*d)!=pontos.end()){
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
