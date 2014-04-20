/*!
 * Main file of my gltest opengl program.
 * \author Micha Ahrweiler
 * \date 2014-04-09
 */

#include <GL/glew.h>        // GLEW
#include <GLFW/glfw3.h>     // GLFW
#include <glm/glm.hpp>      // GLM

#include "gltestapp.h"
// stl
#include <cstdlib>
#include <cstdio>

gltestapp::gltestapp() {}
bool gltestapp::Init(int argc, char *argv[])
{
    glfwSetErrorCallback(ErrorCallback);
    if(!glfwInit())
    {
        fprintf(stderr, "failed to initialize glfw\n");
        return false;
    }
    startTime = glfwGetTime();
    if(!OpenWindow())
        return false;
    return true;
    
}
bool gltestapp::OpenWindow()
{
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x aa
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Mainwindow = glfwCreateWindow(640, 480, "simple ex", NULL, NULL);
    if(!Mainwindow)
    {
        glfwTerminate();
        return false;
    }
    return true;
}
void gltestapp::ErrorCallback(int error, const char* description)
{
    fputs(description, stderr);
}

void gltestapp::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void gltestapp::show_framerate()
{
    printf("\r|%f|%f|%lld|", framecounter / (glfwGetTime() - startTime), glfwGetTime()-startTime, framecounter);
}

int gltestapp::Run()
{
    GLuint VertexArrayID;
    //glGenVertexArrays(1, &VertexArrayID);
    //glBindVertexArray(VertexArrayID);

    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };
    

    glfwMakeContextCurrent(Mainwindow);
    glewExperimental=GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        fprintf(stderr, "glew init failed\n");
        return EXIT_FAILURE;
    }
    glfwSetKeyCallback(Mainwindow, KeyCallback);

    while(!glfwWindowShouldClose(Mainwindow))
    {
        float ratio;
        int width;
        int height;

        glfwGetFramebufferSize(Mainwindow, &width, &height);
        ratio = width / float(height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();
        glRotatef(float(glfwGetTime()) * 50.f, 0.f, 0.f, 1.f);

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(-0.9f, -0.9f, 0.f);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(-0.9f, -0.8f, 0.f);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(-0.8f, -0.9f, 0.f);
        glEnd();

        // block in the middle
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(-0.4f, -0.4f, 0.f);
        glVertex3f(0.0f, -0.0f, 0.f);
        glVertex3f(-0.4f, -0.0f, 0.f);
        glVertex3f(-0.4f, -0.4f, 0.f);
        glVertex3f(0.0f, -0.0f, 0.f);
        glVertex3f(-0.0f, -0.4f, 0.f);

        glVertex3f(0.4f, 0.4f, 0.f);
        glVertex3f(0.0f, 0.0f, 0.f);
        glVertex3f(0.4f, 0.0f, 0.f);
        glVertex3f(0.4f, 0.4f, 0.f);
        glVertex3f(0.0f, 0.0f, 0.f);
        glVertex3f(0.0f, 0.4f, 0.f);


        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.4f, 0.4f, 0.2f);
        glVertex3f(-0.0f, 0.0f, 0.f);
        glVertex3f(-0.4f, 0.0f, 0.f);
        glVertex3f(-0.4f, 0.4f, 0.2f);
        glVertex3f(-0.0f, 0.0f, 0.f);
        glVertex3f(-0.0f, 0.4f, 0.f);

        glVertex3f(0.4f, -0.4f, 0.2f);
        glVertex3f(0.0f, -0.0f, 0.f);
        glVertex3f(0.4f, -0.0f, 0.f);
        glVertex3f(0.4f, -0.4f, 0.2f);
        glVertex3f(0.0f, -0.0f, 0.f);
        glVertex3f(0.0f, -0.4f, 0.f);
        glEnd();

        glfwSwapBuffers(Mainwindow);
        glfwPollEvents();
        ++framecounter;
        show_framerate();
    }

    glfwDestroyWindow(Mainwindow);
    glfwTerminate();
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    gltestapp app;
    if(!app.Init(argc, argv))
        return EXIT_FAILURE;
    return app.Run();
}
