#ifndef HW2_DEFS_H
#define HW2_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define Cos(th) cos(3.1415927/180*(th))
#define Sin(th) sin(3.1415927/180*(th))

#ifdef __cplusplus
extern "C" {
#endif

// AUXILIARY
void Print(const char* format , ...);
void Project(int fov,double asp,double dim,int mode);
void Params(int th,int ph,int mode);

// OBJECTS
void cube(double x,double y,double z,
	      double dx,double dy,double dz,
	      double th);
void axes(float len);

#ifdef __cplusplus
}
#endif

#endif