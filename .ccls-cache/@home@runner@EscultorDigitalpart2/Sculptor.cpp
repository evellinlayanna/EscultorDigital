#include "Sculptor.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

Sculptor::Sculptor(int nx_, int ny_, int nz_) {

  nx = nx_;
  ny = ny_;
  nz = nz_;

  v = new Voxel **[nx];
  for (int i = 0; i < nx; i++) {
    v[i] = new Voxel *[ny];
    for (int j = 0; j < ny; j++) {
      v[i][j] = new Voxel[nz];
    }
  }

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        v[i][j][k].show = false;
      }
    }
  }
}

Sculptor::~Sculptor() {

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      delete[] v[i][j];
    }
  }
  for (int i = 0; i < nx; i++) {
    delete[] v[i];
  }
  delete[] v;
}

/**
@brief O método setColor define as cores ao desenho.
*/

void Sculptor::setColor(float r_, float g_, float b_, float a_) {
  r = r_;
  b = b_;
  g = g_;
  a = a_;
}

void Sculptor::putVoxel(int x, int y, int z) {

  v[x][y][z].show = true;
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
}

void Sculptor::cutVoxel(int x, int y, int z) { v[x][y][z].show = false; }

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {

  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        putVoxel(i, j, k);
      }
    }
  }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {

  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        cutVoxel(i, j, k);
      }
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {

  double dist;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        dist = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
        if (dist <= pow(radius, 2)) {
          putVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {

  double dist;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        dist = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
        if (dist <= pow(radius, 2)) {
          cutVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {

  double dist;
  if (rx == 0) {
    for (int j = 0; j <= ny; j++) {
      for (int k = 0; k <= nz; k++) {
        dist =
            pow(j - ycenter, 2) / pow(ry, 2) + pow(k - zcenter, 2) / pow(rz, 2);
        if (dist <= 1) {
          putVoxel(xcenter, j, k);
        }
      }
    }
  } else if (ry == 0) {
    for (int i = 0; i <= nx; i++) {
      for (int k = 0; k <= nz; k++) {
        dist =
            pow(i - xcenter, 2) / pow(rx, 2) + pow(k - zcenter, 2) / pow(rz, 2);
        if (dist <= 1) {
          putVoxel(i, ycenter, k);
        }
      }
    }

  } else if (rz == 0) {
    for (int i = 0; i <= nx; i++) {
      for (int j = 0; j <= ny; j++) {
        dist =
            pow(i - xcenter, 2) / pow(rx, 2) + pow(j - ycenter, 2) / pow(ry, 2);
        if (dist <= 1) {
          putVoxel(i, j, zcenter);
        }
      }
    }
  } else {
    for (int i = 0; i < nx; i++) {
      for (int j = 0; j < ny; j++) {
        for (int k = 0; k < nz; k++) {
          dist = pow(i - xcenter, 2) / pow(rx, 2) +
                 pow(j - ycenter, 2) / pow(ry, 2) +
                 pow(k - zcenter, 2) / pow(rz, 2);
          if (dist <= 1) {
            putVoxel(i, j, k);
          }
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {

  double dist;
  if (rx == 0) {
    for (int j = 0; j <= ny; j++) {
      for (int k = 0; k <= nz; k++) {
        dist =
            pow(j - ycenter, 2) / pow(ry, 2) + pow(k - zcenter, 2) / pow(rz, 2);
        if (dist <= 1) {
          cutVoxel(xcenter, j, k);
        }
      }
    }
  } else if (ry == 0) {
    for (int i = 0; i <= nx; i++) {
      for (int k = 0; k <= nz; k++) {
        dist =
            pow(i - xcenter, 2) / pow(rx, 2) + pow(k - zcenter, 2) / pow(rz, 2);
        if (dist <= 1) {
          cutVoxel(i, ycenter, k);
        }
      }
    }

  } else if (rz == 0) {
    for (int i = 0; i <= nx; i++) {
      for (int j = 0; j <= ny; j++) {
        dist =
            pow(i - xcenter, 2) / pow(rx, 2) + pow(j - ycenter, 2) / pow(ry, 2);
        if (dist <= 1) {
          cutVoxel(i, j, zcenter);
        }
      }
    }
  } else {
    for (int i = 0; i < nx; i++) {
      for (int j = 0; j < ny; j++) {
        for (int k = 0; k < nz; k++) {
          dist = pow(i - xcenter, 2) / pow(rx, 2) +
                 pow(j - ycenter, 2) / pow(ry, 2) +
                 pow(k - zcenter, 2) / pow(rz, 2);
          if (dist <= 1) {
            cutVoxel(i, j, k);
          }
        }
      }
    }
  }
}

void Sculptor::writeOFF(const char *filename) {

  int x, y, z, nfaces, index;
  float lado = 0.5;

  ofstream fout;
  nfaces = 0;

  fout.open(filename);

  fout << "OFF\n";

  for (x = 0; x < nx; x++) {
    for (y = 0; y < ny; y++) {
      for (z = 0; z < nz; z++) {
        if (v[x][y][z].show) {
          nfaces++;
        }
      }
    }
  }

  fout << nfaces * 8 << " " << nfaces * 6 << " 0 \n";
  for (x = 0; x < nx; x++) {
    for (y = 0; y < ny; y++) {
      for (z = 0; z < nz; z++) {
        if (v[x][y][z].show) {

          fout << x - lado << " " << y + lado << " " << z - lado << "\n"
               << flush;
          fout << x - lado << " " << y - lado << " " << z - lado << "\n"
               << flush;
          fout << x + lado << " " << y - lado << " " << z - lado << "\n"
               << flush;
          fout << x + lado << " " << y + lado << " " << z - lado << "\n"
               << flush;
          fout << x - lado << " " << y + lado << " " << z + lado << "\n"
               << flush;
          fout << x - lado << " " << y - lado << " " << z + lado << "\n"
               << flush;
          fout << x + lado << " " << y - lado << " " << z + lado << "\n"
               << flush;
          fout << x + lado << " " << y + lado << " " << z + lado << "\n"
               << flush;
        }
      }
    }
  }

  nfaces = 0;

  for (x = 0; x < nx; x++) {
    for (y = 0; y < ny; y++) {
      for (z = 0; z < nz; z++) {
        if (v[x][y][z].show) {
          index = nfaces * 8;

          fout << fixed;
          fout << 4 << " " << index + 0 << " " << index + 3 << " " << index + 2
               << " " << index + 1 << " ";
          fout << setprecision(2) << v[x][y][z].r << " " << setprecision(2)
               << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " "
               << setprecision(2) << v[x][y][z].a << "\n";

          fout << 4 << " " << index + 4 << " " << index + 5 << " " << index + 6
               << " " << index + 7 << " ";
          fout << setprecision(2) << v[x][y][z].r << " " << setprecision(2)
               << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " "
               << setprecision(2) << v[x][y][z].a << "\n";

          fout << 4 << " " << index + 0 << " " << index + 1 << " " << index + 5
               << " " << index + 4 << " ";
          fout << setprecision(2) << v[x][y][z].r << " " << setprecision(2)
               << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " "
               << setprecision(2) << v[x][y][z].a << "\n";

          fout << 4 << " " << index + 0 << " " << index + 4 << " " << index + 7
               << " " << index + 3 << " ";
          fout << setprecision(2) << v[x][y][z].r << " " << setprecision(2)
               << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " "
               << setprecision(2) << v[x][y][z].a << "\n";

          fout << 4 << " " << index + 7 << " " << index + 6 << " " << index + 2
               << " " << index + 3 << " ";
          fout << setprecision(2) << v[x][y][z].r << " " << setprecision(2)
               << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " "
               << setprecision(2) << v[x][y][z].a << "\n";

          fout << 4 << " " << index + 1 << " " << index + 2 << " " << index + 6
               << " " << index + 5 << " ";
          fout << setprecision(2) << v[x][y][z].r << " " << setprecision(2)
               << v[x][y][z].g << " " << setprecision(2) << v[x][y][z].b << " "
               << setprecision(2) << v[x][y][z].a << "\n";
          nfaces++;
        }
      }
    }
  }

  fout.close();
}