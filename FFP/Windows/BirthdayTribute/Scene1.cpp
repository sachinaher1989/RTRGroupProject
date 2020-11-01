#include "Scene1.h"

bool bScene1End = 0;
bool bScene1Transition = 0;

static GLfloat i = 0.0f;

DWORD WINAPI Thread_Scene1Logo(LPVOID Param)
{
    PlaySound(MAKEINTRESOURCE(MYSONG_SCENE1LOGO), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);    
    return(TRUE);
}

void Scene1_AmitPoints_Initialize(void)
{
	for (int i = 0; i < 800; i++)
	{
		array_X[i] = GLfloat(rand() % 10) - 5;
		array_Y[i] = GLfloat(rand() % 8) - 4;
		array_Z[i] = GLfloat(rand() % 10) - 5;
	}
}


void Scene1_AmitPoints(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(position / 3.0f, 0.0f, position);
	glPointSize(2.0f);
	for (int i = 0; i < 800; i++)
	{
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(array_X[i], array_Y[i], array_Z[i]);
		glEnd();
	}
	glPointSize(1.0f);

}

void Scene1_AmitPoints_Update(void)
{
	position = position + 0.0005f;
	position = position + 0.0005f;

	if (position > 1.0f)
	{
		position = 0.0f;
	}
}


void DrawLogo(void)
{
    //variable declaration
    //T = triangle , C = circle
    static GLfloat Tx = -7.0f;
    static GLfloat Ty = -7.0f;
    static GLfloat Cx = 7.0f;
    static GLfloat Cy = -7.35f;
    static GLfloat Ey = 7.0f;
    static GLfloat rotAngle = 0.0f;
    static GLfloat rAlpha = 0.0f;
	static GLfloat s = 1.0f;
	

    static bool bCircle = false;
    static bool bEye = false;
    static bool bRotate = true;

    float radius = 0.0f;

    //code
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  
    glTranslatef(Tx, Ty, -10.0f);
    glRotatef(rotAngle, 0.0f, 1.0f, 0.0f);

    //triangle
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 1.2f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.15f, -1.09f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(-1.15f, -1.09f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.15f, -1.09f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glVertex3f(1.15f, -1.09f, 0.0f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.2f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    

    //circle
    if(bCircle)
    {
        glDisable(GL_DEPTH_TEST);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(Cx, Cy, -10.0f);
        glRotatef(rotAngle, 0.0f, 1.0f, 0.0f);

        radius = 0.68f;
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
    
            for(float angle = 0.0f; angle < 2 * M_PI; angle += (M_PI / 18.0f))
            {
                float x = radius * cos(angle);
                float y = radius * sin(angle);

                glVertex3f(x, y, 0.0f);
            }
        glEnd();

        radius = 0.62f;
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
    
            for(float angle = 0.0f; angle < 2 * M_PI; angle += (M_PI / 18.0f))
            {
                float x = radius * cos(angle);
                float y = radius * sin(angle);

                glVertex3f(x, y, 0.0f);
            }
        glEnd();
    
        glEnable(GL_DEPTH_TEST);
    }

    //R starts here
    //eyebrow
	glDisable(GL_DEPTH_TEST);
	static GLfloat index = 0.0f;
	static GLfloat Ex = 0.0f;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, Ey, -10.0f);
    glRotatef(rotAngle, 0.0f, 1.0f, 0.0f);	

	glScalef(s, s, s);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(-0.1f, 0.1f, 0.0f);
        glVertex3f(-0.48f, -0.03f, 0.0f);
        glVertex3f(-0.45f, -0.09f, 0.0f);
        glVertex3f(-0.1f, 0.03f, 0.0f);

        glVertex3f(-0.1f, 0.1f, 0.0f);
        glVertex3f(-0.1f, 0.03f, 0.0f);
        glVertex3f(0.1f, 0.03f, 0.0f);
        glVertex3f(0.1f, 0.1f, 0.0f);

        glVertex3f(0.1f, 0.1f, 0.0f);
        glVertex3f(0.48f, -0.03f, 0.0f);
        glVertex3f(0.45f, -0.09f, 0.0f);
        glVertex3f(0.1f, 0.03f, 0.0f);
    glEnd();

    //eye
    glTranslatef(0.0f, -0.15f, 0.0f);

    glBegin(GL_QUADS);
        glVertex3f(-0.1f, 0.1f, 0.0f);
        glVertex3f(-0.48f, -0.03f, 0.0f);
        glVertex3f(-0.45f, -0.09f, 0.0f);
        glVertex3f(-0.1f, 0.03f, 0.0f);

        glVertex3f(-0.1f, 0.1f, 0.0f);
        glVertex3f(-0.1f, 0.03f, 0.0f);
        glVertex3f(0.1f, 0.03f, 0.0f);
        glVertex3f(0.1f, 0.1f, 0.0f);

        glVertex3f(0.1f, 0.1f, 0.0f);
        glVertex3f(0.48f, -0.03f, 0.0f);
        glVertex3f(0.45f, -0.09f, 0.0f);
        glVertex3f(0.1f, 0.03f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-0.15f, -0.18f, 0.0f);
        glVertex3f(-0.48f, -0.03f, 0.0f);
        glVertex3f(-0.46f, -0.11f, 0.0f);
        glVertex3f(-0.15f, -0.25f, 0.0f);

        glVertex3f(-0.15f, -0.18f, 0.0f);
        glVertex3f(-0.15f, -0.25f, 0.0f);
        glVertex3f(0.05f, -0.25f, 0.0f);
        glVertex3f(0.05f, -0.18f, 0.0f);

        glVertex3f(0.05f, -0.18f, 0.0f);
        glVertex3f(0.48f, -0.03f, 0.0f);
        glVertex3f(0.46f, -0.11f, 0.0f);
        glVertex3f(0.05f, -0.25f, 0.0f);
    glEnd();

    //eyeball
    //glDisable(GL_DEPTH_TEST);
    
    glTranslatef(0.0f, -0.01f, 0.0f);
    radius = 0.11f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, 0.0f, 0.0f);
    
        for(float angle = 0.0f; angle < 2 * M_PI; angle += (M_PI / 18.0f))
        {
            float x = radius * cos(angle);
            float y = radius * sin(angle);

            glVertex3f(x, y, 0.0f);
        }
    glEnd();

    radius = 0.07f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
    
        for(float angle = 0.0f; angle < 2 * M_PI; angle += (M_PI / 18.0f))
        {
            float x = radius * cos(angle);
            float y = radius * sin(angle);

            glVertex3f(x, y, 0.0f);
        }
    glEnd();

    //glEnable(GL_DEPTH_TEST);

    glTranslatef(0.04f, 0.01f, 0.0f);
    //R lines
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-0.465f, -0.1f, 0.0f);
        glVertex3f(0.25f, -0.64f, 0.0f);
        glVertex3f(0.35f, -0.66f, 0.0f);
        glVertex3f(-0.15f, -0.25f, 0.0f);

        glVertex3f(-0.25f, -0.7f, 0.0f);
        glVertex3f(-0.22f, -0.7f, 0.0f);
        glVertex3f(-0.25f, -0.4f, 0.0f);
        glVertex3f(-0.35f, -0.4f, 0.0f);
        
        glVertex3f(-0.35f, -0.4f, 0.0f);
        glVertex3f(-0.25f, -0.4f, 0.0f);
        glVertex3f(-0.25f, -0.2f, 0.0f);
        glVertex3f(-0.33f, -0.2f, 0.0f);
    glEnd();
    //R ends here

    //update
    //triangle animation
    if(Tx < 0.0f)
    {
        Tx += 0.0001f * triangle_speed;
        Ty += 0.0001f * triangle_speed;
    }
    else    
        bCircle = true;

    if(bRotate)
    {
        rotAngle += 0.07f * rotation_speed;
        if(rotAngle >= 360.0f)
            rotAngle = 0.0f;
    }
    else
    {
        if(rotAngle < 360.0f)
            rotAngle += 0.07f * rotation_speed;
    }

    //circle animation
    if(bCircle)
    {
        if(Cx > 0.0f)
            Cx -= 0.0001f * circle_speed;
    
        if(Cy < -0.35f)
            Cy += 0.0001f * circle_speed;
        else
            bEye = true;
    }

    if(bEye)
    {
        if(Ey >= 0.0f)
            Ey -= 0.0001f * r_speed;
        else
            bRotate = false;
    }
	
	if (bRotate == false)
	{
		render_group_render_start = true;

		if (index <= 1.0f)
		{}
	
		else if (index <= 6.0f)
		{	
			s += 0.001 * LOGOSCALESPEED;
		}
		else if (index <= 11.0f)
		{
			s -= 0.001f* LOGOSCALESPEED;
		}
		else if (index <= 16.0f)
		{
			s += 0.001f* LOGOSCALESPEED;
		}
		else if (index <= 21.0f)
		{
			if ((Ex > -9.0f) && (Ey < 2.0f))
			{	
			//	glTranslatef(Ex, Ey, -10.0f);
			//	Ex -= 0.01f;
			//	Ey += 0.0026f;
				s -= 0.001f* LOGOSCALESPEED;
			}
		}	
		else if (index <= 22.0f)
		{
			s = 1.0f;
			gray += 0.001f;
		}
		else if (index >= 22.0f)
		{
			//Ex = 0.0f;
			//Ey = 0.0f;
			//glTranslatef(Ex, Ey, -10.0f);
			bRotate = true;
		}

/* astromedicomp */		

		if ((index >= 22.1f) && (ax >= -6.0f))
		{
			if (ax >= -6.0f)
			{
				ax -= 0.001f*ASTROMEDICOMPSPEED;
			}	
			if (ay >= -3.0f)
			{
				ay -= 0.001f*ASTROMEDICOMPSPEED;
			}
			if (px <= 6.0f)
			{
				px += 0.001f*ASTROMEDICOMPSPEED;
			}
			if (py >= -3.0f)
			{
				py -= 0.001f*ASTROMEDICOMPSPEED;
			}
			ag += 0.1f;
			pg += 0.1f;
		}
		else if ((index >= 22.1f) && (dy >= -3.0f))
		{
			if (dx <= 1.0f)
			{
				dx += 0.001f*ASTROMEDICOMPSPEED;
			}	
			if (dy >= -3.0f)
			{
				dy -= 0.001f*ASTROMEDICOMPSPEED;
			}
			dg += 0.1f;
		}	
		else if ((index >= 22.6f) && (o2x <= 4.0f))
		{
			if (o1x >= -2.0f)
			{
				o1x -= 0.001f*ASTROMEDICOMPSPEED;
			}	
			if (o1y >= -3.0f)
			{
				o1y -= 0.001f*ASTROMEDICOMPSPEED;
			}
			if (o2x <= 4.0f)
			{
				o2x += 0.001f*ASTROMEDICOMPSPEED;
			}	
			if (o2y >= -3.0f)
			{
				o2y -= 0.001f*ASTROMEDICOMPSPEED;
			}
			o1g += 0.1f;
			o2g += 0.1f;
		}
		else if ((index >= 30.0f) && (rx >= -3.0f))
		{
			if (rx >= -3.0f)
			{
				rx -= 0.001f*ASTROMEDICOMPSPEED;
			}	
			if (ry >= -3.0f)
			{
				ry -= 0.001f*ASTROMEDICOMPSPEED;
			}		
			if (ey >= -3.0f)
			{
				ey -= 0.001f*ASTROMEDICOMPSPEED;
			}
			rg += 0.1f;
			eg += 0.1f;
		}	
		else if ((index >= 23.3f) && (sx >= -5.0f))
		{
			if (sx >= -5.0f)
			{
				sx -= 0.0015f*ASTROMEDICOMPSPEED;
			}	
			if (sy >= -3.0f)
			{
				sy -= 0.001f*ASTROMEDICOMPSPEED;
			}
			if (cx <= 3.0f)
			{
				cx += 0.001f*ASTROMEDICOMPSPEED;
			}	
			if (cy >= -3.0f)
			{
				cy -= 0.001f*ASTROMEDICOMPSPEED;
			}	
			sg += 0.1f;
			cg += 0.1f;
		}
		else if ((index >= 23.35f) && (m2x <= 4.8f))
		{
			if (m2x <= 4.8f)
			{
				m2x += 0.0015f*ASTROMEDICOMPSPEED;
			}	
			if (m2y >= -3.0f)
			{
				m2y -= 0.001f*ASTROMEDICOMPSPEED;
			}
			if (m1x >= -1.2f)
			{
				m1x -= 0.001f*ASTROMEDICOMPSPEED;
			}	
			if (m1y >= -3.0f)
			{
				m1y -= 0.001f*ASTROMEDICOMPSPEED;
			}
			m1g += 0.1f;
			m2g += 0.1f;
		}
		else if ((index >= 26.0f) && (tx >= -4.0f))
		{
			if (tx >= -4.0f)
			{
				tx -= 0.001f*ASTROMEDICOMPSPEED;
			}
			if (tx <= -3.9f)
			{
				//bScene1End = 1;
				bScene1Transition = 1;
			}	
			if (ty >= -3.0f)
			{
				ty -= 0.001f*ASTROMEDICOMPSPEED;
			}
			if (ix <= 2.1f)
			{
				ix += 0.0015f*ASTROMEDICOMPSPEED;
			}	
			if (iy >= -3.0f)
			{
				iy -= 0.001f*ASTROMEDICOMPSPEED;
			}
			tg += 0.1f;
			ig += 0.1f;
			//fprintf(gpFile, "tg : %f, ig : %f\n", tg, ig);
		}		
	//	index += 0.01f;
		index += 0.001f * LOGOSTARTSCALINGTIME;
	}	
}

/* ************************************************** RENDER GROUP RENDER START ******************************************** */
void render_group_render(void)
{
	void Draw_R(GLfloat x, GLfloat y, GLfloat z);
	void Draw_E(GLfloat x, GLfloat y, GLfloat z);
	void Draw_N(GLfloat x, GLfloat y, GLfloat z);
	void Draw_D(GLfloat x, GLfloat y, GLfloat z);
	void Draw_G(GLfloat x, GLfloat y, GLfloat z);
	void Draw_O(GLfloat x, GLfloat y, GLfloat z);
	void Draw_U(GLfloat x, GLfloat y, GLfloat z);
	void Draw_P(GLfloat x, GLfloat y, GLfloat z);
	void Draw_S(GLfloat x, GLfloat y, GLfloat z);
	DWORD WINAPI Thread_Scene1Logo(LPVOID Param);

	HANDLE hTHread12 = NULL;
	static int songflag = 0;

	if(songflag == 0)
    {
        hTHread12 =  CreateThread(NULL, 0, Thread_Scene1Logo, (LPVOID)ghwnd, 0, NULL);
        songflag = 1;
    }

	if(render_group_render_start == false)
		return;
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Draw_R(-1.0f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_E(-1.0f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_N(-1.0f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_D(-1.0f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_E(0.0f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_R(0.7f, 1.0f, 0.0f);
	
	glLoadIdentity();
	Draw_G(-0.6f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_R(1.95f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_O(-0.6f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_U(-0.6f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_P(-0.6f, 1.0f, 0.0f);
	
	glLoadIdentity();
	Draw_R(3.7f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_E(3.7f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_N(3.7f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_D(3.7f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_E(4.7f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_R(5.4f, 1.0f, 0.0f);
	glLoadIdentity();
	Draw_S(7.7f, 3.0f, -14.0f);
}

void Draw_R(GLfloat x, GLfloat y, GLfloat z) 
{
    
	// R Letter radius
	GLfloat innercircle_radius_1 = 0.1f;
	GLfloat outercircle_radius_1 = 0.135f;
	GLfloat innercircle_radius_2 = 0.13f;
	GLfloat outercircle_radius_2 = 0.165f;
	GLfloat r = 0.05f;

    i += 0.001f;
	glTranslatef(x, y, z);
	// R Letter starts
	glTranslatef(0.0f, 0.0f, -6.0f); // 4th change
	//glScalef(0.5f, 0.5f,0.5f);
	glBegin(GL_QUADS);
	//glColor4f(1.0f, 1.0f, 1.0f, gray);
    glColor3f(sin(i), cos(i), 0.5f);
	glVertex3f(-2.5f, 0.5f, 0.0f);
	glVertex3f(-2.55f, 0.5f, 0.0f);
	glVertex3f(-2.55f, 0.15f, 0.0f);
	glVertex3f(-2.5f, 0.1f, 0.0f);

	glVertex3f(-2.55f, 0.5f, 0.0f);
	glVertex3f(-2.6f, 0.5f, 0.0f);
	glVertex3f(-2.57f, 0.45f, 0.0f);
	glVertex3f(-2.55f, 0.45f, 0.0f);
	glEnd();

	glTranslatef(-2.5f, 0.4f, 0.0f);

	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1 = angle_1 + 1.0f)
	{
		if (angle_1 >= 270.0f && angle_1 <= 450.0f)
		{
			glVertex3f(cos(Radian(angle_1)) * (innercircle_radius_1 + 0.05f), sin(Radian(angle_1)) * innercircle_radius_1 - 0.03f, 0.0f);
			glVertex3f(cos(Radian(angle_1)) * (outercircle_radius_1 + 0.05f), sin(Radian(angle_1)) * outercircle_radius_1 - 0.031f, 0.0f);
		}
	}
	glEnd();

	glLoadIdentity();
	glTranslatef(x, y, z);
	glTranslatef(-2.355f, 0.28f, -6.0f);
	glRotatef(104.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 360.0f; angle_1 = angle_1 + 1.0f)
	{
		if (angle_1 >= 90.0f && angle_1 <= 180.0f)
		{
			glVertex3f(cos(Radian(angle_1)) * (innercircle_radius_2 + r + 0.03f), sin(Radian(angle_1)) * innercircle_radius_2 - 0.03f, 0.0f);
			glVertex3f(cos(Radian(angle_1)) * (outercircle_radius_2 + 0.08f), sin(Radian(angle_1)) * outercircle_radius_2 - 0.03f, 0.0f);

			if (innercircle_radius_2 + r < (outercircle_radius_2 + 0.05f))
			{
				r += 0.002f;
			}
		}
	}
	glEnd();
}

void Draw_E(GLfloat x, GLfloat y, GLfloat z) 
{
    glColor3f(sin(i+30), cos(i+30), 0.5f);
	glTranslatef(x, y, z);
	glTranslatef(0.0f, 0.0f, -6.0f);
	//glScalef(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-2.15f, 0.5f, 0.0f);
	glVertex3f(-2.2f, 0.5f, 0.0f);
	glVertex3f(-2.2f, 0.15f, 0.0f);
	glVertex3f(-2.15f, 0.1f, 0.0f);

	glVertex3f(-2.2f, 0.5f, 0.0f);
	glVertex3f(-2.25f, 0.5f, 0.0f);
	glVertex3f(-2.23f, 0.45f, 0.0f);
	glVertex3f(-2.2f, 0.45f, 0.0f);

	//'E' Letter First Line
	glVertex3f(-2.0f, 0.5f, 0.0f);
	glVertex3f(-2.15f, 0.5f, 0.0f);
	glVertex3f(-2.15f, 0.45f, 0.0f);
	glVertex3f(-1.95f, 0.45f, 0.0f);

	//'E' Letter Middle Line
	glVertex3f(-2.05f, 0.35f, 0.0f);
	glVertex3f(-2.15f, 0.35f, 0.0f);
	glVertex3f(-2.15f, 0.3f, 0.0f);
	glVertex3f(-2.0f, 0.3f, 0.0f);

	//'E' Letter Last Line
	glVertex3f(-2.0f, 0.15f, 0.0f);
	glVertex3f(-2.15f, 0.15f, 0.0f);
	glVertex3f(-2.15f, 0.1f, 0.0f);
	glVertex3f(-1.95f, 0.1f, 0.0f);
	glEnd();
	// E Letter Ends---------------------------------------------------------------------
}

void Draw_N(GLfloat x, GLfloat y, GLfloat z)
{
	// N Letter Starts
	glColor3f(sin(i+45), cos(i+45), 0.1f);
	glTranslatef(x, y, z);
	glTranslatef(0.0f, 0.0f, -6.0f);
	//glScalef(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-1.8f, 0.5f, 0.0f);
	glVertex3f(-1.85f, 0.5f, 0.0f);
	glVertex3f(-1.85f, 0.15f, 0.0f);
	glVertex3f(-1.8f, 0.1f, 0.0f);

	//Middle N letter line
	glVertex3f(-1.8f, 0.5f, 0.0f);
	glVertex3f(-1.83f, 0.5f, 0.0f);
	glVertex3f(-1.63f, 0.2f, 0.0f);
	glVertex3f(-1.6f, 0.2f, 0.0f);

	glVertex3f(-1.6f, 0.5f, 0.0f);
	glVertex3f(-1.65f, 0.5f, 0.0f);
	glVertex3f(-1.65f, 0.15f, 0.0f);
	glVertex3f(-1.6f, 0.1f, 0.0f);

	// First Quad
	glVertex3f(-1.85f, 0.5f, 0.0f);
	glVertex3f(-1.9f, 0.5f, 0.0f);
	glVertex3f(-1.87f, 0.45f, 0.0f);
	glVertex3f(-1.85f, 0.45f, 0.0f);

	//Second Quad
	glVertex3f(-1.65f, 0.5f, 0.0f);
	glVertex3f(-1.7f, 0.5f, 0.0f);
	glVertex3f(-1.67f, 0.45f, 0.0f);
	glVertex3f(-1.65f, 0.45f, 0.0f);
	glEnd();
	// N Letter Ends-------------------------------------------------------------------------
}

void Draw_D(GLfloat x, GLfloat y, GLfloat z)
{
    glColor3f( cos(i+60), sin(i+60),0.3f);
	// D Letter radius
	GLfloat d_innercircleradius_1 = 0.3f;
	GLfloat d_outercircleradius_2 = 0.4f;

	// D Letter Starts
	
	glTranslatef(x,y,z);
	glTranslatef(0.0f, 0.0f, -6.0f);
	//glScalef(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-1.45f, 0.5f, 0.0f);
	glVertex3f(-1.5f, 0.5f, 0.0f);
	glVertex3f(-1.5f, 0.15f, 0.0f);
	glVertex3f(-1.45f, 0.1f, 0.0f);

	glVertex3f(-1.5f, 0.5f, 0.0f);
	glVertex3f(-1.55f, 0.5f, 0.0f);
	glVertex3f(-1.53f, 0.45f, 0.0f);
	glVertex3f(-1.5f, 0.45f, 0.0f);
	glEnd();

	glTranslatef(x, y, z);
	glTranslatef(-2.899f, 0.6f, -6.0f);

	glBegin(GL_LINES);
	for (float angle_2 = 0.0f; angle_2 <= 450.0f; angle_2 = angle_2 + 1.0f)
	{
		if (angle_2 >= 270.0f && angle_2 <= 450.0f)
		{
			glVertex3f(cos(Radian(angle_2)) * d_innercircleradius_1, sin(Radian(angle_2)) * d_innercircleradius_1, 0.0f);
			glVertex3f(cos(Radian(angle_2)) * d_outercircleradius_2, sin(Radian(angle_2)) * d_outercircleradius_2, 0.0f);
		}
	}
	glEnd();
}

void Draw_G(GLfloat x, GLfloat y, GLfloat z)
{
    glColor3f( tan(i+60), 0.5, sin(i));
	// G Letter Radius 
	GLfloat g_innercircleradius_1 = 0.15f;
	GLfloat g_outercircleradius_1 = 0.15f;
	GLfloat r = 0.05f;

	// G Letter Starts Here 
	glTranslatef(x, y, z);
	glTranslatef(-0.18f, 0.30f, -6.0f);
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 290.0f; angle_1 = angle_1 + 1.0f)
	{
		if (angle_1 >= 60.0f && angle_1 <= 290.0f)
		{
			if (angle_1 <= 85.0f && g_outercircleradius_1 < 0.2f)
			{
				glVertex3f(cos(Radian(angle_1)) * (g_innercircleradius_1), sin(Radian(angle_1)) * g_innercircleradius_1, 0.0f);
				glVertex3f(cos(Radian(angle_1)) * (g_outercircleradius_1), sin(Radian(angle_1)) * g_outercircleradius_1, 0.0f);
				g_outercircleradius_1 += 0.0025f;
			}
			else if (angle_1 >= 270.0f && g_outercircleradius_1 > 0.21f)
			{

				glVertex3f(cos(Radian(angle_1)) * g_innercircleradius_1, sin(Radian(angle_1)) * g_innercircleradius_1, 0.0f);
				glVertex3f(cos(Radian(angle_1)) * g_outercircleradius_1, sin(Radian(angle_1)) * g_outercircleradius_1, 0.0f);
				g_outercircleradius_1 -= 0.001f;
				g_innercircleradius_1 += 0.001f;
			}
			else
			{
				g_outercircleradius_1 = 0.2f;
				glVertex3f(cos(Radian(angle_1)) * g_innercircleradius_1, sin(Radian(angle_1)) * g_innercircleradius_1, 0.0f);
				glVertex3f(cos(Radian(angle_1)) * g_outercircleradius_1, sin(Radian(angle_1)) * g_outercircleradius_1, 0.0f);
			}
		}
	}
	glEnd();

	// G letter back Quad
	glBegin(GL_QUADS);
	glVertex3f(0.02f, 0.20f, 0.0f);
	glVertex3f(-0.22f, 0.20f, 0.0f);
	glVertex3f(-0.19f, 0.15f, 0.0f);
	glVertex3f(-0.1f, 0.15f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(x, y, z);
	glTranslatef(0.02f, 0.28f, -6.0f);

	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 360.0f; angle_1 = angle_1 + 0.5f)
	{
		if (angle_1 >= 90.0f && angle_1 <= 180.0f)
		{
			glVertex3f(cos(Radian(angle_1)) * (g_innercircleradius_1 + r + 0.03f), sin(Radian(angle_1)) * g_innercircleradius_1 - 0.03f, 0.0f);
			glVertex3f(cos(Radian(angle_1)) * (g_outercircleradius_1 + 0.08f), sin(Radian(angle_1)) * g_outercircleradius_1 - 0.03f, 0.0f);

			if (g_innercircleradius_1 + r < (g_outercircleradius_1 + 0.05f))
			{
				r += 0.0005f;
			}
		}
	}
	glEnd();

	glLoadIdentity();
	glTranslatef(x, y, z);
	glTranslatef(-0.18f, 0.30f, -6.0f);

	glBegin(GL_QUADS);

	glVertex3f(0.08f, 0.03f, 0.0f);
	glVertex3f(-0.06f, 0.03f, 0.0f);
	glVertex3f(-0.03f, -0.02f, 0.0f);
	glVertex3f(0.08f, -0.02f, 0.0f);
	glEnd();
	// G letter ends-------------------------------------------------------------------------------------------------------------------
}

void Draw_O(GLfloat x, GLfloat y, GLfloat z)
{
    glColor3f( 0.6f, cos(i), sin(i));
	// O Letter Radius
	GLfloat o_innercircleradius_1 = 0.1f;
	GLfloat o_outercircleradius_2 = 0.144f;

	// O letter starts ------------------------------------------------------------------------------------------------------------------------
	
	glTranslatef(x, y, z);
	glTranslatef(0.45f, 0.28f, -6.0f);
	//glScalef(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 360.0f; angle_1 = angle_1 + 0.5f)
	{
		glVertex3f(cos(Radian(angle_1)) * (o_innercircleradius_1 + 0.02f), sin(Radian(angle_1)) * (o_innercircleradius_1 + 0.07f), 0.0f);
		glVertex3f(cos(Radian(angle_1)) * (o_outercircleradius_2 + 0.02f), sin(Radian(angle_1)) * (o_outercircleradius_2 + 0.07f), 0.0f);

	}
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.05f, 0.21f, 0.0f);
	glVertex3f(-0.20f, 0.21f, 0.0f);
	glVertex3f(-0.17f, 0.15f, 0.0f);
	glVertex3f(-0.1f, 0.15f, 0.0f);
	glEnd();

	// O Letter Ends---------------------------------------------------------------------------------------------------------------------------
}

void Draw_U(GLfloat x, GLfloat y, GLfloat z)
{
    glColor3f( sin(i+30), cos(i), sin(i+45));
	GLfloat u_innerradius_1 = 0.1f;
	GLfloat u_outerradius_1 = 0.144;
	// U Letter Starts------------------------------------------------------------------------------------------------------------------------
	
	glTranslatef(x, y, z);
	glTranslatef(0.85f, 0.28f, -6.0f);
	//glScalef(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	for (float angle_1 = 180.0f; angle_1 <= 360.0f; angle_1 = angle_1 + 0.5f)
	{
		glVertex3f(cos(Radian(angle_1)) * (u_innerradius_1 + 0.02f), sin(Radian(angle_1)) * (u_innerradius_1 + 0.07f), 0.0f);
		glVertex3f(cos(Radian(angle_1)) * (u_outerradius_1 + 0.02f), sin(Radian(angle_1)) * (u_outerradius_1 + 0.07f), 0.0f);
	}
	glEnd();

	glBegin(GL_QUADS);
	// First Quad 180.0f
	glVertex3f(-0.115f, 0.18f, 0.0f);
	glVertex3f(-0.165f, 0.18f, 0.0f);
	glVertex3f(-0.165f, 0.0f, 0.0f);
	glVertex3f(-0.115f, 0.0f, 0.0f);

	//first Upper Quad
	glVertex3f(-0.115f, 0.22f, 0.0f);
	glVertex3f(-0.22f, 0.22f, 0.0f);
	glVertex3f(-0.19f, 0.17f, 0.0f);
	glVertex3f(-0.115f, 0.17f, 0.0f);

	//Second Quads above 360.0f
	glVertex3f(0.165f, 0.18f, 0.0f);
	glVertex3f(0.115f, 0.18f, 0.0f);
	glVertex3f(0.115f, -0.16f, 0.0f);
	glVertex3f(0.165f, -0.22f, 0.0f);

	// Second Upper Quads
	glVertex3f(0.165f, 0.22f, 0.0f);
	glVertex3f(0.06f, 0.22f, 0.0f);
	glVertex3f(0.09f, 0.17f, 0.0f);
	glVertex3f(0.165f, 0.17f, 0.0f);
	glEnd();
	//U Letter Ends Here----------------------------------------------------------------------------------------------------
}

void Draw_P(GLfloat x, GLfloat y, GLfloat z)
{

    glColor3f( cos(i+30), cos(i+10), sin(i+45));
	GLfloat innercircle_radius_1 = 0.1f;
	GLfloat outercircle_radius_1 = 0.135f;

	GLfloat innercircle_radius_2 = 0.13f;
	GLfloat outercircle_radius_2 = 0.165f;

	GLfloat r = 0.05f;
	// P Letter Starts From here--------------------------------------------------------------------------------------------------------------
	
	glTranslatef(x, y, z);
	glTranslatef(1.95f, 0.0f, -6.0f); // 4th change
	//glScalef(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);

	glVertex3f(-0.8f, 0.5f, 0.0f);
	glVertex3f(-0.85f, 0.5f, 0.0f);
	glVertex3f(-0.85f, 0.15f, 0.0f);
	glVertex3f(-0.8f, 0.1f, 0.0f);

	glVertex3f(-0.85f, 0.5f, 0.0f);
	glVertex3f(-0.9f, 0.5f, 0.0f);
	glVertex3f(-0.87f, 0.45f, 0.0f);
	glVertex3f(-0.85f, 0.45f, 0.0f);
	glEnd();

	glTranslatef(-0.8f, 0.4f, 0.0f);

	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1 = angle_1 + 1.0f)
	{
		if (angle_1 >= 270.0f && angle_1 <= 450.0f)
		{
			glVertex3f(cos(Radian(angle_1)) * (innercircle_radius_1 + 0.05f), sin(Radian(angle_1)) * innercircle_radius_1 - 0.03f, 0.0f);
			glVertex3f(cos(Radian(angle_1)) * (outercircle_radius_1 + 0.05f), sin(Radian(angle_1)) * outercircle_radius_1 - 0.031f, 0.0f);
		}
	}
	glEnd();

	// P lette Ends Here----------------------------------------------------------------------------------------------------------------------
}

void Draw_S(GLfloat x, GLfloat y, GLfloat z)
{
	/* SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS */	
	GLfloat innercircle_radius_1 = 0.2f;
	GLfloat outercircle_radius_1 = 0.3f;	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(x, y, z);
//	glTranslatef(.0f, -3.0f, -12.0f);
	
	glBegin(GL_QUADS);
		glVertex3f(0.1f, 0.5f, 0.0f);
		glVertex3f(-0.4f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.4f, 0.0f);
		glVertex3f(0.1f, 0.4f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 55.0f && angle_1 <= 270.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_1) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_1) + 0.20f, 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_1) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_1) + 0.20f, 0.0f);
		}
	}
	glEnd();
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 220.0f && angle_1 <= 450.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_1) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_1) + (-0.30f), 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_1) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_1) + (-0.30f), 0.0f);
		}
	}
	glEnd();
}
/* ************************************************** RENDER GROUP RENDER END ******************************************** */
/* **************************************************** ASTROMEDICOMP START ********************************************** */
void astromedicomp_print(void)
{
	float Radian(float);

    glColor3f(218/255,165/255,32/255);
/*
	static float ax = 0.0f, az = 0.0f, sx = 0.0f, sz = 0.0f, tx = 0.0f, index = 0.0f;
	static float tz = 0.0f, rx = 0.0f, rz = 0.0f, o1x = 0.0f, o1z = 0.0f; 
	static float m1x = 0.0f, m1z = 0.0f, ex = 0.0f, ez = 0.0f, dx = 0.0f;
	static float dz = 0.0f, ix = 0.0f, iz = 0.0f, cx = 0.0f, cz = 0.0f; 
	static float o2x = 0.0f, m2x = 0.0f, m2z = 0.0f, px = 0.0f, pz = 0.0f; 
	static float ay = 0.0f, sy = 0.0f, ty = 0.0f, ry = 0.0f, o1y = 0.0f;
	static float m1y = 0.0f, ey = 0.0f, dy = 0.0f, iy = 0.0f, cy = 0.0f, o2y = 0.0f, m2y = 0.0f, py = 0.0f;
	static float ag = 0.0f, sg = 0.0f, tg = 0.0f, m1g = 0.0f, eg = 0.0f, o1g = 0.0f, rg = 0.0f, dg = 0.0f, ig = 0.0f, cg = 0.0f, o2g = 0.0f, m2g = 0.0f, pg = 0.0f; 
*/
/*	
	if (index < 100000.0f)
	{	
		if ((index >= 0.1f) && (ax >= -6.0f))
		{
			if (ax >= -6.0f)
			{
				ax -= 0.001f;
			}	
			if (ay >= -3.0f)
			{
				ay -= 0.001f;
			}
			if (px <= 6.0f)
			{
				px += 0.001f;
			}
			if (py >= -3.0f)
			{
				py -= 0.001f;
			}
			ag += 0.1f;
			pg += 0.1f;
		}
		else if ((index >= 1.0f) && (dy >= -3.0f))
		{
			if (dx <= 1.0f)
			{
				dx += 0.001f;
			}	
			if (dy >= -3.0f)
			{
				dy -= 0.001f;
			}
			dg += 0.1f;
		}	
		else if ((index >= 1.5f) && (o2x <= 4.0f))
		{
			if (o1x >= -2.0f)
			{
				o1x -= 0.001f;
			}	
			if (o1y >= -3.0f)
			{
				o1y -= 0.001f;
			}
			if (o2x <= 4.0f)
			{
				o2x += 0.001f;
			}	
			if (o2y >= -3.0f)
			{
				o2y -= 0.001f;
			}
			o1g += 0.1f;
			o2g += 0.1f;
		}
		else if ((index >= 100.0f) && (rx >= -3.0f))
		{
			if (rx >= -3.0f)
			{
				rx -= 0.001f;
			}	
			if (ry >= -3.0f)
			{
				ry -= 0.001f;
			}		
			if (ey >= -3.0f)
			{
				ey -= 0.001f;
			}
			rg += 0.1f;
			eg += 0.1f;
		}	
		else if ((index >= 1.3f) && (sx >= -5.0f))
		{
			if (sx >= -5.0f)
			{
				sx -= 0.0015f;
			}	
			if (sy >= -3.0f)
			{
				sy -= 0.001f;
			}
			if (cx <= 3.0f)
			{
				cx += 0.001f;
			}	
			if (cy >= -3.0f)
			{
				cy -= 0.001f;
			}	
			sg += 0.1f;
			cg += 0.1f;
		}
		else if ((index >= 1.35f) && (m2x <= 5.0f))
		{
			if (m2x <= 4.8f)
			{
				m2x += 0.0015f;
			}	
			if (m2y >= -3.0f)
			{
				m2y -= 0.001f;
			}
			if (m1x >= -1.2f)
			{
				m1x -= 0.001f;
			}	
			if (m1y >= -3.0f)
			{
				m1y -= 0.001f;
			}
			m1g += 0.1f;
			m2g += 0.1f;
		}
		else if (index >= 1.4f) 
		{
			if (tx >= -4.0f)
			{
				tx -= 0.001f;
			}	
			if (ty >= -3.0f)
			{
				ty -= 0.001f;
			}
			if (ix <= 2.0f)
			{
				ix += 0.0015f;
			}	
			if (iy >= -3.0f)
			{
				iy -= 0.001f;
			}
			tg += 0.1f;
			ig += 0.1f;
		}		
		index += 0.01f;
	}	
*/	
	/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(ax, ay, -10.f);	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, ag);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.4f, 0.0f);
		glVertex3f(0.0f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.4f, 0.0f);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.4f, -0.5f, 0.0f);
		glVertex3f(-0.3f, -0.6f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(0.0f, 0.4f, 0.0f);
		glVertex3f(0.4f, -0.6f, 0.0f);
		glVertex3f(0.43f, -0.6f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(0.15f, 0.05f, 0.0f);
		glVertex3f(-0.3f, 0.05f, 0.0f);
		glVertex3f(-0.2f, -0.05f, 0.0f);
		glVertex3f(0.2f, -0.05f, 0.0f);
	glEnd();
		
/* SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS */	
	GLfloat innercircle_radius_1 = 0.2f;
	GLfloat outercircle_radius_1 = 0.3f;	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(sx, sy, -10.0f);
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, sg);
		glVertex3f(0.1f, 0.5f, 0.0f);
		glVertex3f(-0.4f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.4f, 0.0f);
		glVertex3f(0.1f, 0.4f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 55.0f && angle_1 <= 270.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_1) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_1) + 0.20f, 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_1) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_1) + 0.20f, 0.0f);
		}
	}
	glEnd();
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 220.0f && angle_1 <= 450.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_1) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_1) + (-0.30f), 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_1) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_1) + (-0.30f), 0.0f);
		}
	}
	glEnd();

/* TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT */
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(tx, ty, -10.0f);
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, tg);
		glVertex3f(0.05f, 0.5f, 0.0f);
		glVertex3f(-0.05f, 0.5f, 0.0f);
		glVertex3f(-0.05f, -0.4f, 0.0f);
		glVertex3f(0.05f, -0.5f, 0.0f);
	glEnd();
		
	glBegin(GL_QUADS);
		glVertex3f(0.4f, 0.5f, 0.0f);
		glVertex3f(-0.4f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.4f, 0.0f);
		glVertex3f(0.4f, 0.4f, 0.0f);
	glEnd();		
	
/* RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR */	
	GLfloat innercircle_radius_4 = 0.2f;
	GLfloat outercircle_radius_4 = 0.3f;
	GLfloat r = 0.05f;
	glLoadIdentity();
	glTranslatef(rx, ry, -10.0f); 
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, rg);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.4f, 0.0f);
		glVertex3f(0.0f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.1f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 270.0f && angle_1 <= 450.0f) 
		{
			glVertex3f(cos(Radian(angle_1)) * (innercircle_radius_4), sin(Radian(angle_1)) * innercircle_radius_4 + 0.20f, 0.0f);
			glVertex3f(cos(Radian(angle_1)) * (outercircle_radius_4), sin(Radian(angle_1)) * outercircle_radius_4 + 0.20f, 0.0f);
		}
	}
	glEnd();

	glRotatef(110.0f,0.0f, 0.0f,1.0f);
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 360.0f; angle_1 = angle_1 + 1.0f)
	{
		if (angle_1 >= 90.0f && angle_1 <= 160.0f)
		{
			glVertex3f(cos(Radian(angle_1)) * (innercircle_radius_4 + r + 0.5f) , sin(Radian(angle_1)) * innercircle_radius_4 - 0.30f, 0.0f);
			glVertex3f(cos(Radian(angle_1)) * (outercircle_radius_4 + 0.5f), sin(Radian(angle_1)) * outercircle_radius_4 - 0.30f, 0.0f);
			
			if (innercircle_radius_4 + r < (outercircle_radius_4 + 0.05f))
			{
				r += 0.002f;
			}
		}
	}	
	glEnd(); 
		
/* OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO */
	GLfloat innercircle_radius_2 = 0.2f;
	GLfloat outercircle_radius_2 = 0.3f;	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(o1x, o1y, -10.0f);
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, o1g);
		glVertex3f(0.1f, 0.5f, 0.0f);
		glVertex3f(-0.4f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.4f, 0.0f);
		glVertex3f(0.1f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 180.0f && angle_1 <= 360.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_2) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_2) + -0.30f, 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_2) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_2) + -0.30f, 0.0f);
		}
	}
	glEnd();
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 0.0f && angle_1 <= 180.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_2) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_2) + 0.20f, 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_2) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_2) + 0.20f, 0.0f);
		}
	}
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(-0.15f, 0.2f, 0.0f);
		glVertex3f(-0.25f, 0.2f, 0.0f);
		glVertex3f(-0.25f, -0.3f, 0.0f);
		glVertex3f(-0.15f, -0.3f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.35f, 0.2f, 0.0f);
		glVertex3f(0.25f, 0.2f, 0.0f);
		glVertex3f(0.25f, -0.3f, 0.0f);
		glVertex3f(0.35f, -0.3f, 0.0f);
	glEnd();
	
/* MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(m1x, m1y, -10.0f);
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, m1g);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.4f, 0.0f);
		glVertex3f(0.0f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.1f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.04f, 0.5f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);
		glVertex3f(0.3f, 0.042f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.7f, 0.4f, 0.0f);
		glVertex3f(0.6f, 0.43f, 0.0f);
		glVertex3f(0.25f, 0.08f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.7f, 0.4f, 0.0f);
		glVertex3f(0.6f, 0.5f, 0.0f);
		glVertex3f(0.6f, -0.4f, 0.0f);
		glVertex3f(0.7f, -0.5f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.6f, 0.5f, 0.0f);
		glVertex3f(0.4f, 0.5f, 0.0f);
		glVertex3f(0.5f, 0.4f, 0.0f);
		glVertex3f(0.7f, 0.4f, 0.0f);
	glEnd();
	
/* EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE */

	glLoadIdentity();
	glTranslatef(ex, ey, -10.0f);
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, eg);
		glVertex3f(0.3f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.4f, 0.0f);
		glVertex3f(0.4f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.1f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.2f, 0.05f, 0.0f);
		glVertex3f(0.0f, 0.05f, 0.0f);
		glVertex3f(0.0f, -0.05f, 0.0f);
		glVertex3f(0.3f, -0.05f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.3f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
		glVertex3f(0.4f, -0.5f, 0.0f);
	glEnd();
	
/* DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD */
	GLfloat innercircle_radius_6 = 0.4f;
	GLfloat outercircle_radius_6 = 0.5f;
	glLoadIdentity();
	glTranslatef(dx, dy, -10.0f); // 4th change
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, dg);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.4f, 0.0f);
		glVertex3f(0.0f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.1f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 270.0f && angle_1 <= 450.0f) 
		{
			glVertex3f(cos(Radian(angle_1)) * (innercircle_radius_6), sin(Radian(angle_1)) * innercircle_radius_6, 0.0f);
			glVertex3f(cos(Radian(angle_1)) * (outercircle_radius_6), sin(Radian(angle_1)) * outercircle_radius_6, 0.0f);
		}
	}
	glEnd();	
		
/* IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII */	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(ix, iy, -10.0f);
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, ig);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.4f, 0.0f);
		glVertex3f(0.0f, 0.4f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.4f, 0.0f);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.1f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
	glEnd();
	
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
	GLfloat innercircle_radius_7 = 0.2f;
	GLfloat outercircle_radius_7 = 0.3f;	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(cx, cy, -10.0f);
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, cg);
		glVertex3f(0.1f, 0.5f, 0.0f);
		glVertex3f(-0.4f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.4f, 0.0f);
		glVertex3f(0.1f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 180.0f && angle_1 <= 360.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_7) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_7) + -0.30f, 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_7) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_7) + -0.30f, 0.0f);
		}
	}
	glEnd();
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 0.0f && angle_1 <= 180.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_7) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_7) + 0.20f, 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_7) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_7) + 0.20f, 0.0f);
		}
	}
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(-0.15f, 0.2f, 0.0f);
		glVertex3f(-0.25f, 0.2f, 0.0f);
		glVertex3f(-0.25f, -0.3f, 0.0f);
		glVertex3f(-0.15f, -0.3f, 0.0f);
	glEnd();

/* OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO */
	GLfloat innercircle_radius_8 = 0.2f;
	GLfloat outercircle_radius_8 = 0.3f;	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(o2x, o2y, -10.0f);
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, o2g);
		glVertex3f(0.1f, 0.5f, 0.0f);
		glVertex3f(-0.4f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.4f, 0.0f);
		glVertex3f(0.1f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 180.0f && angle_1 <= 360.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_8) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_8) + -0.30f, 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_8) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_8) + -0.30f, 0.0f);
		}
	}
	glEnd();
	
	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 0.0f && angle_1 <= 180.0f) 
		{
			glVertex3f((cos(Radian(angle_1)) * innercircle_radius_2) + 0.05f, (sin(Radian(angle_1)) * innercircle_radius_2) + 0.20f, 0.0f);
			glVertex3f((cos(Radian(angle_1)) * outercircle_radius_2) + 0.05f, (sin(Radian(angle_1)) * outercircle_radius_2) + 0.20f, 0.0f);
		}
	}
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(-0.15f, 0.2f, 0.0f);
		glVertex3f(-0.25f, 0.2f, 0.0f);
		glVertex3f(-0.25f, -0.3f, 0.0f);
		glVertex3f(-0.15f, -0.3f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.35f, 0.2f, 0.0f);
		glVertex3f(0.25f, 0.2f, 0.0f);
		glVertex3f(0.25f, -0.3f, 0.0f);
		glVertex3f(0.35f, -0.3f, 0.0f);
	glEnd();
		
/* MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(m2x, m2y, -10.0f);
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, m2g);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.4f, 0.0f);
		glVertex3f(0.0f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.1f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.04f, 0.5f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);
		glVertex3f(0.3f, 0.042f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.7f, 0.4f, 0.0f);
		glVertex3f(0.6f, 0.43f, 0.0f);
		glVertex3f(0.25f, 0.08f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.7f, 0.4f, 0.0f);
		glVertex3f(0.6f, 0.5f, 0.0f);
		glVertex3f(0.6f, -0.4f, 0.0f);
		glVertex3f(0.7f, -0.5f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.6f, 0.5f, 0.0f);
		glVertex3f(0.4f, 0.5f, 0.0f);
		glVertex3f(0.5f, 0.4f, 0.0f);
		glVertex3f(0.7f, 0.4f, 0.0f);
	glEnd();
		
/* PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP */	

	GLfloat innercircle_radius_5 = 0.2f;
	GLfloat outercircle_radius_5 = 0.3f;
	glLoadIdentity();
	glTranslatef(px, py, -10.0f); // 4th change
	
	glBegin(GL_QUADS);
		glColor4f(0.75f, 0.75f, 0.75f, pg);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.3f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.4f, 0.0f);
		glVertex3f(0.0f, 0.4f, 0.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(-0.1f, 0.5f, 0.0f);
		glVertex3f(-0.1f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	for (float angle_1 = 0.0f; angle_1 <= 450.0f; angle_1= angle_1 + 1.0f)
	{
		if (angle_1 >= 270.0f && angle_1 <= 450.0f) 
		{
			glVertex3f(cos(Radian(angle_1)) * (innercircle_radius_5), sin(Radian(angle_1)) * innercircle_radius_5 + 0.20f, 0.0f);
			glVertex3f(cos(Radian(angle_1)) * (outercircle_radius_5), sin(Radian(angle_1)) * outercircle_radius_5 + 0.20f, 0.0f);
		}
	}
	glEnd();
}
/* **************************************************** ASTROMEDICOMP END ************************************************ */

float Radian(float angle)
{
	return(angle * (M_PI / 180.0f));
}

void Scene1_transition_end(void) 
{
    //variable declaration
    static GLfloat alpha = 0.0f;
	static int frame_count = 0;

    //code
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -0.5f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
        glColor4f(0.0f, 0.0f, 0.0f, alpha);
        glVertex3f(2.0f, 2.0f, 0.0f);
        glVertex3f(-2.0f, 2.0f, 0.0f);
        glVertex3f(-2.0f, -2.0f, 0.0f);
        glVertex3f(2.0f, -2.0f, 0.0f);
    glEnd();

	frame_count++;

    //update 
    if(alpha < 1.0f)
        alpha += 0.0008f;
	
	if(frame_count == 1600)
	{
		frame_count = 0;
		bScene1End = 1;
	}
}
