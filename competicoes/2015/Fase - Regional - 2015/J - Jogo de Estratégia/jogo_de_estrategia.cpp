#include <iostream>
#include <vector>

using namespace std;

int viagem(int c, int d){
  int count = 0;
  int value;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < d*c; i++) {
    cin >> value;
    a.push_back(value);
    if(i < c)
      b.push_back(value);
    else{
      b[count] += a[i];
    }

    count ++;
    if(count == c)
      count = 0;
  }

  int aux, index = 1;
  aux = b[0];
  
  for (int j = 1; j < c; j++) {
    if(aux < b[j]){
      aux = b[j];
      index = j+1;
    }
    if(aux == b[j]){
      index = j+1;
    }

  }
  return index;
}

int main () {


  int d, c;

  cin >> c >> d ;

  cout << viagem(c, d) << endl;
  return 0;
}
