#include "PVI_PC.h"

PVI_PC::PVI_PC (double v0, double y0, double v1, double y1, double v2, double y2, double v3, double y3, double k, double m, double tempo) {

  this->k = k;
  this->m = m;
  this->v0 = v0;
  this->y0 = y0;
  this->v1 = v1;
  this->y1 = y1;
  this->v2 = v2;
  this->y2 = y2;
  this->v3 = v3;
  this->y3 = y3;
  
  this->vi = v3;
  this->yi = y3;
  this->tempo = tempo;

}

void PVI_PC::atualizarEstado(double t) {

  double f0v, f1v, f2v, f3v, f4v;
  double f0y, f1y, f2y, f3y, f4y;

  //Predição

  double v_int, y_int;

  f0v = (-10.0-(k/m)*v0);
  f1v = (-10.0-(k/m)*v1);
  f2v = (-10.0-(k/m)*v2);
  f3v = (-10.0-(k/m)*v3);

  f0y = v0;
  f1y = v1;
  f2y = v2;
  f3y = v3;

  v_int = v3 + (t/24)*(-9*f0v+37*f1v-59*f2v+55*f3v);
  y_int = y3 + (t/24)*(-9*f0y+37*f1y-59*f2y+55*f3y);

  //Correção

  double v_n, y_n;

  f4v = (-10.0-(k/m)*v_int);
  f4y = v_int;

  v_n = v3 + (t/24)*(f1v-5*f2v+19*f3v+9*f4v);
  y_n = y3 + (t/24)*(f1y-5*f2y+19*f3y+9*f4y);

  this->v0 = v1;
  this->y0 = y1;
  this->v1 = v2;
  this->y1 = y2;
  this->v2 = v3;
  this->y2 = y3;
  this->v3 = v_n;
  this->y3 = y_n;

  this->vi = v_n;
  this->yi = y_n;

  this->tempo = tempo+t;

}