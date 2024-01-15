/*
Name: Guan Ying Goh
Instructor: Professor Ligorio
Course: CSCI 235
*/

#include "Character.hpp"
#include <cctype>

//Default constructor to initializes member variables to default values
Character::Character() 
{
    name_ = "NAMELESS";
    race_ = NONE;
    vitality_ = 0;
    armor_ = 0;
    level_ = 0;
    enemy_ = false;
}

//Parameterized constructor to set the member variables 
Character::Character(const std::string& name, Race race, int vitality, int armor, int level, bool enemy) 
{
    name_ = name;
    setRace(race);
    vitality_ = vitality;
    armor_ = armor;
    level_ = level;
    enemy_ = enemy;
}


// Accessor methods
std::string Character::getName() const 
{
    return name_;
}

std::string Character::getRace() const 
{
    switch (race_) {
        case NONE: 
            return "NONE";
            break;
        case HUMAN: 
            return "HUMAN";
            break;
        case ELF: 
            return "ELF";
            break;
        case DWARF: 
            return "DWARF";
            break;
        case LIZARD: 
            return "LIZARD";
            break;
        case UNDEAD: 
            return "UNDEAD";
            break;
    }
    return "UNKNOWN";
}

int Character::getVitality() const 
{
    return vitality_;
}

int Character::getArmor() const 
{
    return armor_;
}

int Character::getLevel() const 
{
    return level_;
}

bool Character::isEnemy() const 
{
    return enemy_;
}

//Mutator Methods
void Character::setName(const std::string& name) 
{
    std::string title;
    for (int i = 0; i < name.length(); i++) {
        char c = name[i];
        if (std::isalpha(c)) {
            title += std::toupper(c);
        }
    }
    if (title.empty()) {
        name_ = "NAMELESS";
    } else {
        name_ = title;
    }
}

//Return the race to a string instead of default integral of enum.
void Character::setRace(Race race) 
{
    race_ = race;
}

void Character::setVitality(int vitality) 
{
    if (vitality >= 0) {
        vitality_ = vitality;
    }
}

void Character::setArmor(int armor) 
{
    if (armor >= 0) {
        armor_ = armor;
    }
}

void Character::setLevel(int level) 
{
    if (level >= 0) {
        level_ = level;
    }
}

void Character::setEnemy() 
{
    enemy_ = true;
}

