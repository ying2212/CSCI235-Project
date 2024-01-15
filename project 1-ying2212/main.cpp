/*Name: Guan Ying Goh
Instructor: Professor Ligorio
Course: CSCI 235
*/

#include <iostream>
#include "Character.hpp"

int main() {
    Character character1("UNKNOWNPLAYER", HUMAN, 100, 50, 10, true);

    std::cout << "Character Name: " << character1.getName() << std::endl;
    std::cout << "Character Race: " << character1.getRace() << std::endl;
    std::cout << "Character Vitality: " << character1.getVitality() << std::endl;
    std::cout << "Character Armor: " << character1.getArmor() << std::endl;
    std::cout << "Character Level: " << character1.getLevel() << std::endl;
    std::cout << "Character Enemy: ";
    //Checking whether character1 is an enemy and printing "Yes" or "No" accordingly
    if (character1.isEnemy()) 
    {
        std::cout << "Yes";
    } 
    else 
    {
        std::cout << "No";
    }
    std::cout << std::endl;
    
    return 0;
}

