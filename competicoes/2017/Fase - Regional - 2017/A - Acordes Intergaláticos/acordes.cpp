#include<iostream>
#include<vector>

using namespace std;

int arvore[262144][9];
int lazy[262144];

//Construindo a segment tree (todas as teclas começam com a nota 1)
void construir(int no, int i, int j){
	lazy[no] = 0;
	//cout << ".";
	if (i == j){
		arvore[no][1] = 1;
		//cout << i;
	}
	else
	{
		int esquerda = 2*no;
		int direita = esquerda + 1;
		int meio = (i + j) / 2;
		
		//cout << "(" << esquerda << "," << direita << "," << meio << "," << i << "," << j << ")";
		
		construir(esquerda,i,meio);
		construir(direita,meio+1,j);
		
		arvore[no][1] = (j-i)+1;
	}
}

//Como somamos o mesmo valor a todas as teclas de dado intervalo, podemos apenas rotacionar
//o valor das frequências
void rotacionar(int v[], int soma){
	int rotAux[9], i;
	soma = 9 - soma;
	for(i = 0; i < 9; i++)
		rotAux[i] = v[(i+soma) % 9];
		
	for (i = 0; i < 9; i++)
		v[i] = rotAux[i];
}

//Atualização tardia, devido a técnica de lazy propagation
void aplicarAtualizacao(int no, int i, int j){
	if (lazy[no] == 0)
		return;
	if (i != j) 
	{
		int esquerda = 2*no;
		int direita = esquerda + 1;
		
		lazy[esquerda] = (lazy[esquerda] + lazy[no]) % 9;
		lazy[direita] = (lazy[direita] + lazy[no]) % 9;
	}
	rotacionar(arvore[no], lazy[no]);
	lazy[no] = 0;
}

//armazena em cont a frequência de cada tecla em um dado intervalo
void contarNotas(int no, int i, int j, int A, int B, int cont[]){
	aplicarAtualizacao(no, i, j);
	if (A <= i && j <= B){
		if (i == A){ 
			for(int i = 0; i < 9; i++)
				cont[i] = arvore[no][i];
		} else {
			for(int i = 0; i < 9; i++)
				cont[i] += arvore[no][i];
		}
	} else {
		int esquerda = 2*no;
		int direita = esquerda + 1;
		int meio = (i + j) / 2;
		
		if (meio >= A)
			contarNotas(esquerda, i, meio, A, B, cont);
		if (meio + 1 <= B)
			contarNotas(direita, meio+1, j, A, B, cont);			
	}
}

//atualiza a frequência das teclas em um dado intervalo
void atualizar(int no, int i, int j, int A, int B, int soma)
{
	aplicarAtualizacao(no, i, j);
	
	if (j < A || i > B)
		return;
		
	if (A <= i && j <= B)
	{
		//cout << "!(" << i << "," << j << ")";
		lazy[no] = soma;
		aplicarAtualizacao(no, i, j);
	} 
	else
	{
		//cout << "(" << i << "," << j << ")";
		int esquerda = 2*no;
		int direita = esquerda + 1;
		int meio = (i + j)/2;
		
		atualizar(esquerda, i, meio, A, B, soma);
		atualizar(direita, meio+1, j, A, B, soma);
		
		for(int k = 0; k < 9; k++)
			arvore[no][k] = arvore[esquerda][k] + arvore[direita][k];
	}
}

int main(){
	int n, q, i, j, A, B, maisFreq;
	int cont[9];
	cin >> n >> q;
	
	construir(1,1,n);
	
	for(j = 0; j < q; j++){
		cin >> A >> B;
		A++; B++;
		contarNotas(1,1,n,A,B,cont);	      //verifica a frequência de cada nota no intervalo A:B
		maisFreq = 0;
		for(i = 0; i < 9; i++)                //verifica qual a nota de maior frequência
			if (cont[i] >= cont[maisFreq])   
				maisFreq = i;
		atualizar(1,1,n,A,B,maisFreq);        //soma o valor da nota de maior frequência em todas as teclas do intervalo
	}
		
	for(i = 1; i <= n; i++){			  	  //exibe a configuração final do piano
		A = B = i;
		contarNotas(1,1,n,A,B,cont);
		maisFreq = 0;
		for(j = 0; j < 9; j++)
			if (cont[j] >= cont[maisFreq])
				maisFreq = j;
		cout << maisFreq << endl;
	}
}
