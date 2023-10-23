#include <Nero/OpenGL.hpp>
#include <Nero/Graphics.hpp>
#include <Nero/Graphics/Camera.hpp>
#include <Nero/Graphics/CameraController.hpp>
#include <Nero/Graphics/Extension.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

using namespace Nero;

int main()
{
    if (!glfwInit())
        return Fatal("glfw initialization failed");

    Info("glfw initialization succeeded");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

            GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const   GLFWvidmode *vidmode = glfwGetVideoMode(monitor);

    unsigned int    wndWidth    = vidmode->width;
    unsigned int    wndHeight   = vidmode->height;
    const char     *wndTitle    = "Whata Pretty Window!!";

    GLFWwindow *window = glfwCreateWindow(wndWidth, wndHeight, wndTitle, monitor, nullptr);

    if (!window)
    {
        glfwTerminate();
        return Fatal("could not create window");
    }
    Info("window creation succeeded");

    glfwMakeContextCurrent(window);

    gladLoadGL();
    glViewport(0, 0, wndWidth, wndHeight);   

    glEnable(GL_DEPTH_TEST);

    Renderer renderer;
    Camera   fpCamera;

    fpCamera.LetOrigin(glm::vec3(0.0f, 1.0f, 10.0f));
    fpCamera.LetWidth(wndWidth);
    fpCamera.LetHeight(wndHeight);
    fpCamera.LetRotation(glm::vec3(0.0f, 0.0f, 0.0f));
    fpCamera.LetFarPlane(15000.0f);

    std::vector<Vertex> batch;

    std::vector<Vertex> surfaceVec  = CreateSurface (CreateModelMatrix(glm::vec3( 0.0f, 0.0f, 0.0f), glm::vec3(4.0f, 4.0f, 4.0f), glm::radians(glm::vec3(90.0f, 0.0f, 0.0f))));
    std::vector<Vertex> pyramidVec  = CreatePyramid (CreateModelMatrix(glm::vec3(-1.0f, 0.6f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::radians(glm::vec3( 0.0f, 0.0f, 0.0f))));
    std::vector<Vertex> cubeVec     = CreateCube    (CreateModelMatrix(glm::vec3( 1.0f, 0.3f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::radians(glm::vec3( 0.0f, 0.0f, 0.0f))));

    batch.insert(batch.end(), surfaceVec.begin(), surfaceVec.end());
    batch.insert(batch.end(), pyramidVec.begin(), pyramidVec.end());
    batch.insert(batch.end(), cubeVec   .begin(), cubeVec   .end());

    RenderData skybox = CreateCube(CreateModelMatrix(glm::vec3(0.0f), glm::vec3(1000.0f), glm::radians(glm::vec3(0.0f))), Color::Sky);

    CameraController fpCameraController = CameraController(&fpCamera, window);

    while (!glfwWindowShouldClose(window))
    { 
        glfwPollEvents();

        fpCameraController.ControlMouseInput();
        fpCameraController.ControlKeyboardInput();
       
        if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
        {
            system("CLS");

            std::cout << std::endl;
            
            std::cout << "fpCamera.GetOrigin().x [ " << fpCamera.GetOrigin().x << " ]" << std::endl;
            std::cout << "fpCamera.GetOrigin().y [ " << fpCamera.GetOrigin().y << " ]" << std::endl;
            std::cout << "fpCamera.GetOrigin().z [ " << fpCamera.GetOrigin().z << " ]" << std::endl;

            std::cout << std::endl;

            std::cout << "fpCamera.GetRotation().x [ " << fpCamera.GetRotation().x << " ]" << std::endl;
            std::cout << "fpCamera.GetRotation().y [ " << fpCamera.GetRotation().y << " ]" << std::endl;
            std::cout << "fpCamera.GetRotation().z [ " << fpCamera.GetRotation().z << " ]" << std::endl;

            std::cout << std::endl;
        }

        renderer.Clear(Color(255.0f, 255.0f, 255.0f, 255.0f), Depth(1.0f));
        renderer.AddSceneCamera(&fpCamera);
        renderer.Draw(batch);
        renderer.Draw(skybox);

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
