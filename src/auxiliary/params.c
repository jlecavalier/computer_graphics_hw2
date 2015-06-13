#include "../hw2_defs.h"

void Params(int th,int ph,int mode,double l_theta,double l_phi,
	        double lookat_x,double lookat_y,double lookat_z,
	        double cam_x,double cam_z,
	        float fx, float fy, float fz,
	        float rx, float ry, float rz) {
  glColor3f(1,1,1);
  if (!mode) {
  	glColor3f(0,0,0);
  	glWindowPos2i(5,20);
    Print("Viewing Angle=%d, %d", th,ph);
  }
  glWindowPos2i(5,5);
  Print("Projection=%s",mode?"Perspective":"Orthogonal");
  if (mode) {
  	glWindowPos2i(5,20);
	Print("theta=%.2f",l_theta);
	glWindowPos2i(5,35);
	Print("phi=%.2f",l_phi);
	glWindowPos2i(5,50);
	Print("Lookat=(%.2f, %.2f, %.2f)",lookat_x,lookat_y,lookat_z);
	glWindowPos2i(5,65);
	Print("Camera Position=(%.2f, 0.2, %.2f)",cam_x,cam_z);
	glWindowPos2i(5,80);
    Print("Forward Vector=<%.2f, %.2f, %.2f>",fx,fy,fz);
	glWindowPos2i(5,95);
	Print("Right Vector=<%.2f, %.2f, %.2f>",rx,ry,rz);
  }
}