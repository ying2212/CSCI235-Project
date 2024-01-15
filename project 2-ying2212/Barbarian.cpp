
/*************************************************
 * @author:  Guan Ying Goh       
 * @date:  09-13-23
 * @discription:  Barbarian.cpp
 * @instructor:   Professor Ligorio
 ************************************************/

#include "Barbarian.hpp"

#include <string>

#include <cctype>

Barbarian::Barbarian(){
    this->name_ = "NAMELESS";
    this->race_ = "NONE";
    this->vitality_ = 0;
    this->level_ = 0;
    this->armor_ = 0;
    this->enemy_ = true;
    setMainWeapon("NONE");
    setSecondaryWeapon("NONE");
    enraged_ = false;
}
    
Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& firstWeapon, const std::string secondWeapon , bool enraged)
{   
    setName (name);
    setRace (race);
    setVitality (vitality);
    setArmor (armor);
    setLevel (level);
    enemy_ = enemy;
    setMainWeapon(firstWeapon);
    setSecondaryWeapon(secondWeapon);
    setEnrage(enraged);
}

bool Barbarian::setMainWeapon(const std::string& firstWeapon) {
    main_weapon_ = ""; 
    for (int i = 0; i < firstWeapon.length(); i++) {
        char c = firstWeapon[i];
        if (std::isalpha(c)) {
            main_weapon_ += std::toupper(c);
        } else if (std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

std::string Barbarian::getMainWeapon() const{
    return main_weapon_;
}

bool Barbarian::setSecondaryWeapon(const std::string& secondWeapon) {
    secondary_weapon_ = ""; 
    for (int i = 0; i < secondWeapon.length(); i++) {
        char c = secondWeapon[i];
        if (std::isalpha(c)) {
            secondary_weapon_ += std::toupper(c);
        } else if (std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

std::string Barbarian::getSecondaryWeapon() const{
    return secondary_weapon_;
}

void Barbarian::setEnrage(bool enraged){
    enraged_ = enraged;
}

bool Barbarian::getEnraged() const{
    return enraged_;
}

void Barbarian::toggleEnrage(){
    enraged_ = !enraged_;
}

