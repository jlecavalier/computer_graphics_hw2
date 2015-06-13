#include "hw2_defs.h"

// Global Vars
int debug=0; // Debug mode
int mode=1; // projection mode
int th=0; // Azimuth of view angle
int ph=0; // Elevation of view angle
int fov=55; // Field of view (perspective mode)
double asp=1; // Aspect ratio
double dim=5.0; // Size of the world
double cam_x=0; // Strafe left and right
double cam_z=0; // Walk forwards and backwards
double win_width=0;
double win_height=0;
double l_theta=90;
double l_phi=0;
double lookat_x=0;
double lookat_y=0;
double lookat_z=0;

// For the grass blades
double dx_mat[7][7];
double th_mat[7][7];

void display() {
  glClearColor(4.0/255.0,12.0/255.0,31.0/255.0,1);
  // Erase the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  // Enable Z-Buffering
  glEnable(GL_DEPTH_TEST);
  // Undo transforms
  glLoadIdentity();

  // Perspective - set eye position
  if (mode) {
    lookat_x = (cam_x + (double)Sin(l_theta));
    lookat_y = (Sin(l_phi));
    lookat_z = (cam_z - Cos(l_theta));
    gluLookAt(cam_x,0.2,cam_z , lookat_x,lookat_y,lookat_z , 0,1,0);
  }
  // Orthogonal - set world orientation
  else {
    glTranslated(0,0,0);
    glRotatef(ph,1,0,0);
    glRotatef(th,0,1,0);
    glScaled(1,1,1);
    //glScaled(1.0/10.0,1.0/10.0,1.0/10.0);
  }

  // A grassy plane
  plane(0,0,5, 
        47.0/255.0,99.0/255.0,56.0/255.0,
        16, 
        0,0,0);

  // Blocks of grass!
  int i;
  int j;
  for (i=-7;i<=7;i++) {
    for (j=-7;j<=7;j++) {
      grass_block(i,0,j,dx_mat,th_mat);
    }
  }

  // Fence at origin, no rotation.
  double k;
  for (k=-8;k<=8;k+=.5) {
    fence(k,0,-7,0);
    fence(-7,0,k,90);
    fence(k,0,7,0);
    fence(7,0,k,90);
  }

  // Display axes and params in debug mode
  if(debug) {
    axes(1);
    float mat[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, mat);
    Params(th,ph,mode,l_theta,l_phi,
           lookat_x,lookat_y,lookat_z,
           cam_x,cam_z,
           mat[2],mat[6],mat[10],
           mat[0],mat[4],mat[8]);
  }

  glFlush();
  glutSwapBuffers();
}

void key(unsigned char ch,int x,int y) {

  float mat[16];
  glGetFloatv(GL_MODELVIEW_MATRIX, mat);
  // Exit when the user presses ESC
  if (ch == 27) {
    exit(0);
  }
  else if (ch == 'm') {
    mode = 1 - mode;
  }
  // 'w' to walk forward
  else if (ch == 'w') {

    cam_x -= (mat[2])/2.0;
    cam_z -= (mat[10])/2.0;
  }
  // 's' to walk backward
  else if (ch == 's') {
    cam_x += (mat[2])/2.0;
    cam_z += (mat[10])/2.0;
  }
  // 'a' strafe left
  else if (ch == 'a') {
    cam_x -= (mat[0])/2.0;
    cam_z -= (mat[8])/2.0;
  }
  // 'd' strafe right
  else if (ch == 'd') {
    cam_x += (mat[0])/2.0;
    cam_z += (mat[8])/2.0;
  }

  if (cam_x < -5.3) {cam_x = -5.3;}
  if (cam_x > 5.3) {cam_x = 5.3;}
  if (cam_z > 5.3) {cam_z = 5.3;}
  if (cam_z < -5.3) {cam_z = 5.3;}
  // We may have updated the projection mode, so reproject
  Project(fov,asp,dim,mode);
  // Redisplay
  glutPostRedisplay();
}

void reshape(int width,int height) {
  // Find the aspect ratio
  asp = (height>0) ? (double)width/height : 1;
  // Set global width and height
  win_width = (double)width;
  win_height = (double)height;
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
  if (ph < 5) {ph = 5;}
  if (ph > 45) {ph = 45;}

  // We need to update the projection
  Project(fov,asp,dim,mode);
  // We updated what the image looks like. Redisplay!
  glutPostRedisplay();
}

void passive_mouse(int x, int y) {
  glLoadIdentity();
  double x_prime = (double)x;
  l_theta = x_prime*(360/win_width);
  if (y >= (win_height/2)) {
    l_phi = 34;
  }
  else {
    float y_prime = win_height - (float)y;
    l_phi = (y_prime*(90/win_height))-11;
  }
  glLoadIdentity();
  Project(fov,asp,dim,mode);
  glutPostRedisplay();
}

/*
  Start up GLUT and tell it what to do
*/
int main(int argc, char* argv[]) {
  srand(time(NULL));
  int i;
  int j;
  for (i=0;i<7;i++) {
    for (j=0;j<7;j++) {
      dx_mat[i][j] = (drand48()*.013)+.001;
      th_mat[i][j] = ((double)rand()/360);
    }
  }
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