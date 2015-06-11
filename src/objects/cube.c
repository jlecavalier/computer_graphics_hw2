#include "../hw2_defs.h"

/*
  Draws a cube at (x,y,z)
  with dimensions (dx,dy,dz)
  rotated th about the y axis
*/

void cube(double x,double y,double z,
	      double dx,double dy, double dz,
	      double th) {
  // Save transformation
  glPushMatrix();
  // Offset
  glTranslated (x,y,z);
  glRotated(th,0,1,0);
  glScaled(dx,dy,dz);
  // Cube
  glBegin(GL_QUADS);
  // Front
  glColor3f(1,0,0);
  glVertex3f(-1,-1, 1);
  glVertex3f(+1,-1, 1);
  glVertex3f(+1,+1, 1);
  glVertex3f(-1,+1, 1);
  //  Back
  glColor3f(0,0,1);
  glVertex3f(+1,-1,-1);
  glVertex3f(-1,-1,-1);
  glVertex3f(-1,+1,-1);
  glVertex3f(+1,+1,-1);
  //  Right
  glColor3f(1,1,0);
  glVertex3f(+1,-1,+1);
  glVertex3f(+1,-1,-1);
  glVertex3f(+1,+1,-1);
  glVertex3f(+1,+1,+1);
  //  Left
  glColor3f(0,1,0);
  glVertex3f(-1,-1,-1);
  glVertex3f(-1,-1,+1);
  glVertex3f(-1,+1,+1);
  glVertex3f(-1,+1,-1);
  //  Top
  glColor3f(0,1,1);
  glVertex3f(-1,+1,+1);
  glVertex3f(+1,+1,+1);
  glVertex3f(+1,+1,-1);
  glVertex3f(-1,+1,-1);
  //  Bottom
  glColor3f(1,0,1);
  glVertex3f(-1,-1,-1);
  glVertex3f(+1,-1,-1);
  glVertex3f(+1,-1,+1);
  glVertex3f(-1,-1,+1);
  //  End
  glEnd();
  //  Undo transformations
  glPopMatrix();
}