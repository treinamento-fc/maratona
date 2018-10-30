#include <iostream>
#include <map>

using namespace std;



struct Local {
	int tam;
	int pos;

	Local() {
		tam=0;
		pos=0;
	}

	Local(int t, int q) {
		tam = t;
		pos = q;
	}
};

map<int, Local> carros;
map<int, Local>::iterator it;

int i, j, k, C, N, P, Q, saldo, taxa, posicao;
bool cabecarr;
bool linha[10001];  // livre = true, ocupado = false;
char Sit; // C = Entrada ou S = Saida

int procuraespaco (int tamanho, int limite) {
	int x, y, pos;
    bool achou;
	pos = 0;

	//for (x=1; x <=limite; x++) {
	//	cout << linha[x] << " ";
	//}
	//cout << endl;

	x = 1;
    for (x=1; x <= (limite - tamanho +1); x++) {
        achou = true;
    	for (y = x; y < (x+tamanho); y++) {
        	if (!linha[y]) {
        		achou = false;
        		break;
        	}
        }
        if (achou) {
            pos = x;
        	break;
        }
    }
    return pos;
}

int main() {


	while (1) {
		cin >> C >> N;
		// cout << C << " " << N << endl;

        if (cin.eof()) {  // Termina se não há mais dados de entrada
	       break;
	    }
        // Inicia Saldo com comprimento total do estacionamento e taxa = 0
        saldo = C;
        taxa  = 0;
		carros.clear();
        for (i=1;i<=10000; i++) { // Limpa controle de espaço no estacionamento
        	linha[i]= true;
        }

        // Ler as entradas e saidas dos carros
        for (i=0; i < N; i++) {
        	cin >> Sit;
            if (Sit == 'C') { // Entrada de Carro no estacionamento
            	cin >> P >> Q;
            	// cout << P << " " << Q << endl;
            	if (saldo >= Q) { // Tem espaço no estacionamento
            		// Verifica se tem espaço continuo de tamanho Q
                    posicao = procuraespaco(Q, C);
                    // cout << "Posição " << posicao << endl;
            		if (posicao > 0) {
					   // Marca Q espacos ocupados (false)
					   for (k=posicao;k<(posicao+Q); k++) {
						   linha[k] = false;
					   }
					   saldo = saldo - Q;    // Reduz o espaço disponível
					   taxa += 10;    // Cobra taxa de estacionamento

					   // Guarda informação do carro (Placa e Comprimento)
		               it = carros.find(P);
		           	   if (it == carros.end()) {
		                  carros.insert(std::pair<int, Local> (P, Local(Q, posicao)));
		           	   }
            		}
            	}
           } else {
               cin >> P;
               it = carros.find(P);
           	   if (it != carros.end()) {
                  saldo = saldo + it->second.tam;
                  // Libera area em linha
                  for (j=it->second.pos;j<(it->second.pos + it->second.tam); j++) {
                	  linha[j]=true;
                  }
                  // Remove iD do carro do map
                  carros.erase(it);
          	   } else {
          		  cout << "Não achou " << P << endl;
          	   }
            }
        }
        // Mostrar taxa total
        cout << taxa << endl;

	}
	return 0;
}