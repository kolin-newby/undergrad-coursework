/*  Homework 5
 *
 *  Key bindings:
 *  l          Toggles lighting
 *  a/A        Toggle axes
 *  m          Toggles light movement
 *  []         Lower/rise light
 *  p          Toggles ortogonal/perspective projection
 *  +/-        Change field of view of perspective
 *  arrows     Change view angle
 *  PgDn/PgUp  Zoom in and out
 *  0          Reset view angle
 *  ESC        Exit
 */
#include "CSCIx229.h"

int axes=1;       //  Display axes
int mode=1;       //  Projection mode
int move=1;       //  Move light
int th=-30;         //  Azimuth of view angle
int ph=35;         //  Elevation of view angle
int fov=65;       //  Field of view (for perspective)
int obj=0;        //  Scene/opbject selection
double asp=1;     //  Aspect ratio
double dim=3;     //  Size of world
// Light values
int light     =   1;  // Lighting
int one       =   1;  // Unit value
int distance  =   5;  // Light distance
int inc       =  10;  // Ball increment
int smooth    =   1;  // Smooth/Flat shading
int local     =   0;  // Local Viewer Model
int emission  =   0;  // Emission intensity (%)
int ambient   =  10;  // Ambient intensity (%)
int diffuse   =  50;  // Diffuse intensity (%)
int specular  =   0;  // Specular intensity (%)
int shininess =   0;  // Shininess (power of two)
float shiny   =   1;  // Shininess (value)
int zh        =  90;  // Light azimuth
float ylight  =   3;  // Elevation of light
typedef struct {float x,y,z;} vtx;
typedef struct {int A,B,C;} tri;
#define n 500
vtx is[n];


static void scene(double x,double y,double z,
                 double dx,double dy,double dz,
                 double th)
{
   glPushMatrix();
   //  Offset
   glTranslated(x,y,z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);

   glColor4f(0.59,0.59,0.59,1);
   
   glBegin(GL_POLYGON);
   
   glNormal3f(0,-1,0);
   for (int theta = 0; theta < 360; theta++) {
      glVertex3f(Sin(theta), 0, Cos(theta));
   }

   glEnd();

   glBegin(GL_QUAD_STRIP);
   
   for (int theta = 0; theta < 361; theta++) {
      glNormal3f(Sin(theta),0,Cos(theta));
      glVertex3f(Sin(theta), 0, Cos(theta));
      glVertex3f(Sin(theta), 4.5, Cos(theta));
   }

   glEnd();

   // -------------------------------Door Frame x-dir

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.38, 0, 1.1);
   glVertex3f(0.30, 0, 1.1);
   glVertex3f(0.30, 1, 1.1);
   glVertex3f(0.38, 1, 1.1);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(-0.38, 0, 1.1);
   glVertex3f(-0.30, 0, 1.1);
   glVertex3f(-0.30, 1, 1.1);
   glVertex3f(-0.38, 1, 1.1);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.38, 1, 1.1);
   glVertex3f(-0.38, 1, 1.1);
   glVertex3f(-0.38, 1.08, 1.1);
   glVertex3f(0.38, 1.08, 1.1);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.38, 1, 1.1);
   glVertex3f(-0.38, 1, 1.1);
   glVertex3f(-0.38, 1.08, 1.1);
   glVertex3f(0.38, 1.08, 1.1);

   glEnd();

   // --------------------------Door Frame z-dir

   glBegin(GL_POLYGON);
   
   glNormal3f(1,0,0);
   glVertex3f(0.38, 1.08, 1.1);
   glVertex3f(0.38, 0, 1.1);
   glVertex3f(0.38, 0, 0);
   glVertex3f(0.38, 1.08, 0);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(-1,0,0);
   glVertex3f(-0.38, 1.08, 1.1);
   glVertex3f(-0.38, 0, 1.1);
   glVertex3f(-0.38, 0, 0);
   glVertex3f(-0.38, 1.08, 0);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,1,0);
   glVertex3f(0.38, 1.08, 1.1);
   glVertex3f(0.38, 1.08, 0);
   glVertex3f(-0.38, 1.08, 0);
   glVertex3f(-0.38, 1.08, 1.1);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,-1,0);
   glVertex3f(0.38, 0, 1.1);
   glVertex3f(0.38, 0, 0);
   glVertex3f(-0.38, 0, 0);
   glVertex3f(-0.38, 0, 1.1);

   glEnd();

   // -----------------------------------Window Frame x-dir

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.38, 2.75, 1.01);
   glVertex3f(0.30, 2.75, 1.01);
   glVertex3f(0.30, 4, 1.01);
   glVertex3f(0.38, 4, 1.01);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(-0.38, 2.75, 1.01);
   glVertex3f(-0.30, 2.75, 1.01);
   glVertex3f(-0.30, 4, 1.01);
   glVertex3f(-0.38, 4, 1.01);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.38, 4, 1.01);
   glVertex3f(-0.38, 4, 1.01);
   glVertex3f(-0.38, 4.08, 1.01);
   glVertex3f(0.38, 4.08, 1.01);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.38, 4, 1.01);
   glVertex3f(-0.38, 4, 1.01);
   glVertex3f(-0.38, 4.08, 1.01);
   glVertex3f(0.38, 4.08, 1.01);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.38, 2.75, 1.01);
   glVertex3f(-0.38, 2.75, 1.01);
   glVertex3f(-0.38, 2.67, 1.01);
   glVertex3f(0.38, 2.67, 1.01);

   glEnd();

   // -------------------------------------Window Frame z-dir

   glBegin(GL_POLYGON);
   
   glNormal3f(1,0,0);
   glVertex3f(0.38, 4.08, 1.01);
   glVertex3f(0.38, 2.67, 1.01);
   glVertex3f(0.38, 2.67, 0);
   glVertex3f(0.38, 4.08, 0);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(-1,0,0);
   glVertex3f(-0.38, 4.08, 1.01);
   glVertex3f(-0.38, 2.67, 1.01);
   glVertex3f(-0.38, 2.67, 0);
   glVertex3f(-0.38, 4.08, 0);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,1,0);
   glVertex3f(0.38, 4.08, 1.01);
   glVertex3f(0.38, 4.08, 0);
   glVertex3f(-0.38, 4.08, 0);
   glVertex3f(-0.38, 4.08, 1.01);

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,-1,0);
   glVertex3f(0.38, 2.67, 1.01);
   glVertex3f(0.38, 2.67, 0);
   glVertex3f(-0.38, 2.67, 0);
   glVertex3f(-0.38, 2.67, 1.01);

   glEnd();

   //------------------------------------Roof

   glColor4f(0.22,0.14,0.05,1);

   glBegin(GL_POLYGON);
   
   glNormal3f(0,-1,0);
   for (int theta = 0; theta < 361; theta++) {
      glVertex3f(1.1 * Sin(theta), 4.5, 1.1 * Cos(theta));
   }

   glEnd();


   glBegin(GL_TRIANGLE_FAN);
   
   for (int theta = 0; theta < 362; theta++) {
      glNormal3f(Sin(theta),1,Cos(theta)); //45-45 triangle
      glVertex3f(1.1 * Sin(theta), 4.5, 1.1 * Cos(theta));
      glVertex3f(0, 5.6, 0);
   }

   glEnd();

   // -----------------------------Door

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.3, 0, 1.1);
   glVertex3f(-0.3, 0, 1.1);
   glVertex3f(-0.3, 1, 1.1);
   glVertex3f(0.3, 1, 1.1);

   glEnd();

   // ------------------------------Window

   glColor4f(0.5,0.5,1,1);

   glBegin(GL_POLYGON);
   
   glNormal3f(0,0,1);
   glVertex3f(0.3, 2.75, 1.01);
   glVertex3f(-0.3, 2.75, 1.01);
   glVertex3f(-0.3, 4, 1.01);
   glVertex3f(0.3, 4, 1.01);

   glEnd();

   // ------------------------Pole

   glColor4f(0.22,0.14,0.05,1);

   glBegin(GL_QUAD_STRIP);
   
   for (int theta = 0; theta < 361; theta++) {
      glNormal3f(Sin(theta),0,Cos(theta));
      glVertex3f(0.05 * Sin(theta), 5, 0.05 * Cos(theta));
      glVertex3f(0.05 * Sin(theta), 6.25, 0.05 * Cos(theta));
   }

   glEnd();

   glBegin(GL_POLYGON);
   
   glNormal3f(0,1,0);
   for (int theta = 0; theta < 361; theta++) {
      glVertex3f(0.05 * Sin(theta), 6.25, 0.05 * Cos(theta));
   }

   glEnd();

   // ----------------------------------Flag

   glColor4f(1,0,0,1);

   glBegin(GL_TRIANGLES);
   
   glNormal3f(0,0,1);
   glVertex3f(0, 6.25, 0);
   glVertex3f(0, 5.75, 0);
   glVertex3f(-1.2, 6, 0);

   glNormal3f(0,0,-1);
   glVertex3f(0, 6.25, -0.001);
   glVertex3f(0, 5.75, -0.001);
   glVertex3f(-1.2, 6, -0.001);

   glEnd();

   //  Undo transformations
   glPopMatrix();
}



static void Vertex(double th,double ph)
{
   double x = Sin(th)*Cos(ph);
   double y = Cos(th)*Cos(ph);
   double z =         Sin(ph);
   //  For a sphere at the origin, the position
   //  and normal vectors are the same
   glNormal3d(x,y,z);
   glVertex3d(x,y,z);
}


static void ball(double x,double y,double z,double r)
{
   int th,ph;
   float yellow[] = {1.0,1.0,0.0,1.0};
   float Emission[]  = {0.0,0.0,0.01*emission,1.0};
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glScaled(r,r,r);
   //  White ball
   glColor3f(1,1,1);
   glMaterialf(GL_FRONT,GL_SHININESS,shiny);
   glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);
   glMaterialfv(GL_FRONT,GL_EMISSION,Emission);
   //  Bands of latitude
   for (ph=-90;ph<90;ph+=inc)
   {
      glBegin(GL_QUAD_STRIP);
      for (th=0;th<=360;th+=2*inc)
      {
         Vertex(th,ph);
         Vertex(th,ph+inc);
      }
      glEnd();
   }
   //  Undo transofrmations
   glPopMatrix();
}

/*
 *  OpenGL (GLUT) calls this routine to display the scene
 */
void display()
{
   const double len=2.0;  //  Length of axes
   //  Erase the window and the depth buffer
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   //  Enable Z-buffering in OpenGL
   glEnable(GL_DEPTH_TEST);

   //  Undo previous transformations
   glLoadIdentity();
   //  Perspective - set eye position
   if (mode)
   {
      double Ex = -2*dim*Sin(th)*Cos(ph);
      double Ey = +2*dim        *Sin(ph);
      double Ez = +2*dim*Cos(th)*Cos(ph);
      gluLookAt(Ex,Ey,Ez , 0,0,0 , 0,Cos(ph),0);
   }
   //  Orthogonal - set world orientation
   else
   {
      glRotatef(ph,1,0,0);
      glRotatef(th,0,1,0);
   }

   //  Flat or smooth shading
   glShadeModel(smooth ? GL_SMOOTH : GL_FLAT);

   //  Light switch
   if (light)
   {
      //  Translate intensity to color vectors
      float Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
      float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
      float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};
      //  Light position
      float Position[]  = {distance*Cos(zh),ylight,distance*Sin(zh),1.0};
      //  Draw light position as ball (still no lighting here)
      glColor3f(1,1,1);
      ball(Position[0],Position[1],Position[2] , 0.1);
      //  OpenGL should normalize normal vectors
      glEnable(GL_NORMALIZE);
      //  Enable lighting
      glEnable(GL_LIGHTING);
      //  Location of viewer for specular calculations
      glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,local);
      //  glColor sets ambient and diffuse color materials
      glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
      glEnable(GL_COLOR_MATERIAL);
      //  Enable light 0
      glEnable(GL_LIGHT0);
      //  Set ambient, diffuse, specular components and position of light 0
      glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
      glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
      glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
      glLightfv(GL_LIGHT0,GL_POSITION,Position);
   }
   else
      glDisable(GL_LIGHTING);

   scene(0,0,0 , 0.5,0.5,0.5 , 0);

   //  Draw axes - no lighting from here on
   glDisable(GL_LIGHTING);
   glColor3f(1,1,1);
   if (axes)
   {
      glBegin(GL_LINES);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(len,0.0,0.0);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(0.0,len,0.0);
      glVertex3d(0.0,0.0,0.0);
      glVertex3d(0.0,0.0,len);
      glEnd();
      //  Label axes
      glRasterPos3d(len,0.0,0.0);
      Print("X");
      glRasterPos3d(0.0,len,0.0);
      Print("Y");
      glRasterPos3d(0.0,0.0,len);
      Print("Z");
   }

   //  Display parameters
   glWindowPos2i(5,5);
   Print("Angle=%d,%d  Dim=%.1f FOV=%d Projection=%s",
     th,ph,dim,fov,mode?"Perpective":"Orthogonal");
   if (light)
   {
      glWindowPos2i(5,45);
      Print("Light Elevation=%.1f",ylight);
      glWindowPos2i(5,25);
      Print("Light=%s",light?"On":"Off");
   }

   //  Render the scene and make it visible
   ErrCheck("display");
   glFlush();
   glutSwapBuffers();
}

/*
 *  GLUT calls this routine when the window is resized
 */
void idle()
{
   //  Elapsed time in seconds
   double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   zh = fmod(90*t,360.0);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when an arrow key is pressed
 */
void special(int key,int x,int y)
{
   //  Right arrow key - increase angle by 5 degrees
   if (key == GLUT_KEY_RIGHT)
      th += 5;
   //  Left arrow key - decrease angle by 5 degrees
   else if (key == GLUT_KEY_LEFT)
      th -= 5;
   //  Up arrow key - increase elevation by 5 degrees
   else if (key == GLUT_KEY_UP)
      ph += 5;
   //  Down arrow key - decrease elevation by 5 degrees
   else if (key == GLUT_KEY_DOWN)
      ph -= 5;
   //  PageUp key - increase dim
   else if (key == GLUT_KEY_PAGE_DOWN)
      dim += 0.1;
   //  PageDown key - decrease dim
   else if (key == GLUT_KEY_PAGE_UP && dim>1)
      dim -= 0.1;
   //  Keep angles to +/-360 degrees
   th %= 360;
   ph %= 360;
   //  Update projection
   Project(mode?fov:0,asp,dim);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when a key is pressed
 */
void key(unsigned char ch,int x,int y)
{
   //  Exit on ESC
   if (ch == 27)
      exit(0);
   //  Reset view angle
   else if (ch == '0')
   {
      th = -30;
      ph = 35;
   }
   //  Toggle axes
   else if (ch == 'a' || ch == 'A')
      axes = 1-axes;
   //  Toggle lighting
   else if (ch == 'l' || ch == 'L')
      light = 1-light;
   //  Switch projection mode
   else if (ch == 'p' || ch == 'P')
      mode = 1-mode;
   //  Toggle light movement
   else if (ch == 'm' || ch == 'M')
      move = 1-move;
   //  Move light
   else if (ch == '<')
      zh += 1;
   else if (ch == '>')
      zh -= 1;
   //  Change field of view angle
   else if (ch == '-' && ch>1)
      fov--;
   else if (ch == '+' && ch<179)
      fov++;
   //  Light elevation
   else if (ch=='[')
      ylight -= 0.1;
   else if (ch==']')
      ylight += 0.1;
   //  Translate shininess power to value (-1 => 0)
   shiny = shininess<0 ? 0 : pow(2.0,shininess);
   //  Reproject
   Project(mode?fov:0,asp,dim);
   //  Animate if requested
   glutIdleFunc(move?idle:NULL);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}

/*
 *  GLUT calls this routine when the window is resized
 */
void reshape(int width,int height)
{
   //  Ratio of the width to the height of the window
   asp = (height>0) ? (double)width/height : 1;
   //  Set the viewport to the entire window
   glViewport(0,0, width,height);
   //  Set projection
   Project(mode?fov:0,asp,dim);
}

/*
 *  Start up GLUT and tell it what to do
 */
int main(int argc,char* argv[])
{
   //  Initialize GLUT
   glutInit(&argc,argv);
   //  Request double buffered, true color window with Z buffering at 600x600
   glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
   glutInitWindowSize(800,600);
   glutCreateWindow("HW5: Kolin Newby");
   //  Set callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(special);
   glutKeyboardFunc(key);
   glutIdleFunc(idle);
   //  Pass control to GLUT so it can interact with the user
   ErrCheck("init");
   glutMainLoop();
   return 0;
}
