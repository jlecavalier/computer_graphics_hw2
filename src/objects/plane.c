#include "../hw2_defs.h"

/*
  Draws a plane centered at (x,y,z)
  with color (r,g,b)
  side length dim
  rotations thx, thy, thz
*/

void plane(double x,double y,double z,
	      float r,float g,float b,
	      double dim,
	      double thx,double thy,double thz) {
  // Save transformation
  glPushMatrix();
  // Offset
  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thy,0,1,0);
  glRotated(thz,0,0,1);
  glScaled(dim,1,dim);
  // Plane
  glBegin(GL_QUADS);
  // Color specified by user
  glColor3f(r,g,b);
  // Centered around origin, then transform
  glVertex3f(+1,0,+1);
  glVertex3f(-1,0,+1);
  glVertex3f(-1,0,-1);
  glVertex3f(+1,0,-1);
  // End
  glEnd();
  // Undo transformations
  glPopMatrix();
}