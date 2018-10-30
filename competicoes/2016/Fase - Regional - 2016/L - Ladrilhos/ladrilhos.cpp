#include<iostream>
#include<queue>

using namespace std;

struct ladrilho{
	int cor;
	int x, y;
	bool controle;
	
	ladrilho(int cor, int x, int y){
		this->cor = cor;
		this->x = x;
		this->y = y;
		controle = true;
	}
};

int main(){
	int H, L, i, j, cor, menor = -1, area, x, y;
	queue<ladrilho> fila;
	ladrilho* mosaico[200][200];
	cin >> H >> L;
	for (i = 0; i < H; i++){
		for (j = 0; j < L; j++){
			cin >> cor;
			mosaico[i][j] = new ladrilho(cor,i,j);
		}
	}
	
	for(i = 0; i < H; i++){
		for (j = 0; j < L; j++){
			if (mosaico[i][j]->controle){
				mosaico[i][j]->controle = false;
				fila.push(*mosaico[i][j]);
				area = 0;
				while(!fila.empty()){
					area++;
					x = fila.front().x;
					y = fila.front().y;
					cor = fila.front().cor;
					fila.pop();
					if ((x - 1) >= 0 && mosaico[x-1][y]->controle && mosaico[x-1][y]->cor == cor){
						mosaico[x-1][y]->controle = false;
						fila.push(*mosaico[x-1][y]);
					}
					if ((y + 1) < L && mosaico[x][y+1]->controle && mosaico[x][y+1]->cor == cor){
						mosaico[x][y+1]->controle = false;
						fila.push(*mosaico[x][y+1]);
					}
					if ((x + 1) < H && mosaico[x+1][y]->controle && mosaico[x+1][y]->cor == cor){
						mosaico[x+1][y]->controle = false;
						fila.push(*mosaico[x+1][y]);
					}
					if ((y - 1) >= 0 && mosaico[x][y-1]->controle && mosaico[x][y-1]->cor == cor){
						mosaico[x][y-1]->controle = false;
						fila.push(*mosaico[x][y-1]);
					}
				}
				if (area < menor || menor == -1)
					menor = area;
			}
		}
	}
	cout << menor << endl;
	return 0;
}
