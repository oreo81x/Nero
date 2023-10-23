
// ______________________________________________________________________

#pragma once

// ______________________________________________________________________

#include <Nero/Config.hpp>
#include <Nero/Graphics/Camera.hpp>
#include <GLFW/glfw3.h>

// ______________________________________________________________________

namespace Nero
{

    // ______________________________________________________________________

    class CameraController
    {
    public:
        float MovmentSpeed      = 0.02f;
        float MouseSensitivity  = 75.0f;

        signed int KeyMoveFront = GLFW_KEY_W;
        signed int KeyMoveBack  = GLFW_KEY_S;
        signed int KeyMoveLeft  = GLFW_KEY_A;
        signed int KeyMoveRight = GLFW_KEY_D;
        signed int KeyMoveUp    = GLFW_KEY_SPACE;
        signed int KeyMoveDown  = GLFW_KEY_LEFT_CONTROL;

        signed int KeyRotatePositivePitch   = GLFW_KEY_KP_8;
        signed int KeyRotateNegativePitch   = GLFW_KEY_KP_2;
        signed int KeyRotatePositiveYaw     = GLFW_KEY_E;
        signed int KeyRotateNegativeYaw     = GLFW_KEY_Q;
        signed int KeyRotatePositiveRoll    = GLFW_KEY_KP_6;
        signed int KeyRotateNegativeRoll    = GLFW_KEY_KP_4;

        inline CameraController(Camera *p_Camera, GLFWwindow *p_Window)
            : m_Camera(p_Camera), m_Window(p_Window)
        {

        }

        inline void ControlMouseInput     ();
        inline void ControlKeyboardInput  ();

    private:
        Camera      *m_Camera = nullptr;
        GLFWwindow  *m_Window = nullptr;
    };

    // ______________________________________________________________________

    void CameraController::ControlMouseInput()
    {
        static bool mouseFirstClick = true;
        static signed int wndWidth  = 0;
        static signed int wndHeight = 0;

        glfwGetWindowSize(m_Window, &wndWidth, &wndHeight);

        if (glfwGetMouseButton(m_Window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	    {
	        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	        if (mouseFirstClick)
	        {
		        glfwSetCursorPos(m_Window, (wndWidth / 2), (wndHeight / 2));
		        mouseFirstClick = false;
	        }

	        double mouseX = 0.0;
	        double mouseY = 0.0;

	        glfwGetCursorPos(m_Window, &mouseX, &mouseY);

	        float rotx = MouseSensitivity * (float)(mouseY - (wndHeight  / 2)) / wndHeight;
    	    float roty = MouseSensitivity * (float)(mouseX - (wndWidth   / 2)) / wndWidth;

            m_Camera->Rotate(glm::vec3(-rotx, roty, 0.0f));

	        glfwSetCursorPos(m_Window, (wndWidth / 2), (wndHeight / 2));
    	}
	    else if (glfwGetMouseButton(m_Window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
    	{
	   	    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	   	    mouseFirstClick = true;
	    }
    }

    void CameraController::ControlKeyboardInput()
    {
        if (glfwGetKey(m_Window, KeyMoveFront) == GLFW_PRESS)
        {
            m_Camera->Move(m_Camera->GetFront() * MovmentSpeed);
        }

        if (glfwGetKey(m_Window, KeyMoveBack) == GLFW_PRESS)
        {
            m_Camera->Move(-m_Camera->GetFront() * MovmentSpeed);
        }

        if (glfwGetKey(m_Window, KeyMoveLeft) == GLFW_PRESS)
        {
            m_Camera->Move(-m_Camera->GetRight() * MovmentSpeed);
        }

        if (glfwGetKey(m_Window, KeyMoveRight) == GLFW_PRESS)
        {
            m_Camera->Move(m_Camera->GetRight() * MovmentSpeed);
        }

        if (glfwGetKey(m_Window, KeyMoveUp) == GLFW_PRESS)
        {
            m_Camera->Move(m_Camera->GetUp() * MovmentSpeed);
        }

        if (glfwGetKey(m_Window, KeyMoveDown) == GLFW_PRESS)
        {
            m_Camera->Move(-m_Camera->GetUp() * MovmentSpeed);
        }

        else {}

        float deg = 0.1f;

        if (glfwGetKey(m_Window, KeyRotatePositivePitch) == GLFW_PRESS)
        {
            m_Camera->Rotate(glm::vec3(deg, 0.0f, 0.0f));
        }

        if (glfwGetKey(m_Window, KeyRotateNegativePitch) == GLFW_PRESS)
        {
            m_Camera->Rotate(glm::vec3(-deg, 0.0f, 0.0f)); 
        }

        if (glfwGetKey(m_Window, KeyRotatePositiveYaw) == GLFW_PRESS)
        {
            m_Camera->Rotate(glm::vec3(0.0f, deg, 0.0f));
        }

        if (glfwGetKey(m_Window, KeyRotateNegativeYaw) == GLFW_PRESS)
        {
            m_Camera->Rotate(glm::vec3(0.0f, -deg, 0.0f));
        }

        if (glfwGetKey(m_Window, KeyRotatePositiveRoll) == GLFW_PRESS)
        {
            m_Camera->Rotate(glm::vec3(0.0f, 0.0f, deg));
        }

        if (glfwGetKey(m_Window, KeyRotateNegativeRoll) == GLFW_PRESS)
        {
            m_Camera->Rotate(glm::vec3(0.0f, 0.0f, -deg));
        }

        else {}
    }

    // ______________________________________________________________________

}

// ______________________________________________________________________
