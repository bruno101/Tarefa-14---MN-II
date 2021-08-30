#include <iostream>
#include "PVI_RK.h"
#include "PVI_PC.h"
using namespace std;

void PC4 (double v0, double y0, double k, double m, int nIter, double t, double t_s) {

  // Inicialização

  double v1, y1, v2, y2, v3, y3;
  
  PVI_RK *p0 = new PVI_RK(v0, y0, k, m);

  double maxY = y0;
  double tMaxY = 0;
  double yAtImpact = y0;
  double vAtImpact = v0;
  double tImpact = 0;
  double v_s = 0;
  double y_s = 0;

  for (int i = 0; i < 3; i++) {

    p0->atualizarEstado(t);

    if (p0->yi > maxY) {
      maxY = p0->yi;
      tMaxY = p0->tempo;
    }

    if (abs(p0->yi) < abs(yAtImpact)) {
      yAtImpact = p0->yi;
      vAtImpact = p0->vi;
      tImpact = p0->tempo;
    }

    if (p0->tempo - t_s < 0.00001) {
      v_s = p0->vi;
      y_s = p0->yi;
    }

    if (i == 0) {
      v1 = p0->vi;
      y1 = p0->yi;
    } else if (i == 1) {
      v2 = p0->vi;
      y2 = p0->yi;
    } else {
      v3 = p0->vi;
      y3 = p0->yi;
    }

  }

  // Fim da inicialização

  PVI_PC *p = new PVI_PC(v0, y0, v1, y1, v2, y2, v3, y3, k, m, 3*t);

  int iter = 0;

  while (1) {

    p->atualizarEstado(t);

    if (p->yi > maxY) {
      maxY = p->yi;
      tMaxY = p->tempo;
    }

    if (abs(p->yi) < abs(yAtImpact)) {
      yAtImpact = p->yi;
      vAtImpact = p->vi;
      tImpact = p->tempo;
    }

    if (p->tempo - t_s < 0.00001) {
      v_s = p->vi;
      y_s = p->yi;
    }

    if ((p->yi < 0) && (p->tempo >= t_s)) {
      break;
    }
    iter++;
    if (iter > nIter) {
      break;
    }

  }

  cout << "Solução para o valor de t_s dado: (v = " << v_s << ", y = " << y_s << ")\n";
  cout << "3a) Altura máxima: " << maxY << "\n";
  cout << "3b) Tempo na altura máxima: " << tMaxY << "\n";
  cout << "3c) Tempo até o impacto: " << tImpact << "\n";
  cout << "3d) Velocidade no momento do impacto: " << vAtImpact << "\n";

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