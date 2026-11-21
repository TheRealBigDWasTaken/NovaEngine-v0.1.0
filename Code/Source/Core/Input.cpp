#include "NovaEngine/Core/Input.h"

namespace NovaE {
	GLFWwindow* Input::m_Window = nullptr;

	void Input::Bind(GLFWwindow* window)
	{
		m_Window = window;
	}

	bool Input::IsKeyPressed(Key key){
        if (!m_Window)
            return false;
		int glfwKey;
        switch (key) {
        case Key::Space:        glfwKey = GLFW_KEY_SPACE; break;
        case Key::Apostrophe:   glfwKey = GLFW_KEY_APOSTROPHE; break;
        case Key::Comma:        glfwKey = GLFW_KEY_COMMA; break;
        case Key::Minus:        glfwKey = GLFW_KEY_MINUS; break;
        case Key::Period:       glfwKey = GLFW_KEY_PERIOD; break;
        case Key::Slash:        glfwKey = GLFW_KEY_SLASH; break;

        case Key::Num0: glfwKey = GLFW_KEY_0; break;
        case Key::Num1: glfwKey = GLFW_KEY_1; break;
        case Key::Num2: glfwKey = GLFW_KEY_2; break;
        case Key::Num3: glfwKey = GLFW_KEY_3; break;
        case Key::Num4: glfwKey = GLFW_KEY_4; break;
        case Key::Num5: glfwKey = GLFW_KEY_5; break;
        case Key::Num6: glfwKey = GLFW_KEY_6; break;
        case Key::Num7: glfwKey = GLFW_KEY_7; break;
        case Key::Num8: glfwKey = GLFW_KEY_8; break;
        case Key::Num9: glfwKey = GLFW_KEY_9; break;

        case Key::Semicolon: glfwKey = GLFW_KEY_SEMICOLON; break;
        case Key::Equal:     glfwKey = GLFW_KEY_EQUAL; break;

        case Key::A: glfwKey = GLFW_KEY_A; break;
        case Key::B: glfwKey = GLFW_KEY_B; break;
        case Key::C: glfwKey = GLFW_KEY_C; break;
        case Key::D: glfwKey = GLFW_KEY_D; break;
        case Key::E: glfwKey = GLFW_KEY_E; break;
        case Key::F: glfwKey = GLFW_KEY_F; break;
        case Key::G: glfwKey = GLFW_KEY_G; break;
        case Key::H: glfwKey = GLFW_KEY_H; break;
        case Key::I: glfwKey = GLFW_KEY_I; break;
        case Key::J: glfwKey = GLFW_KEY_J; break;
        case Key::K: glfwKey = GLFW_KEY_K; break;
        case Key::L: glfwKey = GLFW_KEY_L; break;
        case Key::M: glfwKey = GLFW_KEY_M; break;
        case Key::N: glfwKey = GLFW_KEY_N; break;
        case Key::O: glfwKey = GLFW_KEY_O; break;
        case Key::P: glfwKey = GLFW_KEY_P; break;
        case Key::Q: glfwKey = GLFW_KEY_Q; break;
        case Key::R: glfwKey = GLFW_KEY_R; break;
        case Key::S: glfwKey = GLFW_KEY_S; break;
        case Key::T: glfwKey = GLFW_KEY_T; break;
        case Key::U: glfwKey = GLFW_KEY_U; break;
        case Key::V: glfwKey = GLFW_KEY_V; break;
        case Key::W: glfwKey = GLFW_KEY_W; break;
        case Key::X: glfwKey = GLFW_KEY_X; break;
        case Key::Y: glfwKey = GLFW_KEY_Y; break;
        case Key::Z: glfwKey = GLFW_KEY_Z; break;

        case Key::LeftBracket:  glfwKey = GLFW_KEY_LEFT_BRACKET; break;
        case Key::Backslash:    glfwKey = GLFW_KEY_BACKSLASH; break;
        case Key::RightBracket: glfwKey = GLFW_KEY_RIGHT_BRACKET; break;
        case Key::GraveAccent:  glfwKey = GLFW_KEY_GRAVE_ACCENT; break;

        case Key::World1: glfwKey = GLFW_KEY_WORLD_1; break;
        case Key::World2: glfwKey = GLFW_KEY_WORLD_2; break;

        case Key::Escape:    glfwKey = GLFW_KEY_ESCAPE; break;
        case Key::Enter:     glfwKey = GLFW_KEY_ENTER; break;
        case Key::Tab:       glfwKey = GLFW_KEY_TAB; break;
        case Key::Backspace: glfwKey = GLFW_KEY_BACKSPACE; break;
        case Key::Insert:    glfwKey = GLFW_KEY_INSERT; break;
        case Key::Delete:    glfwKey = GLFW_KEY_DELETE; break;

        case Key::Right: glfwKey = GLFW_KEY_RIGHT; break;
        case Key::Left:  glfwKey = GLFW_KEY_LEFT; break;
        case Key::Down:  glfwKey = GLFW_KEY_DOWN; break;
        case Key::Up:    glfwKey = GLFW_KEY_UP; break;

        case Key::PageUp:   glfwKey = GLFW_KEY_PAGE_UP; break;
        case Key::PageDown: glfwKey = GLFW_KEY_PAGE_DOWN; break;
        case Key::Home:     glfwKey = GLFW_KEY_HOME; break;
        case Key::End:      glfwKey = GLFW_KEY_END; break;

        case Key::CapsLock:   glfwKey = GLFW_KEY_CAPS_LOCK; break;
        case Key::ScrollLock: glfwKey = GLFW_KEY_SCROLL_LOCK; break;
        case Key::NumLock:    glfwKey = GLFW_KEY_NUM_LOCK; break;
        case Key::PrintScreen: glfwKey = GLFW_KEY_PRINT_SCREEN; break;
        case Key::Pause:      glfwKey = GLFW_KEY_PAUSE; break;

        case Key::F1:  glfwKey = GLFW_KEY_F1; break;
        case Key::F2:  glfwKey = GLFW_KEY_F2; break;
        case Key::F3:  glfwKey = GLFW_KEY_F3; break;
        case Key::F4:  glfwKey = GLFW_KEY_F4; break;
        case Key::F5:  glfwKey = GLFW_KEY_F5; break;
        case Key::F6:  glfwKey = GLFW_KEY_F6; break;
        case Key::F7:  glfwKey = GLFW_KEY_F7; break;
        case Key::F8:  glfwKey = GLFW_KEY_F8; break;
        case Key::F9:  glfwKey = GLFW_KEY_F9; break;
        case Key::F10: glfwKey = GLFW_KEY_F10; break;
        case Key::F11: glfwKey = GLFW_KEY_F11; break;
        case Key::F12: glfwKey = GLFW_KEY_F12; break;
        case Key::F13: glfwKey = GLFW_KEY_F13; break;
        case Key::F14: glfwKey = GLFW_KEY_F14; break;
        case Key::F15: glfwKey = GLFW_KEY_F15; break;
        case Key::F16: glfwKey = GLFW_KEY_F16; break;
        case Key::F17: glfwKey = GLFW_KEY_F17; break;
        case Key::F18: glfwKey = GLFW_KEY_F18; break;
        case Key::F19: glfwKey = GLFW_KEY_F19; break;
        case Key::F20: glfwKey = GLFW_KEY_F20; break;
        case Key::F21: glfwKey = GLFW_KEY_F21; break;
        case Key::F22: glfwKey = GLFW_KEY_F22; break;
        case Key::F23: glfwKey = GLFW_KEY_F23; break;
        case Key::F24: glfwKey = GLFW_KEY_F24; break;
        case Key::F25: glfwKey = GLFW_KEY_F25; break;

        case Key::KP0: glfwKey = GLFW_KEY_KP_0; break;
        case Key::KP1: glfwKey = GLFW_KEY_KP_1; break;
        case Key::KP2: glfwKey = GLFW_KEY_KP_2; break;
        case Key::KP3: glfwKey = GLFW_KEY_KP_3; break;
        case Key::KP4: glfwKey = GLFW_KEY_KP_4; break;
        case Key::KP5: glfwKey = GLFW_KEY_KP_5; break;
        case Key::KP6: glfwKey = GLFW_KEY_KP_6; break;
        case Key::KP7: glfwKey = GLFW_KEY_KP_7; break;
        case Key::KP8: glfwKey = GLFW_KEY_KP_8; break;
        case Key::KP9: glfwKey = GLFW_KEY_KP_9; break;

        case Key::KPDecimal:  glfwKey = GLFW_KEY_KP_DECIMAL; break;
        case Key::KPDivide:   glfwKey = GLFW_KEY_KP_DIVIDE; break;
        case Key::KPMultiply: glfwKey = GLFW_KEY_KP_MULTIPLY; break;
        case Key::KPSubtract: glfwKey = GLFW_KEY_KP_SUBTRACT; break;
        case Key::KPAdd:      glfwKey = GLFW_KEY_KP_ADD; break;
        case Key::KPEnter:    glfwKey = GLFW_KEY_KP_ENTER; break;
        case Key::KPEqual:    glfwKey = GLFW_KEY_KP_EQUAL; break;

        case Key::LeftShift:   glfwKey = GLFW_KEY_LEFT_SHIFT; break;
        case Key::LeftControl: glfwKey = GLFW_KEY_LEFT_CONTROL; break;
        case Key::LeftAlt:     glfwKey = GLFW_KEY_LEFT_ALT; break;
        case Key::LeftSuper:   glfwKey = GLFW_KEY_LEFT_SUPER; break;

        case Key::RightShift:   glfwKey = GLFW_KEY_RIGHT_SHIFT; break;
        case Key::RightControl: glfwKey = GLFW_KEY_RIGHT_CONTROL; break;
        case Key::RightAlt:     glfwKey = GLFW_KEY_RIGHT_ALT; break;
        case Key::RightSuper:   glfwKey = GLFW_KEY_RIGHT_SUPER; break;

        case Key::Menu: glfwKey = GLFW_KEY_MENU; break;

        default:
            return false;
        }
		return glfwGetKey(m_Window, glfwKey) == GLFW_PRESS;
	}
    bool Input::IsMouseButtonPressed(MouseButton mb) {
        if (!m_Window)
            return false;
        int glfwButton;
        switch (mb) {
        case MouseButton::Left:
            glfwButton = GLFW_MOUSE_BUTTON_LEFT;
            break;
        case MouseButton::Right:
            glfwButton = GLFW_MOUSE_BUTTON_RIGHT;
            break;
        case MouseButton::Middle:
            glfwButton = GLFW_MOUSE_BUTTON_MIDDLE;
            break;
        case MouseButton::Button4:
            glfwButton = GLFW_MOUSE_BUTTON_4;
            break;
        case MouseButton::Button5:
            glfwButton = GLFW_MOUSE_BUTTON_5;
            break;
        case MouseButton::Button6:
            glfwButton = GLFW_MOUSE_BUTTON_6;
            break;
        case MouseButton::Button7:
            glfwButton = GLFW_MOUSE_BUTTON_7;
            break;
        case MouseButton::Button8:
            glfwButton = GLFW_MOUSE_BUTTON_8;
            break;
        default:
            return false;
        }
        return glfwGetMouseButton(m_Window, glfwButton) == GLFW_PRESS;
    }
}