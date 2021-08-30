class PVI_PC {

  public:
    double v0, y0, v1, y1, v2, y2, v3, y3, k, m; 
    double vi, yi, tempo;

    PVI_PC (double v0, double y0, double v1, double y1, double v2, double y2, double v3, double y3, double k, double m, double tempo);
    void atualizarEstado(double t);

};