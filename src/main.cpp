#include <cstdlib>
#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class gltestapp
{
    public:
        int run(int, char*[]);
    protected:
        static void error_callback(int error, const char* description);
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        void show_framerate();
        GLFWwindow *Mainwindow = nullptr;
        long long framecounter = 0l;
        float startTime = 0.f;

};
void gltestapp::error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

void gltestapp::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void gltestapp::show_framerate()
{
    printf("\r|%f|%f|%lld|", framecounter / (glfwGetTime() - startTime), glfwGetTime()-startTime, framecounter);
}

int gltestapp::run(int argc, char *argv[])
{
    glfwSetErrorCallback(error_callback);

    if(!glfwInit())
        exit(EXIT_FAILURE);
    startTime = glfwGetTime();

    Mainwindow = glfwCreateWindow(640, 480, "simple ex", NULL, NULL);
    if(!Mainwindow)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(Mainwindow);
    glfwSetKeyCallback(Mainwindow, key_callback);

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
    return app.run(argc, argv);
}
