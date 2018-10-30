//============================================================================
// Name        : apagando.cpp
// Author      : Jamilly
// Version     :
// Copyright   : 
// Description : ICPC - Regional 2008 - Problema A - Apagando e Ganhando
//============================================================================

#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int main()
{	
	int n, d;
	string num;     
	int apagados, comeco, a;
	
	while(cin>>n>>d && (n || d)) //enquanto estiver digitando
	{	
		vector <char> numf;	
		numf.assign(1,-1); //colocar um valor no vetor para poder comparar depois
		cin>>num; //entrada da string numero
		
		for(a = apagados = comeco = 0; a<n; a++)  
		{		
			while(num[a]>numf[comeco] && comeco > 0 && apagados < d) //se o num atual for maior que o num final e ainda não tiver apagado tudo
			{
				apagados++; comeco--; //apagar mais uma vez e ir para a posição anterior do vetor
				if((int)numf.size() > 0) //se o tamanho do vetor for maior que zero
				numf.pop_back(); //retirar o valor
			}
			
			if(comeco<n-d) //se ainda existem algarismos para colocar
			{
				if((int)numf.size() >= comeco) 
				{
					numf.push_back(num[a]);
					comeco++;
				}
			}
		}
		
		
		copy(numf.begin()+1, numf.end(), ostream_iterator<char>(cout, ""));
		cout<<endl;
	}		
	
	return 0;   
}                
