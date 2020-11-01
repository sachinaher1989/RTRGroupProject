#include "Scene3.h"

#define CUTOUTSPEED 3.0f
#define FLAMEWAITPERIOD 0.6f

extern HDC ghdc;
bool bScene3End = 0;

DWORD WINAPI ThreadProc5(LPVOID Param);

DWORD WINAPI ThreadProc5(LPVOID Param)
{
    PlaySound(MAKEINTRESOURCE(MYSONG4), GetModuleHandle(NULL), SND_RESOURCE);    
    return(TRUE);
}

void Scene3_Initialize(void)
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
    
    gliFontListMarathi_S3 = glGenLists(128);
    
    wglUseFontOutlines(ghdc, 0, 128, gliFontListMarathi_S3, 0.0f, 0.0f, WGL_FONT_POLYGONS, agmf);

    DeleteObject(hfontAMS_Manthan);
    
    /*****************************************************/
    
    //initialize particles for large flame
    for(int i = 0; i < high; i++)
    {
        particles_1[i].active = true;                         
        particles_1[i].life = 1.0f;
        particles_1[i].fade = (float)(rand() % 100) / 1000.0f + 0.003f;
    
        particles_1[i].x = 0.0f;
        particles_1[i].y = 0.0f;

        particles_1[i].xi = (float)((rand() % 60) - 24.0f);
        particles_1[i].yi = (float)((rand() % 60) - 22.0f);
    
        particles_1[i].xg = 0.0f;
        particles_1[i].yg = 0.8f;
    }

    //initialize particles for small flame
    for(int i = 0; i < medium; i++)
    {
        particles_2[i].active = true;                         
        particles_2[i].life = 1.0f;
        particles_2[i].fade = (float)(rand() % 100) / 1000.0f + 0.003f;
    
        particles_2[i].x = 0.0f;
        particles_2[i].y = 0.0f;

        particles_2[i].xi = (float)((rand() % 60) - 24.0f);
        particles_2[i].yi = (float)((rand() % 60) - 22.0f);
    
        particles_2[i].xg = 0.0f;
        particles_2[i].yg = 0.8f;
    }

    //set initial positions of 11 small flames
    for(int i = 0; i < 11; i++)
    {
        initial_pos[i][0] = -1.95f;
        initial_pos[i][1] = 1.2f;
    }

    /*****************************************************/
    
    //scaling glfFinalPositionVertices array & filling initial array with random values
    for(int i = 0; i < MAX_SIZE; i++)
    {
        glfFinalPositionVertices[i][0] *= 0.0007;
        glfFinalPositionVertices[i][1] *= -0.0007;

        glfInitialPositionVertices[i][0] = (3.0f / (float)RAND_MAX) * rand() - 1.5f;
        glfInitialPositionVertices[i][1] = (3.0f / (float)RAND_MAX) * rand() - 1.5f;
    }
    
}


void Scene3_CutOutDrawing(void)
{
    DWORD WINAPI ThreadProc5(LPVOID Param);
    HANDLE hTHread5 = NULL;
    static bool bCutpoutSong = 0;

    //variable declaration
    float step = 0.0001f;    
    int i;
    GLfloat glScaleValue = 2.0f;
    if(bCutpoutSong == 0)
    {
        hTHread5 = CreateThread(NULL, 0, ThreadProc5, (LPVOID)ghwnd, 0, NULL);
        bCutpoutSong = 1;
    }
    
    //code
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(-0.2f, 0.8f, -2.0f);
    glScalef(glScaleValue, glScaleValue, glScaleValue);

    glPointSize(6.0f);
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 1.0f, 0.0f);
        for(i = 0; i < MAX_SIZE; i++)
        {
            //x incr
            if(glfInitialPositionVertices[i][0] < glfFinalPositionVertices[i][0])
                glfInitialPositionVertices[i][0] += step*CUTOUTSPEED;
            else if(glfInitialPositionVertices[i][0] > glfFinalPositionVertices[i][0])
                glfInitialPositionVertices[i][0] -= step*CUTOUTSPEED;
            
            //y incr
            if(glfInitialPositionVertices[i][1] < glfFinalPositionVertices[i][1])
                glfInitialPositionVertices[i][1] += step*CUTOUTSPEED;
            else if(glfInitialPositionVertices[i][1] > glfFinalPositionVertices[i][1])
                glfInitialPositionVertices[i][1] -= step*CUTOUTSPEED;
            
            glVertex3f(glfInitialPositionVertices[i][0], glfInitialPositionVertices[i][1], 0.0f);
        }   
    glEnd();
}

void Scene3_RenderFlame(void)
{
    //function declaration
    void Scene3_LargeFlame(void);
    void Scene3_SmallFlame(float xTrans, float yTrans, float zTrans);
    void Scene3_transition_end(void);

    //variable declaration
    char cBirthdayWish[128] = "!! jaIvaeta Sard: Satama !!";    "!! janmaidvasasya haid_k SauBakamanaaina Aaacaaya_ !!";
    GLfloat glScaleValue = 0.24f;
    static GLfloat xb = 0.775f;
    static GLfloat yb = -0.5f;  //glTranslatef(0.77f, -0.5f, -2.0f);

    static int frame_count = 0;
    float step = 0.001f;
    static bool bsmall_flame = false;
    static bool bmedium_flame = false;
    static bool bEnd = false;

    //code
    //code
    glListBase(gliFontListMarathi_S3);                                 //DO NOT CHANGE
    
    //Font Rednering
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-1.3f, -0.125f, -2.0f);
    glScalef(glScaleValue, glScaleValue, glScaleValue);
    glColor3f(0.0f, glfValueGreenForWish, 0.0f);
    glCallLists(strlen(cBirthdayWish), GL_UNSIGNED_BYTE, cBirthdayWish);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //large flame 
    Scene3_LargeFlame();

    //medium flame
    if(bmedium_flame)
        Scene3_SmallFlame(xb, yb, -2.0f);

    //small flames
    if(bsmall_flame)
    {
        for(int i = 0; i < 11; i++)
        {
            //x increment
            if(initial_pos[i][0] > flame_pos[i][0])
                initial_pos[i][0] -= step;
            else if(initial_pos[i][0] < flame_pos[i][0])
                initial_pos[i][0] += step;
        
            //y increment
            if(initial_pos[i][1] > flame_pos[i][1])
                initial_pos[i][1] -= step;
            else if(initial_pos[i][1] < flame_pos[i][1])
                initial_pos[i][1] += step;

            Scene3_SmallFlame(initial_pos[i][0], initial_pos[i][1], -5.0f);
        }
    }

    if(bEnd)
        Scene3_transition_end();

    frame_count++;

   //update
    if(bmedium_flame)
    {
        if(xb > -0.775f)
            xb -= 0.000756f;

        if(yb < 0.45f)
            yb += 0.00046f;
        
        if((xb < -0.775) &&(yb > 0.45))
            bsmall_flame = true;
    }

    /*
    if(initial_pos[9][1] <= flame_pos[9][1])
    {
        bScene3End = 1;
    }
    */

    if(frame_count == 500)
    {
        bmedium_flame = true;
    }   

    if(frame_count == 5000)
    {
        bEnd = true;
    }    

    if(frame_count == 6300)
    {
        bScene3End = 1;
        frame_count = 0;
    } 
}

void Scene3_LargeFlame(void)
{
    //code
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.77f, -0.5f, -2.0f);
   
    glPointSize(20.0f);
    glDisable(GL_DEPTH_TEST);

    for(int i = 0; i < high; i++)
    {
        if(particles_1[i].active == true)
        {
            float x = particles_1[i].x;
            float y = particles_1[i].y;

            glColor4f(1.0f, 0.5f, 0.02f, particles_1[i].life);

            glBegin(GL_POINTS);
                glVertex3f(x, y, 0.0f);
                glVertex3f(x + 0.01f, y, 0.0f);
                glVertex3f(x - 0.01f, y, 0.0f);
            glEnd();
        
            particles_1[i].x += particles_1[i].xi / (60.0f * 1000.0f);
            particles_1[i].y += particles_1[i].yi / (60.0f * 1000.0f);
        
            particles_1[i].xi += particles_1[i].xg;
            particles_1[i].yi += particles_1[i].yg;

            particles_1[i].life -= particles_1[i].fade;

            if(particles_1[i].life < 0.0f)
            {
                particles_1[i].life = 1.0f;
                particles_1[i].fade = (float)(rand() % 100) / 1000.0f + 0.003f;
            
                particles_1[i].x = 0.0f;
                particles_1[i].y = 0.0f;

                particles_1[i].xi = (float)((rand() % 60) - 24.0f);
                particles_1[i].yi = (float)((rand() % 60) - 22.0f);
            }
        }
    } 
}

void Scene3_SmallFlame(float xTrans, float yTrans, float zTrans)
{
    //code
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef((GLfloat)xTrans, (GLfloat)yTrans, (GLfloat)zTrans);
   
    glPointSize(20.0f);
    glDisable(GL_DEPTH_TEST);

    for(int i = 0; i < medium; i++)
    {
        if(particles_2[i].active == true)
        {
            float x = particles_2[i].x;
            float y = particles_2[i].y;

            glColor4f(1.0f, 0.5f, 0.02f, particles_2[i].life);

            glBegin(GL_POINTS);
                glVertex3f(x, y, 0.0f);
                glVertex3f(x + 0.01f, y, 0.0f);
                glVertex3f(x - 0.01f, y, 0.0f);
            glEnd();
        
            particles_2[i].x += particles_2[i].xi / (250.0f * 1000.0f);
            particles_2[i].y += particles_2[i].yi / (250.0f * 1000.0f);
        
            particles_2[i].xi += particles_2[i].xg;
            particles_2[i].yi += particles_2[i].yg;

            particles_2[i].life -= particles_2[i].fade;

            if(particles_2[i].life < 0.0f)
            {
                particles_2[i].life = 1.0f;
                particles_2[i].fade = (float)(rand() % 100) / 1000.0f + 0.0025f;
            
                particles_2[i].x = 0.0f;
                particles_2[i].y = 0.0f;

                particles_2[i].xi = (float)((rand() % 60) - 24.0f);
                particles_2[i].yi = (float)((rand() % 60) - 22.0f);
            }
        }
    } 
}

void Scene3_transition_end(void) 
{
    //variable declaration
    static GLfloat alpha = 0.0f;

    //code
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -1.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
        glColor4f(0.0f, 0.0f, 0.0f, alpha);
        glVertex3f(2.0f, 2.0f, 0.0f);
        glVertex3f(-2.0f, 2.0f, 0.0f);
        glVertex3f(-2.0f, -2.0f, 0.0f);
        glVertex3f(2.0f, -2.0f, 0.0f);
    glEnd();

    //update 
    if(alpha < 1.0f)
        alpha += 0.0008f;
}

// --- Update() ---
void Scene3_Update()
{
    static GLfloat value = 0.0f;
    
    //code
    value += 0.01f*FLAMEWAITPERIOD;
    if(value >= 45.0f)
        bRender = true;
    
    //if(glfValueGreenForWish <= 1.0f)
        glfValueGreenForWish += 0.00005f;
}
