#include <iostream>
using namespace std;

void PC4 (double v0, double y0, double k, double m, int nIter, double t, double t_s) {

}

int main() {

  double v0, y0, k, m;
  int nIter;
  double t;
  double t_s;

  cout << "Digite o valor de v0: ";
  cin >> v0;
  cout << "Digite o valor de y0: ";
  cin >> y0;
  cout << "Digite o valor de k: ";
  cin >> k;
  cout << "Digite o valor de m: ";
  cin >> m;
  cout << "Digite o número máximo de iterações: ";
  cin >> nIter;
  cout << "Digite o valor de t em cada iteração: ";
  cin >> t;
  cout << "Digite o valor t_s do tempo para o qual você quer a solução (esse valor deve ser múltiplo de t): ";
  cin >> t_s;
  cout << "\n";

  PC4(v0,y0,k,m,nIter,t,t_s);

}