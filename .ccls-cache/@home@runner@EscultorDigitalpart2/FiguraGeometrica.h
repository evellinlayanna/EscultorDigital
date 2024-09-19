#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

class FiguraGeometrica {
public:
  virtual ~FiguraGeometrica() {}
  virtual void draw(Sculptor &s) = 0;

protected:
  float r, g, b, a;

private:
};

#endif // FIGURAGEOMETRICA_H

// Tutorial:
// https://agostinhobritojr.github.io/curso/progav-dca1202/escultor.html#_a_classe_escultor_parte_2_estruturas_avan%C3%A7adas

// Checklist
// 5.1 Criação da classe abstrata FiguraGeometrica (OK)
// 5.2 Criação da classe concreta PutVoxel (OK)
// 5.3 Criação da classe concreta CutVoxel (OK)
// 5.4 Criação da classe concreta PutBox (OK)
// 5.5 Criação da classe concreta CutBox (OK)
// 5.6 Criação da classe concreta PutSphere (OK)
// 5.7 Criação da classe concreta CutSphere (OK)
// 5.8 Criação da classe concreta PutEllipsoid (OK)
// 5.9 Criação da classe concreta CutEllipsoid (OK)
// 5.10 Armazenamento de figuras (OK)
// 5.11 Teste das funcionalidades implementadas (OK)