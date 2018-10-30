#include <bits/stdc++.h>
using namespace std;
void mostra(int a,int b,int c){
	if((a>=b)&&(a>=c)){
		if(b>c){
			cout<<c<<" "<<b<<" "<<a<<endl;
		}else{
			cout<<b<<" "<<c<<" "<<a<<endl;
		}
	}else if((b>=a)&&(b>=c)){
		if(a>c){
			cout<<c<<" "<<a<<" "<<b<<endl;
		}else{
			cout<<a<<" "<<c<<" "<<b<<endl;
		}
	}else{
		if(a>=b){
			cout<<b<<" "<<a<<" "<<c<<endl;
		}else{
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c;
	while(cin>>a>>b>>c){
		//cout<<endl;
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if((a+b+c)==0){
			break;
		}
		//cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
		if((a==b)&&(a==c)){
			if(a==13){
				cout<<"*"<<endl;
			}else{
				mostra(a+1,a+1,a+1);
			}
		}else if(a==b){
			if(a==13){
				if(c==12){
					mostra(1,1,1);
				}else{
					mostra(a,a,c+1);
				}
			}else
			if(c==13){
				mostra(a+1,a+1,1);
			}else{
				if((c+1)==a){
					if((c+1)==13){
						mostra(1,1,1);
					}else{
						mostra(a,b,c+2);
					}
				}else{	
					mostra(a,b,c+1);
				}
			}
		}else if(a==c){
			if(a==13){
				if(b==12){
					mostra(1,1,1);
				}else{
					mostra(a,a,b+1);
				}
			}else
			if(b==13){
				mostra(a+1,a+1,1);
			}else{
				if((b+1)==a){
					if((b+1)==13){
						mostra(1,1,1);
					}else{
						mostra(a,c,b+2);
					}
				}else{
					mostra(a,c,b+1);
				}
			}
		}else if(b==c){
			if(b==13){
				if(a==12){
					mostra(1,1,1);
				}else{
					mostra(b,b,a+1);
				}
			}else
			if(a==13){
				mostra(b+1,b+1,1);
			}else{
				if((a+1)==b){
					if((a+1)==13){
						mostra(1,1,1);
					}else{
						mostra(b,c,a+2);
					}
				}else{
					mostra(b,c,a+1);
				}
			}
		}else{
			mostra(1,2,1);
		}
	}
	return 0;
}
