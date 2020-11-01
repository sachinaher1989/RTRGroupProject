//headers
#include "Scene4.h"

//macros
#define BLAST_LIMIT 15.0f
#define NAMESSPEED 0.39f
#define ROCKETSPEED 0.2f
#define BLASTSPEED 0.2f

static GLint gliFontListMarathi, gliFontListEnglish;            //list
static GLfloat glfAngle = 90.0f;                                 //rotational angle
static GLfloat glRedValue = 0.0f;                                //initial value of red color for group member names
static GLfloat glGreenValue = 0.0f;                          //initial value of green color for group member names
static GLfloat glBlueValue = 0.0f;                               //initial value of blue color for group member names
static GLfloat glfGroupNameX_Position = -3.5f;                   //initial position of 'Render Group'
static GLfloat glfMessageX_Position = 3.5f;                  //initial position of vijayadashami message

static GLfloat RocketYpos1 = -1.0f;
//Variables For Leaf Animation
static GLfloat LeafColor = 0.0f;
static GLfloat LineColor = 0.0f;
static int RocketWhistleflag = 0;
static int RocketBlastflag = 0;
static int flag11 = 0;


void Scene4_DrawPaan(void)
{
    DWORD WINAPI ThreadProc1(LPVOID Param);

    //Variable Declaration
    GLfloat i, j;
    GLfloat radius = 0.5f;
    GLfloat px1, py1, px2, py2;
    GLfloat Xpos1, Ypos1, Xpos2, Ypos2;
    GLfloat PaanScale = 0.75;
    HANDLE hTHread1 = NULL;
    
    glScalef(PaanScale, PaanScale, PaanScale);
    //Leaf base
    glColor3f(0.0f, LeafColor, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(0.02f, 0.0f, 0.0f);
        glVertex3f(-0.02f, 0.0f, 0.0f);
        glVertex3f(-0.02f, 0.7f, 0.0f);
        glVertex3f(0.02f, 0.7f, 0.0f);
    glEnd();

    //Leaf Left
    glColor3f(0.0f, LeafColor, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for (i = 0.0; i < 2.0f * M_PI; i += 0.01f)
    {
        px1 = radius * cos(i);
        py1 = radius * sin(i);

        Xpos1 = 0.3 + px1;
        Ypos1 = py1;
        glVertex3f(-Xpos1, Ypos1, 0.0f);
    }
    glEnd();

    glColor3f(0.0f, LeafColor, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for (j = 0.0; j < 2.0f * M_PI; j += 0.01f)
    {
        px2 = radius * cos(j);
        py2 = radius * sin(j);

        Xpos2 = 0.3 + px2;
        Ypos2 = py2;
        glVertex3f(Xpos2, Ypos2, 0.0f);
    }
    glEnd();

    //Central Line
    glColor3f(0.0f, LineColor, 0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.4f, 0.0f);
        glVertex3f(0.0f, -0.4f, 0.0f);
    glEnd();

        LeafColor = LeafColor + 0.0001f;
    if (LeafColor >= 0.3f)
        LeafColor = 0.3f;

    LineColor = LineColor + 0.0001f;
    if (LineColor >= 0.4f)
    {
        LineColor = 0.4f;
    }

}


DWORD WINAPI ThreadProc(LPVOID Param)
{
    PlaySound(MAKEINTRESOURCE(MYSONG), GetModuleHandle(NULL), SND_RESOURCE);    
    return(TRUE);
}


DWORD WINAPI ThreadProc1(LPVOID Param)
{
    PlaySound(MAKEINTRESOURCE(MYSONG1), GetModuleHandle(NULL), SND_RESOURCE);
    return(TRUE);
}

void Scene4_PrintingAllNames(void)
{
    
    void Rocket(void);
    void Blast(void);
    DWORD WINAPI ThreadProc(LPVOID Param);
    DWORD WINAPI ThreadProc1(LPVOID Param);
    void AptyachiPane(void);

    
    HANDLE hTHread[12] = {NULL};
    HANDLE hTHread1 = NULL;


    static GLfloat RocketYpos1 = -1.0f;
    
    
    static GLfloat zTranslate = 11.0f;
    static GLfloat zTranslate1 = zTranslate+1;
    static GLfloat zTranslate2 = zTranslate1+2;
    static GLfloat zTranslate3 = zTranslate2+3;
    static GLfloat zTranslate4 = zTranslate3+2;
    static GLfloat zTranslate5 = zTranslate4+6;
    static GLfloat zTranslate6 = zTranslate5+1;
    static GLfloat zTranslate7 = zTranslate6+2;
    static GLfloat zTranslate8 = zTranslate7+2;
    static GLfloat zTranslate9 = zTranslate8+2;
    static GLfloat zTranslate10 = zTranslate9+2;
    static GLfloat zTranslate11 = zTranslate10+2;

    static int BMflag = 0;
    static int flag1 = 0;
    static int flag2 = 0;
    static int flag3 = 0;
    static int flag4 = 0;
    static int flag5 = 0;
    static int flag6 = 0;
    static int flag7 = 0;
    static int flag8 = 0;
    static int flag9 = 0;
    static int flag10 = 0;

    static GLfloat xPos = 0.0f, xPos1 = 0.0f;

    HMODULE HModule = GetModuleHandle(NULL);
    static int songflag = 0;
    
    //variable declaration
    char cVijayadashamiWishes[128] = "tafe_ ivajayaadSamaIcyaa haid_k SauBaecCa!";
    char cBharatMazire[128] = "Baarta maaiJare";
    char cAmitHailkar[128] = "Aaimata hElakr";
    char cAmitAvalaskar[128] = "Aaimata AaavaLsakr";
    char cAshviniBhutare[128] = "AaiSvanaI Bautaare";
    char cDushyantPawar[128] = "duVyaa/ta pavaar";
    char cGayatriJoshi[128] = "gaayaPaI jaaeSaI";
    char cOmkarPhale[128] = "Aaae/kar fLe";
    char cPrasadNiphadkar[128] = "paXsaad inafaDkr";
    char cSachinAher[128] = "saicana Aaaher";
    char cSahebSingh[128] = "saaheba isa/ga";
    char cVijayanandRaorane[128] = "ivajayaana/d ravaraNae";
    char cYashPatel[128] = "yaSa paoela";                           //all group member names
    GLfloat glScaleValue = 0.25f;

    if(songflag == 0)
    {
        hTHread1 = CreateThread(NULL, 0, ThreadProc1, (LPVOID)ghwnd, 0, NULL);
        songflag = 1;
    }

    //code
    glListBase(gliFontListEnglish);
    
    //'Render Group' coming from left side
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glTranslatef(glfGroupNameX_Position, 0.6f, -2.0f);
    glTranslatef(-0.85, 0.6f, -2.0f);
    glScalef(0.1f, 0.1f, 0.1f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glCallLists(strlen("Render Group"), GL_UNSIGNED_BYTE, "Render Group");
    
    glListBase(gliFontListMarathi);
    
    //vijayadashami message coming from right side
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glTranslatef(glfMessageX_Position, 0.6f, -2.0f);
    glTranslatef(-0.23, 0.6f, -2.0f);
    glScalef(0.2f, 0.2f, 0.2f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glCallLists(strlen(cVijayadashamiWishes), GL_UNSIGNED_BYTE, cVijayadashamiWishes);

    
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-4.0+xPos, 0.4f, 0.0f);
        glVertex3f(-4.0+xPos, -0.3f, 0.0f);
        glVertex3f(2.0+xPos, -0.3f, 0.0f);
        glVertex3f(2.0+xPos, 0.4f, 0.0f);
    glEnd();

    
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(-10.0+xPos1, 0.4f, 0.0f);
        glVertex3f(-10.0+xPos1, -0.3f, 0.0f);
        glVertex3f(-4.0+xPos1, -0.3f, 0.0f);
        glVertex3f(-4.0+xPos1, 0.4f, 0.0f);
    glEnd();
    
    if(xPos < 5.0f)
    {
        xPos += 0.0013f;
        xPos1 -= 0.0013f;
    }
    else
    {
        xPos += 0.05f;    
        xPos1 -= 0.05f;   
    }

    glLoadIdentity();

    if(xPos > 4.5f)
    {
        if(BMflag == 0)
        {
            hTHread[0] = CreateThread(NULL, 0, ThreadProc, (LPVOID)ghwnd, 0, NULL);
            BMflag = 1;
        }

    //top center
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.2f, 0.3f, zTranslate);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cBharatMazire), GL_UNSIGNED_BYTE, cBharatMazire);    
    if(zTranslate >= -2.0f)
        zTranslate -= 0.04f*NAMESSPEED;
        

    //first row
    //left side name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-1.2f, 0.1f, zTranslate1);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cSachinAher), GL_UNSIGNED_BYTE, cSachinAher);
    if(zTranslate1 >= -2.0f)
        zTranslate1 -= 0.04f*NAMESSPEED;
    
    //middle name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.2f, 0.1f, zTranslate2);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cYashPatel), GL_UNSIGNED_BYTE, cYashPatel);
    if(zTranslate2 >= -2.0f)
        zTranslate2 -= 0.04f*NAMESSPEED;


    //right side name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.6f, 0.1f, zTranslate3);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cAshviniBhutare), GL_UNSIGNED_BYTE, cAshviniBhutare);    
    if(zTranslate3 >= -2.0f)
        zTranslate3 -= 0.04f*NAMESSPEED;


    //second row
    //left side name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-1.2f, -0.1f, zTranslate4);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cAmitHailkar), GL_UNSIGNED_BYTE, cAmitHailkar);
    if(zTranslate4 >= -2.0f)
        zTranslate4 -= 0.04f*NAMESSPEED;

    //middle name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.2f, -0.1f, zTranslate5);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cOmkarPhale), GL_UNSIGNED_BYTE, cOmkarPhale);
    if(zTranslate5 >= -2.0f)
        zTranslate5 -= 0.04f*NAMESSPEED;
    
    //right side name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.6f, -0.1f, zTranslate6);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cGayatriJoshi), GL_UNSIGNED_BYTE, cGayatriJoshi);
    if(zTranslate6 >= -2.0f)
        zTranslate6 -= 0.04f*NAMESSPEED;

    //third row
    //left side name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-1.2f, -0.3f, zTranslate7);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cPrasadNiphadkar), GL_UNSIGNED_BYTE, cPrasadNiphadkar);
    if(zTranslate7 >= -2.0f)
        zTranslate7 -= 0.04f*NAMESSPEED;

    //middle name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.2f, -0.3f, zTranslate8);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cSahebSingh), GL_UNSIGNED_BYTE, cSahebSingh);
    if(zTranslate8 >= -2.0f)
        zTranslate8 -= 0.04f*NAMESSPEED;

    //right side name
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.6f, -0.3f, zTranslate9);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cDushyantPawar), GL_UNSIGNED_BYTE, cDushyantPawar);
    if(zTranslate9 >= -2.0f)
        zTranslate9 -= 0.04f*NAMESSPEED;

    //fourth row
    //right side
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-0.8f, -0.5f, zTranslate10);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cVijayanandRaorane), GL_UNSIGNED_BYTE, cVijayanandRaorane);
    if(zTranslate10 >= -2.0f)
        zTranslate10 -= 0.04f*NAMESSPEED;
    else
    {
        if(flag10 == 0)
        {
            flag10 = 1;
            RocketWhistleflag = 2;
        }
    }

    //bottom center
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.1f, -0.5f, zTranslate11);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(glRedValue, glGreenValue, glBlueValue);
    glCallLists(strlen(cAmitAvalaskar), GL_UNSIGNED_BYTE, cAmitAvalaskar);
    if(zTranslate11 >= -2.0f)
        zTranslate11 -= 0.04f*NAMESSPEED;
    else
        flag11 = 1;
    
}

}


DWORD WINAPI ThreadProc2(LPVOID Param)
{
    PlaySound(MAKEINTRESOURCE(MYSONG2), GetModuleHandle(NULL), SND_RESOURCE);
    return(TRUE);
}

DWORD WINAPI ThreadProc3(LPVOID Param)
{
    PlaySound(MAKEINTRESOURCE(MYSONG3), GetModuleHandle(NULL), SND_RESOURCE);
    return(TRUE);
}
void Scene4_RDisplay(void)
{
    //function prototype
    void Update(void);
    void Rocket(void);
    void Blast(void);
    DWORD WINAPI ThreadProc2(LPVOID Param);
    DWORD WINAPI ThreadProc3(LPVOID Param);
    

    HANDLE hTHread2 = NULL;
    HANDLE hTHread3 = NULL;

    if(RocketWhistleflag == 2)
    {
        hTHread2 = CreateThread(NULL, 0, ThreadProc2, (LPVOID)ghwnd, 0, NULL);
        RocketWhistleflag = 1;
    }
    
    if(flag11 == 1)
    {
    glLoadIdentity();

    /***********Rocket center***************/
    glTranslatef(0.0f, RocketYpos1, 0.0f);
    Rocket();
    if (RocketYpos1 >= 1.0f)
    {
        glLoadIdentity();
        glTranslatef(0.0f, 1.0f, 0.0f);
        Blast();
    }
    
    /***********Rocket Left 1***************/
    glLoadIdentity();

    glTranslatef(-0.5f, RocketYpos1, 0.0f);
    Rocket();
    if (RocketYpos1 >= 1.0f)
    {
        glLoadIdentity();
        glTranslatef(-0.5f, 1.0f, 0.0f);
        Blast();
    }

    /***********Rocket Right 1***************/
    glLoadIdentity();

    glTranslatef(0.5f, RocketYpos1, 0.0f);
    Rocket();
    if (RocketYpos1 >= 1.0f)
    {
        glLoadIdentity();
        glTranslatef(0.5f, 1.0f, 0.0f);
        Blast();
    }

    glLoadIdentity();

    /***********Rocket Left 2***************/
    glTranslatef(-1.0f, RocketYpos1, 0.0f);
    Rocket();
    if (RocketYpos1 >= 1.0f)
    {
        glLoadIdentity();
        glTranslatef(-1.0f, 1.0f, 0.0f);
        Blast();
    }

    /***********Rocket Right 2***************/
    glLoadIdentity();

    glTranslatef(1.0f, RocketYpos1, 0.0f);
    Rocket();
    if (RocketYpos1 >= 1.0f)
    {
        glLoadIdentity();
        glTranslatef(1.0f, 1.0f, 0.0f);
        Blast();
    }

    /***********Rocket Left 3***************/
    glLoadIdentity();

    glTranslatef(-1.5f, RocketYpos1, 0.0f);
    Rocket();
    if (RocketYpos1 >= 1.0f)
    {
        glLoadIdentity();
        glTranslatef(-1.5f, 1.0f, 0.0f);
        Blast();
    }

    /***********Rocket Right 2***************/
    glLoadIdentity();

    glTranslatef(1.5f, RocketYpos1, 0.0f);
    Rocket();
    if (RocketYpos1 >= 1.0f)
    {
        glLoadIdentity();
        glTranslatef(1.5f, 1.0f, 0.0f);
        Blast();
        if(RocketBlastflag == 0)
        {
            RocketBlastflag = 1;
            hTHread3 = CreateThread(NULL, 0, ThreadProc3, (LPVOID)ghwnd, 0, NULL);
        }
    }

    //Rocket upward position
    RocketYpos1 = RocketYpos1 + 0.008f * ROCKETSPEED;
}
}

void Blast(void)
{
    static GLfloat pointXPos = 0.0f;
    static GLfloat pointYPos = 0.0f;
    GLfloat BlackColor[3] = { 0.0f, 0.0f, 0.0f };
    glPointSize(4.0f);

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(1.0f, 0.0f, 1.0f);

    glPointSize(3.0f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
    {
        glVertex3f(2*pointXPos*sin(i)*0.9,pointYPos*cos(i)*0.9, -3.0f);
    }
    glEnd();

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45), pointYPos * cos(i + 45), -3.0f);
    glEnd();

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45)*0.8, pointYPos * cos(i + 45)*0.8, -3.0f);
    glEnd();

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45) *0.7, pointYPos * cos(i + 45) *0.7, -3.0f);
    glEnd();

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(1.0f, 0.5f, 0.1f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45) * 0.6, pointYPos * cos(i + 45) * 0.6, -3.0f);
    glEnd();

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45) * 0.5, pointYPos * cos(i + 45) * 0.5, -3.0f);
    glEnd();

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(0.2f, 1.0f, 0.7f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45) * 0.4, pointYPos * cos(i + 45) * 0.4, -3.0f);
    glEnd();

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45) * 0.3, pointYPos * cos(i + 45) * 0.3, -3.0f);
    glEnd();

    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(0.5f, 1.0f, 0.5f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45) * 0.2, pointYPos * cos(i + 45) * 0.2, -3.0f);
    glEnd();
    if (pointXPos > BLAST_LIMIT)
        glColor3fv(BlackColor);
    else
        glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    for (GLfloat i = 1; i < 50; i = i + 1)
        glVertex3f(2 * pointXPos * sin(i + 45) * 0.1, pointYPos * cos(i + 45) * 0.1, -3.0f);
    glEnd();
    pointXPos = pointXPos + 0.0008f*BLASTSPEED;
    pointYPos = pointYPos + 0.0008f*BLASTSPEED;
}

void Sparklingline(void)
{
    static GLfloat linelength1 = 1.0f;
    static GLfloat linelength2 = 0.0f;
    static GLfloat offset1 = 0.0001f;
    static GLfloat offset2 = 0.0001f;
    static int flag1;
    static int flag2;


    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    for (GLfloat i = M_PI - M_PI/6 ; i < M_PI + M_PI / 6; i = i + 0.2)
    {
        glVertex3f(0.0f, 0.0f, -3.0f);
        glVertex3f(linelength1 * sin(i), linelength1 * cos(i), -3.0f);
    }
    glEnd();


    glBegin(GL_LINES);
    for (GLfloat i = M_PI - M_PI /6 ; i < M_PI + M_PI / 6; i = i + 0.1)
    {
        glVertex3f(0.0f, 0.0f, -3.0f);
        glVertex3f(linelength2 * sin(i), linelength2 * cos(i), -3.0f);
    }
    glEnd();

    linelength1 = linelength1 + offset1;
    linelength2 = linelength2 + offset2;

    if (linelength1 >= 1.5f)
    {
        flag1 = 0;
    }
    if (linelength1 <= 0.0f)
    {
        flag1 = 1;
    }

    if (linelength2 >= 1.5f)
    {
        flag2 = 0;
    }
    if (linelength2 <= 0.0f)
    {
        flag2 = 1;
    }


    if (flag1)
        offset1 = 0.01f;
    else
        offset1 = -0.01f;


    if (flag2)
        offset2 = 0.01f;
    else
        offset2 = -0.01f;
}

void Rocket(void)
{
    void Sparklingline(void);

    glScalef(0.2f, 0.2f, 1.0f);

    glColor3f(0.8f, 0.3f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 1.0f, -3.0f);
        glVertex3f(0.1f, 0.7f, -3.0f);
        glVertex3f(-0.1f, 0.7f, -3.0f);
    glEnd();

    glColor3f(0.9f, 0.1f, 0.2f);
    glBegin(GL_QUADS);
        glVertex3f(0.1f, 0.7f, -3.0f);
        glVertex3f(0.1f, 0.1f, -3.0f);
        glVertex3f(-0.1f, 0.1f, -3.0f);
        glVertex3f(-0.1f, 0.7f, -3.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(0.1f, 0.1f, -3.0f);
        glVertex3f(0.1f, -1.0f, -3.0f);
        glVertex3f(0.085f, -1.0f, -3.0f);
        glVertex3f(0.085f, 0.1f, -3.0f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.1f, -3.0f);
        glVertex3f(0.0f, -0.1f, -3.0f);
    glEnd();

    glScalef(0.2f, 0.2f, 1.0f);
    Sparklingline();
}

// Display Window

void CenterLine(void)
{
    glColor3f(0.0f, 0.5f, 0.0f);

    glBegin(GL_LINES);

    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(0.0f, -0.4f, 0.0f);

    glEnd();

}

void Rectangle(void)
{
    //code
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.3f, 0.0f);

    glVertex3f(0.02f, 0.0f, 0.0f);
    glVertex3f(-0.02f, 0.0f, 0.0f);
    glVertex3f(-0.02f, -0.7f, 0.0f);
    glVertex3f(0.02f, -0.7f, 0.0f);

    glEnd();
}

void CircleFilled(void)
{
    //my variables
    GLfloat i;
    GLfloat radius = 0.5f;
    GLfloat x, y;

    //code
    glColor3f(0.0f, 0.3f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    for (i = 0.0; i < 2.0f * M_PI; i += 0.00001f)
    {
        x = radius * cos(i);
        y = radius * sin(i);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

}

void Scene4_Update(void)
{

    glfAngle -= 0.1f;                           //increment rotational angle for names
    if(glfAngle <= 0.0f)                    
        glfAngle = 0.0f;
    
    if(glRedValue <= 1.0f)                      //pass maximum of red color for names
        glRedValue += 0.002f;
    
    if(glGreenValue <= 0.3f)                    //pass maximum of green color for names
        glGreenValue += 0.001f;
        
    if(glfGroupNameX_Position <= -0.85f)        //pass final position of 'Render Group'
        glfGroupNameX_Position += 0.002f;   
    
    if(glfMessageX_Position >= -0.23f)          //pass final position of vijayadashami message
        glfMessageX_Position -= 0.003f;
}

void Scene4_Initialize(void)
{

    // --- Setup Render Scene ---
    HFONT hfontAMS_Manthan, hfontBell_MT;
    GLYPHMETRICSFLOAT agmf[128];
    LOGFONT lfAMS_Manthan, lfBell_MT;

    //initialization of lfAMS_Manthan
    lfAMS_Manthan.lfHeight          = -10.0f;
    lfAMS_Manthan.lfWidth           = 0.0f;
    lfAMS_Manthan.lfEscapement      = 0.0f;
    lfAMS_Manthan.lfOrientation     = 0.0f;
    lfAMS_Manthan.lfWeight          = FALSE;
    lfAMS_Manthan.lfItalic          = FALSE;
    lfAMS_Manthan.lfUnderline       = FALSE;
    lfAMS_Manthan.lfStrikeOut       = FALSE;
    lfAMS_Manthan.lfCharSet         = ANSI_CHARSET;
    lfAMS_Manthan.lfOutPrecision    = OUT_DEFAULT_PRECIS;
    lfAMS_Manthan.lfClipPrecision   = CLIP_DEFAULT_PRECIS;
    lfAMS_Manthan.lfQuality         = DEFAULT_QUALITY;
    lfAMS_Manthan.lfPitchAndFamily  = DEFAULT_PITCH;
    strcpy(lfAMS_Manthan.lfFaceName, "AMS Manthan");
    
    //create the font and display list
    hfontAMS_Manthan = CreateFontIndirect(&lfAMS_Manthan);
    SelectObject(ghdc, hfontAMS_Manthan);
    
    gliFontListMarathi = glGenLists(128);
    
    wglUseFontOutlines(ghdc, 0, 128, gliFontListMarathi, 0.0f, 0.0f, WGL_FONT_POLYGONS, agmf);

    DeleteObject(hfontAMS_Manthan);
    
    /*****************************************************/
    //initialization of lfBell_MT
    lfBell_MT.lfHeight          = -10.0f;
    lfBell_MT.lfWidth           = 0.0f;
    lfBell_MT.lfEscapement      = 0.0f;
    lfBell_MT.lfOrientation     = 0.0f;
    lfBell_MT.lfWeight          = FALSE;
    lfBell_MT.lfItalic          = FALSE;
    lfBell_MT.lfUnderline       = FALSE;
    lfBell_MT.lfStrikeOut       = FALSE;
    lfBell_MT.lfCharSet         = ANSI_CHARSET;
    lfBell_MT.lfOutPrecision    = OUT_DEFAULT_PRECIS;
    lfBell_MT.lfClipPrecision   = CLIP_DEFAULT_PRECIS;
    lfBell_MT.lfQuality         = DEFAULT_QUALITY;
    lfBell_MT.lfPitchAndFamily  = DEFAULT_PITCH;
    strcpy(lfBell_MT.lfFaceName, "Arial Rounded MT Bold");

    //create the font and display list
    hfontBell_MT = CreateFontIndirect(&lfBell_MT);
    SelectObject(ghdc, hfontBell_MT);
    
    gliFontListEnglish = glGenLists(128);
    
    wglUseFontOutlines(ghdc, 0, 128, gliFontListEnglish, 0.0f, 0.0f, WGL_FONT_POLYGONS, agmf);

    hfontBell_MT = CreateFontIndirect(&lfBell_MT);
    SelectObject(ghdc, hfontBell_MT);

    DeleteObject(hfontBell_MT);
    /*****************************************************/

}



