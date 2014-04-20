#ifndef __GLTEST_H__
#define __GLTEST_H__

#include <GL/glew.h>        // GLEW
#include <GLFW/glfw3.h>     // GLFW
#include <glm/glm.hpp>      // GLM

/*!
 * Main class for gltest.
 */
class gltestapp
{
    public:
        gltestapp();
        /*!
         * Init function, sets up the context.
         * \param [in] argc Count of commandline params, like in int main.
         * \param [in] argv Double array of the commandline params like in int main.
         * \return false on error, otherwise true.
         */
        bool Init(int argc, char *argv[]);
        int Run();
        bool OpenWindow();
    protected:
        /*! Error callback for glfw. */
        static void ErrorCallback(int error, const char* description);
        /*! Key callback for glfw. */
        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        void show_framerate();
        GLFWwindow *Mainwindow = nullptr;
        long long framecounter = 0l;
        float startTime = 0.f;
};

#endif /* __GLTEST_H__ */
