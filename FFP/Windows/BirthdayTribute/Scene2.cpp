
#include "Scene2.h"

bool bScene2End = 0;
GLuint mouselist;

void Scene2_Initialize(void)
{
	// --- Setup Render Scene ---

	HFONT hfontAMS_Manthan, hfontBell_MT;
	GLYPHMETRICSFLOAT agmf[128];
	LOGFONT lfAMS_Manthan, lfBell_MT;

	//initialization of lfAMS_Manthan
	lfAMS_Manthan.lfHeight = -10.0f;
	lfAMS_Manthan.lfWidth = 0.0f;
	lfAMS_Manthan.lfEscapement = 0.0f;
	lfAMS_Manthan.lfOrientation = 0.0f;
	lfAMS_Manthan.lfWeight = FALSE;
	lfAMS_Manthan.lfItalic = FALSE;
	lfAMS_Manthan.lfUnderline = FALSE;
	lfAMS_Manthan.lfStrikeOut = FALSE;
	lfAMS_Manthan.lfCharSet = ANSI_CHARSET;
	lfAMS_Manthan.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfAMS_Manthan.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lfAMS_Manthan.lfQuality = DEFAULT_QUALITY;
	lfAMS_Manthan.lfPitchAndFamily = DEFAULT_PITCH;
	strcpy(lfAMS_Manthan.lfFaceName, "AMS Manthan");

	//create the font and display list
	hfontAMS_Manthan = CreateFontIndirect(&lfAMS_Manthan);
	SelectObject(ghdc, hfontAMS_Manthan);

	gliFontListMarathi = glGenLists(128);

	wglUseFontOutlines(ghdc, 0, 128, gliFontListMarathi, 0.0f, 0.0f, WGL_FONT_POLYGONS, agmf);

	DeleteObject(hfontAMS_Manthan);

	/*****************************************************/
	//initialization of lfBell_MT
	lfBell_MT.lfHeight = -10.0f;
	lfBell_MT.lfWidth = 0.0f;
	lfBell_MT.lfEscapement = 0.0f;
	lfBell_MT.lfOrientation = 0.0f;
	lfBell_MT.lfWeight = FALSE;
	lfBell_MT.lfItalic = FALSE;
	lfBell_MT.lfUnderline = FALSE;
	lfBell_MT.lfStrikeOut = FALSE;
	lfBell_MT.lfCharSet = ANSI_CHARSET;
	lfBell_MT.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfBell_MT.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lfBell_MT.lfQuality = DEFAULT_QUALITY;
	lfBell_MT.lfPitchAndFamily = DEFAULT_PITCH;
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

	float mousePts[219][2] =
	{
	   {345.0f   , -212.0f     },
	   {340.0f   , -213.0f     },
	   {335.0f   , -219.0f     },
	   {331.0f   , -223.0f     },
	   {326.0f   , -228.0f     },
	   {321.0f   , -231.0f     },
	   {321.0f   , -239.0f     },
	   {318.0f   , -244.0f     },
	   {316.0f   , -247.0f     },
	   {316.0f   , -253.0f     },
	   {319.0f   , -257.0f     },
	   {322.0f   , -263.0f     },
	   {325.0f   , -272.0f     },
	   {325.0f   , -272.0f     },
	   {329.0f   , -277.0f     },
	   {332.0f   , -282.0f     },
	   {337.0f   , -284.0f     },
	   {342.0f   , -289.0f     },
	   {346.0f   , -294.0f     },
	   {351.0f   , -297.0f     },
	   {357.0f   , -300.0f     },
	   {362.0f   , -304.0f     },
	   {366.0f   , -309.0f     },
	   {445.0f   , -358.0f     },
	   {405.0f   , -331.0f     },
	   {416.0f   , -339.0f     },
	   {424.0f   , -342.0f     },
	   {431.0f   , -351.0f     },
	   {373.0f   , -314.0f     },
	   {379.0f   , -316.0f     },
	   {387.0f   , -320.0f     },
	   {392.0f   , -326.0f     },
	   {454.0f   , -363.0f     },
	   {465.0f   , -371.0f     },
	   {473.0f   , -377.0f     },
	   {484.0f   , -378.0f     },
	   {495.0f   , -385.0f     },
	   {507.0f   , -390.0f     },
	   {515.0f   , -392.0f     },
	   {522.0f   , -395.0f     },
	   {535.0f   , -398.0f     },
	   {542.0f   , -398.0f     },
	   {549.0f   , -400.0f     },
	   {560.0f   , -401.0f     },
	   {327.0f   , -267.0f     },
	   {334.0f   , -272.0f     },
	   {340.0f   , -277.0f     },
	   {346.0f   , -279.0f     },
	   {352.0f   , -284.0f     },
	   {358.0f   , -287.0f     },
	   {364.0f   , -292.0f     },
	   {373.0f   , -294.0f     },
	   {383.0f   , -297.0f     },
	   {389.0f   , -302.0f     },
	   {395.0f   , -302.0f     },
	   {401.0f   , -304.0f     },
	   {408.0f   , -304.0f     },
	   {412.0f   , -308.0f     },
	   {417.0f   , -308.0f     },
	   {422.0f   , -309.0f     },
	   {429.0f   , -311.0f     },
	   {435.0f   , -313.0f     },
	   {440.0f   , -316.0f     },
	   {447.0f   , -316.0f     },
	   {457.0f   , -322.0f     },
	   {462.0f   , -324.0f     },
	   {468.0f   , -325.0f     },
	   {475.0f   , -330.0f     },
	   {479.0f   , -331.0f     },
	   {486.0f   , -336.0f     },
	   {490.0f   , -340.0f     },
	   {495.0f   , -342.0f     },
	   {501.0f   , -345.0f     },
	   {506.0f   , -351.0f     },
	   {511.0f   , -353.0f     },
	   {516.0f   , -358.0f     },
	   {520.0f   , -362.0f     },
	   {526.0f   , -366.0f     },
	   {527.0f   , -371.0f     },
	   {532.0f   , -374.0f     },
	   {538.0f   , -379.0f     },
	   {543.0f   , -383.0f     },
	   {549.0f   , -387.0f     },
	   {557.0f   , -390.0f     },
	   {562.0f   , -393.0f     },
	   {568.0f   , -390.0f     },
	   {572.0f   , -395.0f     },
	   {569.0f   , -399.0f     },
	   {580.0f   , -396.0f     },
	   {588.0f   , -396.0f     },
	   {594.0f   , -393.0f     },
	   {600.0f   , -389.0f     },
	   {606.0f   , -385.0f     },
	   {606.0f   , -385.0f     },
	   {611.0f   , -382.0f     },
	   {615.0f   , -378.0f     },
	   {618.0f   , -372.0f     },
	   {620.0f   , -366.0f     },
	   {623.0f   , -357.0f     },
	   {623.0f   , -351.0f     },
	   {625.0f   , -343.0f     },
	   {625.0f   , -341.0f     },
	   {625.0f   , -337.0f     },
	   {625.0f   , -331.0f     },
	   {623.0f   , -326.0f     },
	   {622.0f   , -321.0f     },
	   {620.0f   , -318.0f     },
	   {620.0f   , -310.0f     },
	   {618.0f   , -306.0f     },
	   {615.0f   , -297.0f     },
	   {612.0f   , -288.0f     },
	   {608.0f   , -282.0f     },
	   {604.0f   , -276.0f     },
	   {601.0f   , -267.0f     },
	   {595.0f   , -262.0f     },
	   {590.0f   , -257.0f     },
	   {585.0f   , -251.0f     },
	   {580.0f   , -247.0f     },
	   {573.0f   , -242.0f     },
	   {568.0f   , -236.0f     },
	   {562.0f   , -230.0f     },
	   {555.0f   , -229.0f     },
	   {549.0f   , -224.0f     },
	   {543.0f   , -220.0f     },
	   {535.0f   , -216.0f     },
	   {528.0f   , -213.0f     },
	   {522.0f   , -212.0f     },
	   {516.0f   , -209.0f     },
	   {511.0f   , -208.0f     },
	   {506.0f   , -205.0f     },
	   {499.0f   , -200.0f     },
	   {491.0f   , -200.0f     },
	   {485.0f   , -198.0f     },
	   {482.0f   , -196.0f     },
	   {477.0f   , -196.0f     },
	   {472.0f   , -196.0f     },
	   {467.0f   , -196.0f     },
	   {461.0f   , -194.0f     },
	   {454.0f   , -193.0f     },
	   {453.0f   , -196.0f     },
	   {452.0f   , -198.0f     },
	   {452.0f   , -202.0f     },
	   {452.0f   , -205.0f     },
	   {452.0f   , -209.0f     },
	   {452.0f   , -214.0f     },
	   {449.0f   , -215.0f     },
	   {448.0f   , -218.0f     },
	   {446.0f   , -218.0f     },
	   {445.0f   , -221.0f     },
	   {437.0f   , -224.0f     },
	   {436.0f   , -228.0f     },
	   {432.0f   , -228.0f     },
	   {427.0f   , -230.0f     },
	   {421.0f   , -232.0f     },
	   {419.0f   , -235.0f     },
	   {415.0f   , -236.0f     },
	   {412.0f   , -239.0f     },
	   {406.0f   , -244.0f     },
	   {403.0f   , -247.0f     },
	   {400.0f   , -247.0f     },
	   {398.0f   , -250.0f     },
	   {394.0f   , -252.0f     },
	   {393.0f   , -253.0f     },
	   {392.0f   , -257.0f     },
	   {387.0f   , -260.0f     },
	   {383.0f   , -265.0f     },
	   {379.0f   , -268.0f     },
	   {376.0f   , -274.0f     },
	   {373.0f   , -278.0f     },
	   {371.0f   , -282.0f     },
	   {368.0f   , -284.0f     },
	   {435.0f   , -220.0f     },
	   {431.0f   , -219.0f     },
	   {427.0f   , -219.0f     },
	   {425.0f   , -218.0f     },
	   {422.0f   , -213.0f     },
	   {420.0f   , -208.0f     },
	   {411.0f   , -203.0f     },
	   {406.0f   , -202.0f     },
	   {400.0f   , -200.0f     },
	   {394.0f   , -200.0f     },
	   {389.0f   , -199.0f     },
	   {383.0f   , -200.0f     },
	   {382.0f   , -203.0f     },
	   {379.0f   , -203.0f     },
	   {376.0f   , -205.0f     },
	   {371.0f   , -203.0f     },
	   {364.0f   , -203.0f     },
	   {363.0f   , -199.0f     },
	   {372.0f   , -197.0f     },
	   {380.0f   , -194.0f     },
	   {387.0f   , -193.0f     },
	   {395.0f   , -191.0f     },
	   {395.0f   , -191.0f     },
	   {401.0f   , -191.0f     },
	   {408.0f   , -189.0f     },
	   {416.0f   , -188.0f     },
	   {422.0f   , -188.0f     },
	   {431.0f   , -188.0f     },
	   {440.0f   , -188.0f     },
	   {446.0f   , -189.0f     },
	   {451.0f   , -191.0f     },
	   {452.0f   , -197.0f     },
	   {452.0f   , -203.0f     },
	   {452.0f   , -208.0f     },
	   {448.0f   , -212.0f     },
	   {445.0f   , -216.0f     },
	   {440.0f   , -221.0f     },
	   {433.0f   , -225.0f     },
	   {427.0f   , -218.0f     },
	   {421.0f   , -218.0f     },
	   {416.0f   , -218.0f     },
	   {411.0f   , -218.0f     },
	   {403.0f   , -218.0f     },
	   {398.0f   , -218.0f     },
	   {393.0f   , -215.0f     },
	   {388.0f   , -215.0f     },
	   {384.0f   , -213.0f     },
	   {379.0f   , -212.0f     }
	}; 

	for(int i = 0; i < 219; i++)
	{
		mousePts[i][0] /= 623.0f;
		mousePts[i][1] /= 623.0f;
	}

	mouselist = glGenLists(1);

	glNewList(mouselist, GL_COMPILE);
    glBegin(GL_LINE_LOOP);
		for(int i = 0; i < 219; i++)
		{
			glVertex3f(mousePts[i][0], mousePts[i][1], -3.0f);
		}

	glEnd();
    glEndList();
}

DWORD WINAPI Thread_Scene2BGMusic(LPVOID Param)
{
    PlaySound(MAKEINTRESOURCE(MYSONG_SCENE2BG), GetModuleHandle(NULL), SND_RESOURCE | SND_LOOP | SND_ASYNC);    
    return(TRUE);
}

/******************** Merged Scene Call *********************************/
HANDLE hTHread6 = NULL;
static int songflag = 0;
void Scene2_Models(void)
{
	//Second Scene Main Functions 
	void Scene_2_Kundali(void);
	void Scene_2_Ayurveda(void);
	void Scene_2_Desktop(void);
	void Scene_2_Drama(void);
	void Scene2_transition_end(void);
	DWORD WINAPI Thread_Scene2BGMusic(LPVOID Param);


	if(songflag == 0)
    {
        hTHread6 = CreateThread(NULL, 0, Thread_Scene2BGMusic, (LPVOID)ghwnd, 0, NULL);
        songflag = 1;
    }

	//Kundali Function call
	if (gbIsKundaliDraw)
		Scene_2_Kundali();
	
	//Drama Face Mask Function Call
	if (gbIsDramaDraw)
		Scene_2_Drama();
	
	//Ayurveda Function call
	if (gbIsAyurvedaDraw)
		Scene_2_Ayurveda();
	
	//Computer Function call
	if (gbIsComputerDraw)
		Scene_2_Desktop();

	if(gbEndTransition)
		Scene2_transition_end();
}

//This Function Is Called in Update()
void Scene_2_Update(void)
{
	/* Animation For All Scence squentially */
	//Function Declaration
	void ToggleKundaliNumbersBlinkFlagCount(void);
	void Ayurveda_Update(void);
	void Drama_Update(void);
	void Kundali_Update(void);
	void Computer_Update(void);
	void Scene2_Shloka_Update(void);

	//Kundali Numbemer Blinking effect
	ToggleKundaliNumbersBlinkFlagCount();

	if (gbIsDramaDraw)
	{
		//Drama Faces Animation
		Drama_Update();
	}

	if (gbIsAyurvedaDraw)
	{
		//Ayurved Animation
		Ayurveda_Update();
	}

	if (gbIsKundaliDraw)
	{
		//Kundali Animation
		Kundali_Update();
	}

	if (gbIsComputerDraw)
	{
		//Computer Animation
		Computer_Update();
	}

	Scene2_Shloka_Update();

}

// Kundali Numbers Blinking Effect
void ToggleKundaliNumbersBlinkFlagCount(void)
{
	static int count = 0;
	if (IsStartBlinkingEffect == true)
	{
		if (gbIsBlinkFlag == true)
		{
			count++;
			if (count == KUNDALI_NUBERS_BLINK_VALUE)
			{
				gbIsBlinkFlag = false;
				count = 0;
			}
		}
		if (gbIsBlinkFlag == false)
		{
			count++;
			if (count == KUNDALI_NUBERS_BLINK_VALUE)
			{
				count = 0;
				gbIsBlinkFlag = true;
			}

		}
	}
}

//Drama Face Mask Animation
void Drama_Update(void)
{
	gfyMoveDrama -= 0.001f * SCENE2_DRAMA_YPOS;
	if (gfyMoveDrama <= 1.0f)
	{
		gfyMoveDrama = 1.0f;
		gfyRotateFace = gfyRotateFace + 0.8f;
		gbIsDramaBlend = true;
	}
}

//Computer Animation
void Computer_Update(void)
{
	gfyMoveComputer -= 0.01f * SCENE2_COMPUTERSPEED_XPOS;
	if (gfyMoveComputer <= 2.0f)
	{
		gfyMoveComputer = 2.0f;
		gfyComputerSceenFadeIn += 0.01f;
		gfyCpuCircle += 0.01f;
		gbIsComputerBlend = true;
	}
}

//Kundali Animation
void Kundali_Update(void)
{
	gfKundaliScaleValue += 0.0005f*SCENE2_KUNDALISCALESPEED;
	if (gfKundaliScaleValue >= 0.50f)
	{
		gfKundaliScaleValue = 0.50f;
		IsStartBlinkingEffect = true;
		gbIsAstrologyBlend = true;
	}
}

//Ayurved Animation
void Ayurveda_Update(void)
{
	// code
	gfyMoveAyurveda -= 0.001f;
	if (gfyMoveAyurveda <= 1.3f)
	{
		gfyMoveAyurveda = 1.3f;
		gbIsAyurvedaBlend = true;
		IsStartMoveEffect = true;
	}

	glfAngle += 0.01f;
	if (glfAngle >= 360.0f)
		glfAngle = 0.0f;

	// Ayurveda dandi move
	if (IsStartMoveEffect == true)
	{
		if (gbIsMoveFlag == true)
		{
			gfAyurvedaDandaYMove += 0.01f* SCENE2_AYURVEDADANDASPEED;
			if (gfAyurvedaDandaYMove >= AYURVEDA_Y_MOVE_VALUE_MAX)
			{
				gbIsMoveFlag = false;
			}
		}
		if (gbIsMoveFlag == false)
		{
			gfAyurvedaDandaYMove -= 0.01f * SCENE2_AYURVEDADANDASPEED;
			if (gfAyurvedaDandaYMove <= AYURVEDA_Y_MOVE_VALUE_MIN)
			{
				gbIsMoveFlag = true;
			}
		}
	}
}

//Shloka Fade in Effect
void Scene2_Shloka_Update(void)
{
	// code 
	if (gbIsAstrologyBlend)
	{
		gfBlendValForAstrologyStr += 0.001f* SCENE2_ASTROLOGYSPEED;
		if (gfBlendValForAstrologyStr >= 1.0f)
		{
			gfBlendValForAstrologyStr = 1.0f;
			gbIsComputerDraw = true;	
		}
	}

	if (gbIsDramaBlend)
	{
		gfBlendValForDramaStr += 0.001f* SCENE2_DRAMASPEED;
		if (gfBlendValForDramaStr >= 1.0f)
		{
			gfBlendValForDramaStr = 1.0f;
			gbIsKundaliDraw = true;
		}
	}

	if (gbIsAyurvedaBlend)
	{
		gfBlendValForAyurvedaStr += 0.001f* SCENE2_AYURVEDASPEED;
		if (gfBlendValForAyurvedaStr >= 1.0f)
		{
			gfBlendValForAyurvedaStr = 1.0f;
			gbIsDramaDraw = true;
		}
	}

	if (gbIsComputerBlend)
	{
		gfBlendValForComputerStr += 0.001f * SCENE2_COMPUTERSPEED;
		if (gfBlendValForComputerStr >= 1.0f)
		{
			gfBlendValForComputerStr = 1.0f;
			// start next scene flag might enable
			//bScene2End = 1;
			gbEndTransition = true;
			songflag = 1;
		}
	}
}

/******************** Actual Draw Functions *********************************/

//Drawing of Ayurveda Objects
void Scene_2_Ayurveda(void)
{
	// variable declaration
	static GLfloat xMoveAyurveda;

	// function prototype
	void Scene2_Shloka_1_Ayurveda(void);
	// code

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(1.7, gfyMoveAyurveda, -5.0f);
	glScalef(0.45f, 0.45f, 0.45f);

	//glRotatef(glfAngle, 0.0f, 1.0f, 0.0f);

	glColor3f(0.8f, 0.8f, 0.8f);
	// full circle
	glBegin(GL_TRIANGLE_FAN);
	for (GLfloat f = 0; f < 2 * M_PI; f = f + 0.001f)
	{
		float x = cos(f);
		float y = 0.2 * sin(f);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	// half circle
	glPointSize(2.0f);
	glBegin(GL_POINTS);
	for (GLfloat f = M_PI; f < 2 * M_PI; f = f + 0.001f)
	{
		float x = cos(f);
		float y = sin(f);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();
	
	glPointSize(1.0f);
	if (IsStartMoveEffect == false)
	{
		// kutya chi dandi 
		// circle
		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_TRIANGLE_FAN);
		for (GLfloat f = 0.0f; f < 2.0f * M_PI; f = f + 0.001f)
		{
			float x = 1.0f + 0.2f * cos(f);
			float y = 1.0f + 0.1f * sin(f);
			glVertex3f(x, y, 0.0f);
		}
		glEnd();
		// draw lines
		glBegin(GL_TRIANGLES);
		glVertex3f(1.2f, 1.0f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);
		glVertex3f(0.8f, 1.0f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);
		glVertex3f(0.8f, 1.0f, 0.0f);
		glVertex3f(-0.3f, 0.0f, 0.0f);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		for (GLfloat f = M_PI; f < 2 * M_PI; f = f + 0.001f)
		{
			float x = 0.3f * cos(f);
			float y = 0.1f * sin(f);
			glVertex3f(x, y, 0.0f);
		}
		glEnd();
	}

	// base lines
	// draw lines
	glLineWidth(3.0f);
	glBegin(GL_LINES);

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.4f, -0.92f, 0.0f);
	glVertex3f(-0.5f, -1.2f, 0.0f);

	glVertex3f(0.4f, -0.92f, 0.0f);
	glVertex3f(0.5f, -1.2f, 0.0f);

	glVertex3f(-0.5f, -1.2f, 0.0f);
	glVertex3f(0.5f, -1.2f, 0.0f);
	glEnd();

	glLineWidth(1.0f);
	// flower
	// centre
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_POINTS);
	for (GLfloat f = 0.0f; f < 2 * M_PI; f = f + 0.001f)
	{
		float x = -0.6f + 0.03f * cos(f);
		float y = 0.03f * sin(f);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	// flower
	glBegin(GL_TRIANGLE_FAN);
	for (GLfloat f = 0.0f; f < 2 * M_PI; f = f + 0.001f)
	{
		float x = -0.6f + 0.08f * cos(f);
		float y = 0.1f + 0.08f * sin(f);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	for (GLfloat f = 0.0f; f < 2 * M_PI; f = f + 0.001f)
	{
		float x = -0.5f + 0.08f * cos(f);
		float y = 0.08f * sin(f);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	for (GLfloat f = 0.0f; f < 2 * M_PI; f = f + 0.001f)
	{
		float x = -0.7f + 0.08f * cos(f);
		float y = 0.08f * sin(f);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	for (GLfloat f = 0.0f; f < 2 * M_PI; f = f + 0.001f)
	{
		float x = -0.6f + 0.08f * cos(f);
		float y = -0.1f + 0.08f * sin(f);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	// dots 
	glPointSize(6.0f);

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.0f, -0.15f, 0.0f);
	glVertex3f(0.1f, -0.17f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glVertex3f(-0.1f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.14f, 0.0f);
	glVertex3f(-0.2f, -0.15f, 0.0f);

	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(-0.15f, -0.0f, 0.0f);
	glVertex3f(-0.2f, -0.1f, 0.0f);

	glVertex3f(-0.25f, -0.12f, 0.0f);
	glVertex3f(-0.3f, -0.13f, 0.0f);
	glVertex3f(-0.35f, -0.15f, 0.0f);

	glVertex3f(-0.25f, -0.09f, 0.0f);
	glVertex3f(-0.3f, -0.1f, 0.0f);
	glVertex3f(-0.35f, -0.07f, 0.0f);

	glEnd();

	// resetting values back
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.0f);

	if (gbIsAyurvedaBlend)
		Scene2_Shloka_1_Ayurveda();

	// run when model got placed after tranformation
	if (IsStartMoveEffect == true)
	{
		// kutya chi dandi 
		// circle
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(1.7f, gfAyurvedaDandaYMove, -5.0f);
		glScalef(0.50f, 0.50f, 0.50f);
		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_TRIANGLE_FAN);
		for (GLfloat f = 0.0f; f < 2.0f * M_PI; f = f + 0.001f)
		{
			float x = 1.0f + 0.2f * cos(f);
			float y = 1.0f + 0.1f * sin(f);
			glVertex3f(x, y, 0.0f);
		}
		glEnd();
		// draw lines
		glBegin(GL_TRIANGLES);
		glVertex3f(1.2f, 1.0f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);
		glVertex3f(0.8f, 1.0f, 0.0f);
		glVertex3f(0.3f, 0.0f, 0.0f);
		glVertex3f(0.8f, 1.0f, 0.0f);
		glVertex3f(-0.3f, 0.0f, 0.0f);
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		for (GLfloat f = M_PI; f < 2 * M_PI; f = f + 0.001f)
		{
			float x = 0.3f * cos(f);
			float y = 0.1f * sin(f);
			glVertex3f(x, y, 0.0f);
		}
		glEnd();
	}


}

//Drawing of Drama Face Objects
void Scene_2_Drama(void)
{
	//function declaration
	void Scene2_Shloka_2_Drama(void);
	void SadFace(void);
	void HappyFace(void);

	//Variable Declaration
	GLfloat MaskScale = 0.8f;

	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-1.10f, gfyMoveDrama, -3.0f);
	glScalef(MaskScale, MaskScale, MaskScale);
	glRotatef(gfyRotateFace, 0.0f, 1.0f, 0.0f); 

	//function call
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	SadFace();
	glRotatef(-60.0f, 0.0f, 0.0f, 1.0f);
	HappyFace();

	if (gbIsDramaBlend)
		Scene2_Shloka_2_Drama();
}

//Drawing of Sad Face
void SadFace(void)
{
	//Variable Declaration
	GLfloat i, j, k, l, m;
	GLfloat FaceXradius = 0.2f;
	GLfloat FaceYradius = 0.4f;
	GLfloat Curveradius = 0.21f;
	GLfloat EyeRadius = 0.05f;
	GLfloat MouthRadius = 0.095f;
	GLfloat px1, py1, px2, py2, px3, py3, px4, py4, px5, py5;
	GLfloat FaceX, FaceY, CurveX, CurveY, MouthX, MouthY;
	GLfloat LeftEyeX, LeftEyeY, RightEyeX, RightEyeY;

	//Sad Face	
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0.0; i < 2.0f * M_PI / 2; i += 0.01f)
	{
		px1 = FaceXradius * cos(i);
		py1 = FaceYradius * sin(i);

		FaceX = -(0.3 + px1);
		FaceY = -py1;

		glVertex3f(FaceX, FaceY, 0.0f);

	}
	glEnd();

	//Face Curve
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (j = 0.0; j < 2.0f * M_PI / 2; j += 0.01f)
	{
		px2 = Curveradius * cos(j);
		py2 = Curveradius * sin(j);

		CurveX = -(0.3 + px2);
		CurveY = (0.1 - py2);

		glVertex3f(CurveX, CurveY, 0.0f);

	}
	glEnd();

	//Left Eye
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (k = 0.0; k < 2.0f * M_PI / 2; k += 0.01f)
	{
		px3 = EyeRadius * cos(k);
		py3 = EyeRadius * sin(k);

		LeftEyeX = -(0.38 + px3);
		LeftEyeY = -(0.15 + py3);

		glVertex3f(LeftEyeX, LeftEyeY, 0.0f);

	}
	glEnd();

	//Right Eye
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (l = 0.0; l < 2.0f * M_PI / 2; l += 0.01f)
	{
		px4 = EyeRadius * cos(l);
		py4 = EyeRadius * sin(l);

		RightEyeX = -(0.2 + px4);
		RightEyeY = -(0.15 + py4);

		glVertex3f(RightEyeX, RightEyeY, 0.0f);

	}
	glEnd();

	//Mouth
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (m = 0.0; m < 2.0f * M_PI / 2; m += 0.01f)
	{
		px5 = MouthRadius * cos(m);
		py5 = MouthRadius * sin(m);

		MouthX = -(0.3 + px5);
		MouthY = -(0.32 - py5);

		glVertex3f(MouthX, MouthY, 0.0f);

	}
	glEnd();
}

//Drawing of Happy Face
void HappyFace(void)
{
	//Variable Declaration
	GLfloat i, j, k, l, m;
	GLfloat FaceXradius = 0.2f;
	GLfloat FaceYradius = 0.4f;
	GLfloat Curveradius = 0.21f;
	GLfloat EyeRadius = 0.05f;
	GLfloat MouthRadius = 0.095f;
	GLfloat px1, py1, px2, py2, px3, py3, px4, py4, px5, py5;
	GLfloat FaceX, FaceY, CurveX, CurveY, MouthX, MouthY;
	GLfloat LeftEyeX, LeftEyeY, RightEyeX, RightEyeY;

	//Happy Face	
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0.0; i < 2.0f * M_PI / 2; i += 0.01f)
	{
		px1 = FaceXradius * cos(i);
		py1 = FaceYradius * sin(i);

		FaceX = 0.3 + px1;
		FaceY = -py1;

		glVertex3f(FaceX, FaceY, 0.0f);

	}
	glEnd();

	//Face Curve
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (j = 0.0; j < 2.0f * M_PI / 2; j += 0.01f)
	{
		px2 = Curveradius * cos(j);
		py2 = Curveradius * sin(j);

		CurveX = 0.3 + px2;
		CurveY = 0.1 - py2;

		glVertex3f(CurveX, CurveY, 0.0f);

	}
	glEnd();

	//Right Eye
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (k = 0.0; k < 2.0f * M_PI / 2; k += 0.01f)
	{
		px3 = EyeRadius * cos(k);
		py3 = EyeRadius * sin(k);

		RightEyeX = 0.385 + px3;
		RightEyeY = -(0.2 - py3);

		glVertex3f(RightEyeX, RightEyeY, 0.0f);

	}
	glEnd();

	//Left Eye
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (l = 0.0; l < 2.0f * M_PI / 2; l += 0.01f)
	{
		px4 = EyeRadius * cos(l);
		py4 = EyeRadius * sin(l);

		LeftEyeX = 0.22 + px4;
		LeftEyeY = -(0.2 - py4);

		glVertex3f(LeftEyeX, LeftEyeY, 0.0f);

	}
	glEnd();

	//Mouth
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (m = 0.0; m < 2.0f * M_PI / 2; m += 0.01f)
	{
		px5 = MouthRadius * cos(m);
		py5 = MouthRadius * sin(m);

		MouthX = 0.3 + px5;
		MouthY = -(0.25 + py5);

		glVertex3f(MouthX, MouthY, 0.0f);

	}
	glEnd();
}

//Drawing of Kundali
void Scene_2_Kundali(void)
{
	// function prototype
	void DrawNumbers(void);
	void DrawQuad(void);
	void DrawLines(void);
	void Scene2_Shloka_3_Astrology(void);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslatef(2.0f, 1.2f, -5.0f);
	glTranslatef(-1.8f, -0.7f, -5.0f);
	glScalef(gfKundaliScaleValue, gfKundaliScaleValue, gfKundaliScaleValue);

	DrawQuad();
	DrawLines();

	if (gbIsBlinkFlag == true)
		DrawNumbers();

	if (gbIsAstrologyBlend)
		Scene2_Shloka_3_Astrology();
}

//Kundali - Numbers Drawing
void DrawNumbers(void)
{
	// code
	// draw numbers in kundali
	glLineWidth(1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	// 1
	glVertex3f(0.0f, 0.4f, 0.0f);
	glVertex3f(0.0f, 0.6f, 0.0f);

	// 7
	glVertex3f(-0.1f, -0.4f, 0.0f);
	glVertex3f(0.1f, -0.4f, 0.0f);
	glVertex3f(0.1f, -0.4f, 0.0f);
	glVertex3f(0.0f, -0.6f, 0.0f);

	//10

	glVertex3f(0.4f, 0.1f, 0.0f);
	glVertex3f(0.4f, -0.1f, 0.0f);

	glVertex3f(0.5f, 0.1f, 0.0f);
	glVertex3f(0.5f, -0.1f, 0.0f);

	glVertex3f(0.6f, 0.1f, 0.0f);
	glVertex3f(0.6f, -0.1f, 0.0f);

	glVertex3f(0.5f, 0.1f, 0.0f);
	glVertex3f(0.6f, 0.1f, 0.0f);

	glVertex3f(0.5f, -0.1f, 0.0f);
	glVertex3f(0.6f, -0.1f, 0.0f);


	// 5

	glVertex3f(-0.8f, -0.3f, 0.0f);
	glVertex3f(-0.95f, -0.3f, 0.0f);
	glVertex3f(-0.8f, -0.4f, 0.0f);
	glVertex3f(-0.95f, -0.4f, 0.0f);

	glVertex3f(-0.95f, -0.3f, 0.0f);
	glVertex3f(-0.95f, -0.4f, 0.0f);

	glVertex3f(-0.8f, -0.4f, 0.0f);
	glVertex3f(-0.8f, -0.5f, 0.0f);

	glVertex3f(-0.8f, -0.5f, 0.0f);
	glVertex3f(-0.95f, -0.5f, 0.0f);


	// 4
	glVertex3f(-0.6f, 0.1f, 0.0f);
	glVertex3f(-0.6f, 0.0f, 0.0f);

	glVertex3f(-0.6f, 0.0f, 0.0f);
	glVertex3f(-0.4f, 0.0f, 0.0f);

	glVertex3f(-0.4f, 0.0f, 0.0f);
	glVertex3f(-0.4f, -0.1f, 0.0f);

	// 11
	glVertex3f(0.7f, 0.6f, 0.0f);
	glVertex3f(0.7f, 0.4f, 0.0f);

	glVertex3f(0.8f, 0.4f, 0.0f);
	glVertex3f(0.8f, 0.6f, 0.0f);


	// 12
	glVertex3f(0.35f, 0.9f, 0.0f);
	glVertex3f(0.35f, 0.7f, 0.0f);

	glVertex3f(0.4f, 0.9f, 0.0f);
	glVertex3f(0.55f, 0.9f, 0.0f);

	glVertex3f(0.4f, 0.8f, 0.0f);
	glVertex3f(0.55f, 0.8f, 0.0f);

	glVertex3f(0.55f, 0.9f, 0.0f);
	glVertex3f(0.55f, 0.8f, 0.0f);

	glVertex3f(0.4f, 0.8f, 0.0f);
	glVertex3f(0.4f, 0.7f, 0.0f);

	glVertex3f(0.4f, 0.7f, 0.0f);
	glVertex3f(0.55f, 0.7f, 0.0f);

	// 2 
	glVertex3f(-0.4f, 0.9f, 0.0f);
	glVertex3f(-0.55f, 0.9f, 0.0f);

	glVertex3f(-0.4f, 0.8f, 0.0f);
	glVertex3f(-0.55f, 0.8f, 0.0f);

	glVertex3f(-0.4f, 0.9f, 0.0f);
	glVertex3f(-0.4f, 0.8f, 0.0f);

	glVertex3f(-0.55f, 0.8f, 0.0f);
	glVertex3f(-0.55f, 0.7f, 0.0f);

	glVertex3f(-0.4f, 0.7f, 0.0f);
	glVertex3f(-0.55f, 0.7f, 0.0f);

	// 3
	glVertex3f(-0.8f, 0.5f, 0.0f);
	glVertex3f(-0.95f, 0.5f, 0.0f);

	glVertex3f(-0.8f, 0.4f, 0.0f);
	glVertex3f(-0.95f, 0.4f, 0.0f);

	glVertex3f(-0.8f, 0.5f, 0.0f);
	glVertex3f(-0.8f, 0.4f, 0.0f);

	glVertex3f(-0.8f, 0.4f, 0.0f);
	glVertex3f(-0.8f, 0.3f, 0.0f);

	glVertex3f(-0.8f, 0.3f, 0.0f);
	glVertex3f(-0.95f, 0.3f, 0.0f);

	// 6
	glVertex3f(-0.4f, -0.7f, 0.0f);
	glVertex3f(-0.6f, -0.7f, 0.0f);
	glVertex3f(-0.4f, -0.8f, 0.0f);
	glVertex3f(-0.6f, -0.8f, 0.0f);

	glVertex3f(-0.6f, -0.7f, 0.0f);
	glVertex3f(-0.6f, -0.8f, 0.0f);

	glVertex3f(-0.4f, -0.8f, 0.0f);
	glVertex3f(-0.4f, -0.9f, 0.0f);

	glVertex3f(-0.6f, -0.8f, 0.0f);
	glVertex3f(-0.6f, -0.9f, 0.0f);

	glVertex3f(-0.4f, -0.9f, 0.0f);
	glVertex3f(-0.6f, -0.9f, 0.0f);


	// 8
	glVertex3f(0.4f, -0.9f, 0.0f);
	glVertex3f(0.55f, -0.9f, 0.0f);

	glVertex3f(0.4f, -0.8f, 0.0f);
	glVertex3f(0.55f, -0.8f, 0.0f);

	glVertex3f(0.55f, -0.9f, 0.0f);
	glVertex3f(0.55f, -0.8f, 0.0f);

	glVertex3f(0.4f, -0.9f, 0.0f);
	glVertex3f(0.4f, -0.8f, 0.0f);

	glVertex3f(0.4f, -0.8f, 0.0f);
	glVertex3f(0.4f, -0.7f, 0.0f);

	glVertex3f(0.55f, -0.8f, 0.0f);
	glVertex3f(0.55f, -0.7f, 0.0f);

	glVertex3f(0.4f, -0.7f, 0.0f);
	glVertex3f(0.55f, -0.7f, 0.0f);

	// 9
	glVertex3f(0.8f, -0.6f, 0.0f);
	glVertex3f(0.95f, -0.6f, 0.0f);

	glVertex3f(0.8f, -0.5f, 0.0f);
	glVertex3f(0.95f, -0.5f, 0.0f);

	glVertex3f(0.95f, -0.6f, 0.0f);
	glVertex3f(0.95f, -0.5f, 0.0f);

	glVertex3f(0.8f, -0.5f, 0.0f);
	glVertex3f(0.8f, -0.4f, 0.0f);

	glVertex3f(0.95f, -0.5f, 0.0f);
	glVertex3f(0.95f, -0.4f, 0.0f);

	glVertex3f(0.8f, -0.4f, 0.0f);
	glVertex3f(0.95f, -0.4f, 0.0f);
	glEnd();
}

//Kundali - Square Drawing
void DrawQuad(void)
{
	// code
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}

//Kundali - Lines Drawing
void DrawLines(void)
{
	// code
	glLineWidth(3.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	// rectangle edges
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);

	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);

	// diagonals
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glEnd();
	glLineWidth(1.0f);
}

//Drawing of Computer Objects
void Scene_2_Desktop(void)
{
	void Scene2_Shloka_4_Computer(void);

	static GLfloat x = 0.05f, y = 0.05f;
	static GLfloat key_xpos = 0.15f;
	static GLfloat key_ypos = -0.1f;
	static GLfloat angle;
	int i;

	//MONITOR OUTER
	glColor3f(200.0f / 255.0f, 200.0f / 255.0f, 200.0f / 255.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslatef(2.0f, -1.0f, -5.0f);
	glTranslatef(gfyMoveComputer, -0.7f, -5.0f);
	glScalef(0.75f, 0.75f, 0.75f);
	glBegin(GL_QUADS);
	glVertex3f(-1.5f, 0.7f, -3.0f);
	glVertex3f(-1.5f, -0.7f, -3.0f);
	glVertex3f(1.5f, -0.7f, -3.0f);
	glVertex3f(1.5f, 0.7f, -3.0f);
	glEnd();

	//MONITOR INNER
	glColor3f(0.0f, 0.0f, gfyComputerSceenFadeIn);
	glBegin(GL_QUADS);
	glVertex3f(-1.35f, 0.55f, -3.0f);
	glVertex3f(-1.35f, -0.55f, -3.0f);
	glVertex3f(1.35f, -0.55f, -3.0f);
	glVertex3f(1.35f, 0.55f, -3.0f);
	glEnd();


	//monitor stand
	glColor3f(150.0f / 255.0f, 150.0f / 255.0f, 150.0f / 255.0f);
	glBegin(GL_QUADS);
	glVertex3f(-0.15f, -0.55f, -3.0f);
	glVertex3f(-0.15f, -1.15f, -3.0f);
	glVertex3f(0.15f, -1.15f, -3.0f);
	glVertex3f(0.15f, -0.55f, -3.0f);
	glEnd();

	//keyboard
	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.0f, -1.15f, -3.0f);
	glVertex3f(-1.05f, -1.75f, -3.0f);
	glVertex3f(1.05f, -1.75f, -3.0f);
	glVertex3f(1.0f, -1.15f, -3.0f);
	glEnd();

	//CPU
	glColor3f(169.0f / 255.0f, 169.0f / 255.0f, 169.0f / 255.0f);
	glBegin(GL_QUADS);
	glVertex3f(1.6f, 0.7f, -3.0f);
	glVertex3f(1.6f, -1.75f, -3.0f);
	glVertex3f(2.5f, -1.75f, -3.0f);
	glVertex3f(2.5f, 0.7f, -3.0f);
	glEnd();

	glColor3f(0.8f, 0.8f, 0.8f);
	// Extra verticles
	glBegin(GL_LINE_LOOP);
	glVertex3f(1.7f, 0.7f, -3.0f);
	glVertex3f(1.7f, -1.75f, -3.0f);
	glVertex3f(2.4f, -1.75f, -3.0f);
	glVertex3f(2.4f, 0.7f, -3.0f);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex3f(1.75f, 0.45f, -3.0f);
	glVertex3f(1.75f, 0.52f, -3.0f);
	glVertex3f(2.35f, 0.52f, -3.0f);
	glVertex3f(2.35f, 0.45f, -3.0f);
	glEnd();

	// CPU horizontal lines
	glBegin(GL_LINES);
	glVertex3f(1.6f, 0.7f, -3.0f);
	glVertex3f(2.5f, 0.7f, -3.0f);

	glVertex3f(1.6f, -1.75f, -3.0f);
	glVertex3f(2.5f, -1.75f, -3.0f);

	glVertex3f(1.6f, 0.7f, -3.0f);
	glVertex3f(1.6f, -1.75f, -3.0f);

	glVertex3f(2.5f, 0.7f, -3.0f);
	glVertex3f(2.5f, -1.75f, -3.0f);
	glVertex3f(1.6f, 0.3f, -3.0f);
	glVertex3f(2.5f, 0.3f, -3.0f);

	glVertex3f(1.6f, -0.1f, -3.0f);
	glVertex3f(2.5f, -0.1f, -3.0f);

	glVertex3f(1.6f, -0.5f, -3.0f);
	glVertex3f(2.5f, -0.5f, -3.0f);

	glVertex3f(1.6f, -0.9f, -3.0f);
	glVertex3f(2.5f, -0.9f, -3.0f);

	glVertex3f(1.6f, -1.3f, -3.0f);
	glVertex3f(2.5f, -1.3f, -3.0f);
	glEnd();

	//circle on CPU
	glColor3f(0.0f, gfyCpuCircle, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (GLfloat angle = 0; angle < 360; angle = angle + 1.0f)
		glVertex3f(0.08f * cos(angle) + 2.05f, 0.08f * sin(angle) - 0.7f, -3.0f);
	glEnd();

	//mouse
	glColor3f(0.8f, 0.8f, 0.8f);
	glRotatef(-30, 0.0f, 0.0f, 1.0f);
	glTranslatef(1.2f, -0.25f, 0.0f);
		glCallList(mouselist);
	glRotatef(30, 0.0f, 0.0f, 1.0f);

	//keyboard keys
	glColor3f(gfyCpuCircle, 0.0f, 0.0f);
	glTranslatef(-1.95f, -0.93f, 0.0f);
	for (i = 0; i < 4; i++)
	{
		glTranslatef(0.0f, key_ypos, 0.0f);
		for (int j = 0; j < 12; j++)
		{
			glTranslatef(key_xpos, 0.0f, 0.0f);
			glBegin(GL_LINE_LOOP);
			glVertex3f(0.0f, 0.5f, -3.0f);
			glVertex3f(0.03f, 0.6f, -3.0f);
			glVertex3f(0.12f, 0.6f, -3.0f);
			glVertex3f(0.15f, 0.5f, -3.0f);
			glEnd();
		}
		glTranslatef(-1.8, 0.0f, 0.0f);
	}
	

	if (gbIsComputerBlend)
		Scene2_Shloka_4_Computer();
}

/******************** Shloka Draw Functions *********************************/

//Drawing of Ayurveda Shloka
void Scene2_Shloka_1_Ayurveda(void)
{
	char cAyurvedaShloka[128] = "!! Aaayauvae_dyaita baaeYayaita qita Aaayauvae_d: !!";
	GLfloat glScaleValue = 0.15f;

	//code
	glListBase(gliFontListMarathi);									//DO NOT CHANGE

	//left bottom- 3rd quadrant
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(-1.3f, -0.75f, -2.0f);
	glTranslatef(0.2f, 0.2f, -2.0f);
	glScalef(glScaleValue, glScaleValue, glScaleValue);
	glColor3f(0.0f, gfBlendValForAyurvedaStr, 0.0f);
	glCallLists(strlen(cAyurvedaShloka), GL_UNSIGNED_BYTE, cAyurvedaShloka);
}

//Drawing of Drama Shloka
void Scene2_Shloka_2_Drama(void)
{
	//variable declaration
	char cDramaShloka[128] = "!! laaek-va&tta-AanaukrNa/ naaoyama !!";
	GLfloat glScaleValue = 0.15f;

	//code
	glListBase(gliFontListMarathi);									//DO NOT CHANGE

	//left top - 2nd quadrant
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-1.15f, 0.2f, -2.0f);
	glScalef(glScaleValue, glScaleValue, glScaleValue);
	glColor3f(0.0f, gfBlendValForDramaStr, 0.0f);
	glCallLists(strlen(cDramaShloka), GL_UNSIGNED_BYTE, cDramaShloka);
}

//Drawing of Astrology Shloka
void Scene2_Shloka_3_Astrology(void)
{
	char cAstrologyShloka[128] = "!! jyaaeitaVaa/ saUyaa_id gaXhNaa/ baaeYakmax SaasPa/ !!";
	GLfloat glScaleValue = 0.15f;

	//code
	glListBase(gliFontListMarathi);									//DO NOT CHANGE

	//right top- 1st quadrant
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.4f, 0.2f, -2.0f);
	glTranslatef(-1.2f, -0.65f, -2.0f);
	glScalef(glScaleValue, glScaleValue, glScaleValue);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, gfBlendValForAstrologyStr, 0.0f);
	glCallLists(strlen(cAstrologyShloka), GL_UNSIGNED_BYTE, cAstrologyShloka);

}

//Drawing of Computer Shloka
void Scene2_Shloka_4_Computer(void)
{
	char cUnixPhilosophy[128] = "Files Have Spaces And Processes Have life.";
	GLfloat glScaleValue = 0.15f;

	glListBase(gliFontListEnglish);									//DO NOT CHANGE

	//right bottom- 4th quadrant
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.1f, -0.65f, -2.0f);
	glScalef(0.06f, 0.06f, 0.06f);
	glColor3f(0.0f, gfBlendValForComputerStr, 0.0f);
	glCallLists(strlen(cUnixPhilosophy), GL_UNSIGNED_BYTE, cUnixPhilosophy);
}

void Scene2_transition_end(void) 
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
        alpha += 0.001f;
	else
		bScene2End = 1;
}
