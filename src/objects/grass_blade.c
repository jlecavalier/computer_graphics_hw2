#include "../hw2_defs.h"

void grass_blade() {
  // Save transformation
  glPushMatrix();

  glScaled(1,1,1);

  // Quadstrip
  glBegin(GL_QUAD_STRIP);
  // White, for now.
  glColor3f(1,1,1);
  // Centeread around origin, then transform
  float i;
  float mpi6 = M_PI/6;
  float mpi5 = M_PI/5;
  for (i=(-M_PI/6);i <= mpi5;i+=0.001) {
  	float cosi = cos(i);
  	glVertex3f(cosi,i+mpi6,0);
  	glVertex3f(1-cosi,i+mpi6,0);
  	glVertex3f(cosi,i+.01+mpi6,0);
  	glVertex3f(1-cosi,i+.01+mpi6,0);
  }
  glEnd();
  glPopMatrix();
}