#include "PVI_RK.h"

PVI_RK::PVI_RK (double v0, double y0, double k, double m) {

  this->k = k;
  this->m = m;

  this->vi = v0;
  this->yi = y0;
  this->tempo = 0;

}

void PVI_RK::atualizarEstado(double t) {

  double v1, v2, v3;
  double y1, y2, y3;
  double f0v, f1v, f2v, f3v;
  double f0y, f1y, f2y, f3y;

  f0v = (-10.0-(k/m)*vi);
  f0y = vi;

  v1 = vi + (t/2)*f0v;
  y1 = yi + (t/2)*f0y;

  f1v = (-10.0-(k/m)*v1);
  f1y = v1;

  v2 = vi + (t/2)*f1v;
  y2 = yi + (t/2)*f1y;

  f2v = (-10.0-(k/m)*v2);
  f2y = v2;

  v3 = vi + t*f2v;
  y3 = yi + t*f2y;

  f3v = (-10.0-(k/m)*v3);
  f3y = v3;

  vi = vi + (t/6)*(f0v+2*f1v+2*f2v+f3v);
  yi = yi + (t/6)*(f0y+2*f1y+2*f2y+f3y);

  this->tempo += t;


}