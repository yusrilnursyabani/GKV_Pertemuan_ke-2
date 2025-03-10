#include <GL/glut.h>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;

void drawRect(float x, float y, float width, float height)
{
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}

void drawCircle(float x, float y, float r, int segmen)
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for(int i = 0; i <= segmen; i++)
        {
            float angle = 2.0f * 3.1415926f * float(i) / float(segmen);
            float dx = r * cosf(angle);
            float dy = r * sinf(angle);
            glVertex2f(x + dx, y + dy);
        }
    glEnd();
}

void drawBackground()
{
    glColor3f(0.6f, 0.8f, 1.0f);
    drawRect(-100.0f, 0.0f, 200.0f, 100.0f);
    glColor3f(0.2f, 0.8f, 0.2f);
    drawRect(-100.0f, -100.0f, 200.0f, 100.0f);
}

void drawSun()
{
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(70.0f, 70.0f, 12.0f, 36);
    glColor3f(1.0f, 0.7f, 0.0f);
    drawCircle(70.0f, 70.0f, 8.0f, 36);
}

void drawCar()
{
    glColor3f(0.8f, 0.0f, 0.0f);
    drawRect(-40.0f, 0.0f, 80.0f, 20.0f);
    glColor3f(0.8f, 0.0f, 0.0f);
    drawRect(-30.0f, 20.0f, 50.0f, 20.0f);
    glColor3f(0.6f, 0.6f, 0.6f);
    drawRect(30.0f, 0.0f, 10.0f, 10.0f);
    glColor3f(0.6f, 0.6f, 0.6f);
    drawRect(-50.0f, 0.0f, 10.0f, 10.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    drawRect(30.0f, 10.0f, 5.0f, 5.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
    drawRect(-50.0f, 10.0f, 5.0f, 5.0f);
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(-30.0f, 20.0f);
        glVertex2f(-5.0f, 20.0f);
        glVertex2f(5.0f, 40.0f);
        glVertex2f(-30.0f, 40.0f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-5.0f, 20.0f);
        glVertex2f(20.0f, 20.0f);
        glVertex2f(20.0f, 40.0f);
        glVertex2f(5.0f, 40.0f);
    glEnd();
    glPushMatrix();
        glTranslatef(25.0f, 0.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(0.0f, 0.0f, 8.0f, 36);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(0.0f, 0.0f, 4.0f, 36);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-25.0f, 0.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(0.0f, 0.0f, 8.0f, 36);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(0.0f, 0.0f, 4.0f, 36);
    glPopMatrix();
}

void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawBackground();
    drawSun();
    glPushMatrix();
        glTranslatef(0.0f, -30.0f, 0.0f);
        drawCar();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Praktikum 3 - Translasi & Rotasi (Contoh Mobil)");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

