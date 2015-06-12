#include "../hw2_defs.h"

void Params(int th,int ph,int mode,float l_theta,float l_phi,
	        double lookat_x,double lookat_y,double lookat_z) {
  glColor3f(1,1,1);
  glWindowPos2i(5,5);
  Print("Angle=%d, %d", th,ph);
  glWindowPos2i(5,20);
  Print("Projection=%s",mode?"Perspective":"Orthogonal");
  glWindowPos2i(5,35);
  Print("theta=%.2f",l_theta);
  glWindowPos2i(5,50);
  Print("phi=%.2f",l_phi);
  glWindowPos2i(5,65);
  Print("Lookat=%d, %d, %d",lookat_x,lookat_y,lookat_z);
}