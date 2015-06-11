#include "../hw2_defs.h"

/*
  Manipulates the projection matrix. If the user is in
  perspective mode, we will use gluPerspective() with
  view angle fov
  aspect ratio asp
  near clipping plane dim/4
  far clipping plane 4*dim
*/

void Project(int fov,double asp,double dim, int mode) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // Perspective transformation
  if (mode) {
    gluPerspective(fov,asp,dim/4,4*dim);
  }
  else {
  	glOrtho(-asp*dim,+asp*dim, -dim,+dim, -dim,+dim);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}