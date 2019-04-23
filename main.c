#include <stdio.h>
#include <GL/glut.h>
#include<math.h>
// #include<AL/al.h>
// #include<AL/al.h>

float coltab[3]= { 0.2,0.2,0.2};//table
float coltab1[3]={ 0.2,0.1,0};
float pos[4]= {30,25,10,0};

float main_zoom = 1.0;
int zoom_in = 1;
int openDoor = 0;
float doorX = 0.1, doorY = 0.1;
float zoom_speed = 0.003;
float zoom_back_speed = 0.003;
float elephantHeadRotation = 0.05;
float elephantHeadRotationAngle = 0;

float elephantLeg1Ypos = -37;
float elephantLeg2Ypos = -37;
float elephantLegMovement = 0.05;
int leg1moved = 0;
int moveElephant = 0;
float elephantScaleVector = 1;
int moveCameraBack = 0;
int scene2Shown = 0;
int scene = 0;
int drum_time = 0;
int transition_to_scene_3 = 0;
int transition_value = 0;
int firework_position = 0;
float drumYaxis = 0;
float drumAddValue = 5;
int firework_size = 0;
GLfloat elephant_scale = 0.0005;
int moveElephantBack = 0;

GLubyte patt[] = {
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x22, 0x22, 0x22, 0x22,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x22, 0x22, 0x22, 0x22,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x22, 0x22, 0x22, 0x22,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x22, 0x22, 0x22, 0x22,
  0x00, 0x00, 0x00, 0x00

};

/* process menu option 'op' */
void menu(int op) {
 
  switch(op) {
  case 'Q':
  case 'q':
    exit(0);
  }
}

void DrawCircle(float cx, float cy, float cz, float r, int num_segments)
{

	int ii;
	float theta, x, y, i;
	glBegin(GL_POLYGON);
	for(ii = 0; ii < num_segments; ii++)
	{
		
		i = (float)ii/(float)num_segments;
		theta = 2.0f*3.1415926f*i;
		x = r * cosf(theta);
		y = r * sinf(theta);
		glVertex3f(x + cx, y + cy, cz);
           
	}
	glEnd();
}

void fireworkWithTrail()
{

}

void drawText(char text[], int x, int y, int z)
{

  // The color, red for me
  glColor3f(0, 0, 0);
  // Position of the text to be printer
  glRasterPos3f(x, y, z);
  for(int i = 0; text[i] != '\0'; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void drawMainScene()
{
  glClearColor(1.0,1.0, 1.0, 1.0);
  char h1[] = "Computer Graphics Project"; 
  char h2[] = "THRISSUR POORAM";
  char h3[] = "by";
  char name1[] = "Musthaq Ahamad";
  char usn1[] = "4SF15CS085";
  char name2[] = "Lalith Sagar Manoj";
  char usn2[] = "4SF15CS066";
  char message[] = "Press Enter to start";

  drawText(h1, -110, 200, 0);
  drawText(h2, -90, 170, 0);
  drawText(h3, -5, 150, 0);
  drawText(name1, -200, 90, 0);
  drawText(usn1, -190, 70, 0);
  drawText(name2, 80, 90, 0);
  drawText(usn2, 100, 70, 0);
  drawText(message, -70, -200, 0);
}

void draw_elephant(int x, int y, int z){

  elephantLeg1Ypos -= (elephantLegMovement);
  if (leg1moved == 1) elephantLeg2Ypos += elephantLegMovement;

  if (elephantLeg1Ypos+y < -42+y){
    if (leg1moved == 0) leg1moved = 1;
    elephantLegMovement = -elephantLegMovement;
  }
  if (elephantLeg1Ypos+y > -37+y) {
    elephantLegMovement = -elephantLegMovement;
  }

  //Elephant Leg right
  glColor3f(0.13, 0.13, 0.13);
  glBegin(GL_POLYGON);
    glVertex3f(22+x, 35+y,z);
    glVertex3f(20+x, 29+y,z);
    glVertex3f(15+x, elephantLeg1Ypos+2+y, z);
    glVertex3f(13+x, elephantLeg1Ypos+1+y, z);
    glVertex3f(9.5+x, elephantLeg1Ypos+y, z);
    glVertex3f(7+x, elephantLeg1Ypos+1+y, z);
    glVertex3f(2+x, elephantLeg1Ypos+2+y, z);
    glVertex3f(0+x, 35+y, z);   
  glEnd();

   //Elephant Leg Left
  glColor3f(0.15, 0.13, 0.15);
  glBegin(GL_POLYGON);
    glVertex3f(-22+x, 35+y,z);
    glVertex3f(-20+x, 29+y,z);
    glVertex3f(-15+x, elephantLeg2Ypos+2+y, z);
    glVertex3f(-13+x, elephantLeg2Ypos+1+y, z);
    glVertex3f(-9.5+x, elephantLeg2Ypos+y, z);
    glVertex3f(-7+x, elephantLeg2Ypos+1+y, z);
    glVertex3f(-2+x, elephantLeg2Ypos+2+y, z);
    glVertex3f(0+x, 35+y, z);   
  glEnd();

  glPushMatrix();
  glRotatef(elephantHeadRotationAngle, 0, 0, 1);
  elephantHeadRotationAngle += elephantHeadRotation;
  if(elephantHeadRotationAngle > 3){
    elephantHeadRotation = -elephantHeadRotation;
  }
  if(elephantHeadRotationAngle < -3){
    elephantHeadRotation = -elephantHeadRotation;
  }
  //Elephant Horn Right
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
    glVertex3f(15+x, 27+y, z);
    glVertex3f(10+x, 27+y, z);
    glVertex3f(10+x, 25+y, z);
    glVertex3f(16+x, 15+y, z);
    glVertex3f(18+x, 12+y, z);
  glEnd();
  //Elephant Horn Left
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-15+x, 27+y, z);
    glVertex3f(-10+x, 27+y, z);
    glVertex3f(-10+x, 25+y, z);
    glVertex3f(-16+x, 15+y, z);
    glVertex3f(-18+x, 12+y, z);
  glEnd();

  //elephant ear Right
  glColor3f(0.15, 0.13, 0.18);
  glBegin(GL_POLYGON);
    glVertex3f(12+x, 62+y, z);
    glVertex3f(18+x, 68+y, z);
    glVertex3f(22+x, 70+y, z);
    glVertex3f(30+x, 65+y, z);
    glVertex3f(28+x, 55+y, z);
    glVertex3f(30+x, 42+y, z);
    glVertex3f(25+x, 32+y, z);
    glVertex3f(20+x, 30+y, z);
    glVertex3f(15+x, 37+y, z);
  glEnd();
  //elephant ear Left
  glColor3f(0.15, 0.13, 0.18);
  glBegin(GL_POLYGON);
    glVertex3f(-12+x, 62+y, z);
    glVertex3f(-18+x, 68+y, z);
    glVertex3f(-22+x, 70+y, z);
    glVertex3f(-30+x, 65+y, z);
    glVertex3f(-28+x, 55+y, z);
    glVertex3f(-30+x, 42+y, z);
    glVertex3f(-25+x, 32+y, z);
    glVertex3f(-20+x, 30+y, z);
    glVertex3f(-15+x, 37+y, z);
  glEnd();

  

  //Elephant head and trunk
  glColor3f(0.17, 0.17, 0.2);
  glBegin(GL_POLYGON);
    glVertex3f(-18+x, 58+y, z);
    glVertex3f(-15+x, 63+y, z);
    glVertex3f(-5+x, 66+y, z);
    glVertex3f(5+x, 66+y, z);
    glVertex3f(15+x, 63+y, z);
    glVertex3f(18+x, 58+y, z);
    glVertex3f(23+x, 45+y, z);
    glVertex3f(15+x, 29+y, z);
    glVertex3f(15+x, 27+y, z);
    glVertex3f(13+x, 27+y, z);
    glVertex3f(6+x, -7+y, z);
    glVertex3f(3+x, -28+y, z);
    glVertex3f(0+x, -30+y, z);
    glVertex3f(-3+x, -28+y, z);
    glVertex3f(-6+x, -7+y, z);
    glVertex3f(-13+x, 27+y, z);
    glVertex3f(-15+x, 27+y, z);
    glVertex3f(-15+x, 29+y, z);
    glVertex3f(-23+x, 45+y, z);
  glEnd();

  glColor3f(1, 0.6, 0.2);
  glBegin(GL_POLYGON);
    glVertex3f(-15+x, 60+y, z);
    glVertex3f(0+x, 65+y, z);
    glVertex3f(15+x, 60+y, z);
    glVertex3f(20+x, 45+y, z);
    glVertex3f(10+x, 20+y, z);
    glVertex3f(5+x, 10+y, z);
    glVertex3f(0+x, 0+y, z);
    glVertex3f(-5+x, 10+y, z);
    glVertex3f(-10+x, 20+y, z);
    glVertex3f(-20+x, 45+y, z);
    glVertex3f(-15+x, 60+y, z);
  glEnd();

  glColor3f(1, 0.9, 0.2);
  glBegin(GL_POLYGON);
    glVertex3f(-13+x, 57+y, z);
    glVertex3f(0+x, 61+y, z);
    glVertex3f(12+x, 57+y, z);
    glVertex3f(17+x, 45+y, z);
    glVertex3f(7+x, 17+y, z);
    glVertex3f(2+x, 7+y, z);
    glVertex3f(0+x, -3+y, z);
    glVertex3f(-2+x, 7+y, z);
    glVertex3f(-7+x, 17+y, z);
    glVertex3f(-17+x, 45+y, z);
    glVertex3f(-12+x, 57+y, z);
  glEnd();

  glColor3f(1, 0.7, 0.2);
  DrawCircle(-8.0+x, 50.0+y, (float)z, 5.0, 30);
  DrawCircle(8.0+x, 50.0+y, (float)z, 5.0, 30);
  DrawCircle(-5.0+x, 40.0+y, (float)z, 3.0, 30);
  DrawCircle(5.0+x, 40.0+y, (float)z, 3.0, 30);
  DrawCircle(0+x, 30.0+y, (float)z, 5.0, 30);
  DrawCircle(0+x, 20.0+y, (float)z, 3.0, 30);

  glPopMatrix();
}

void drawFanElephant(int x, int y, int z){

  int elephantLeg1Ypos = -37;
  int elephantLeg2Ypos = -37;

  //Elephant Leg right
  glColor3f(0.13, 0.13, 0.13);
  glBegin(GL_POLYGON);
    glVertex3f(22+x, 35+y,z);
    glVertex3f(20+x, 29+y,z);
    glVertex3f(15+x, elephantLeg1Ypos+2+y, z);
    glVertex3f(13+x, elephantLeg1Ypos+1+y, z);
    glVertex3f(9.5+x, elephantLeg1Ypos+y, z);
    glVertex3f(7+x, elephantLeg1Ypos+1+y, z);
    glVertex3f(2+x, elephantLeg1Ypos+2+y, z);
    glVertex3f(0+x, 35+y, z);   
  glEnd();

   //Elephant Leg Left
  glColor3f(0.15, 0.13, 0.15);
  glBegin(GL_POLYGON);
    glVertex3f(-22+x, 35+y,z);
    glVertex3f(-20+x, 29+y,z);
    glVertex3f(-15+x, elephantLeg2Ypos+2+y, z);
    glVertex3f(-13+x, elephantLeg2Ypos+1+y, z);
    glVertex3f(-9.5+x, elephantLeg2Ypos+y, z);
    glVertex3f(-7+x, elephantLeg2Ypos+1+y, z);
    glVertex3f(-2+x, elephantLeg2Ypos+2+y, z);
    glVertex3f(0+x, 35+y, z);   
  glEnd();

  glPushMatrix();
  //Elephant Horn Right
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
    glVertex3f(15+x, 27+y, z);
    glVertex3f(10+x, 27+y, z);
    glVertex3f(10+x, 25+y, z);
    glVertex3f(16+x, 15+y, z);
    glVertex3f(18+x, 12+y, z);
  glEnd();
  //Elephant Horn Left
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-15+x, 27+y, z);
    glVertex3f(-10+x, 27+y, z);
    glVertex3f(-10+x, 25+y, z);
    glVertex3f(-16+x, 15+y, z);
    glVertex3f(-18+x, 12+y, z);
  glEnd();

  //elephant ear Right
  glColor3f(0.15, 0.13, 0.18);
  glBegin(GL_POLYGON);
    glVertex3f(12+x, 62+y, z);
    glVertex3f(18+x, 68+y, z);
    glVertex3f(22+x, 70+y, z);
    glVertex3f(30+x, 65+y, z);
    glVertex3f(28+x, 55+y, z);
    glVertex3f(30+x, 42+y, z);
    glVertex3f(25+x, 32+y, z);
    glVertex3f(20+x, 30+y, z);
    glVertex3f(15+x, 37+y, z);
  glEnd();
  //elephant ear Left
  glColor3f(0.15, 0.13, 0.18);
  glBegin(GL_POLYGON);
    glVertex3f(-12+x, 62+y, z);
    glVertex3f(-18+x, 68+y, z);
    glVertex3f(-22+x, 70+y, z);
    glVertex3f(-30+x, 65+y, z);
    glVertex3f(-28+x, 55+y, z);
    glVertex3f(-30+x, 42+y, z);
    glVertex3f(-25+x, 32+y, z);
    glVertex3f(-20+x, 30+y, z);
    glVertex3f(-15+x, 37+y, z);
  glEnd();

  

  //Elephant head and trunk
  glColor3f(0.17, 0.17, 0.2);
  glBegin(GL_POLYGON);
    glVertex3f(-18+x, 58+y, z);
    glVertex3f(-15+x, 63+y, z);
    glVertex3f(-5+x, 66+y, z);
    glVertex3f(5+x, 66+y, z);
    glVertex3f(15+x, 63+y, z);
    glVertex3f(18+x, 58+y, z);
    glVertex3f(23+x, 45+y, z);
    glVertex3f(15+x, 29+y, z);
    glVertex3f(15+x, 27+y, z);
    glVertex3f(13+x, 27+y, z);
    glVertex3f(6+x, -7+y, z);
    glVertex3f(3+x, -28+y, z);
    glVertex3f(0+x, -30+y, z);
    glVertex3f(-3+x, -28+y, z);
    glVertex3f(-6+x, -7+y, z);
    glVertex3f(-13+x, 27+y, z);
    glVertex3f(-15+x, 27+y, z);
    glVertex3f(-15+x, 29+y, z);
    glVertex3f(-23+x, 45+y, z);
  glEnd();

  glColor3f(1, 0.6, 0.2);
  glBegin(GL_POLYGON);
    glVertex3f(-15+x, 60+y, z);
    glVertex3f(0+x, 65+y, z);
    glVertex3f(15+x, 60+y, z);
    glVertex3f(20+x, 45+y, z);
    glVertex3f(10+x, 20+y, z);
    glVertex3f(5+x, 10+y, z);
    glVertex3f(0+x, 0+y, z);
    glVertex3f(-5+x, 10+y, z);
    glVertex3f(-10+x, 20+y, z);
    glVertex3f(-20+x, 45+y, z);
    glVertex3f(-15+x, 60+y, z);
  glEnd();

  glColor3f(1, 0.9, 0.2);
  glBegin(GL_POLYGON);
    glVertex3f(-13+x, 57+y, z);
    glVertex3f(0+x, 61+y, z);
    glVertex3f(12+x, 57+y, z);
    glVertex3f(17+x, 45+y, z);
    glVertex3f(7+x, 17+y, z);
    glVertex3f(2+x, 7+y, z);
    glVertex3f(0+x, -3+y, z);
    glVertex3f(-2+x, 7+y, z);
    glVertex3f(-7+x, 17+y, z);
    glVertex3f(-17+x, 45+y, z);
    glVertex3f(-12+x, 57+y, z);
  glEnd();

  glColor3f(1, 0.7, 0.2);
  DrawCircle(-8.0+x, 50.0+y, (float)z, 5.0, 30);
  DrawCircle(8.0+x, 50.0+y, (float)z, 5.0, 30);
  DrawCircle(-5.0+x, 40.0+y, (float)z, 3.0, 30);
  DrawCircle(5.0+x, 40.0+y, (float)z, 3.0, 30);
  DrawCircle(0+x, 30.0+y, (float)z, 5.0, 30);
  DrawCircle(0+x, 20.0+y, (float)z, 3.0, 30);

  glPopMatrix();
}
/* function to draw the ladscape */
void draw_landscape(){

  glPushMatrix();
  glBegin(GL_POLYGON); //Green grass
  glColor3f(0.2, 0.4, 0);
    glVertex3f(-670, 0, -2);
    glVertex3f(670, 0, -2);
    glVertex3f(670, -350, -2);
    glVertex3f(-670, -350, -2);
  glEnd();

  glBegin(GL_POLYGON); //temple shadow 
  glColor3f(0.1, 0.3, 0);
    glVertex3f(-250, -50, -1);
    glVertex3f(250, -50, -1);
    glVertex3f(320, -140, -1);
    glVertex3f(-320, -140, -1);
  glEnd();

  glBegin(GL_POLYGON); //compoumd
  glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-670, 10, -1);
    glVertex3f(670, 10, -1);
    glVertex3f(670, -45, -1);
    glVertex3f(-670,-45, -1);
  glEnd();
  glBegin(GL_POLYGON); //compund top
  glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-670, 10, -1);
    glVertex3f(670, 10, -1);
    glVertex3f(670, 20, -1);
    glVertex3f(-670, 20, -1);
  glEnd();

  glBegin(GL_POLYGON);
    glColor4f(0.2, 0.2, 0.2, 0.5);
    glVertex3f(-60, -120, -1);
    glVertex3f(60, -120, -1);
    glVertex3f(200, -350, -1);
    glVertex3f(-200, -350, -1);
  glEnd();
  glPopMatrix();
}

void draw_door() {

  if( openDoor == 1){
    if( doorX < 30 && doorX > 0.1){
      doorX += 0.3;
    }else{
      zoom_in = 0;
      openDoor = 0;
      if(moveElephant == 0)
        moveElephant = 1;
    }

    if( doorY < 10 && doorY > 0.1){
      doorY += 0.1;
    }
  }

  

  glColor3f(0.65, 0.35, 0.15);
    glBegin(GL_POLYGON); //Door border@6
      glVertex3f(-50, -120, 2);
      glVertex3f(50, -120, 2);
      glVertex3f(50, 0, 2);
      glVertex3f(-50, 0, 2);
    glEnd(); 
    glColor3f(0.3,0.3, 0.3);
    glBegin(GL_POLYGON); //Door border
      glVertex3f(-45, -120, 2);
      glVertex3f(45, -120, 2);
      glVertex3f(45, -5, 2);
      glVertex3f(-45, -5, 2);
    glEnd();

    glPushMatrix();
        if(moveElephant == 1 && elephantScaleVector < 2.5) {
          elephantScaleVector= elephantScaleVector+elephant_scale;
          if (elephantScaleVector > 1.2)
            moveCameraBack = 1;
        }


        if (elephantScaleVector >= 2.5){
          elephantLegMovement = 0;
          transition_to_scene_3 = 1;
          
        }

        if (elephantScaleVector >= 1.2 && scene2Shown == 0){
          scene=2;
          scene2Shown == 1;
        }

      glScalef(elephantScaleVector, elephantScaleVector, elephantScaleVector);
      draw_elephant(0, -80, 2);
    glPopMatrix();

    glPushMatrix();
      if(moveElephant == 1){
        glScalef(2.3, 2.3, 2.3);
        drawFanElephant(-100, -80, 2);
        drawFanElephant(-200, -80, 2);
        drawFanElephant(-300, -80, 2);
        drawFanElephant( 100, -80, 2);
        drawFanElephant( 200, -80, 2);
        drawFanElephant( 300, -80, 2);
      }
    glPopMatrix();

    glColor3f(0.8,0.4, 0);
    glBegin(GL_POLYGON); //Door
      glVertex3f(-45, -120, 2);
      glVertex3f(-2-doorX, -120+doorY, 2);
      glVertex3f(-2-doorX, -5-doorY, 2);
      glVertex3f(-45, -5, 2);
    glEnd();
    glColor3f(0.8,0.4, 0);
    glBegin(GL_POLYGON); //Door
      glVertex3f(-45, -120, 2);
      glVertex3f(-2-doorX, -120+doorY, 2);
      glVertex3f(-2-doorX, -5-doorY, 2);
      glVertex3f(-45, -5, 2);
    glEnd();
    
    glBegin(GL_POLYGON); //Door
      glVertex3f(45, -120 , 2);
      glVertex3f(2+doorX, -120+doorY , 2);
      glVertex3f(2+doorX, -5-doorY, 2);
      glVertex3f(45, -5, 2);
    glEnd();
}

void draw_temple() {
  glPushMatrix();
    //body lower ground
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
      glVertex3f(-250, -100, 0);
      glVertex3f(250, -100, 0);
      glVertex3f(250, 40, 0);
      glVertex3f(-250, 40, 0);
    glEnd();
    glColor3f(0.4, 0.4, 0.4); //roof shadow
    glBegin(GL_POLYGON);
      glVertex3f(-250, 40, 0);
      glVertex3f(250, 40, 0);
      glVertex3f(250, -10, 0);
      glVertex3f(-250, -10, 0);
    glEnd();
    glColor3f(0.6, 0.6, 0.6); //kaathana
    glBegin(GL_POLYGON);
      glVertex3f(-260, -100, 0);
      glVertex3f(260, -100, 0);
      glVertex3f(260, -70, 0);
      glVertex3f(-260, -70, 0);
    glEnd();
    glColor3f(0.5,0.1,0.0); //roof extension bg
    glBegin(GL_POLYGON);
      glVertex3f(-280, 10, -1);
      glVertex3f(280, 10, -1);
      glVertex3f(240, -5, -1);
      glVertex3f(-240, -5, -1);
    glEnd();

    //roof
    glColor3f(0.7,0.3,0.1);
    glBegin(GL_POLYGON);
      glVertex3f(-280, 10, 1);
      glVertex3f(280, 10, 1);
      glVertex3f(240, 55, 1);
      glVertex3f(-240, 55, 1);
    glEnd();
  //second floor
  //body
  glColor3f(0.5, 0.5, 0.5);
  glBegin(GL_POLYGON);
      glVertex3f(-240, 50, 0);
      glVertex3f(240, 50, 0);
      glVertex3f(240, 110, 0);
      glVertex3f(-240, 110, 0);
  glEnd();
  glColor3f(0.4, 0.4, 0.4); //roof shadow
    glBegin(GL_POLYGON);
      glVertex3f(-240, 110, 1);
      glVertex3f(240, 110, 1);
      glVertex3f(240, 70, 1);
      glVertex3f(-240, 70, 1);
    glEnd();
    glColor3f(0.5,0.1,0.0); //roof extension bg
    glBegin(GL_POLYGON);
      glVertex3f(-270, 90, -1);
      glVertex3f(270, 90, -1);
      glVertex3f(200, 50, -1);
      glVertex3f(-200, 50, -1);
    glEnd();
    //roof
    glColor3f(0.7,0.3,0.1);
    glBegin(GL_POLYGON);
      glVertex3f(-210, 150, 1);
      glVertex3f(210, 150, 1);
      glVertex3f(270, 90, 1);
      glVertex3f(-270, 90, 1);
    glEnd();

    //Third floor
    //body
  glColor3f(0.5, 0.5, 0.5);
  glBegin(GL_POLYGON);
      glVertex3f(-210, 130, 0);
      glVertex3f(210, 130, 0);
      glVertex3f(210, 190, 0);
      glVertex3f(-210, 190, 0);
  glEnd();
  glColor3f(0.45, 0.45, 0.45); //roof shadow
    glBegin(GL_POLYGON);
      glVertex3f(-210, 130, 0);
      glVertex3f(210, 130, 0);
      glVertex3f(210, 190, 0);
      glVertex3f(-210, 190, 0);
  glEnd();
  glColor3f(0.5,0.1,0.0); //roof extension bg
    glBegin(GL_POLYGON);
      glVertex3f(-250, 170, -1);
      glVertex3f(250, 170, -1);
      glVertex3f(190, 150, -1);
      glVertex3f(-190, 150, -1);
    glEnd();
    //roof
    glColor3f(0.7,0.3,0.1);
    glBegin(GL_POLYGON);
      glVertex3f(-200, 230, 1);
      glVertex3f(200, 230, 1);
      glVertex3f(250, 170, 1);
      glVertex3f(-250, 170, 1);
    glEnd();
    glColor3f(0.5,0.1,0.0); //roof2 extension bg
    glBegin(GL_POLYGON);
      glVertex3f(-220, 230, -1);
      glVertex3f(220, 230, -1);
      glVertex3f(190, 200, -1);
      glVertex3f(-190, 200, -1);
    glEnd();
    glColor3f(0.7,0.3,0.1);
    glBegin(GL_POLYGON);
      glVertex3f(-220, 230, 1);
      glVertex3f(220, 230, 1);
      glVertex3f(190, 290, 1);
      glVertex3f(-190, 290, 1);
    glEnd();

    //front
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
      glVertex3f(-100, -120, 2);
      glVertex3f(100, -120, 2);
      glVertex3f(100, 40, 2);
      glVertex3f(-100, 40, 2);
    glEnd();
     glColor3f(0.6, 0.6, 0.6); //roof shadow
    glBegin(GL_POLYGON);
      glVertex3f(-100, 40, 2);
      glVertex3f(100, 40, 2);
      glVertex3f(100, 0, 2);
      glVertex3f(-100, 0, 2);
    glEnd();
    glColor3f(0.65, 0.65, 0.65);
    glBegin(GL_POLYGON); //kaathana
      glVertex3f(-110, -120, 2);
      glVertex3f(110, -120, 2);
      glVertex3f(110, -80, 2);
      glVertex3f(-110, -80, 2);
    glEnd();
    
    draw_door();

  glColor3f(0.65,0.25,0.1);//roof shadow bg
    glBegin(GL_POLYGON);
      glVertex3f(-140, 10, 1);
      glVertex3f(140, 10, 1);
      glVertex3f(120, 55, 1);
      glVertex3f(-120, 55, 1);
    glEnd();
    glColor3f(0.4, 0.4, 0.4); //roof shadow
    glBegin(GL_POLYGON);
      glVertex3f(-130, 80, 0);
      glVertex3f(130, 80, 0);
      glVertex3f(100, 60, 0);
      glVertex3f(-100, 60, 0);
    glEnd();
    glColor3f(0.5,0.1,0.0); //roof back
    glBegin(GL_POLYGON);
      glVertex3f(-130, 20, 1);
      glVertex3f(130, 20, 1);
      glVertex3f(90, 5, 1);
      glVertex3f(-90, 5, 1);
    glEnd();
    //front stage1 roof
    glColor3f(0.7,0.3,0.1);
    glBegin(GL_POLYGON);
      glVertex3f(-130, 20, 2);
      glVertex3f(130, 20, 2);
      glVertex3f(90, 80, 2);
      glVertex3f(-90, 80, 2);
    glEnd();

    //front stage 2
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
      glVertex3f(-90, 80, 2);
      glVertex3f(90, 80, 2);
      glVertex3f(90, 130, 2);
      glVertex3f(-90, 130, 2);
    glEnd();
    glColor3f(0.6, 0.6, 0.6); //roof shadow on body
    glBegin(GL_POLYGON);
      glVertex3f(-90, 130, 2);
      glVertex3f(90, 130, 2);
      glVertex3f(90, 90, 2);
      glVertex3f(-90, 90, 2);
    glEnd();
    glColor3f(0.65,0.25,0.1);//roof shadow bg
    glBegin(GL_POLYGON);
      glVertex3f(-130, 90, 1);
      glVertex3f(130, 90, 1);
      glVertex3f(100, 150, 1);
      glVertex3f(-100, 150, 1);
    glEnd();
    glColor3f(0.5,0.1,0.0); //roof back
    glBegin(GL_POLYGON);
      glVertex3f(-120, 100, 1);
      glVertex3f(120, 100, 1);
      glVertex3f(90, 90, 1);
      glVertex3f(-90, 90, 1);
    glEnd();
    glColor3f(0.7,0.3,0.1); //front stage2 roof
    glBegin(GL_POLYGON);
      glVertex3f(-120, 100, 2);
      glVertex3f(120, 100, 2);
      glVertex3f(90, 160, 2);
      glVertex3f(-90, 160, 2);
    glEnd();

    glColor3f(0.85,0.85,0.8); //Name Board
    glBegin(GL_POLYGON);
      glVertex3f(-75, 135, 3);
      glVertex3f(75, 135, 3);
      glVertex3f(75, 170, 3);
      glVertex3f(-75, 170, 3);
    glEnd();

    
    
    //stage 3
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
      glVertex3f(-90, 160, 2);
      glVertex3f(90, 160, 2);
      glVertex3f(90, 180, 2);
      glVertex3f(-90, 180, 2);
    glEnd();
    glColor3f(0.65,0.25,0.1);//roof shadow bg
    glBegin(GL_POLYGON);
      glVertex3f(-130, 170, 1);
      glVertex3f(130, 170, 1);
      glVertex3f(80, 230, 1);
      glVertex3f(-80, 230, 1);
    glEnd();
    glColor3f(0.5,0.1,0.0); //roof back
    glBegin(GL_POLYGON);
      glVertex3f(-120, 175, 1);
      glVertex3f(120, 175, 1);
      glVertex3f(80, 160, 1);
      glVertex3f(-80, 160, 1);
    glEnd();
    glColor3f(0.7,0.3,0.1); //front stage3 roof
    glBegin(GL_POLYGON);
      glVertex3f(-120, 175, 2);
      glVertex3f(120, 175, 2);
      glVertex3f(80, 220, 2);
      glVertex3f(-80, 220, 2);
    glEnd();

    //final top
    glColor3f(0.5,0.5,0.5); //front stage3 roof
    glBegin(GL_POLYGON);
      glVertex3f(80, 220, 2);
      glVertex3f(-80, 220, 2);
      glVertex3f(0, 300, 2);
    glEnd();
    glColor3f(0.6,0.2,0.1);
    glBegin(GL_POLYGON);
      glVertex3f(70, 220, 2);
      glVertex3f(-70, 220, 2);
      glVertex3f(0, 290, 2);
    glEnd();

    


  glPopMatrix();
}


void drawTempleSideWays()
{
  glBegin(GL_POLYGON); //Green grass
  glColor3f(0.2, 0.4, 0);
    glVertex3f(-670,-250, -2);
    glVertex3f(670, -250, -2);
    glVertex3f(670, -350, -2);
    glVertex3f(-670, -350, -2);
  glEnd();

  glBegin(GL_POLYGON); //kaathana
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(200, -275, 3);
    glVertex3f(670, -275, 3);
    glVertex3f(670, -190, 3);
    glVertex3f(200, -190, 3);
  glEnd();

  glBegin(GL_POLYGON); //body
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(230, -190, 3);
    glVertex3f(670, -190, 3);
    glVertex3f(670, 450, 3);
    glVertex3f(230, 450, 3);
  glEnd();

  glBegin(GL_POLYGON); //roof shadow
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(230, 150, 3);
    glVertex3f(670, 150, 3);
    glVertex3f(670, 450, 3);
    glVertex3f(230, 450, 3);
  glEnd();

  glBegin(GL_POLYGON); //roof
    glColor3f(0.7,0.3,0.1);
    glVertex3f(100, 200, 4);
    glVertex3f(670, 200, 4);
    glVertex3f(670, 420, 4);
    glVertex3f(230, 370, 4);
  glEnd();
}

void drawChenda(int x, int y)
{

  if(scene == 1)
    return;
  

  glPushMatrix();
  glTranslatef(-200, -300, -5);
  glScalef(1.47, 2, 0.5);
    glColor3f(0.7,0.4,0.2);
    glutSolidCube(300);
  glPopMatrix();

  glPushMatrix();
  glScalef(1, 0.3, 5);
  glColor3f(0.8,0.5,0.3);
  DrawCircle(x, y, 50, 220, 100);
  glColor3f(0.8,0.8,0.8);
  DrawCircle(x, y, 50, 200, 100);
  glPopMatrix();

  glPushMatrix();
    glColor3f(0.9,0.6,0.1);
    glRotatef(-10, 0, 0, 1);
    glBegin(GL_POLYGON);
      glVertex3f(0, -400, 99);
      glVertex3f(10, -400, 99);
      glVertex3f(10, 10, 99);
      glVertex3f(0, 10, 99);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex3f(-100, -400, 99);
      glVertex3f(-110, -400, 99);
      glVertex3f(-110, 10, 99);
      glVertex3f(-100, 10, 99);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex3f(-200, -400, 99);
      glVertex3f(-210, -400, 99);
      glVertex3f(-210, 10, 99);
      glVertex3f(-200, 10, 99);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex3f(-300, -450, 99);
      glVertex3f(-310, -450, 99);
      glVertex3f(-310, 0, 99);
      glVertex3f(-300, 00, 99);
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glColor3f(0.9,0.6,0.1);
    glRotatef(10, 0, 0, 1);

    glBegin(GL_POLYGON);
      glVertex3f(-100, -400, 99);
      glVertex3f(-110, -400, 99);
      glVertex3f(-110, 10, 99);
      glVertex3f(-100, 10, 99);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex3f(-200, -400, 99);
      glVertex3f(-210, -400, 99);
      glVertex3f(-210, 10, 99);
      glVertex3f(-200, 10, 99);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex3f(-300, -450, 99);
      glVertex3f(-310, -450, 99);
      glVertex3f(-310, 0, 99);
      glVertex3f(-300, 00, 99);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex3f(-400, -450, 99);
      glVertex3f(-410, -450, 99);
      glVertex3f(-410, 60, 99);
      glVertex3f(-400, 60, 99);
    glEnd();
  glPopMatrix();
 
}

void drawDrumSticks()
{


  drumYaxis+= drumAddValue;
  if (drumYaxis > 30){
      drumAddValue = -drumAddValue;
  }
  if (drumYaxis < -10){
    drumAddValue = -drumAddValue;
    drum_time++;
  }

  if (drum_time > 20){
    scene = 1;
    scene2Shown = 1;
    glutPostRedisplay();
  }
  //if (drumYaxis > )
   glPushMatrix();
  glColor3f(0.5,0.3,0.1);
  glBegin(GL_POLYGON);
    glVertex3f(-410, 90, 300);
    glVertex3f(-410, 80, 300);
    glVertex3f(-180, 10-drumYaxis, 300);
    glVertex3f(-180, 20-drumYaxis, 300);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.5,0.3,0.1);
  glBegin(GL_POLYGON);
    glVertex3f(-410, 80, 300);
    glVertex3f(-410, 70, 300);
    glVertex3f(-180, 10+drumYaxis, 300);
    glVertex3f(-180, 20+drumYaxis, 300);
  glEnd();
  glPopMatrix();
}
/* executed when a regular key is pressed */
void keyboardDown(unsigned char key, int x, int y) {
 
  switch(key) {
  case 13: //enter key
    scene = 1;
    break;
  case 'Q':
  case 'q':
  case  27:   // ESC
    exit(0);
  }
}
 
/* executed when a regular key is released */
void keyboardUp(unsigned char key, int x, int y) {
 
}
 
/* executed when a special key is pressed */
void keyboardSpecialDown(int k, int x, int y) {
 
}
 
/* executed when a special key is released */
void keyboardSpecialUp(int k, int x, int y) {
 
}
 
/* reshaped window */
void reshape(int width, int height) {
 
  GLfloat fieldOfView = 90.0f;
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);
 
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-662, 662, -350, 350, -450, 450);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
 
/* executed when button 'button' is put into state 'state' at screen position ('x', 'y') */
void mouseClick(int button, int state, int x, int y) {
 
}
 
/* executed when the mouse moves to position ('x', 'y') */
void mouseMotion(int x, int y) {
 
}

void drawFireworks()
{
  if (firework_size < 100)
  {
    firework_size++;
    glEnable(GL_POLYGON_STIPPLE);
    glPolygonStipple(patt);
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(300, 350, 0, firework_size, 100);
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(-430, 470, 0, firework_size, 100);
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(-300, 350, 0, firework_size, 100);
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(430, 470, 0, firework_size, 100);
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(0, 470, 0, firework_size, 100);
    glDisable(GL_POLYGON_STIPPLE);
  }
  
}

void scene1()
{
      if (transition_to_scene_3 == 1)
      {
        glClearColor(0.2f, 0.2f, 0.3f, 1.0f );
      } else {
        glClearColor(0.2f, 0.8f, 1.0f, 1.0f );
      }

      if (transition_to_scene_3 == -1)
      {

      }

      glPushMatrix();
      glScalef(main_zoom, main_zoom, 1); 
      if (transition_to_scene_3 == 1 && transition_value > -300){
        transition_value -= 2;
        glTranslatef(0, transition_value, 0);
      }else if (transition_value <= -300){
        glTranslatef(0, transition_value, 0);
        drawFireworks();
      }
      draw_landscape();
      draw_temple();
      glPopMatrix();
      
}

void scene2()
{
      drawTempleSideWays();
      glPushMatrix();
      glTranslatef(-300, -50, 0);
      glRotatef(-10, 0, 0, 1);
      drawChenda(-200, 0);
      drawDrumSticks();
      glPopMatrix();
}
 
/* render the scene */
void draw() {
 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 
  /* render the scene here */

  switch(scene)
  {
    case 0:
      drawMainScene();
      break;
    case 1:
      scene1();
      break;
    case 2:
      scene2();
      break;

  }
 
   
  glFlush();
  glutSwapBuffers();
}
 
/* executed when program is idle */
void idle() { 

if(scene == 1)
{
  if(zoom_in == 1 && main_zoom < 3.9)
    main_zoom += zoom_speed;
  else if( openDoor == 0 && moveElephant == 0){
    zoom_in = -1;
    openDoor = 1;
  }

  if(zoom_in == 0 && moveCameraBack == 1 && openDoor == 0 && main_zoom > 1.0){
    main_zoom -= zoom_back_speed;
  }
}
  


  glutPostRedisplay();
}
 
/* initialize OpenGL settings */
void initGL(int width, int height) {
 
  reshape(width, height);
 
  glClearColor(0.2f, 0.8f, 1.0f, 1.0f );
  glClearDepth(1.0f);
 
	glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  
}
 
/* initialize GLUT settings, register callbacks, enter main loop */
int main(int argc, char** argv) {
   
  glutInit(&argc, argv);
 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1244, 700);
  glutInitWindowPosition(100, 0);
  glutCreateWindow("Thrissur Pooram");
 
  // register glut call backs
  glutKeyboardFunc(keyboardDown);
  glutKeyboardUpFunc(keyboardUp);
  glutSpecialFunc(keyboardSpecialDown);
  glutSpecialUpFunc(keyboardSpecialUp);
  glutMouseFunc(mouseClick);
  glutMotionFunc(mouseMotion);
  glutReshapeFunc(reshape);
  glutDisplayFunc(draw);  
  glutIdleFunc(idle);
  glutIgnoreKeyRepeat(1); // ignore keys held down
 
  // create a sub menu 
  int subMenu = glutCreateMenu(menu);
  glutAddMenuEntry("Do nothing", 0);
  glutAddMenuEntry("Really Quit", 'q');
 
  // create main "right click" menu
  glutCreateMenu(menu);
  glutAddSubMenu("Sub Menu", subMenu);
  glutAddMenuEntry("Quit", 'q');
  glutAttachMenu(GLUT_RIGHT_BUTTON);
 
  initGL(1244, 700);
  glutMainLoop();
  return 0;
}