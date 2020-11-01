#pragma once
// --- Headers ---

#include <windows.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/GLU.h>
#define _USE_MATH_DEFINES
#include <math.h>

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "Winmm.lib")

#define MYLOGO 1000

extern bool bRender;
extern bool bScene3End;
extern bool bScene2End;
extern bool bScene1End;
extern bool bScene1Transition;

extern void DrawLogo(void);
extern void render_group_render(void);
extern void astromedicomp_print(void);
extern void Scene1_AmitPoints_Initialize(void);
extern void Scene1_AmitPoints_Update(void);
extern void Scene1_AmitPoints(void);


extern void Scene2_Initialize(void);
extern void Scene2_Models(void);
extern void Scene_2_Update(void);


extern void Scene3_Initialize(void);
extern void Scene3_CutOutDrawing(void);
extern void Scene3_RenderFlame(void);
extern void Scene3_LargeFlame(void);
extern void Scene3_SmallFlame(float xTrans, float yTrans, float zTrans);
extern void Scene3_Update();

extern void Scene4_RDisplay(void);
extern void Scene4_PrintingAllNames(void);
extern void Scene4_DrawPaan(void);
extern void Scene4_Update(void);
extern void Scene4_Initialize(void);











