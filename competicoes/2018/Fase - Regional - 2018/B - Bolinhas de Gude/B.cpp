

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char **argv)
{
	int n,m,i;
	char l;
	int total;
	vector<int> esquerda(60);
	vector<int> direita(60);
	while(cin>>n){
		for(i=0;i<=60;i++){
			esquerda[i]=0;
			direita[i]=0;
		}
		total=0; 
		for(i=0;i<n;i++){
			cin>>m>>l;
			if(l =='D'){
				direita[m]=direita[m]+1;
			}else{
				esquerda[m]=esquerda[m]+1;
				
			}
			
		}
		for(i=30;i<=60;i++){
			if(direita[i]>=esquerda[i]){
				
				total+=esquerda[i];
			}else{
				
				total+=direita[i];
			}
		}
		cout << total << endl;
	}
	
	return 0;
}

