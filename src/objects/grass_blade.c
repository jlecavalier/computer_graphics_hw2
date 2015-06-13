#include "../hw2_defs.h"

void grass_blade() {
  // Save transformation
  glPushMatrix();

  glScaled(1,1,1);

  // Quadstrip
  glBegin(GL_QUAD_STRIP);
  // White, for now.
  glColor3f(1,1,1);
  float i;
  float mpi6 = M_PI/6;
  float mpi3 = M_PI/3;
  // First, we draw the base of the blade.
  for (i=(-M_PI/6);i <= mpi3;i+=0.001) {
  	float cosi = cos(i);
  	float z_pos = pow((mpi6+i)/1.5,2);
  	glVertex3f(cosi,i+mpi6,z_pos);
  	glVertex3f(1-cosi,i+mpi6,z_pos);
  	glVertex3f(cosi,i+.01+mpi6,z_pos+.001);
  	glVertex3f(1-cosi,i+.01+mpi6,z_pos+.001);
  }
  glEnd();
  // Now, we draw the tip of the blade.
  glPopMatrix();
}