#include <iostream>
using namespace std;
int main(){
	int k,n,count=0,aux,i,j,l,c,m[300][300];
	cin>>l>>c;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			cin>>m[i][j];
		}
	}
	
	//insert sort nas linhas
	for(i=0;i<(l-1);i++){//organiza linhas
	//1. achar o valor min
	    n = m[i][0];
	    for(k=i;k<l;k++){
	    	if(m[k][0]<n){
	    		n=m[k][0];
	    		//cout<<"n ="<<n<<endl;
			}
		}
	    for(k=i;k<l;k++){
	    	if(m[k][0]==n){
	    		break;
			}
		}
		if(m[i][0]!=n){
			count++;
			for(j=0;j<c;j++){
				aux=m[i][j];
				m[i][j]=m[k][j];
				m[k][j]=aux;
			}
		}
	}
	/*
	cout<<endl;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	n=1; //insert sort nas colunas
	for(j=0;j<(c-1);j++){
		//em qual coluna está o menor
		for(k=j;k<c;k++){
			if(m[0][k]==n){
				break;
			}
		}
		if(m[0][j]!=n){
			count++;
			for(i=0;i<l;i++){
				aux=m[i][j];
				m[i][j]=m[i][k];
				m[i][k]=aux;
			}
		}
		n++;
	}
	/*
	cout<<endl;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	*/
	n=1;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			if(m[i][j]!=n){
				cout<<"*"<<endl;
				return 0;
			}
			n++;
		}
	}
	cout<<count<<endl;
	return 0;
}
