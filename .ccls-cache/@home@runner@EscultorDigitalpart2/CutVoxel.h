#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
@brief  Classe Cutvoxel herdeira de FiguraGeometrica, responsável por remover
pontos da escultura.
*/

class CutVoxel : public FiguraGeometrica {

public:
  CutVoxel(int x_, int y_, int z_);
  ~CutVoxel() {}

  void draw(Sculptor &s);

protected:
  int x, y, z;

private:
};

#endif // CUTVOXEL_H