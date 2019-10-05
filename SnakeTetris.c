#include <stdio.h>
#include <gl/glut.h>
#include<windows.h>
#include<string.h>
#include <time.h>
time_t start, stop;
char name[15];
GLfloat rotation = 90.0;
GLfloat posX[1000] = {0.0}, posY[1000] = {0.0}, posZ[1000] = {0.0};
GLint NumOfElem=4;
char KeyPress='\0';
float move_unit = 1.0;
GLfloat posXrand,posYrand,posZrand=0.0,posXrand1,posYrand1;
int rand_ref=0;
int interval=100,width=800,height=800;
float tempX=0.0,tempY=0.0;
int score=0,changeLevel=0;
char score_str[5];
int Camp_highscore=0,highscore=0,menu_key=0,in_game=0;
int genBonus=0,bonusTimer=0;
int NoOfBlockElem=0;
int ti=0;
int stop_camp=1;
int resume_key=0;

void keyboard(unsigned char keys,int x,int y);
void reshape(int w, int h)
{
	width=w;
	height=h;
	if(h<w)
	{
	    tempX=(w-h)/2;
	}
	else
	    tempX=0.0;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 20.0, 0.0, 21.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void generateRandom()
{
	int i,j;
	label:
	posXrand=(rand()%20)*1.0;
	posYrand=(rand()%20)*1.0;
	if(in_game==2)
	{
		for(i=0;i<NumOfElem;i++)
		if((posXrand==posX[i]&&posYrand==posY[i]) || posXrand<=1||posXrand>=19||posYrand<=1||posYrand>=19  )
		   goto label;
	}
	else if(in_game==3)
	{
	       for(i=0;i<NumOfElem;i++)
    		   if((posXrand<1&&posYrand>13) || (posXrand<1&&posYrand<6) || (posXrand>=19&&posYrand>13) || (posXrand>=19&&posYrand<6) || 
			     (posXrand<6&&posYrand<1) || (posXrand<6&&posYrand>=19) || (posXrand>15&&posYrand<1) || (posXrand>15&&posYrand>=19) || 
		         ((posXrand>6&&posXrand<13)&&(posYrand<13&&posYrand>11)) || ((posXrand>6&&posXrand<13)&&(posYrand<8&&posYrand>6))
		         || (posXrand==posX[i]&&posYrand==posY[i]))
		               goto label;
	}
	else if(in_game==4)
	{
	 for(i=0;i<NumOfElem;i++)
	      if(posYrand<=1|| posYrand>=19||((posXrand>3&&posXrand<6)&&(posYrand>5&&posYrand<15))||((posXrand>14&&posXrand<17)&&(posYrand>5&&posYrand<15))
	      ||((posXrand>3&&posXrand<17)&&(posYrand>5&&posYrand<7)) || ((posXrand>4&&posXrand<7)&&(posYrand>12&&posYrand<15))||
		  (posXrand==posX[i]&&posYrand==posY[i]))
		       goto label;
	}
	else if(in_game==5)
	{
		for(i=0;i<NumOfElem;i++)
	      if((posXrand<1&&posYrand>14) || (posXrand>14&&posYrand>=19) || (posXrand>=19&&posYrand<5) || (posXrand<5&&posYrand<1) || 
	          ((posXrand>6&&posXrand<14)&&(posYrand>15&&posYrand<17)) || ((posXrand>2&&posXrand<9)&&(posYrand>12&&posYrand<14)) || 
	          ((posXrand>10&&posXrand<17)&&(posYrand>10&&posYrand<12)) || ((posXrand>2&&posXrand<9)&&(posYrand>7&&posYrand<9)) ||
	          ((posXrand>10&&posXrand<17)&&(posYrand>5&&posYrand<7)) || ((posXrand>6&&posXrand<14)&&(posYrand>2&&posYrand<4)) || 
		      (posXrand==posX[i]&&posYrand==posY[i]))
		   goto label;
	}
	else if(in_game==6)
	{
	    for(i=0;i<NumOfElem;i++)
	      if(posXrand<1 || posXrand>=19 || (posXrand>13&&posYrand>=19) || (posXrand<6&&posYrand>=19) || (posXrand<6&&posYrand<1) || 
	      ((posXrand>2&&posXrand<17)&&(posYrand>15&&posYrand<17)) || ((posXrand>2&&posXrand<4)&&(posYrand>12&&posYrand<16)) || 
	      ((posXrand>15&&posXrand<17)&&(posYrand>12&&posYrand<16)) || ((posXrand>2&&posXrand<17)&&(posYrand>2&&posYrand<4)) ||
	      ((posXrand>2&&posXrand<4)&&(posYrand>3&&posYrand<7)) || ((posXrand>15&&posXrand<17)&&(posYrand>3&&posYrand<7)) || 
	      ((posXrand>5&&posXrand<7)&&(posYrand>5&&posYrand<14)) || ((posXrand>6&&posXrand<8)&&(posYrand>12&&posYrand<14)) || 
	      ((posXrand>6&&posXrand<8)&&(posYrand>5&&posYrand<7)) || ((posXrand>12&&posXrand<14)&&(posYrand>5&&posYrand<14)) ||
	      ((posXrand>11&&posXrand<13)&&(posYrand>12&&posYrand<14)) || ((posXrand>11&&posXrand<13)&&(posYrand>5&&posYrand<7)) ||
	      ((posXrand>8&&posXrand<11)&&(posYrand>8&&posYrand<11)) || (posXrand==posX[i]&&posYrand==posY[i]) || (posXrand>13&&posYrand<1))
		   goto label;
	}
	else
	{
	for(i=0;i<NumOfElem;i++)
	    if(posXrand==posX[i]&&posYrand==posY[i])
		   goto label;
    }
    //printf("Random: %f %f",posXrand,posYrand);
}

void generateRandom1()
{
	int i,j;
	label:
	posXrand1=(rand()%20)*1.0;
	posYrand1=(rand()%20)*1.0;
	if(in_game==2)
	{
		for(i=0;i<NumOfElem;i++)
		if((posXrand1==posX[i]&&posYrand1==posY[i]) || posXrand1<=1||posXrand1>=19||posYrand1<=1||posYrand1>=19  )
		   goto label;
	}
	else if(in_game==3)
	{
	       for(i=0;i<NumOfElem;i++)
    		   if((posXrand1<1&&posYrand1>13) || (posXrand1<1&&posYrand1<6) || (posXrand1>=19&&posYrand1>13) || (posXrand1>=19&&posYrand1<6) || 
			     (posXrand1<6&&posYrand1<1) || (posXrand1<6&&posYrand1>=19) || (posXrand1>15&&posYrand1<1) || (posXrand1>15&&posYrand1>=19) || 
		         ((posXrand1>6&&posXrand1<13)&&(posYrand1<13&&posYrand1>11)) || ((posXrand1>6&&posXrand1<13)&&(posYrand1<8&&posYrand1>6))
		         || (posXrand1==posX[i]&&posYrand1==posY[i]))
		               goto label;
	}
	else if(in_game==4)
	{
	 for(i=0;i<NumOfElem;i++)
	      if(posYrand1<=1|| posYrand1>=19||((posXrand1>3&&posXrand1<6)&&(posYrand1>5&&posYrand1<15))||((posXrand1>14&&posXrand1<17)&&(posYrand1>5&&posYrand1<15))
	      ||((posXrand1>3&&posXrand1<17)&&(posYrand1>5&&posYrand1<7)) || ((posXrand1>4&&posXrand1<7)&&(posYrand1>12&&posYrand1<15))||
		  (posXrand1==posX[i]&&posYrand1==posY[i]))
		       goto label;
	}
	else if(in_game==5)
	{
		for(i=0;i<NumOfElem;i++)
	      if((posXrand1<1&&posYrand1>14) || (posXrand1>14&&posYrand1>=19) || (posXrand1>=19&&posYrand1<5) || (posXrand1<5&&posYrand1<1) || 
	          ((posXrand1>6&&posXrand1<14)&&(posYrand1>15&&posYrand1<17)) || ((posXrand1>2&&posXrand1<9)&&(posYrand1>12&&posYrand1<14)) || 
	          ((posXrand1>10&&posXrand1<17)&&(posYrand1>10&&posYrand1<12)) || ((posXrand1>2&&posXrand1<9)&&(posYrand1>7&&posYrand1<9)) ||
	          ((posXrand1>10&&posXrand1<17)&&(posYrand1>5&&posYrand1<7)) || ((posXrand1>6&&posXrand1<14)&&(posYrand1>2&&posYrand1<4)) || 
		      (posXrand1==posX[i]&&posYrand1==posY[i]))
		   goto label;
	}
	else if(in_game==6)
	{
	    for(i=0;i<NumOfElem;i++)
	      if(posXrand1<1 || posXrand1>=19 || (posXrand1>13&&posYrand1>=19) || (posXrand1<6&&posYrand1>=19) || (posXrand1<6&&posYrand1<1) || 
	      ((posXrand1>2&&posXrand1<17)&&(posYrand1>15&&posYrand1<17)) || ((posXrand1>2&&posXrand1<4)&&(posYrand1>12&&posYrand1<16)) || 
	      ((posXrand1>15&&posXrand1<17)&&(posYrand1>12&&posYrand1<16)) || ((posXrand1>2&&posXrand1<17)&&(posYrand1>2&&posYrand1<4)) ||
	      ((posXrand1>2&&posXrand1<4)&&(posYrand1>3&&posYrand1<7)) || ((posXrand1>15&&posXrand1<17)&&(posYrand1>3&&posYrand1<7)) || 
	      ((posXrand1>5&&posXrand1<7)&&(posYrand1>5&&posYrand1<14)) || ((posXrand1>6&&posXrand1<8)&&(posYrand1>12&&posYrand1<14)) || 
	      ((posXrand1>6&&posXrand1<8)&&(posYrand1>5&&posYrand1<7)) || ((posXrand1>12&&posXrand1<14)&&(posYrand1>5&&posYrand1<14)) ||
	      ((posXrand1>11&&posXrand1<13)&&(posYrand1>12&&posYrand1<14)) || ((posXrand1>11&&posXrand1<13)&&(posYrand1>5&&posYrand1<7)) ||
	      ((posXrand1>8&&posXrand1<11)&&(posYrand1>8&&posYrand1<11)) || (posXrand1==posX[i]&&posYrand1==posY[i]) || (posXrand1>13&&posYrand1<1))
		   goto label;
	}
	else
	{
	for(i=0;i<NumOfElem;i++)
	    if(posXrand1==posX[i]&&posYrand1==posY[i])
		   goto label;
    }
    //printf("Random: %f %f",posXrand1,posYrand1);
}

void rect(int x,int y){
	
	glPointSize(20.0);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x,y-1);
    glVertex2f(x-1,y-1);
    glVertex2f(x-1,y);
    glEnd();

}

void quadVertices(float l,float m,float n,float o, float p,float q,float r,float s)
{
	glVertex2f(l,m);
    glVertex2f(n,o);
    glVertex2f(p,q);
    glVertex2f(r,s);
}

void campaign1()
{
	glColor3f(1.0,1.0,1.0);
	glPointSize(20.0);
	glBegin(GL_QUADS);
	quadVertices(0,0,0,20,1,20,1,0);
    quadVertices(0,0,0,1,20,1,20,0);
    quadVertices(0,20,20,20,20,19,0,19);
    quadVertices(19,0,20,0,20,20,19,20);
    glEnd();
}

void campaign2()
{
	glColor3f(1.0,1.0,1.0);
	glPointSize(20.0);
	glBegin(GL_QUADS);
	quadVertices(0,14,0,20,1,20,1,14);
	quadVertices(1,20,6,20,6,19,1,19);
    quadVertices(14,20,14,19,20,19,20,20);
    quadVertices(19,19,20,19,20,14,19,14);
    quadVertices(20,0,20,6,19,6,19,0);
    quadVertices(14,0,14,1,19,1,19,0);
    quadVertices(0,0,0,1,6,1,6,0);
    quadVertices(0,1,0,6,1,6,1,1);
    quadVertices(7,12,7,13,13,13,13,12);
    quadVertices(7,8,7,7,13,7,13,8);
    glEnd();
}

void campaign3()
{
	glColor3f(1.0,1.0,1.0);
	glPointSize(20.0);
	glBegin(GL_QUADS);
	quadVertices(0,20,20,20,20,19,0,19);
	quadVertices(0,0,0,1,20,1,20,0);
	quadVertices(4,6,5,6,5,14,4,14);
	quadVertices(5,6,15,6,15,7,5,7);
	quadVertices(15,6,16,6,16,14,15,14);
	quadVertices(5,14,8,14,8,13,5,13);
	quadVertices(15,14,12,14,12,13,15,13);
    glEnd();	
}

void campaign4()
{
	glColor3f(1.0,1.0,1.0);
	glPointSize(20.0);
	glBegin(GL_QUADS);
	quadVertices(7,17,7,16,14,16,14,17);
	quadVertices(3,14,3,13,9,13,9,14);
	quadVertices(11,12,11,11,17,11,17,12);
	quadVertices(3,9,3,8,9,8,9,9);
	quadVertices(11,7,11,6,17,6,17,7);
	quadVertices(7,4,7,3,14,3,14,4);
	quadVertices(0,15,0,20,1,20,1,15);
	quadVertices(15,20,15,19,20,19,20,20);
	quadVertices(20,0,20,5,19,5,19,0);
	quadVertices(0,0,0,1,5,1,5,0);
	glEnd();	
}

void campaign5()
{
	glColor3f(1.0,1.0,1.0);
	glPointSize(20.0);
	glBegin(GL_QUADS);
	quadVertices(0,0,0,20,1,20,1,0);
	quadVertices(19,0,20,0,20,20,19,20);
	
	quadVertices(1,20,6,20,6,19,1,19);
	quadVertices(14,20,14,19,19,19,19,20);
	quadVertices(14,0,14,1,19,1,19,0);
	quadVertices(1,0,1,1,6,1,6,0);
	
	quadVertices(3,17,3,16,17,16,17,17);
	quadVertices(3,16,4,16,4,13,3,13);
	quadVertices(17,16,16,16,16,13,17,13);
	
	quadVertices(3,3,3,4,17,4,17,3);
	quadVertices(3,4,4,4,4,7,3,7);
	quadVertices(17,4,16,4,16,7,17,7);
	
	quadVertices(6,14,7,14,7,6,6,6);
	quadVertices(7,14,8,14,8,13,7,13);
	quadVertices(7,6,8,6,8,7,7,7);
	
	quadVertices(14,14,13,14,13,6,14,6);
	quadVertices(13,14,13,13,12,13,12,14);
	quadVertices(13,6,13,7,12,7,12,6);
	
	quadVertices(9,11,11,11,11,9,9,9);
	glEnd();	
}

void display1(int n)
{
	glPushMatrix();
    if(in_game==2)
      campaign1();
	else if(in_game==3)
	{
      campaign2(); 
   }
    else if(in_game==4)
      campaign3();
    else if(in_game==5)
      campaign4();
    else if(in_game==6)
      campaign5();
    if(posX[0]==posXrand&&posY[0]==posYrand)
        glColor3f(0.0, 1.0, 0.0);
    else if(posX[0]==posXrand1&&posY[0]==posYrand1)
        glColor3f(0.0, 1.0, 0.0);
    else
        glColor3f(1.0, 0.0, 0.0);
    glTranslatef(posX[n],posY[n],posZ[n]);
    rect(1,1);
    glPopMatrix();
}

void food()
{
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    if(posX[0]==posXrand&&posY[0]==posYrand)
        glColor3f(0.0, 1.0, 0.0);
    else
        glColor3f(0.0, 0.0, 1.0);
    glTranslatef(posXrand,posYrand,posZrand);
    rect(1,1);
    glPopMatrix();
}

void bonusFood()
{
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    if(posX[0]==posXrand1&&posY[0]==posYrand1)
        glColor3f(0.0, 1.0, 0.0);
    else
    {
    	glColor3f(0.0, 1.0, 1.0);
    }
    glTranslatef(posXrand1,posYrand1,posZrand);
    rect(1,1);
    glPopMatrix();
}

//void output(GLfloat x, GLfloat y, char *text)
//{
//    char *p;
//    int i=0;
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glEnable(GL_BLEND);
//    glEnable(GL_LINE_SMOOTH);
//    glPushMatrix();
//    glTranslatef(x, y, 0);
//    for (p = text; *p; p++)
//        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
//    glPopMatrix();
//}

//void cover_screen()
//{
//    glPushMatrix();
//    glLoadIdentity();
//    glTranslated(0,180,0);
//    glLineWidth(2.0);
//    glScaled(0.5,0.5,1);
//    output(50,300,"SNAKE TETRIS");
//    output(50,250,"1. CLASSIC");
//    output(50,200,"2. CAMPAIGN");
//    output(50,150,"3. EXIT");
//    glPopMatrix();
//}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int i;
    if(width!=height)
    {
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glEnable(GL_SCISSOR_TEST);
        glScissor(tempX, tempY, height, height);
        glClearColor(1.0,1.0,1.0,0.0);
    }
    else
    {
    	glClearColor(0.0,0.0,0.0,0.0);
    }
    glViewport(tempX, tempY, height, height);
    glLoadIdentity();
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2f(0,20);
    glVertex2f(20,20);
    glEnd();
   
    char s1[11];
    sprintf(s1, "SCORE: %d", score);
    char s2[30];
    if(in_game>1)
    {
    	if(score<=Camp_highscore)
        	sprintf(s2, "HIGHSCORE: %d", Camp_highscore);
        else
        	sprintf(s2, "HIGHSCORE: %d (%s)", score,name);
    }
    else
	{
    	if(score<=highscore)
        	sprintf(s2, "HIGHSCORE: %d", highscore);
        else
        	sprintf(s2, "HIGHSCORE: %d (%s)", score,name);
    }
    glColor3f(1,0,0);
    glRasterPos2f(1,20.3);
    for(i=0;i<strlen(s1);i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s1[i]);
    glRasterPos2f(15,20.3);
    for(i=0;i<strlen(s2);i++)
  		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s2[i]);
    for(i=0;i<NumOfElem;i++)
	 	display1(i);
	food();
	if(genBonus==1)
	{
	 	bonusFood();
	}
    glFlush();	                      
    glutSwapBuffers();
}

void displayCoverScreen(float transX,float transY,float scaleX,float scaleY,char *s)
{
	int i;
	glPushMatrix();
    glRasterPos2i(20,10);
	glTranslated(transX,transY,0);
	glScaled(scaleX,scaleY,0);
    for(i=0;i<strlen(s);i++)
         glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
    glPopMatrix();
}

void display2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int i;
    
    if(width!=height)
    {
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glEnable(GL_SCISSOR_TEST);
        glScissor(tempX, tempY, height, height);
        glClearColor(1.0,1.0,1.0,0.0);
    }
    else
    {
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glClearColor(0.0,0.0,0.0,0.0);
    }
    glViewport(tempX, tempY, height, height);
    glLoadIdentity();
    char *s1="SNAKE TETRIS";
	char *s2="1. CLASSIC";
    char *s3="2. CAMPAIGN";
    char *s4="3. EXIT";
    char *s5="DEVELOPED BY:";
    char *s6="KARTIKEYAN L V (1AM13CS068)";
   	glColor3f(1,0,0);
	glViewport(0,0,height,height);
	displayCoverScreen(1,16,0.02,0.02,s1);
	displayCoverScreen(6,12,0.01,0.01,s2);
    displayCoverScreen(6,10,0.01,0.01,s3);
    displayCoverScreen(6,8,0.01,0.01,s4);
    displayCoverScreen(1,3,0.007,0.007,s5);
    displayCoverScreen(1,2,0.005,0.005,s6);
    glFlush();	                      
    glutSwapBuffers();
}

void text()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	char *s1="GAME OVER";
	char s2[15];
	sprintf(s2, "SCORE: %d", score);
	char *s3="Press ENTER to go to MENU";
	glLoadIdentity();
	glColor3f(1,0,0);
	glViewport(0,0,height,height);
	displayCoverScreen(2.5,14,0.02,0.02,s1);
	displayCoverScreen(6.5,11,0.01,0.01,s2);
	displayCoverScreen(3,8,0.007,0.007,s3);
  	glFlush();
  	glutSwapBuffers();
}

void resume()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	char *s1="RESUME(Y/N)?";
	char s2[15];
	sprintf(s2, "SCORE: %d", score);
	glLoadIdentity();
	glColor3f(1,0,0);
	glViewport(0,0,height,height);
	displayCoverScreen(2.3,12,0.015,0.015,s1);
	displayCoverScreen(6.5,9,0.01,0.01,s2);
  	glFlush();
  	glutSwapBuffers();
}

void myidlefunc()
{
	FILE *fp;
    char s[4];
    int t;
    int i,j;
    stop=time(NULL);
    if(stop-start>=5&&genBonus==1)
    {
    	genBonus=0;
    }
    if(posX[0]==posXrand1&&posY[0]==posYrand1&&genBonus==1)
    {
    	genBonus=0;
    	score+=(5-(stop-start));
    }
    	
    if(posX[0]==posXrand&&posY[0]==posYrand)
    {
	   NumOfElem++;
	   interval--;
	   changeLevel++;
	   generateRandom();
	   if(changeLevel%4==0||genBonus==1)
	   {
	   	if(genBonus!=1)
	   	{
		   genBonus=1;
	   	   generateRandom1();
 		   start=time(NULL);
	     }
	   }
	   //printf("\n Snake size = %d",NumOfElem);
	   score+=2;
	   if(in_game>1)
	   {
	   	  if(changeLevel==10)
	   	  {
	   	  	 Sleep(100);
	   	     in_game=3;
	   	     NumOfElem=4;
		     posX[0]=0;
		     posY[0]=10;
		     interval=110;
		     for(i=1;i<NumOfElem;i++)
	         {
		         posX[i]=0;
		         posY[i]=0;
		     }
		     KeyPress='\0';
	      }
	   	  else if(changeLevel==20)
	   	  {
	   	     in_game=4;
	   	     NumOfElem=4;
		     posX[0]=0;
		     posY[0]=10;
		     interval=110;
		     for(i=1;i<NumOfElem;i++)
	         {
		         posX[i]=0;
		         posY[i]=0;
		     }
		     KeyPress='\0';
	      }
	   	  else if(changeLevel==30)
	   	  {
	   	     in_game=5;
	   	     NumOfElem=4;
		     posX[0]=0;
		     posY[0]=10;
		     interval=110;
		     for(i=1;i<NumOfElem;i++)
	         {
		         posX[i]=0;
		         posY[i]=0;
		     }
		     KeyPress='\0';
	      }
	   	  else if(changeLevel==40)
	   	  {
	   	     in_game=6;
	   	     NumOfElem=4;
		     posX[0]=1;
		     posY[0]=10;
		     interval=110;
		     for(i=1;i<NumOfElem;i++)
	         {
		         posX[i]=0;
		         posY[i]=0;
		     }
		     KeyPress='\0';
	      }
	   }
    }
   if(in_game>1&&stop_camp==1)
    {
    	if(in_game==2)
    	{
    		for(i=1;i<NumOfElem;i++)
    		    if(posX[0]<1||posX[0]>=19||posY[0]<1||posY[0]>=19||(posX[0]==posX[i]&&posY[0]==posY[i]))
    		    {
    		    	//glutDisplayFunc(display2);
    		    	glutDisplayFunc(text);
    		    	stop_camp=0;
    		    	glutKeyboardFunc(keyboard);
    		    }
    	}
    	else if(in_game==3)
    	{
    		for(i=1;i<NumOfElem;i++)
    		   if((posX[0]<1&&posY[0]>13) || (posX[0]<1&&posY[0]<6) || (posX[0]>=19&&posY[0]>13) || (posX[0]>=19&&posY[0]<6) || 
			     (posX[0]<6&&posY[0]<1) || (posX[0]<6&&posY[0]>=19) || (posX[0]>15&&posY[0]<1) || (posX[0]>15&&posY[0]>=19) || 
		         ((posX[0]>6&&posX[0]<13)&&(posY[0]<13&&posY[0]>11)) || ((posX[0]>6&&posX[0]<13)&&(posY[0]<8&&posY[0]>6))
		         || (posX[0]==posX[i]&&posY[0]==posY[i]))
		         {
		       	    //glutDisplayFunc(display2);
		       	    glutDisplayFunc(text);
		       	    stop_camp=0;
		       	    glutKeyboardFunc(keyboard);
		         }
    	}
    	else if(in_game==4)
    	{
    		for(i=1;i<NumOfElem;i++)
    		if((posX[0]==posX[i]&&posY[0]==posY[i]) || (posY[0]>=19) || (posY[0]<1) || ((posX[0]>3&&posX[0]<5)&&(posY[0]>5&&posY[0]<14)) ||
		      ((posX[0]>4&&posX[0]<15)&&(posY[0]>5&&posY[0]<7)) || ((posX[0]>14&&posX[0]<16)&&(posY[0]>5&&posY[0]<14)) ||
		      ((posX[0]>4&&posX[0]<8)&&(posY[0]>12&&posY[0]<14)) || ((posX[0]>11&&posX[0]<15)&&(posY[0]>12&&posY[0]<14)))
		      {
		      	  //glutDisplayFunc(display2);
		      	  glutDisplayFunc(text);
		      	  stop_camp=0;
		      	  glutKeyboardFunc(keyboard);
		      }
    	}
    	else if(in_game==5)
    	{
    		for(i=1;i<NumOfElem;i++)
    		if((posX[0]<1&&posY[0]>14) || (posX[0]>14&&posY[0]>=19) || (posX[0]>=19&&posY[0]<5) || (posX[0]<5&&posY[0]<1) || 
	          ((posX[0]>6&&posX[0]<14)&&(posY[0]>15&&posY[0]<17)) || ((posX[0]>2&&posX[0]<9)&&(posY[0]>12&&posY[0]<14)) || 
	          ((posX[0]>10&&posX[0]<17)&&(posY[0]>10&&posY[0]<12)) || ((posX[0]>2&&posX[0]<9)&&(posY[0]>7&&posY[0]<9)) ||
	          ((posX[0]>10&&posX[0]<17)&&(posY[0]>5&&posY[0]<7)) || ((posX[0]>6&&posX[0]<14)&&(posY[0]>2&&posY[0]<4)) || 
		      (posX[0]==posX[i]&&posY[0]==posY[i]))
		      {
		    		//glutDisplayFunc(display2);
		    		glutDisplayFunc(text);
		    		stop_camp=0;
		    		glutKeyboardFunc(keyboard);
		      }
    	}
    	else if(in_game==6)
    	{
    		for(i=1;i<NumOfElem;i++)
		  if(posX[0]<1 || posX[0]>=19 || (posX[0]>13&&posY[0]>=19) || (posX[0]<6&&posY[0]>=19) || (posX[0]<6&&posY[0]<1) || 
	      ((posX[0]>2&&posX[0]<17)&&(posY[0]>15&&posY[0]<17)) || ((posX[0]>2&&posX[0]<4)&&(posY[0]>12&&posY[0]<16)) || 
	      ((posX[0]>15&&posX[0]<17)&&(posY[0]>12&&posY[0]<16)) || ((posX[0]>2&&posX[0]<17)&&(posY[0]>2&&posY[0]<4)) ||
	      ((posX[0]>2&&posX[0]<4)&&(posY[0]>3&&posY[0]<7)) || ((posX[0]>15&&posX[0]<17)&&(posY[0]>3&&posY[0]<7)) || 
	      ((posX[0]>5&&posX[0]<7)&&(posY[0]>5&&posY[0]<14)) || ((posX[0]>6&&posX[0]<8)&&(posY[0]>12&&posY[0]<14)) || 
	      ((posX[0]>6&&posX[0]<8)&&(posY[0]>5&&posY[0]<7)) || ((posX[0]>12&&posX[0]<14)&&(posY[0]>5&&posY[0]<14)) ||
	      ((posX[0]>11&&posX[0]<13)&&(posY[0]>12&&posY[0]<14)) || ((posX[0]>11&&posX[0]<13)&&(posY[0]>5&&posY[0]<7)) ||
	      ((posX[0]>8&&posX[0]<11)&&(posY[0]>8&&posY[0]<11)) || (posX[0]==posX[i]&&posY[0]==posY[i]) || (posX[0]>13&&posY[0]<1)) 
          {
    			//glutDisplayFunc(display2);
    			glutDisplayFunc(text);
    			stop_camp=0;
    			glutKeyboardFunc(keyboard);
    	  }
       }
    }
    
	else
   		if(NumOfElem>4)
    		for(i=1,j=0;i<NumOfElem;i++,j++)
	    		if((posX[0]==posX[i]&&posY[0]==posY[i]))
	   			{
	   				if(in_game>1)
	   				{
	   					if(score>Camp_highscore)
	    				{
	    					if((fp=fopen("file1.txt", "w+")) == NULL) 
			    			{
                   				printf("Cannot open file.\n");
                   				exit(1);
                			}
                			fprintf(fp, "%d",score); 
                			fclose(fp);
                			Camp_highscore=score;
	    				}
            			//printf("\n Highscore: %d",Camp_highscore);
	   				}
	   				else
	   				{
	   					stop_camp=0;
	   					if(score>highscore)
	    				{
	    					if((fp=fopen("file.txt", "w+")) == NULL) 
			    			{
                   				printf("Cannot open file.\n");
                   				exit(1);
                			}
                			fprintf(fp, "%d",score); 
                			fclose(fp);
                			highscore=score;
	    				}
            			//printf("\n Highscore: %d",highscore);
            			glutDisplayFunc(text);
            			glutKeyboardFunc(keyboard);
	   				}
	   				
//	   				glutDisplayFunc(display2);
	   				

	    			
	    		}
   
    if(KeyPress=='r')
	{
     	for(i=NumOfElem-1;i>0;i--)
        {
        	posX[i]=posX[i-1];
        	posY[i]=posY[i-1];
        }
        posX[0]+=move_unit;
        if(posX[0]>=20.0)
        	posX[0]=0.0;
	}
	if(KeyPress=='l')
	{
     	for(i=NumOfElem-1;i>0;i--)
        {
        	posX[i]=posX[i-1];
        	posY[i]=posY[i-1];
        }
        posX[0]-=move_unit;
        if(posX[0]<0.0)
           posX[0]=19.0;
	}
	if(KeyPress=='u')
	{
     	for(i=NumOfElem-1;i>0;i--)
        {
        	posX[i]=posX[i-1];
        	posY[i]=posY[i-1];
        }
        posY[0]+=move_unit;
        if(posY[0]>=20.0)
        	posY[0]=0.0;
	}
	if(KeyPress=='d')
	{
     	for(i=NumOfElem-1;i>0;i--)
        {
        	posX[i]=posX[i-1];
        	posY[i]=posY[i-1];
        }
        posY[0]-=move_unit;
        if(posY[0]<0.0)
        	posY[0]=19.0;
	}
	glutPostRedisplay();
    glutTimerFunc(interval,myidlefunc,1);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void keyboardown(int key, int x, int y)
{
	int i;
    switch (key)
	{
        case GLUT_KEY_RIGHT:
        					if(KeyPress=='l')
			   					KeyPress='l';
        					else
        	  					KeyPress='r';
           				 	break;

        case GLUT_KEY_LEFT:
				        	if(KeyPress=='r')
							   KeyPress='r';
				        	else
				        	   KeyPress='l';
				            break;

        case GLUT_KEY_UP:
				        	if(KeyPress=='d')
							   KeyPress='d';
				        	else
				        	   KeyPress='u';
				            break;

        case GLUT_KEY_DOWN:
					        if(KeyPress=='u')
								KeyPress='u';
					        else
					        	KeyPress='d';
					        break;
        default: break;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char keys,int x,int y)
{
	int i;
	switch(keys)
	{
		case 27:  if(in_game!=0)	//escape
		          {
		          	glutDisplayFunc(resume);
		            glutKeyboardFunc(keyboard);
		            //in_game=0;
		            KeyPress='\0';
		            resume_key=1;
		            break;
		          }
		          else
		        	exit(0);
		        	
	    case 49: //printf("\n Enter name: "); 		//1
    			 //scanf("%s",&name);
    			 stop_camp=1;
				 in_game=1;
	             NumOfElem=4;
	             interval=100;
	             changeLevel=0;
	             score=0;
	             for(i=0;i<NumOfElem;i++)
	             {
		         posX[i]=0;
		         posY[i]=0;
		         }
		         KeyPress='\0';
	             glutDisplayFunc(display);
	             glutSpecialFunc(keyboardown);
	             glutKeyboardFunc(keyboard);
		         break;
		         
		case 50: //printf("\n Enter name: ");		//2
    			 //scanf("%s",&name);
    			 stop_camp=1;
		         in_game=2;
		         generateRandom();
		         NumOfElem=4;
		         score=0;
		         changeLevel=0;
		         posX[0]=1;
		         posY[0]=10;
		         interval=110;
		         for(i=1;i<NumOfElem;i++)
	             {
		         posX[i]=0;
		         posY[i]=0;
		         }
		         KeyPress='\0';
		         glutDisplayFunc(display);
	             glutSpecialFunc(keyboardown);
	             glutKeyboardFunc(keyboard);
		         break;
		         
        case 51: exit(0);
        
        case 13: if(stop_camp==0) //enter
        		 {
        		 	glutDisplayFunc(display2);
                    
        		 }
         		 break;
        case 121: if(resume_key==1)	//y
                  {
                  	glutDisplayFunc(display);
		            glutKeyboardFunc(keyboard);
		            resume_key=0;
                  }
                  break;
        case 89: if(resume_key==1)	//Y
                  {
                  	glutDisplayFunc(display);
		            glutKeyboardFunc(keyboard);
		            resume_key=0;
                  }
                  break;
        case 110: if(resume_key==1)	//n
                  {
                  	glutDisplayFunc(display2);
		            glutKeyboardFunc(keyboard);
		            in_game=0;
		            KeyPress='\0';
		            resume_key=0;
                  }
                  break;
        case 78: if(resume_key==1)	//N
                  {
                  	glutDisplayFunc(display2);
		            glutKeyboardFunc(keyboard);
		            in_game=0;
		            KeyPress='\0';
		            resume_key=0;
                  }
                  break;
	}
}

int main(int argc, char** argv)
{
    FILE *fp;
    char s[4];
    int t;
    printf("\n Enter name: ");
    scanf("%s",&name);
    if(rand_ref==0)
    {
    	rand_ref=1;
    	generateRandom();
    }
    if((fp=fopen("file.txt", "r")) == NULL) 
	{
        fopen("file.txt", "w");
        fprintf(fp, "%d",highscore);
    }
    fgets (s, 4, fp);
    t = atoi(s);
    highscore=t;
    fprintf(fp, "%d",highscore); 
    fclose(fp);
    if((fp=fopen("file1.txt", "r")) == NULL) 
	{
        fopen("file1.txt", "w");
        fprintf(fp, "%d",Camp_highscore);
    }
    fgets (s, 4, fp);
    t = atoi(s);
    Camp_highscore=t;
    fprintf(fp, "%d",Camp_highscore); 
    fclose(fp);
    //printf("\n Main func highscore: %d",highscore);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(GetSystemMetrics(SM_CYSCREEN)-100,GetSystemMetrics(SM_CYSCREEN)-100);
    glutInitWindowPosition(200, 40);
    glutCreateWindow("SNAKE TETRIS");
 	glutDisplayFunc(display2);
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,myidlefunc,0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
