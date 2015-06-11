#include "../hw2_defs.h"

/*
  Draw the x, y, and z axes in white at the origin
  len is the length of the axes.
*/

void axes(float len) {
  glColor3f(1,1,1);
  glBegin(GL_LINES);
  glVertex3d(0,0,0);
  glVertex3d(len,0,0);
  glVertex3d(0,0,0);
  glVertex3d(0,len,0);
  glVertex3d(0,0,0);
  glVertex3d(0,0,len);
  glEnd();
  glRasterPos3d(len,0,0);
  Print("X");
  glRasterPos3d(0,len,0);
  Print("Y");
  glRasterPos3d(0,0,len);
  Print("Z");
}