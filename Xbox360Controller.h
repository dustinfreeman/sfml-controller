#include <SFML/Graphics.hpp>

class Xbox360Controller {
private:
    int sf_Joystick_index;
    
    Xbox360Controller(int _sf_Joystick_index)
    {   sf_Joystick_index = _sf_Joystick_index; }
public:
    static Xbox360Controller GetController()  {
        for (int j = 0; j < sf::Joystick::Count; j++) {
            if (sf::Joystick::isConnected(j)) {
                Xbox360Controller controller(j);
                return controller;
            }
        }

        //HACKXbox360Controller controller(-1);
        Xbox360Controller controller(0);
        return controller;
    }
    
    bool isConnected()  {
        if (sf_Joystick_index < 0 || sf_Joystick_index > sf::Joystick::Count)
            return false;
        else
            return sf::Joystick::isConnected(sf_Joystick_index);
    }
    
    bool A()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 0);    }
    bool B()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 1);    }
    bool X()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 2);    }
    bool Y()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 3);    }
    
    bool RightBumper()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 4);    }
    bool LeftBumper()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 5);    }
    
    bool LeftThumbstickClick()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 6);    }
    bool RightThumbstickClick()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 7);    }
    
    bool Start()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 8);    }
    bool Back()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 9);    }
    bool XboxButton()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 10);    }
    
    bool DpadUp()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 11);    }
    bool DpadDown()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 12);    }
    bool DpadLeft()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 13);    }
    bool DpadRight()
    {    return sf::Joystick::isButtonPressed(sf_Joystick_index, 14);    }
    
    float LeftTriggerValue()
    {   return sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Z);    }
    float RightTriggerValue()
    {   return sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::R);   }

    float TriggerThreshold = 0;
    bool LeftTrigger()
    {   return LeftTriggerValue() > TriggerThreshold;    }
    bool RightTrigger()
    {   return RightTriggerValue() > TriggerThreshold;    }
    
    sf::Vector2f LeftThumbstick()
    {   return sf::Vector2f(sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::X),
                            sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Y));     }
    sf::Vector2f RightThumbstick()
    {   return sf::Vector2f(sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::U),
                            sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::V));     }

    //Motions from the D-pad or left thumbstick
    float ThumbstickThreshold = 50.0f;
    bool Up()
    {   return DpadUp() || LeftThumbstick().y < - ThumbstickThreshold;  }
    bool Down()
    {   return DpadDown() || LeftThumbstick().y > ThumbstickThreshold;  }
    bool Left()
    {   return DpadLeft() || LeftThumbstick().x < -ThumbstickThreshold;    }
    bool Right()
    {   return DpadRight() || LeftThumbstick().x > ThumbstickThreshold;    }

};
