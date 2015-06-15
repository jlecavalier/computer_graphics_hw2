#include "../hw2_defs.h"

void moon(double x,double y,double z,double r,
	      double thx,double thy,double thz) {
  const int d=5;
  int th,ph;

  // Save transformation
  glPushMatrix();
  // Offset
  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thy,0,1,0);
  glRotated(thz,0,0,1);
  glScaled(r,r,r);

  // Latitude bands
  for (ph=-90;ph<90;ph+=d) {
  	glBegin(GL_QUAD_STRIP);
  	glColor3f(ph/90.0+.1,ph/90.0+.1,ph/90.0+.1);
  	for (th=0;th<=360;th+=d) {
  	  glVertex3d(Sin(th)*Cos(ph),Sin(ph),Cos(th)*Cos(ph));
  	  glVertex3d(Sin(th)*Cos(ph+d),Sin(ph+d),Cos(th)*Cos(ph+d));
  	}
  	glEnd();
  }

  // Undo transformations
  glPopMatrix();
}