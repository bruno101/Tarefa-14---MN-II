class PVI_RK {

  public:
    double k, m; 
    double vi, yi, tempo;

    PVI_RK (double v0, double y0, double k, double m);
    void atualizarEstado(double t);

};