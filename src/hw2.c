#include "hw2_defs.h"

void display() {
  // Erase the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  // Enable Z-Buffering
  glEnable(GL_DEPTH_TEST);
  // Undo transforms
  glLoadIdentity();

  cube(0,0,0 , 0.3,0.3,0.3 , 0);

  glFlush();
  glutSwapBuffers();
}

/*
  Start up GLUT and tell it what to do
*/
int main(int argc, char* argv[]) {
  // Initialize GLUT
  glutInit(&argc,argv);
  // Request double buffer, true color, z buffering
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  // Window is as large as the user's computer can handle
  int user_width = glutGet(GLUT_SCREEN_WIDTH);
  int user_height = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize(user_width,user_height);
  // Actually create the window
  glutCreateWindow("Jay LeCavalier --- hw2");
  // Set callbacks
  glutDisplayFunc(display);
  // Pass control to GLUT so it can interact with the user
  glutMainLoop();
  return 0;
}