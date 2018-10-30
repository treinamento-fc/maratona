#include <iostream>

using namespace std;

int viagem(int a, int b){
  if(a == b){
    return a;
  }
  if(a > b){
    return a;
  }
  else{
    return b;
  }
}

int main () {

  int a, b;

  cin >> a >> b;
  cout << viagem(a, b) << endl;
  return 0;
}
