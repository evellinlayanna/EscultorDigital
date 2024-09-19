#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
@brief Classe Cutsphere herdeira de FiguraGeometrica, responsável por remover
esferas em nossa escultura.
*/

class CutSphere : public FiguraGeometrica {
public:
  CutSphere(int xc_, int yc_, int zc_, int radius_);
  ~CutSphere() {}

  void draw(Sculptor &s);

protected:
  int xcenter, ycenter, zcenter, radius;

private:
};

#endif // CUTSPHERE_H