#pragma once

#include <windows.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/GLU.h>
#define _USE_MATH_DEFINES 
#include <math.h>

#define MYSONG_SCENE1LOGO 1014
#define LOGOSTARTSCALINGTIME 2
#define LOGOSCALESPEED 1.0
#define ASTROMEDICOMPSPEED 3

float Radian(float angle);

extern HWND ghwnd;

const float rotation_speed = 4.0f;
const float triangle_speed = 9.0f;
const float circle_speed = 9.0f;
const float r_speed = 15.0f;
static GLfloat gray = 0.0f;
static float ax = 0.0f, az = 0.0f, sx = 0.0f, sz = 0.0f, tx = 0.0f, index = 0.0f;
static float tz = 0.0f, rx = 0.0f, rz = 0.0f, o1x = 0.0f, o1z = 0.0f; 
static float m1x = 0.0f, m1z = 0.0f, ex = 0.0f, ez = 0.0f, dx = 0.0f;
static float dz = 0.0f, ix = 0.0f, iz = 0.0f, cx = 0.0f, cz = 0.0f; 
static float o2x = 0.0f, m2x = 0.0f, m2z = 0.0f, px = 0.0f, pz = 0.0f; 
static float ay = 0.0f, sy = 0.0f, ty = 0.0f, ry = 0.0f, o1y = 0.0f;
static float m1y = 0.0f, ey = 0.0f, dy = 0.0f, iy = 0.0f, cy = 0.0f, o2y = 0.0f, m2y = 0.0f, py = 0.0f;
static float ag = 0.0f, sg = 0.0f, tg = 0.0f, m1g = 0.0f, eg = 0.0f, o1g = 0.0f, rg = 0.0f, dg = 0.0f, ig = 0.0f, cg = 0.0f, o2g = 0.0f, m2g = 0.0f, pg = 0.0f; 

//Amit
GLfloat tAngle = 0.0f;
GLfloat rAngle = 0.0f;
static GLfloat position = 0.0f;
GLfloat array_X[800];
GLfloat array_Y[800];
GLfloat array_Z[800];
int iPoints;

bool render_group_render_start = false;
