#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool verificaTroca(set<int> & cartasDestino, int c) {
  return cartasDestino.find(c) == cartasDestino.end();
}

void mostra(set<int> & cartas) {
  for (int c : cartas) {
    cout << c << " ";
  }
  cout << endl;
}

int main() {
  int a, b, aux;
  while (cin >> a >> b) {
    if (a == 0 && b == 0)
      return 0;
    set<int> CartasDeA, CartasDeB;
    //Le cartas de A
    for (int i = 0; i < a; i++) {
      cin >> aux;
      CartasDeA.insert(aux);
    }
    //Le cartas de B
    for (int i = 0; i < b; i++) {
      cin >> aux;
      CartasDeB.insert(aux);
    }

//    mostra(CartasDeA);
//    mostra(CartasDeB);

    int contSaideA = 0;
    for (int c : CartasDeA) {
      if (verificaTroca(CartasDeB, c))
        contSaideA++;
    }
    int contSaideB = 0;
    for (int c : CartasDeB) {
      if (verificaTroca(CartasDeA, c))
        contSaideB++;
    }
    cout << min(contSaideA, contSaideB) << endl;
  }

  return 0;
}
