#include "hw2_defs.h"

void display() {
  // Erase the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  // Enable Z-Buffering
  glEnable(GL_DEPTH_TEST);
  // Undo transforms
  glLoadIdentity();
  glColor3f(1,1,1);
  glWindowPos2i(50,50);
  Print("Hello, world!");
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
  // Window is 600 X 600
  glutInitWindowSize(600,600);
  // Actually create the window
  glutCreateWindow("Jay LeCavalier --- hw2");
  // Set callbacks
  glutDisplayFunc(display);
  // Pass control to GLUT so it can interact with the user
  glutMainLoop();
  return 0;
}