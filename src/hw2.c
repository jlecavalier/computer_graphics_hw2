#include "hw2_defs.h"

// Global Vars
int debug=0; // Debug mode
int mode=0; // projection mode
int th=0; // Azimuth of view angle
int ph=0; // Elevation of view angle
int fov=55; // Field of view (perspective mode)
double asp=1; // Aspect ratio
double dim=5.0; // Size of the world
double cam_x=0; // Strafe left and right
double cam_z=5; // Walk forwards and backwards
float win_width=0;
float win_height=0;
float l_theta;

void display() {
  // Erase the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  // Enable Z-Buffering
  glEnable(GL_DEPTH_TEST);
  // Undo transforms
  glLoadIdentity();

  // Perspective - set eye position
  if (mode) {
    double lookat_x = cam_x - Cos(l_theta);
    gluLookAt(cam_x,0,cam_z , lookat_x,0,cam_z-5 , 0,1,0);
  }
  // Orthogonal - set world orientation
  else {
    glRotatef(ph,1,0,0);
    glRotatef(th,0,1,0);
  }

  // Cube at origin with length 0.3 and no rotation
  cube(0,0,0 , 0.3,0.3,0.3 , 0);

  // Display axes and params in debug mode
  if(debug) {
    axes(1);
    Params(th,ph,mode,l_theta);
  }

  glFlush();
  glutSwapBuffers();
}

void key(unsigned char ch,int x,int y) {
  // Exit when the user presses ESC
  if (ch == 27) {
    exit(0);
  }
  else if (ch == 'm') {
    mode = 1 - mode;
  }
  // 'w' to walk forward
  else if (ch == 'w') {
    cam_z -= 0.1;
  }
  // 's' to walk backward
  else if (ch == 's') {
    cam_z += 0.1;
  }
  // 'a' cam_xs left
  else if (ch == 'a') {
    cam_x -= 0.1;
  }
  // 'd' cam_xs right
  else if (ch == 'd') {
    cam_x += 0.1;
  }
  // We may have updated the projection mode, so reproject
  Project(fov,asp,dim,mode);
  // Redisplay
  glutPostRedisplay();
}

void reshape(int width,int height) {
  // Find the aspect ratio
  asp = (height>0) ? (double)width/height : 1;
  // Set global width and height
  win_width = (float)width;
  win_height = (float)height;
  // Set the viewport to the entire window
  glViewport(0,0,width,height);
  // Set the projection accordingly
  Project(fov,asp,dim,mode);
}

void special(int key,int x,int y) {
  if (key == GLUT_KEY_RIGHT) {
    th += 5;
  }
  else if (key == GLUT_KEY_LEFT) {
    th -= 5;
  }
  else if (key == GLUT_KEY_UP) {
    ph += 5;
  }
  else if (key == GLUT_KEY_DOWN) {
    ph -= 5;
  }

  // F1 to switch to debug mode
  else if (key == GLUT_KEY_F1) {
    debug = 1 - debug;
  }

  // Angles are in degrees!
  th %= 360;
  ph %= 360;

  // We need to update the projection
  Project(fov,asp,dim,mode);
  // We updated what the image looks like. Redisplay!
  glutPostRedisplay();
}

void passive_mouse(int x, int y) {
  glLoadIdentity();
  float x_prime = (float)x;
  l_theta = x_prime*(180/win_width);
  glLoadIdentity();
  glutPostRedisplay();
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
  glutKeyboardFunc(key);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutPassiveMotionFunc(passive_mouse);
  glutMotionFunc(passive_mouse);
  // Pass control to GLUT so it can interact with the user
  glutMainLoop();
  return 0;
}