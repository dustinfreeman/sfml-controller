//Code for testing joysticks
//Possibly slightly broken - copied out of another project.
#include <SFML/Graphics.hpp>

int main(int, char const**)
{
 
    while(true) {
        //Joysticks
        sf::Joystick::update();
        for (int j = 0; j < sf::Joystick::Count; j++) {
            if (!sf::Joystick::isConnected(j))
                continue;

            std::cout << "Joystick " << j << "\n";
            
            
            for (int b = 0; b < sf::Joystick::getButtonCount(j); b++) {
                std::cout <<"\tButton " << b << ": "<< sf::Joystick::isButtonPressed(j,b) << "\n";
            }
            
            //Axes
            if (sf::Joystick::hasAxis(j, sf::Joystick::X)) {
                std::cout << "\tAxis " << "X " << ": " << sf::Joystick::getAxisPosition(j, sf::Joystick::X) << "\n";
            }
            if (sf::Joystick::hasAxis(j, sf::Joystick::Y)) {
                std::cout << "\tAxis " << "Y " << ": " << sf::Joystick::getAxisPosition(j, sf::Joystick::Y) << "\n";
            }
            if (sf::Joystick::hasAxis(j, sf::Joystick::Z)) {
                std::cout << "\tAxis " << "Z " << ": " << sf::Joystick::getAxisPosition(j, sf::Joystick::Z) << "\n";
            }
            if (sf::Joystick::hasAxis(j, sf::Joystick::R)) {
                std::cout << "\tAxis " << "R " << ": " << sf::Joystick::getAxisPosition(j, sf::Joystick::R) << "\n";
            }
            if (sf::Joystick::hasAxis(j, sf::Joystick::U)) {
                std::cout << "\tAxis " << "U " << ": " << sf::Joystick::getAxisPosition(j, sf::Joystick::U) << "\n";
            }
            if (sf::Joystick::hasAxis(j, sf::Joystick::V)) {
                std::cout << "\tAxis " << "V " << ": " << sf::Joystick::getAxisPosition(j, sf::Joystick::V) << "\n";
            }
            if (sf::Joystick::hasAxis(j, sf::Joystick::PovX)) {
                std::cout << "\tAxis " << "PovX " << ": " << sf::Joystick::getAxisPosition(j, sf::Joystick::PovX) << "\n";
            }
            if (sf::Joystick::hasAxis(j, sf::Joystick::PovY)) {
                std::cout << "\tAxis " << "PovY " << ": " << sf::Joystick::getAxisPosition(j, sf::Joystick::PovY) << "\n";
            }
        }
    
    }
}
