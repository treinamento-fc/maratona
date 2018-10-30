#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Pto {
  long x, y;

  Pto(int X = 0, int Y = 0) {
    x = X;
    y = Y;
  }

  bool operator<(const Pto &p) const {
    return y < p.y;
  }
};

struct Tile {
  set<Pto> esq;
  set<Pto> dir;
  double dx = 0;
  long n;
  Pto ptoAnt;
  bool subindo = true;

  void lePtos() {
    Pto p(0, 0);
    cin >> n;
    long i = 0;
    do {
      ptoAnt = p;
      cin >> p.x >> p.y;
      i++;
    } while (ptoAnt.y == p.y);
    dir.insert(ptoAnt);
    dir.insert(p);
    ptoAnt = p;
    for (; i < n; i++) {
      cin >> p.x >> p.y;
      if (subindo) {
        if (p.y < ptoAnt.y) {
          subindo = false;
          // quando inverte a direção pode ser que o último ponto do lado direito seja o primeiro do lado esquerdo
          esq.insert(ptoAnt);
        }
      }
      // como será sempre convexo, y's iguais não são colocados, evitando pontos que estão alinhados no topo ou na base
      if (ptoAnt.y != p.y) {
        if (subindo) {
          dir.insert(p);
        } else {
          esq.insert(p);
        }
      }
      ptoAnt = p;
      if (!subindo && p.y == 0)
        break;
    }
    if (subindo) {
      esq.insert(p);
    }
    if (p.x != 0) {
      p.x = p.y = 0;
      esq.insert(p);
    }
  }

  void mostra() {
    for (Pto p : esq) {
      cout << "(" << p.x + dx << ", " << p.y << ") " << endl;
    }
    cout << "---------" << endl;
    for (Pto p : dir) {
      cout << "(" << p.x + dx << ", " << p.y << ") " << endl;
    }
    cout << "==========" << endl;
  }
};

int ordem[14];

// Dado y retorna x na reta
double xNaReta(long x1, long y1, long x2, long y2, long y) {
  return x2 - double(x2 - x1) / (y2 - y1) * (y2 - y);
}

// Verifica se x está entre a e b
bool entre(long x, long a, long b) {
  if (a < b)
    return a <= x && x <= b;
  else
    return b <= x && x <= a;
}

// Em cada reta do lado esquerdo do tile, verifica a reta correspondente a y e calcula para y a distância do x até a reta
double comYCalculaX(long y, set<Pto> ptos) {
  auto e = ptos.lower_bound(Pto(0, y));
  if (e == ptos.begin())
    e++; // se for o primeiro, incrementa para decrementar na linha abaixo
  const Pto &p1 = *(e--);
  const Pto &p2 = *e;
  return xNaReta(p1.x, p1.y, p2.x, p2.y, y);
}

// Com os pontos da direita do tile dado por parâmetro, encontra a menor distância do toque com o lado esquerdo deste (*this).tile.
double calculaMenorDistanciaDeCadaPto(Tile t1, Tile t2) {
  double menorDistX = LONG_MAX;
  double distX;
  for (Pto p : t2.dir) {
    distX = comYCalculaX(p.y, t1.esq) - p.x;
//    cout << " e->d distX: " << distX;
    if (distX < menorDistX)
      menorDistX = distX;
  }
//  cout << endl;
  for (Pto p : t1.esq) {
    distX = p.x - comYCalculaX(p.y, t2.dir);
//    cout << " d->e distX: " << distX;
    if (distX < menorDistX)
      menorDistX = distX;
  }
//  cout << endl;
  return menorDistX;
}

void posicionaTiles(Tile tiles[], int ordem[], int n) {
  tiles[ordem[0]].dx = 0;
  for (int i = 1; i < n; i++) {
    double dx = calculaMenorDistanciaDeCadaPto(tiles[ordem[i - 1]],
        tiles[ordem[i]]);
//    cout << " dx: " << dx << " \n";
    tiles[ordem[i]].dx = tiles[ordem[i - 1]].dx + dx;
  }
}

double calculaDimensao(Tile tiles[], int ordem[], int ini, int n) {
  auto &tileMin = tiles[ordem[ini + n - 1]];
  double min = tileMin.esq.begin()->x;
  for (auto &ptoMin : tileMin.esq)
    if (min > ptoMin.x)
      min = ptoMin.x;
  min += tileMin.dx;
  auto &tileMax = tiles[ordem[ini]];
  double max = tileMax.dir.begin()->x;
  for (auto &ptoMax : tileMax.dir)
    if (max < ptoMax.x)
      max = ptoMax.x;
  max += tileMax.dx;
  return max - min;
}

bool ordemEmUso[14];
double menorDim = LONG_MAX;
/** n é o número de tiles
 *  nivel é o nível da recursão
 */
void combina(Tile tiles[], int n, int nivel) {
  if (n == nivel) {
//    for (int i = 0; i < n; i++) {
//      cout << ordem[i] << " ";
//    }
//    cout << endl;
    posicionaTiles(tiles, ordem, n);
    double dim = calculaDimensao(tiles, ordem, 0, n);
    if (dim < menorDim) {
      menorDim = dim;
    }
//    printf("%.3f\n", dim);
  } else {
    for (int i = 0; i < n; i++) {
      if (!ordemEmUso[i]) {
        ordem[nivel] = i;
        ordemEmUso[i] = true;
        combina(tiles, n, nivel + 1);
        ordemEmUso[i] = false;
      }
    }
  }
}

void combina(Tile tiles[], int n) {
  for (int i = 0; i < n; i++) {
    ordem[i] = i;
    ordemEmUso[i] = false;
  }
  combina(tiles, n, 0);
}

int main() {
  long n;
  while (cin >> n) {
    Tile tiles[n];
    for (long i = 0; i < n; i++) {
      Tile t;
      t.lePtos();
      tiles[i] = t;
    }
//    for (long i = 0; i < n; i++) {
//      tiles[ordem[i]].mostra();
//    }
    combina(tiles, n);
    printf("%.3f\n", menorDim);
//    cout << menorDim << " #########" << endl;
  }
  return 0;
}
