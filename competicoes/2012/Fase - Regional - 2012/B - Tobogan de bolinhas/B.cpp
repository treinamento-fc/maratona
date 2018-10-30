#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int x[3]; // s�o computados 3 pontos por vez, (x[0],y[0]) , (x[1],y[1]) e (x[2],y[2])
	int y[3]; 
	//x0y0 � o ponto final da aleta acima
	//x1y1 � o ponto inicial da aleta
	//x2y2 � o ponto final da aleta
	int aletas;	// quantas aletas existem no total
	int L;		//distancia entre as hastes horizontais
	int H;		//tamanho das hates
	int i;  	// aleta sendo analisada (analise da aleta '0' � trivial)
	float d;	// distancia de um ponto a um seguimento de reta
	float min;	// menor distacia at� agora
	float m;	// inclina��o da aleta
	bool dir;	//indica se a aleta tem inicio na diretira (true) ou na esquerda (false)
	
	while(1){
		aletas=0;
		cin >> aletas;
		if(!aletas) break;	//criterio de parada
		cin >> L >> H;		
		dir = 0;			//prieira aleta sempre a esquerda
		x[1] = 0;			
		cin >> y[1];	
		cin >> x[2];
		cin >> y[2];
		min = L - x[2];		//menor distacia � a bola passar pelo fim da primeira aleta e a haste a direita
		for(i=1;i<aletas;i++){
			dir = !dir;		//as aletas s�o alternadas entre direita e esquerda
			x[0] = x[2];	//o fim da aleta anterior � um ponto importante para analisar a proxima aleta
			y[0] = y[2];
			cin >> y[1];
			cin >> x[2];
			cin >> y[2];
			
			if(dir){
				if(min > x[2]) min = x[2];
				x[1] = L;
			}
			else{
				if(min > L - x[2]) min = L - x[2];
				x[1] = 0;
			}
		
			m = (y[2]-y[1]) / (float)(x[2]-x[1]); //MEU DEUS OLHA ESSE CAST NAO ESQUECE DISSO PORFAVOR
			
			if( y[0] - y[2] - (x[2] - x[0])/m > 0 )	// inequa��o explicada no fim do c�digo
				d = abs(y[0] - y[2] + m*(x[2] - x[0])) / sqrt(1 + m*m);	///distancia entre ponto e reta
			else
				d = sqrt(pow(y[0] - y[2],2) + pow(x[0]-x[2],2));  //distancia entre os pontos que representam o fim das aletas
			
			if(d<min) min = d;
			
			//cout << dir<<z <<"("<<x[0] <<"," <<y[0] <<") ("<<x[1] <<"," <<y[1] <<") ("<<x[2] <<"," <<y[2] <<") " <<qual<< "d: " << d << " hmm " << L-x[2]<< "  min: "<<min<<endl;// << << << <<	
		}
		printf("%.2f\n",min);
	}
	return 0;
}

/* 
para determinar se � preciso calcular a distancia entre ponto e reta ou entre dois pontos, 
� preciso criar uma reta perpendicular � aleta analisada,
como a inclina��o da aleta � M, a reta perpenducular a ela � -1/M,
tomase como ponto de refencia da nova reta o fim da aleta (x2,y2), chamaremos essa reta de cleber
agora com a equa��o de cleber basta fazer um " f(x0,y0) " com a equa��o de cleber,
caso ele seja maior que zero, 
	significa que o ponto est� a cima de cleber e que
	a menor distancia entre as duas aletas � determinada pela distancia entre ponto e reta
caso contrario
	significa que a menor distancia entre as duas aletas � determinado pelia distancia de dois pontos
*/
