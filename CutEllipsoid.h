#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
@brief Classe Cutellipsoid herdeira de FiguraGeometrica, responsável por
adicionar elipsoides na escultura.
*/

class CutEllipsoid : public FiguraGeometrica {
public:
  CutEllipsoid(int xc_, int yc_, int zc_, int rx_, int ry_, int rz_);
  ~CutEllipsoid() {}

  void draw(Sculptor &s);

protected:
  int xcenter, ycenter, zcenter, rx, ry, rz;

private:
};

#endif // CUTELLIPSOID_H