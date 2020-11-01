#pragma once

#include <windows.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/GLU.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define MYSONG_SCENE2BG 1007
#define MYSONG_SCENE2AYURVEDA 1008
#define MYSONG_SCENE2DRAMA 1009 
#define MYSONG_SCENE2KUNDALI 1010 
#define MYSONG_SCENE2COMPUTER 1011

//#define PI 3.14159265359f 
#define KUNDALI_NUBERS_BLINK_VALUE 50
#define AYURVEDA_Y_MOVE_VALUE_MIN 1.3f
#define AYURVEDA_Y_MOVE_VALUE_MAX 1.7f

#define SCENE2_ASTROLOGYSPEED  0.7f
#define SCENE2_DRAMASPEED 0.7f
#define SCENE2_AYURVEDASPEED 0.7f
#define SCENE2_COMPUTERSPEED 0.7f
#define SCENE2_AYURVEDADANDASPEED 0.3f
#define SCENE2_KUNDALISCALESPEED 0.7f
#define SCENE2_COMPUTERSPEED_XPOS 0.2f
#define SCENE2_DRAMA_YPOS 0.7f


extern HWND ghwnd;
extern HDC ghdc;

//Variables for Devnagari Font Shlokas
GLint gliFontListMarathi, gliFontListEnglish;
GLfloat glfAngle = 0.0f;								 //rotational angle
GLfloat glRedValue = 0.0f;								 //initial value of red color for group member names
GLfloat glGreenValue = 0.0f;							 //initial value of green color for group member names
GLfloat glBlueValue = 0.0f;								 //initial value of blue color for group member names
GLfloat glfGroupNameX_Position = -3.5f;					 //initial position of 'Render Group'
GLfloat glfMessageX_Position = 3.5f;

//Variable for Translate all scenes 
GLfloat gfKundaliScaleValue = 0.0f;
GLfloat gfyMoveComputer = 5.0f;
GLfloat gfyMoveDrama = 2.0f;
GLfloat gfyMoveAyurveda = 3.0f;
GLfloat gfAyurvedaDandaYMove = 1.4f;

GLfloat gfyRotateFace = 0.0f;
GLfloat gfyComputerSceenFadeIn = 0.0f;
GLfloat gfyCpuCircle = 0.0f;
GLfloat gfyKeyBoardKey = 0.0f;

//Flag For Kundali Blinking
bool IsStartBlinkingEffect = false;
bool gbIsBlinkFlag = true;

// Flag For Ayurveda Dandi
bool IsStartMoveEffect = false;
bool gbIsMoveFlag = true;

//Flag for all scenes draw
bool gbIsKundaliDraw = false;
bool gbIsDramaDraw = false;
bool gbIsAyurvedaDraw = true;
bool gbIsComputerDraw = false;
bool gbEndTransition = false;

//Blending effect for all scenes
GLfloat gfBlendValForAstrologyStr = 0.0f;
GLfloat gfBlendValForDramaStr = 0.0f;
GLfloat gfBlendValForAyurvedaStr = 0.0f;
GLfloat gfBlendValForComputerStr = 0.0f;

//Blendig effect flags for all scene
bool gbIsAstrologyBlend = false;
bool gbIsComputerBlend = false;
bool gbIsAyurvedaBlend = false;
bool gbIsDramaBlend = false;
