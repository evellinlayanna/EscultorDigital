#include "Leitura.h"
#include "Sculptor.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

/**
@brief Na main, o Sculptor implementa as classes e funções presentes no código
deste projeto.
*/

using namespace std;

int main() {
  Sculptor *desenho;
  Leitura parser;
  std::vector<FiguraGeometrica *> figuras;

  figuras = parser.parse("pacman.txt");
  desenho = new Sculptor(parser.getDx(), parser.getDy(), parser.getDz());

  for (size_t i = 0; i < figuras.size(); i++) {
    figuras[i]->draw(*desenho);
  }

  desenho->writeOFF((char *)"pacman.off");

  for (size_t i = 0; i < figuras.size(); i++) {
    delete figuras[i];
  }

  delete desenho;
}