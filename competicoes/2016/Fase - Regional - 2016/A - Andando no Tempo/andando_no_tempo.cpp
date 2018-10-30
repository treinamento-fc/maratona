#include <iostream>

using namespace std;

void viagem(int a, int b, int c){
  int aux_1 = b + c;
  int aux_2 = a + b;
  int aux_3 = a + c;
  if(a - aux_1 == 0 || a - b == 0 || a - c == 0 || b - c == 0 || b - aux_3 == 0 || c - aux_2 == 0){
    cout << 'S' << endl;
  }
  else
    cout << 'N' << endl;
}

int main () {

  int a, b, c;

  cin >> a >> b >> c;
  viagem(a, b, c);
  return 0;
}
