#include "../hw2_defs.h"

void Params(int th,int ph,int mode) {
  glColor3f(1,1,1);
  glWindowPos2i(5,5);
  Print("Angle=%d, %d", th,ph);
  glWindowPos2i(5,20);
  Print("Projection=%s",mode?"Perspective":"Orthogonal");
}