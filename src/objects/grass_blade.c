#include "../hw2_defs.h"

void grass_blade(double x,double y,double z,
	             double dx,double dy,double dz,
	             double th) {
  // Save transformation
  glPushMatrix();
  // Transform as desired
  glTranslated(x,y,z);
  glRotated(th,0,1,0);
  glScaled(dx,dy,dz);
  // Quadstrip
  glBegin(GL_QUAD_STRIP);
  // White, for now.
  glColor3f(1,1,1);
  float i;
  float mpi6 = M_PI/6;
  float mpi3 = M_PI/3;
  float r = 58.0/255.0;
  float g = 92.0/255.0;
  float b = 48.0/255.0;
  // First, we draw the base of the blade.
  for (i=(-M_PI/6);i <= mpi3;i+=0.1) {
  	glColor3f(r,g,b);
  	float cosi = cos(i);
  	float z_pos = pow((mpi6+i)/1.5,2);
  	glVertex3f(cosi,i+mpi6,z_pos);
  	glVertex3f(1-cosi,i+mpi6,z_pos);
  	glVertex3f(cosi,i+.01+mpi6,z_pos+.001);
  	glVertex3f(1-cosi,i+.01+mpi6,z_pos+.001);
  	r = r + .01;
  	g = g + .025;
  }
  glEnd();
  // Now, we draw the tip of the blade.
  glPopMatrix();
}