 #include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

bool tabela[1000][1000], verificado[1000][1000], visitados[1000], duplicata[1000][1000];

void atualizaDuplicata(int N,int linha){
    for(int i = 1; i < N; ++i){
        if(linha != i && visitados[i] == true){
        	//printf("\nAtualizando linha %d : ", linha);
        	//cout << "colunas: " << i;
            duplicata[linha][i] = true;

        }
    }
}

bool recursao(int i, int j, int N){
    visitados[i] = true;
    if(duplicata[i][j] == true){
        //cout << "Achou: " << " i: " << i << " j: " << j << endl;
        verificado[j][i] = true;
        atualizaDuplicata(N,i);
        return true;
    }
    for(int r = 1; r <= N; ++r){
        if(duplicata[i][r] == true && r != j && visitados[r] == false){
            //cout << "Buscando j: " << " i: " << i << " r: " << r << " j: " << j << endl;
            if(recursao(r,j,N) == true){
            	atualizaDuplicata(N,i);
            	return true;
            }
        }
    }
    return false;
}

void limpaVisitado(int N){
    for(int i = 1; i <= N; ++i)
        visitados[i] = false;
}

int operacao(int N, int M){
    int i, j, V, W, P;

    for(i = 1; i <= N; ++i){
        visitados[i] = false;
        for(j = 1; j <= N; ++j)
            duplicata[i][j] = tabela[i][j] = verificado[i][j] = false;
    }
    for(i = 1; i <= M; ++i){
        cin >> V >> W >> P;
        duplicata[V][W] = tabela[V][W] = true;
        if(P == 2)
            duplicata[W][V] = tabela[W][V] = true;
    }

    for(i = 1; i <= N; ++i){
        for(j = 1; j <= N; ++j){
            if(verificado[j][i] == false){
                limpaVisitado(N);
                if(i != j && tabela[i][j]){
                    //cout << "Entrando: " << " i: " << i << " j: " << j << endl;
                    if (recursao(j, i, N) == false){
                        return 0;
                    }
                    atualizaDuplicata(N,i);
                }
            }
        }
    }

    for(i = 1; i <= N; ++i){
        for(j = 1; j <= N; ++j){
            if(duplicata[i][j] == true){
                for(int k = 1; k <= N; ++k){
                    if(duplicata[j][k] == true && i != k)
                        duplicata[i][k] = true;
                }
            }
        }
    }
/*
    for(i = 1; i <= N; ++i){
    	printf("\n");
        for(j = 1; j <= N; ++j){
        	//cout << duplicata[i][j] << " ";
        }
    }
    */

    for(i = 1; i <= N; ++i){
            for(j = 1; j <= N; ++j){
                if(i != j && duplicata[i][j] == false){
                    return 0;
                }
            }
    }

    return 1;
}

int main() {
    int N, M;
    cin >> N >> M;
    while(N != 0 && M != 0){
        cout << operacao(N, M) << endl;
        cin >> N >> M;
    }
}

