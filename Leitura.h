#ifndef LEITURA_H
#define LEITURA_H
#include "FiguraGeometrica.h"
#include <string>
#include <vector>

class Leitura {
public:
  Leitura();

  std::vector<FiguraGeometrica *> parse(std::string filename);
  int getDx();
  int getDy();
  int getDz();

protected:
  int dx, dy, dz;
  float r, g, b, a;

private:
};

#endif // LEITURA_H