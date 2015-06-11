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

#ifdef __cplusplus
extern "C" {
#endif

void Print(const char* format , ...);
void cube(double x,double y,double z,
	      double dx,double dy,double dz,
	      double th);

#ifdef __cplusplus
}
#endif

#endif