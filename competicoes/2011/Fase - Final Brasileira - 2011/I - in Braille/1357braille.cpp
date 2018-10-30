#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d,i;
	string x,l1,l2,l3;
	string braille1[]={".*","*.","*.","**","**","*.","**","**","*.",".*"};
	string braille2[]={"**","..","*.","..",".*",".*","*.","**","**","*."};
	string braille3="..";
	char l;
	map<string,int> mapa;
	mapa[".***"]=0;
	mapa["*..."]=1;
	mapa["*.*."]=2;
	mapa["**.."]=3;
	mapa["**.*"]=4;
	mapa["*..*"]=5;
	mapa["***."]=6;
	mapa["****"]=7;
	mapa["*.**"]=8;
	mapa[".**."]=9;
	cin>>d;
	while(d>0){
		cin>>l;
		if(l=='S'){
			cin>>x;
			l1="";
			l2="";
			l3="";
			for(i=0;i<(d-1);i++){
				//cout<<" hi";
				l1.append(braille1[x[i]-'0']+" ");
				//cout<<" hello";
				l2+=braille2[x[i]-'0']+" ";
				//cout<<" bye";
				l3+=".. ";
			}
			l1+=braille1[x[i]-'0'];
			l2+=braille2[x[i]-'0'];
			l3+="..";
			cout<<l1<<endl<<l2<<endl<<l3<<endl;
		}else{
			//cout<<" oi";
			cin.ignore();
			getline(cin,l1);
			//cout<<" hi";
			getline(cin,l2);
			//cout<<" hello";
			getline(cin,l3);
			//cout<<" bye";
			for(i=0;i<d;i++){
				cout<<mapa[l1.substr(i*3,2)+l2.substr(i*3,2)];
			}
			cout<<endl;
		}
		cin>>d;
	}
	return 0;
}
