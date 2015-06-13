#include "../hw2_defs.h"

void fencepost(double x,double y,double z,
	           double dx,double dy,double dz) {
  // Save transformation
  glPushMatrix();
  // Offset
  glTranslated(x,y,z);
  glScaled(dx,dy,dz);
  // Fencepost
  glBegin(GL_QUADS);
  glColor3f(1,1,1);
  // Fencepost base
  glVertex3f(.25,0,0);
  glVertex3f(0,0,0);
  glVertex3f(0,.75,0);
  glVertex3f(.25,.75,0);
  // Fencepost cap
  glVertex3f(.25,.75,0);
  glVertex3f(0,.75,0);
  glVertex3f(.124,1,0);
  glVertex3f(.126,1,0);
  //End
  glEnd();
  // Undo Transformations
  glPopMatrix();
}