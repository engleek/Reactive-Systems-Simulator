#include <QtGui>
#include <QtOpenGL>

#include <math.h>

#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    object = 0;
    xRot = 0;
    yRot = 0;
    zRot = 0;

    rtri = rquad = 0.0f;

    trolltechGreen = QColor::fromCmykF(0.40, 0.0, 1.0, 0.0);
    trolltechPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
}

GLWidget::~GLWidget()
{
    makeCurrent();
    glDeleteLists(object, 1);
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

void GLWidget::setXRotation(int angle)
{
}

void GLWidget::setYRotation(int angle)
{
}

void GLWidget::setZRotation(int angle)
{
}

void GLWidget::initializeGL()
{
    qglClearColor(trolltechPurple.dark());
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,10.0f);				// Move Right And Into The Screen

	glRotatef(rquad,1.0f,1.0f,1.0f);			// Rotate The Cube On X, Y & Z

	glBegin(GL_QUADS);					// Start Drawing The Cube	
		glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Green
		glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f, 1.0f);			// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f, 1.0f, 1.0f);			// Bottom Right Of The Quad (Top)
		
		glColor3f(1.0f,0.5f,0.0f);			// Set The Color To Orange
		glVertex3f( 1.0f,-1.0f, 1.0f);			// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f, 1.0f);			// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Bottom)
		glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Bottom)
		
		glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
		glVertex3f( 1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Front)
		glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,-1.0f, 1.0f);			// Bottom Left Of The Quad (Front)
		glVertex3f( 1.0f,-1.0f, 1.0f);			// Bottom Right Of The Quad (Front)

		glColor3f(1.0f,1.0f,0.0f);			// Set The Color To Yellow
		glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Back)
		glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Back)
		glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Back)
		glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Back)
		
		glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
		glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Left)
		glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f, 1.0f);			// Bottom Right Of The Quad (Left)
		
		glColor3f(1.0f,0.0f,1.0f);			// Set The Color To Violet
		glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Right)
		glVertex3f( 1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f, 1.0f);			// Bottom Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Right)
	glEnd();						// Done Drawing The Quad

	rquad-=0.15f;					// Decrease The Rotation Variable For The Quad
}

void GLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.5, +0.5, +0.5, -0.5, 4.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
	/*
    lastPos = event->pos();
    */
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
	/*
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
    */
}

GLuint GLWidget::makeObject()
{
	/*
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    glBegin(GL_QUADS);

    GLdouble x1 = +0.06;
    GLdouble y1 = -0.14;
    GLdouble x2 = +0.14;
    GLdouble y2 = -0.06;
    GLdouble x3 = +0.08;
    GLdouble y3 = +0.00;
    GLdouble x4 = +0.30;
    GLdouble y4 = +0.22;

    quad(x1, y1, x2, y2, y2, x2, y1, x1);
    quad(x3, y3, x4, y4, y4, x4, y3, x3);

    extrude(x1, y1, x2, y2);
    extrude(x2, y2, y2, x2);
    extrude(y2, x2, y1, x1);
    extrude(y1, x1, x1, y1);
    extrude(x3, y3, x4, y4);
    extrude(x4, y4, y4, x4);
    extrude(y4, x4, y3, x3);

    const double Pi = 3.14159265358979323846;
    const int NumSectors = 200;

    for (int i = 0; i < NumSectors; ++i) {
        double angle1 = (i * 2 * Pi) / NumSectors;
        GLdouble x5 = 0.30 * sin(angle1);
        GLdouble y5 = 0.30 * cos(angle1);
        GLdouble x6 = 0.20 * sin(angle1);
        GLdouble y6 = 0.20 * cos(angle1);

        double angle2 = ((i + 1) * 2 * Pi) / NumSectors;
        GLdouble x7 = 0.20 * sin(angle2);
        GLdouble y7 = 0.20 * cos(angle2);
        GLdouble x8 = 0.30 * sin(angle2);
        GLdouble y8 = 0.30 * cos(angle2);

        quad(x5, y5, x6, y6, x7, y7, x8, y8);

        extrude(x6, y6, x7, y7);
        extrude(x8, y8, x5, y5);
    }

    glEnd();

    glEndList();
    return list;
    */
}

void GLWidget::quad(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2,
                    GLdouble x3, GLdouble y3, GLdouble x4, GLdouble y4)
{
	/*
    qglColor(trolltechGreen);

    glVertex3d(x1, y1, -0.05);
    glVertex3d(x2, y2, -0.05);
    glVertex3d(x3, y3, -0.05);
    glVertex3d(x4, y4, -0.05);

    glVertex3d(x4, y4, +0.05);
    glVertex3d(x3, y3, +0.05);
    glVertex3d(x2, y2, +0.05);
    glVertex3d(x1, y1, +0.05);
    */
}

void GLWidget::extrude(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
	/*
    qglColor(trolltechGreen.dark(250 + int(100 * x1)));

    glVertex3d(x1, y1, +0.05);
    glVertex3d(x2, y2, +0.05);
    glVertex3d(x2, y2, -0.05);
    glVertex3d(x1, y1, -0.05);
    */
}

void GLWidget::normalizeAngle(int *angle)
{
	/*
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
    */
} 