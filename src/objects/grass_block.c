#include "../hw2_defs.h"

void grass_block(double x,double y,double z,double dx_mat[7][7],double th_mat[7][7]) {
  glPushMatrix();
  // Translate as desired
  glTranslated(x,y,z);
  
  int i;
  int j;
  float dx;
  float th;
  // Make 49 blades of grass inside a unit box.
  // Each blade is rotated a random amount and
  // scaled within a random amount (a reasonable scale)
  for (i=0;i<7;i++) {
    for (j=0;j<7;j++) {
      dx = dx_mat[i][j];
      th = th_mat[i][j];
      grass_blade((float)i/7,0,(float)j/7 , dx,7.5*dx,.1 , th);
    }
  }

  glPopMatrix();
}